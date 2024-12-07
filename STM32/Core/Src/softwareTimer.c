/*
 * timerSetting.c
 *
 *  Created on: Sep 25, 2024
 *      Author: ADMIN
 */
#include "softwareTimer.h"
#define TICK 10

int timerRed_flag = 0;
int timerRed_counter = 0;

int timerGreen_flag = 0;
int timerGreen_counter = 0;

int timerEnable_flag = 0;
int timerEnable_counter = 0;

int oneSecond_flag = 0;
int oneSecond_counter = 0;

int timer1_flag = 0;
int timer1_counter = 0;

int timer1Flag() {
	if (timer1_flag == 1) {
		timer1_flag = 0;
		return 1;
	} else
		return 0;
}

int redFlag() {
	if (timerRed_flag == 1) {
		timerRed_flag = 0;
		return 1;
	} else
		return 0;
}

int greenFlag() {
	if (timerGreen_flag == 1) {
		timerGreen_flag = 0;
		return 1;
	} else
		return 0;
}

int enableFlag() {
	if (timerEnable_flag == 1) {
		timerEnable_flag = 0;
		return 1;
	} else
		return 0;
}

int oneSecondFlag() {
	if (oneSecond_flag == 1) {
		oneSecond_flag = 0;
		return 1;
	} else
		return 0;
}

void setTimerRed() {
	timerRed_counter = durForRed * 100;
//	timerRed_flag = 0;
}

void setTimerGreen() {
	timerGreen_counter = durForGreen * 100;
//	timerGreen_flag = 0;
}

void setTimerEnable() {
	timerEnable_counter = 50;
//	timerEnable_flag = 0;
}

void setOneSecond(int duration) {
	oneSecond_counter = 100;
//	oneSecond_flag = 0;
}

void setTimer1(int duration){
	timer1_flag = duration / TICK;
//	timer1_counter = 0;
}

void timerRun() {
	if (timerRed_counter > 0) {
		timerRed_counter--;
		if (timerRed_counter == 0)
			timerRed_flag = 1;
	}
	if (timerGreen_counter > 0) {
		timerGreen_counter--;
		if (timerGreen_counter == 0)
			timerGreen_flag = 1;
	}
	if (timerEnable_counter > 0) {
		timerEnable_counter--;
		if (timerEnable_counter == 0)
			timerEnable_flag = 1;
	}
	if (oneSecond_counter > 0) {
		oneSecond_counter--;
		if (oneSecond_counter == 0)
			oneSecond_flag = 1;
	}
	if (timer1_counter > 0) {
		timer1_counter--;
		if (timer1_counter == 0)
			timer1_flag = 1;
	}
}







