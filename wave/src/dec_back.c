// V2X Vanilla Module
// Justin Han - Inha Univ Cvlab
// Makefile is in the same folder 
// make clean
// make
//
// FOR UPDATE VERSION
// git clone git@cvlab.ddns.net:han/wave
// AUTHORIZATION NEEDED -> CONTACT +821029231680
//
// tcprewrite -D 192.168.1.255:127.0.0.1 -i ./2.pcap -o ./3.pcap
// udpreplay -i lo 3.pcap -r 10 -c 100

/*
<TODO>
제한속도            TIM
  (INT) : 29/30/50
신호등 상태 및 시간   SPAT
  (INT)RED : 3
  (INT)GREEN : 5
  (INT)YELLOW : 7
  (INT)N/A : 0 / -1

응급차량 위치        BSM

const char* msg = "40|";
*/

#include <errno.h>
#include <inttypes.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>

#include "../j2735/MessageFrame.h"
#include <arpa/inet.h>
// #include <MessageFrame.h>

#define J2735_UPER_MAP 18
#define J2735_UPER_SPAT 19
#define J2735_UPER_BSM 20
#define J2735_UPER_RSA 27
#define J2735_UPER_RTCM 28
#define J2735_UPER_TIM 31

#define OBU_IP "192.168.123.201"
#define OBU_PORT 60000
/*#define OBU_PORT 30004*/

int speedLimit_a = 0;	//Speed limit in School Zone
int signal_stat_a = 0; //First Traffic Light Status
int signal_stat_b = 0; //Second Traffic Light
int signal_stat_c = 0; //Third Traffic Light 

int signal_time_a = 0; //First Traffic Light Time
int signal_time_b = 0; //Second Traffic Light Time
int signal_time_c = 0; //Third Traffic Light Time

long coordinate_lat = 0;
long coordinate_long = 0;

char buf_l[200];

long tim_lat[12], tim_lon[12];

int flag = 0;

typedef struct AVC_HDR {
  uint32_t sec;
  uint32_t usec;
  uint32_t type;
  uint32_t len;
} __attribute__((packed)) AVC_HDR_t;

typedef struct AVC_TAIL {
  uint16_t crc16;
} __attribute__((packed)) AVC_TAIL_t;

static int RUNNING = 0;

// Used to Debug Traffic Signal time
static void print_SPaT() {
  printf("A: %d %d \nB: %d %d \nC: %d %d\n", signal_stat_a, signal_time_a,
         signal_stat_b, signal_time_b, signal_stat_c, signal_time_c);
}

//Did not use map Data
static void decode_MapData(MessageFrame_t *frame) {}

