/*
 * button.h
 *
 *  Created on: Oct 26, 2024
 *      Author: ADMIN
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "global.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET

#define MODE 		0
#define INC			1
#define DEC			2
#define APPLY		3

void subkeyProcess(int index);
int isButtonPressed(int index);
void getKeyInput();

#endif /* INC_BUTTON_H_ */
