/*
 * traffic_light.c
 *
 *  Created on: Oct 26, 2024
 *      Author: ADMIN
 */

#include "traffic_light.h"
#include "main.h"

void led_red_and_green(){
	//TODO
	HAL_GPIO_WritePin(R0_GPIO_Port, R0_Pin, SET);
	HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, SET);
	HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, RESET);
	HAL_GPIO_WritePin(Y0_GPIO_Port, Y0_Pin, RESET);
	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, RESET);
	HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, RESET);
}

void led_red_and_yellow(){
	//TODO
	HAL_GPIO_WritePin(R0_GPIO_Port, R0_Pin, SET);
	HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, RESET);
	HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, RESET);
	HAL_GPIO_WritePin(Y0_GPIO_Port, Y0_Pin, RESET);
	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, RESET);
	HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, SET);
}

void led_green_and_red(){
	//TODO
	HAL_GPIO_WritePin(R0_GPIO_Port, R0_Pin, RESET);
	HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, RESET);
	HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, SET);
	HAL_GPIO_WritePin(Y0_GPIO_Port, Y0_Pin, RESET);
	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, SET);
	HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, RESET);
}

void led_yellow_and_red(){
	//TODO
	HAL_GPIO_WritePin(R0_GPIO_Port, R0_Pin, RESET);
	HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, RESET);
	HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, RESET);
	HAL_GPIO_WritePin(Y0_GPIO_Port, Y0_Pin, SET);
	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, SET);
	HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, RESET);
}

void led_red(){
	HAL_GPIO_TogglePin(R0_GPIO_Port, R0_Pin);
	HAL_GPIO_TogglePin(R1_GPIO_Port, R1_Pin);
	HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, RESET);
	HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, RESET);
	HAL_GPIO_WritePin(Y0_GPIO_Port, Y0_Pin, RESET);
	HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, RESET);
}

void led_green(){
	HAL_GPIO_TogglePin(G0_GPIO_Port, G0_Pin);
	HAL_GPIO_TogglePin(G1_GPIO_Port, G1_Pin);
	HAL_GPIO_WritePin(R0_GPIO_Port, R0_Pin, RESET);
	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, RESET);
	HAL_GPIO_WritePin(Y0_GPIO_Port, Y0_Pin, RESET);
	HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, RESET);
}

void led_yellow(){
	HAL_GPIO_TogglePin(Y0_GPIO_Port, Y0_Pin);
	HAL_GPIO_TogglePin(Y1_GPIO_Port, Y1_Pin);
	HAL_GPIO_WritePin(R0_GPIO_Port, R0_Pin, RESET);
	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, RESET);
	HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, RESET);
	HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, RESET);
}





