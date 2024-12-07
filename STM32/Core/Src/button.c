/*
 * button.c
 *
 *  Created on: Oct 26, 2024
 *      Author: ADMIN
 */

#include "button.h"

int keyReg0[4] = { NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE };
int keyReg1[4] = { NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE };
int keyReg2[4] = { NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE };
int keyReg3[4] = { NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE };
int button_flag[4] = { 0, 0, 0, 0 };
int TimeOutForKeyPress[4] = { 500, 500, 500, 500 };

int isButtonPressed(int index) {
	if (button_flag[index] == 1) {
		button_flag[0] = 0;
		button_flag[1] = 0;
		button_flag[2] = 0;
		button_flag[3] = 0;
		return 1;
	} else
		return 0;
}

int isButtonLongPressed(int index) {
	if (button_flag[index] == 1) {
		button_flag[0] = 0;
		button_flag[1] = 0;
		button_flag[2] = 0;
		button_flag[3] = 0;
		return 1;
	} else
		return 0;
}

void subKeyProcess(int index) {
	button_flag[index] = 1;
}

void getKeyInput() {
	for (int i = 0; i < 4; i++) {
		keyReg2[i] = keyReg1[i];
		keyReg1[i] = keyReg0[i];
		switch (i) {
		case MODE:
			keyReg0[i] = HAL_GPIO_ReadPin(but1_GPIO_Port, but1_Pin);
			break;
		case INC:
			keyReg0[i] = HAL_GPIO_ReadPin(but2_GPIO_Port, but2_Pin);
			break;
		case DEC:
			keyReg0[i] = HAL_GPIO_ReadPin(but3_GPIO_Port, but3_Pin);
			break;
		case APPLY:
			keyReg0[i] = HAL_GPIO_ReadPin(but4_GPIO_Port, but4_Pin);
			break;
		default:
			break;
		}

		if ((keyReg1[i] == keyReg0[i]) && (keyReg1[i] == keyReg2[i])) {
			if (keyReg2[i] != keyReg3[i]) {
				keyReg3[i] = keyReg2[i];
				if (keyReg3[i] == PRESSED_STATE) {
					subKeyProcess(i);
					TimeOutForKeyPress[i] = 500;
					button_flag[i] = 1;
				}
			} else {
				TimeOutForKeyPress[i]--;
				if (TimeOutForKeyPress[i] == 0) {
					TimeOutForKeyPress[i] = 500;
					if (keyReg3[i] == PRESSED_STATE){
						subKeyProcess(i);
						button_flag[i] = 1;
					}
				}
			}
		}
	}
}
