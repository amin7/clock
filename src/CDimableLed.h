/*
 * CDimableLed.h
 *
 * on: 3 Jan , 2020
 *      Author: ominenko
 */

#pragma once
#include <Arduino.h>
#include <stdint.h>
#include <IRrecv.h>
#include <IRremoteESP8266.h>
#include <IRutils.h>
#include <IRtext.h>
#include <string>
#include <functional>
#include <map>
#include "./libs/CSignal.h"

constexpr uint16_t kCaptureBufferSize = 1024;
constexpr uint8_t kTimeout = 15;  // Milli-Seconds
constexpr auto GPIO_POUT_LED = D1;
constexpr auto GPIO_PIN_WALL_SWITCH = D2;
constexpr auto GPIO_PIN_IRsensor = D3;
constexpr auto TIMEOUT_WALL_SWITCH = 100;


class CIRSignal:public SignalLoop<uint64_t>{
	IRrecv irrecv;
public:
	CIRSignal();
	bool getExclusive(uint64_t &val, const uint32_t timeout=5000);
	void begin() override;
	void loop() override;
};


class CWallSwitchSignal:public SignalChange<bool>{
private:
	bool preVal_;
	uint32_t event_timeout;
	bool getValue();
	bool readRaw()const;
public:
	void begin() override;
};

/*
 *
 */

class CLedCmdSignal:public Signal<uint16_t >{
	int ledValue;
	std::map<std::string , std::function <void(const int32_t)> > cmd_list;
	void set(const int32_t val);
	void toggle(const int32_t val);
	bool m_enabled=false;
public:
	CLedCmdSignal();
	bool onCmd(const std::string &cmd,const int32_t val);
	void onIRcmd(const uint64_t &cmd);
	void onWallcmd(const bool &state);
	void loop();
	void begin();
};

class CDimableLed {
public:
	void setup();
    void loop();
};

extern CLedCmdSignal ledCmdSignal;
extern CIRSignal IRSignal;
extern CWallSwitchSignal WallSwitchSignal;
extern CDimableLed dimableLed;

