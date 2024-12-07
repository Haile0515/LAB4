/*
 * fsm_manual.c
 *
 *  Created on: Oct 26, 2024
 *      Author: ADMIN
 */
#include "global.h"

void fsm_manual_run(){
	switch(status){
		case RED_MODE:
			number1 = 2;
			number2 = durForRed;
			led_red();
			if (isButtonPressed(MODE) == 1){
				status = GREEN_MODE;
			} else if (isButtonPressed(INC) == 1){
				durForRed++;
				durForGreen++;
			} else if (isButtonPressed(DEC) == 1){
				if (durForRed > 2) {
					durForRed--;
				}
			} else if (isButtonPressed(APPLY) == 1){
				status = INIT;
			}
			break;
		case GREEN_MODE:
			number1 = 3;
			number2 = durForGreen;
			led_green();
			if (isButtonPressed(MODE) == 1){
				status = YELLOW_MODE;
			} else if (isButtonPressed(INC) == 1){
				durForRed++;
				durForGreen++;
			} else if (isButtonPressed(DEC) == 1){
				if (durForGreen > 1)
					durForGreen--;
			} else if (isButtonPressed(APPLY) == 1){
				status = INIT;
			}
			break;
		case YELLOW_MODE:
			number1 = 4;
			number2 = durForRed - durForGreen;
			led_yellow();
			if (isButtonPressed(MODE) == 1){
				status = INIT;
				durForGreen = 3;
				durForRed = 5;
			} else if (isButtonPressed(INC) == 1){
				durForGreen++;
				durForRed++;
			} else if (isButtonPressed(DEC) == 1){
				if ((durForRed - durForGreen) > 1) {
					durForRed--;
				}
			} else if (isButtonPressed(APPLY) == 1){
				status = INIT;
			}
			break;
		default:
			break;
	}
}