static void decode_TravelerInformation(MessageFrame_t *frame) {
  /*Make sure to differenciate WK Zone from School Zone
  Task 1 : IF(WK Zone or School Zone)
    Task 2 :  IF(WK) : ID and save lat lon
              IF(SZ) : SpeedLimit
  */
  int speedlimit_int; //Speed limit in INT
  char speedlimit_char; //Speed Limit in String - Not Seperate 

  TravelerInformation_t *msg = &frame->value.TravelerInformation;
  TravelerDataFrameList_t *dataFrames = &msg->dataFrames;

  fprintf(stdout, "TIM\n");
  for (int i = 0; i < dataFrames->list.count; i++) { //List of Workzone areas 
    struct TravelerDataFrame__content *timContent =
        &dataFrames->list.array[i]->content;

    // WorkZone
    if (timContent->present == 2) {
      int ind = 0;
      GeographicalPath_t *geoPoint =
      dataFrames->list.array[i]->regions.list.array[0];
      if(i == 0) ind = 0;
      else if(i == 1) ind = 3;
      else if(i == 2) ind = 6;


      //Anchor Point -> Note this is not the start/end point -> Just the anchor
      tim_lat[ind] = geoPoint->anchor->lat;
      tim_lon[ind] = geoPoint->anchor->Long;

      //Start Point Lat/Lon
      tim_lat[ind + 1] = geoPoint->description->path.offset.xy.nodes.list.array[0]
                       ->delta.node_LatLon.lat;
      tim_lon[ind + 1] = geoPoint->description->path.offset.xy.nodes.list.array[0]
                       ->delta.node_LatLon.lon;

      //End Point Lat/Lon
      tim_lat[ind + 2] = geoPoint->description->path.offset.xy.nodes.list.array[1]
                       ->delta.node_LatLon.lat;
      tim_lon[ind + 2] = geoPoint->description->path.offset.xy.nodes.list.array[1]
                       ->delta.node_LatLon.lon;


      flag = 1;
      // -----TIM OUTPUT----- Remove Comment if Output is needed
      // system("clear");
      // printf("WORKZONE ---%ld:%ld:%ld:%ld:%ld:%ld\n", tim_lat[0], tim_lon[0], tim_lat[1],
      //        tim_lon[1], tim_lat[2], tim_lon[2]);
      // -----TIM OUTPUT----- END
    };

    // School ZONE
    if (timContent->present == 4) {
      GeographicalPath_t *geoPoint =
          dataFrames->list.array[i]->regions.list.array[0];
     
      
      //Anchor Point -> Note this is not the start/end point -> Just the anchor
      tim_lat[9] = geoPoint->anchor->lat;
      tim_lon[9] = geoPoint->anchor->Long;

      //Start Point -> Lat/Lon
      tim_lat[10] = geoPoint->description->path.offset.xy.nodes.list.array[0]
                       ->delta.node_LatLon.lat;
      tim_lon[10] = geoPoint->description->path.offset.xy.nodes.list.array[0]
                       ->delta.node_LatLon.lon;

      //End Point -> Lat/Lon
      tim_lat[11] = geoPoint->description->path.offset.xy.nodes.list.array[1]
                       ->delta.node_LatLon.lat;
      tim_lon[11] = geoPoint->description->path.offset.xy.nodes.list.array[1]
                       ->delta.node_LatLon.lon;

      flag = 1;
      // system("clear");
      // printf("SCHOOLZONE ---%ld:%ld:%ld:%ld:%ld:%ld\n", tim_lat[0], tim_lon[0], tim_lat[1],
      //        tim_lon[1], tim_lat[2], tim_lon[2]);
    };

    // printf("%ld\n",&timContent->speedLimit.list.array[0]->item.itis);
    SpeedLimit_t *speedLimit_l = &timContent->speedLimit;

    ITIStextPhrase_t *timtext = &speedLimit_l->list.array[0]->item.text;
    sscanf((const char *)timtext->buf, "%[^,],%d", &speedlimit_char,
           &speedlimit_int);
    // printf("%s\n", timtext->buf);
    // printf("%d\n", speedlimit_int);

    for (int j = 0; j < dataFrames->list.array[i]->regions.list.count; j++) {
      // printf("%d\n", i);
      GeographicalPath_t *startpoint =
          dataFrames->list.array[i]->regions.list.array[j];
      // system("clear");
      // for (int k = 0;
      //   k < startpoint->description->path.offset.xy.nodes.list.count; k++) {
      //     NodeXY_t *start =
      //       startpoint->description->path.offset.xy.nodes.list.array[0];
      //   printf("Latitude : %ld\n", start->delta.node_LatLon.lat);
      //   printf("Longitude : %ld\n", start->delta.node_LatLon.lon);
      //     NodeXY_t *end =
      //       startpoint->description->path.offset.xy.nodes.list.array[1];
      //   printf("Latitude : %ld\n", end->delta.node_LatLon.lat);
      //   printf("Longitude : %ld\n", end->delta.node_LatLon.lon);
      // // }
    }
  }
}

