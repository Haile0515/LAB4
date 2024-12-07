/*
 * global.h
 *
 *  Created on: Oct 26, 2024
 *      Author: ADMIN
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "softwareTimer.h"
#include "fsm_automatic.h"
#include "fsm_manual.h"
#include "fsm_setting.h"
#include "led7_segment.h"
#include "button.h"
#include "traffic_light.h"
//#include "Sche.h"

#define INIT		1
#define LEFTRIGHT	2
#define TOPBOT		3

#define RED_MODE	12
#define YELLOW_MODE 13
#define GREEN_MODE  14

extern int timerRed_flag;
extern int timerGreen_flag;
extern int timerEnable_flag;
extern int oneSecond_flag;

extern int status;
extern int stateSeg;

extern int durForRed;
extern int durForGreen;

extern int number1;
extern int number2;

extern int button_flag[4];

#endif /* INC_GLOBAL_H_ */
