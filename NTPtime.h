/*
 * NTPtime.h
 *
 *  Created on: 4 ???. 2017 ?.
 *      Author: User
 */

#ifndef CLOCK_NTPTIME_H_
#define CLOCK_NTPTIME_H_
//#define DUBUG_CLOCK_NTPTIME

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <time.h>

class NTPtime {
private:
  time_t refreshPeriod = 10 * 1000; // ms
  const static uint32 sendDiscardPeriod = 1000;     // ms
  uint32 refreshed = 0;                             // ms
  uint32 sendOn = 0;                                // ms
  IPAddress timeServerIP; // time.nist.gov NTP server address
  const char *ntpServerName = "time.nist.gov";

  const static int NTP_PACKET_SIZE =   48; // NTP time stamp is in the first 48 bytes of the message

  byte packetBuffer[NTP_PACKET_SIZE]; // buffer to hold incoming packets

  const static unsigned int localPort =  2390; // local port to listen for UDP packets
  WiFiUDP udp;
  int32 parceAsEpoch();
  int sendNTPpacket();

public:
	NTPtime();
	void init();
	time_t getTime();
	void setSyncInterval(time_t interval){
		refreshPeriod=interval;
	}
	time_t getTimeAsink();
	virtual ~NTPtime();
};

#endif /* CLOCK_NTPTIME_H_ */