static void decode_SignalPhaseAndTimingMessage(MessageFrame_t *frame) {
  SPAT_t *msg = &frame->value.SPAT;
  IntersectionStateList_t *intersections = &msg->intersections;
   printf("%ld/n",intersections->list.array[0]->id.id);

   //SPaT -- Traffic Signal 
   //State, Start/End Remaining Time 
   //For ID=400,500,700 (KCity Traffic Signal Points)
  if (intersections->list.array[0]->id.id == 400) {
    signal_stat_a = intersections->list.array[0]
                        ->states.list.array[6]
                        ->state_time_speed.list.array[0]
                        ->eventState;

    signal_time_a = intersections->list.array[0]
                        ->states.list.array[6]
                        ->state_time_speed.list.array[0]
                        ->timing->minEndTime;
    flag = 1;
  }

  if (intersections->list.array[0]->id.id == 500) {
    signal_stat_b = intersections->list.array[0]
                        ->states.list.array[6]
                        ->state_time_speed.list.array[0]
                        ->eventState;

    signal_time_b = intersections->list.array[0]
                        ->states.list.array[6]
                        ->state_time_speed.list.array[0]
                        ->timing->minEndTime;
    flag = 1;
  }

  if (intersections->list.array[0]->id.id == 700) {
    signal_stat_c = intersections->list.array[0]
                        ->states.list.array[4]
                        ->state_time_speed.list.array[0]
                        ->eventState;

    signal_time_c = intersections->list.array[0]
                        ->states.list.array[4]
                        ->state_time_speed.list.array[0]
                        ->timing->minEndTime;
    flag = 1;
  }
}

static void decode_BasicSafetyMessage(MessageFrame_t *frame) {
  BasicSafetyMessage_t *msg = &frame->value.BasicSafetyMessage;
  BSMcoreData_t *coreData = &msg->coreData;

  /*  fprintf(stdout, "  lat          : %ld\n", coreData->lat);*/
  /*  fprintf(stdout, "  Long         : %ld\n", coreData->Long);*/
  /*  fprintf(stdout, "  elev         : %ld\n", coreData->elev);*/

  if (msg->partII == NULL || msg->partII->list.count == 0)
    return;

  for (int i = 0; i < msg->partII->list.count; i++) {
    // if (msg->partII->list.array[i]->partII_Id ==
    //         PartIIcontent__partII_Value_PR_VehicleSafetyExtensions &&
    //     msg->partII->list.array[i]->partII_Value.present ==
    //         PartIIcontent__partII_Value_PR_VehicleSafetyExtensions) {
    // VehicleSafetyExtensions_t *vehicleSafetyExtensions =
    //     &msg->partII->list.array[i]->partII_Value.VehicleSafetyExtensions;

    // fprintf(stdout, "%ld\n",msg->partII->list.array[i]->partII_Id);
    // fprintf(stdout, "%d\n",msg->partII->list.array[i]->partII_Value.present);
    if (msg->partII->list.array[i]->partII_Id == 2 &&
        msg->partII->list.array[i]->partII_Value.present == 3) {
      SupplementalVehicleExtensions_t *SuppSafetyExtensions =
          &msg->partII->list.array[i]
               ->partII_Value.SupplementalVehicleExtensions;

      /*      fprintf(stdout, "%S\n", SuppSafetyExtensions->classification);*/
    }
  }
}

//Used for GNSS Correction using RTCM message types 
//Not Used in this Project
static void decode_RTCMcorrections(MessageFrame_t *frame) {}

