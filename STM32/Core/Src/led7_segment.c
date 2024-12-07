/*
 * led7_segment.c
 *
 *  Created on: Oct 26, 2024
 *      Author: ADMIN
 */

#include "led7_segment.h"

void cleaeAll7SEG() {
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_All, RESET);
}

static uint8_t LED7_SEG[10] = { 0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8,
		0x80, 0x90 };

void turnSeg0(int num) {
	HAL_GPIO_WritePin(GPIOA, SEG0_Pin, ((LED7_SEG[num] >> 0) & 0x01));
	HAL_GPIO_WritePin(GPIOA, SEG1_Pin, ((LED7_SEG[num] >> 1) & 0x01));
	HAL_GPIO_WritePin(GPIOA, SEG2_Pin, ((LED7_SEG[num] >> 2) & 0x01));
	HAL_GPIO_WritePin(GPIOA, SEG3_Pin, ((LED7_SEG[num] >> 3) & 0x01));
	HAL_GPIO_WritePin(GPIOA, SEG4_Pin, ((LED7_SEG[num] >> 4) & 0x01));
	HAL_GPIO_WritePin(GPIOA, SEG5_Pin, ((LED7_SEG[num] >> 5) & 0x01));
	HAL_GPIO_WritePin(GPIOA, SEG6_Pin, ((LED7_SEG[num] >> 6) & 0x01));
}

void turnSeg1(int num) {
	HAL_GPIO_WritePin(GPIOA, SEG7_Pin, ((LED7_SEG[num] >> 0) & 0x01));
	HAL_GPIO_WritePin(GPIOA, SEG8_Pin, ((LED7_SEG[num] >> 1) & 0x01));
	HAL_GPIO_WritePin(GPIOA, SEG9_Pin, ((LED7_SEG[num] >> 2) & 0x01));
	HAL_GPIO_WritePin(GPIOA, SEG10_Pin, ((LED7_SEG[num] >> 3) & 0x01));
	HAL_GPIO_WritePin(GPIOA, SEG11_Pin, ((LED7_SEG[num] >> 4) & 0x01));
	HAL_GPIO_WritePin(GPIOA, SEG12_Pin, ((LED7_SEG[num] >> 5) & 0x01));
	HAL_GPIO_WritePin(GPIOA, SEG13_Pin, ((LED7_SEG[num] >> 6) & 0x01));
}

void enableSeg(int num1, int num2) {
	switch (stateSeg) {
	case 0:
		cleaeAll7SEG();
//		turnSeg0(num1 / 10);
//		turnSeg1(num2 / 10);
//		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
		stateSeg = 1;
		setTimerEnable();
		break;
	case 1: //hang chuc
		turnSeg0(num1 / 10);
		turnSeg1(num2 / 10);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
		if (enableFlag() == 1) {
			stateSeg = 2;
			setTimerEnable();
		}
		break;
	case 2: //hang don vi
		turnSeg0(num1 % 10);
		turnSeg1(num2 % 10);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
		if (enableFlag() == 1) {
			stateSeg = 1;
			setTimerEnable();
		}
		break;
	default:
		break;
	}
}

