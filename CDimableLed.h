/*
 * CDimableLed.h
 *
 *  Created on: Dec 6, 2017
 *      Author: ominenko
 */

#ifndef CDIMABLELED_H_
#define CDIMABLELED_H_
#include <Arduino.h>
#include "CFilter.h"
#include "IRremoteESP8266_nec.h"
enum{
	CMD_LED_OFF=0,
	CMD_LED_NIGHT,
	CMD_LED_NIGHT_HIGHT,
	CMD_LED_HIGHT,
	CMD_LED_SWICH_STATE
};

const int GPIO_POUT_LED 	    =D1;
const int GPIO_PIN_WALL_SWITCH 	=D2;
const int GPIO_PIN_IRsensor     =D3;

const int LED_OFF         =0;
const int LED_NIGHT       =1;
const int LED_NIGHT_HIGHT =(PWMRANGE/4);
const int LED_HIGHT       =PWMRANGE;

class CDimableLed {
public:
	void setup();
	virtual ~CDimableLed(){};
};

#endif /* CDIMABLELED_H_ */
