// tcprewrite -D 192.168.1.255:127.0.0.1 -i ./2.pcap -o ./3.pcap
// udpreplay -i lo 3.pcap -r 10 -c 100

#include <errno.h>
#include <inttypes.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>
#include <czmq.h>

#include "../j2735/MessageFrame.h"
#include <arpa/inet.h>

#define J2735_UPER_MAP 18
#define J2735_UPER_SPAT 19
#define J2735_UPER_BSM 20
#define J2735_UPER_RSA 27
#define J2735_UPER_RTCM 28
#define J2735_UPER_TIM 31

#define OBU_IP "192.168.123.201"
#define OBU_PORT 30004
/*#define OBU_PORT 60000*/

long long alpha = 0;

int signal_state_a = 0; //First Traffic Light Status
int signal_state_b = 0; //Second Traffic Light

int signal_time_a = 0; //First Traffic Light Time
int signal_time_b = 0; //Second Traffic Light Time

char buf_x[30];
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

//Did not use map Data
static void decode_MapData(MessageFrame_t *frame) {
	printf("MAP : recv number :  %d\n",alpha);
	alpha++;
	
  /*printf("-----------------\n");*/
	/*MapData_t *msg = &frame->value.MapData;*/
  /*asn_fprint(stdout, &asn_DEF_MapData, msg);*/
   /*printf("map\n");*/
}

static void decode_TravelerInformation(MessageFrame_t *frame) {
  printf("tim\n");
}

static void decode_SignalPhaseAndTimingMessage(MessageFrame_t *frame) {
	SPAT_t *msg = &frame->value.SPAT;
   /*asn_fprint(stdout, &asn_DEF_SPAT, msg);*/
	IntersectionStateList_t *intersections = &msg->intersections;

	/*printf("%ld\n",intersections->list.array[0]->id.id);*/

	if (intersections->list.array[0]->id.id == 556) {
		signal_state_a = intersections->list.array[0]
							->states.list.array[0]
							->state_time_speed.list.array[0]
							->eventState;

		signal_time_a = intersections->list.array[0]
							->states.list.array[0]
							->state_time_speed.list.array[0]
							->timing->minEndTime;
		flag = 1;
	}

	if (intersections->list.array[0]->id.id == 560) {
		signal_state_b = intersections->list.array[0]
							->states.list.array[0]
							->state_time_speed.list.array[0]
							->eventState;

		signal_time_b = intersections->list.array[0]
							->states.list.array[0]
							->state_time_speed.list.array[0]
							->timing->minEndTime;
		flag = 1;
	}

	/*printf("%d\n",signal_time_a);*/
	/*printf("%d\n",signal_time_b);*/
	/*printf("%d\n",signal_state_a);*/
	/*printf("%d\n",signal_state_b);*/
}

static void decode_BasicSafetyMessage(MessageFrame_t *frame) {
  // BasicSafetyMessage_t *msg = &frame->value.BasicSafetyMessage;
  printf("bsm\n");

}

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


static void signal_handler(int signum) {
  fprintf(stdout, "\n");
  RUNNING = 0;
}

int main(int argc, char *argv[]) {
  struct timeval tv;
  fd_set fds;

  zsock_t *publisher = zsock_new_pub("tcp://*:5555");
  assert(publisher);

   /*FOR MAIN MODULE*/
/*   struct sockaddr_in sockaddr_x;*/
/*   int sock_x = -1;*/

/*   sockaddr_x.sin_family = AF_INET;*/
/*   sockaddr_x.sin_port = htons(65431);*/
/*   sockaddr_x.sin_addr.s_addr = inet_addr("192.168.123.253");*/

/*   if ((sock_x = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) { */
/*	   perror("socket creation failed"); */
/*	   exit(EXIT_FAILURE); */
/*   } */

   /*END MAIN*/

   /*FOR ESSYS OBU*/
   struct sockaddr_in sockaddr_l;
   int sock_l = -1;

   sockaddr_l.sin_family = AF_INET;
   sockaddr_l.sin_port = htons(OBU_PORT);
   sockaddr_l.sin_addr.s_addr = inet_addr(OBU_IP);
   /*END ESSYS*/


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
  /*sockaddr.sin_addr.s_addr = htonl("192.168.123.253");*/
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
		   printf("Send Complete/n");
	   } else {
		   printf("Resending/n");
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
	     ret = decode_MessageFrame(buf, nrecv);

      if (ret < 0) {
		 fprintf(stderr, "failed to decode: %d\n", ret);
        // close(sock);
        // return EXIT_FAILURE;
	  } else {
	  	  snprintf(buf_x, 30, "ff//%d//%d//%d//%d//", signal_time_a, signal_state_a,
	  	  		  								signal_time_b, signal_state_b);

		  if (flag == 1){
/*		  	  int result = sendto(sock_x, buf_x, sizeof(buf_x), 0,*/
/*		  	           (const struct sockaddr *)&sockaddr_x, sizeof(sockaddr_x));*/
                int result = zsock_send(publisher, "ss", "wave", buf_x);
				printf("sent : %d\n", result);
			flag = 0;
		  }
	  }
    }
	 /*system("clear");*/
  }
  zsock_destroy(&publisher);
  close(sock);
  return EXIT_SUCCESS;
}