//Stage 2 Decoding => Extract MessageFrame from AVC2019 Data
static int decode_MessageFrame(const uint8_t *buf, int len) {
  MessageFrame_t *frame = NULL;
  asn_dec_rval_t rval;
  rval = uper_decode_complete(NULL, &asn_DEF_MessageFrame, (void **)&frame, buf,
                              len);
  if (rval.code != RC_OK) {
    // fprintf(stderr, "failed to decode MessageFrame\n");
    ASN_STRUCT_FREE(asn_DEF_MessageFrame, frame);
    return -1;
  }

  //Goes to Decoded Function
  if (frame->messageId == J2735_UPER_MAP &&
      frame->value.present == MessageFrame__value_PR_MapData) {
    decode_MapData(frame);
  }

  // SPAT!!!!!!!!!!!!!!!!!
  else if (frame->messageId == J2735_UPER_SPAT &&
           frame->value.present == MessageFrame__value_PR_SPAT) {
    decode_SignalPhaseAndTimingMessage(frame);
  }

  // BSM!!!!!!!!!!!!!!!!!!
  else if (frame->messageId == J2735_UPER_BSM &&
           frame->value.present == MessageFrame__value_PR_BasicSafetyMessage) {
    decode_BasicSafetyMessage(frame);
  }

  // RTCM!!!!!!!!!!!!!!!!!
  else if (frame->messageId == J2735_UPER_RTCM &&
           frame->value.present == MessageFrame__value_PR_RTCMcorrections) {
    decode_RTCMcorrections(frame);
  }

  // TIM!!!!!!!!!!!!!!!!!!
  else if (frame->messageId == J2735_UPER_TIM &&
           frame->value.present == MessageFrame__value_PR_TravelerInformation) {
    decode_TravelerInformation(frame);
  }

  ASN_STRUCT_FREE(asn_DEF_MessageFrame, frame);
  return rval.code;
}

//Stage 1 Decoding -> Extract Header and goes to MessageFrame
static int decode_avc2019(const uint8_t *buf, int len) {
	printf("%d", buf);
  	printf("Len : %d // Packetsize : : %d \n", len, sizeof(AVC_HDR_t));
  if (len < sizeof(AVC_HDR_t)) {
    fprintf(stderr, "packet size is less than header\n");
    return -1;
  }

 
  const AVC_HDR_t *hdr = (AVC_HDR_t *)buf;


  uint32_t sec = ntohl(hdr->sec);
  uint32_t usec = ntohl(hdr->usec);
  uint32_t type = ntohl(hdr->type);
  uint32_t dlen = ntohl(hdr->len);

  // fprintf(stdout, "================================================\n");
  // fprintf(stdout, "time: %u.%06u, type: %2u, len: %4u\n", sec, usec, type,
  // dlen);

  if (dlen + sizeof(AVC_HDR_t) + sizeof(AVC_TAIL_t) != len) {
    fprintf(stderr, "packet size is less than data: %lu %u\n",
            dlen + sizeof(AVC_HDR_t), len);
    fprintf(stdout, "================================================\n");
    return -1;
  }

  return decode_MessageFrame(buf + sizeof(AVC_HDR_t), dlen);
}

static void signal_handler(int signum) {
  fprintf(stdout, "\n");
  RUNNING = 0;
}

