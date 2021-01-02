/*
 * clock.h
 *
 *  Created on: 23 ????. 2017 ?.
 *      Author: User
 */

#ifndef CLOCK_CLOCK_H_
#define CLOCK_CLOCK_H_

#define ROOM 2

#if 1==ROOM
#define ROOM_NAME "Parent"
#define _USE_DIMABLE_LED_
#define LED_MATRIX_ROTATION 1
#endif
#if 2==ROOM
#define ROOM_NAME "Children"
#define LED_MATRIX_ROTATION 3
#endif

#include <Arduino.h>
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPUpdateServer.h>
#include <LittleFS.h>

#include <Wire.h> // must be included here so that Arduino library object file references work
#include <pgmspace.h>
#include <stdio.h>
#include <iostream>
#include <sstream>

#include "./libs/NTPtime.h"
#include "./libs/Max72xxPanel.h" // https://github.com/markruys/arduino-Max72xxPanel.git
#include "FreeMono9pt7b.h"

#include "DHTesp.h"

#include "./libs/unsorted.h"
#include "./libs/CLightDetectResistor.h"

#include "./libs/CMQTT.h"
#include "./libs/misk.h"
#include "./libs/wifiHandle.h"
#include "./libs/TimeLib.h"
#include "./libs/Timezone.h"
#include "./libs/logs.h"

const uint16_t kRecvPin = D3;
const uint16_t kCaptureBufferSize = 512;
const uint8_t kTimeout = 50;  // Milli-Seconds

#include <IRrecv.h>
#include <IRremoteESP8266.h>
#include <IRutils.h>
#include <IRtext.h>


#include "secret.h_ex"


#ifdef _USE_DIMABLE_LED_
#include "CDimableLed.h"
#endif

#define MQTT_TEMPERATURE (1+(ROOM-1)*2)
#define MQTT_HUMIDITY (MQTT_TEMPERATURE+1)
#define DEVICE_NAME "CLOCK_" ROOM_NAME
#define DEF_AP_PWD "12345678"

#define DEBUG

#define SERIAL_BAUND 115200
#define SERVER_PORT_WEB 80
#define WIFI_CONNECT_TIMEOUT 20000 //ms

#endif /* CLOCK_CLOCK_H_ */
