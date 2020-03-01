// tcprewrite -D 192.168.1.255:127.0.0.1 -i ./2.pcap -o ./3.pcap
// 
// udpreplay -i lo 3.pcap -r 10 -c 100

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

#define J2735_UPER_MAP 18
#define J2735_UPER_SPAT 19
#define J2735_UPER_BSM 20
#define J2735_UPER_RSA 27
#define J2735_UPER_RTCM 28
#define J2735_UPER_TIM 31

#define OBU_IP "192.168.123.201"
#define OBU_PORT 60000


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
	MAP *msg = &frame->value.MAP;
  asn_fprint(stdout, &asn_DEF_MapData, msg);
  // printf("map\n");
}

static void decode_TravelerInformation(MessageFrame_t *frame) {
  printf("tim\n");
}

static void decode_SignalPhaseAndTimingMessage(MessageFrame_t *frame) {
  SPAT_t *msg = &frame->value.SPAT;
  // asn_fprint(stdout, &asn_DEF_SPAT, msg);

    // IntersectionStateList_t *intersections = &msg->intersections;

    // if (intersections->list.array[0]->id.id == 400) {
    //   printf("%ld\n", intersections->list.array[0]
    //                     ->states.list.array[6]
    //                     ->state_time_speed.list.array[0]
    //                     ->eventState);
    // }
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

  /* FOR ESSYS OBU*/
  // struct sockaddr_in sockaddr_l;
  // int sock_l = -1;
  //
  // sockaddr_l.sin_family = AF_INET;
  // sockaddr_l.sin_port = htons(OBU_PORT);
  // sockaddr_l.sin_addr.s_addr = inet_addr(OBU_IP);
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
  // sockaddr.sin_addr.s_addr = htonl("127.0.0.1");
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

  // while(isend_result == 0) {
	//   isend_result =  sendto(sock, msg, sizeof(msg), 0, (const struct sockaddr *)&sockaddr_l, sizeof(sockaddr_l) );
	//   if (isend_result == 1){
	// 	  printf("Send Complete");
	//   } else {
	// 	  printf("Resending");
	//   }
  // }

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
      }
    }
    // system("clear");
  }
  close(sock);
  return EXIT_SUCCESS;
}