int main(int argc, char *argv[]) {
  struct timeval tv;
  fd_set fds;

  /*[> FOR HYUNDAI MISSION<]
  //To Decision Module
  struct sockaddr_in sockaddr_l;
  int sock_l = -1;

  sockaddr_l.sin_family = AF_INET;
  sockaddr_l.sin_port = htons(60000);
  sockaddr_l.sin_addr.s_addr = inet_addr(YOUR_IP);

  sock_l = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if (sock_l == -1) {
    fprintf(stderr, "failed to create socket PIPE\n");
    // return EXIT_FAILURE;
  }
*/

  /* FOR ESSYS OBU*/
  struct sockaddr_in sockaddr_l;
  int sock_l = -1;

  sockaddr_l.sin_family = AF_INET;
  sockaddr_l.sin_port = htons(OBU_PORT);
  sockaddr_l.sin_addr.s_addr = inet_addr(OBU_IP);
  /* END ESSYS*/
  

  /* MAIN WAVE SOCKET*/
  //From OBU 
  struct sockaddr_in sockaddr;
  int sock = -1;
  int ret = -1;
  int on = 1;
  char* msg = "INHA UNIVERSITY";
  
  /*int msg_len = strlen(msg);*/
  uint8_t buf[4096];
  int isend_result = 0;
  int nrecv;

  memset(&sockaddr, 0, sizeof(sockaddr));
  sockaddr.sin_family = AF_INET;
  sockaddr.sin_port = htons(30004);
  sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  /*sockaddr.sin_addr.s_addr = htonl("127.0.0.1");*/
  /*sockaddr.sin_addr.s_addr = inet_addr(OBU_IP);*/

  sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if (sock == -1) {
    fprintf(stderr, "failed to create socket\n");
    return EXIT_FAILURE;
  }

  ret = setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
  if (ret == -1) {
    fprintf(stderr, "failed to set socket option: %d\n", errno);
    close(sock);
    return EXIT_FAILURE;
  }

  ret = bind(sock, (struct sockaddr *)&sockaddr, sizeof(sockaddr));
  if (ret == -1) {
    fprintf(stderr, "failed to bind socket: %d\n", errno);
    close(sock);
    return EXIT_FAILURE;
  }

  signal(SIGINT, signal_handler);

  RUNNING = 1;
  
  while(isend_result == 0) {
	  isend_result =  sendto(sock, msg, sizeof(msg), 0, (const struct sockaddr *)&sockaddr_l, sizeof(sockaddr_l) );
	  if (isend_result == 1){
		  printf("Send Complete");
	  } else {
		  printf("Resending");
	  }
  }

  while (RUNNING) {
    FD_ZERO(&fds);
    FD_SET(sock, &fds);

    tv.tv_sec = 0;
    tv.tv_usec = 1000; /* 1ms */

    ret = select(sock + 1, &fds, NULL, NULL, &tv);
    if (ret == -1) {
      if (errno == EINTR)
        continue;
      fprintf(stderr, "failed to select socket: %d\n", errno);
      close(sock);
      return EXIT_FAILURE;
    } else if (ret == 0)
      continue;

    if (FD_ISSET(sock, &fds)) {
      nrecv = recvfrom(sock, buf, sizeof(buf), 0, NULL, NULL);
      if (nrecv == -1) {
        fprintf(stderr, "failed to recvfrom: %d\n", nrecv);
        close(sock);
        return EXIT_FAILURE;
      }

      /*ret = decode_avc2019(buf, nrecv);*/
	/*ret = decode_MessageFrame(buf, nrecv);*/
      
      fprintf("%d", ret);

      if (ret < 0) {
		 fprintf(stderr, "failed to decode: %d\n", ret);
        // close(sock);
        // return EXIT_FAILURE;
      } else {
	//Place Holder for UDP Send -> Dest : Decision/Planning Module
		/*
         *snprintf(buf_l, 200, "%d|%d|%d|%d|%d|%d|%ld|%ld|%ld|%ld|%ld|%ld|%ld|%ld|%ld|%ld|%ld|%ld|%ld|%ld|%ld|%ld|%ld|%ld|%ld|%ld|%ld|%ld|%ld|%ld\n", signal_stat_a,
         *         signal_time_a, signal_stat_b, signal_time_b, signal_stat_c,
         *         signal_time_c, tim_lat[0], tim_lon[0], tim_lat[1], tim_lon[1],
         *         tim_lat[2], tim_lon[2], tim_lat[3], tim_lon[3], tim_lat[4],
         *         tim_lon[4], tim_lat[5], tim_lon[5], tim_lat[6], tim_lon[6],
         *         tim_lat[7], tim_lon[7], tim_lat[8], tim_lon[8], tim_lat[9],
         *         tim_lon[9], tim_lat[10], tim_lon[10], tim_lat[11], tim_lon[11]);
		 */
		 	printf("%s", buf_l);
		 	printf("HERE");
        if (flag == 1) {
          	    system("clear\n");
                printf("%s", buf_l);

          /*sendto(sock_l, buf_l, sizeof(buf_l), 0,
                 (const struct sockaddr *)&sockaddr_l, sizeof(sockaddr_l));*/
          flag = 0;
        }
      }
    }
    // system("clear");
  }
  close(sock);
  return EXIT_SUCCESS;
}
