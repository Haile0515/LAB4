/*
 * timerSetting.h
 *
 *  Created on: Sep 25, 2024
 *      Author: ADMIN
 */
#include "global.h"

#ifndef INC_SOFTWARETIMER_H_
#define INC_SOFTWARETIMER_H_

int timer1Flag();

int redFlag();

int greenFlag();

int enableFlag();

int oneSecondFlag();

void setTimerGreen();

void setTimerRed();

void setTimerEnable();

void setOneSecond(int duration);

void setTimer1(int duration);

void timerRun();

#endif /* INC_SOFTWARETIMER_H_ */
