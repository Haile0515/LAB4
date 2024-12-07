/*
 * fsm_automatic.c
 *
 *  Created on: Oct 26, 2024
 *      Author: ADMIN
 */

#include "global.h"

void fsm_automatic_run(){
	switch(status){
		case INIT:
			number1 = durForGreen; //time count down for red
			number2 = durForRed; //time count down for green
			led_red_and_green(); //R0 - G1
			setTimerRed(); // 5s
			setTimerGreen(); // 3s
			setOneSecond(1000);
			status = LEFTRIGHT;
			break;
		case LEFTRIGHT:
			if (oneSecondFlag() == 1){
				number1--;
				number2--;
				setOneSecond(1000);
			}

			if (greenFlag() == 1){
				HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, SET); //turn on Y1
				HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, RESET);//turn off G1
				number1 = durForRed - durForGreen;
			}

			if (redFlag() == 1){
				number1 = durForRed;
				number2 = durForGreen;
				led_green_and_red(); // R1 - G0
				setTimerRed();
				setTimerGreen();
				setOneSecond(1000);
				status = TOPBOT;
			}

			if (isButtonPressed(MODE)){
				status = RED_MODE;
			}
			break;
		case TOPBOT:
			if (oneSecondFlag() == 1){
				number1--;
				number2--;
				setOneSecond(1000);
			}

			if (greenFlag() == 1){
				HAL_GPIO_WritePin(Y0_GPIO_Port,Y0_Pin, SET); //turn on Y0
				HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, RESET); //turn off G0
				number2 = durForRed - durForGreen;
			}

			if (redFlag() == 1){
				number1 = durForGreen;
				number2 = durForRed;
				led_red_and_green(); //R1 - G0
				setTimerRed();
				setTimerGreen();
				setOneSecond(1000);
				status = LEFTRIGHT;
			}

			if (isButtonPressed(MODE)){
				status = RED_MODE;
			}
			break;
		default:
			break;
	}
}
