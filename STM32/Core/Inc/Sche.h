/*
 * scheduler.h
 *
 *  Created on: Nov 20, 2024
 *      Author: ADMIN
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>
#include <stdio.h>
#define SCH_TASKNUMBER 8
#define SCH_TIMERTICK 10

typedef struct {
    void (*pTask)(void);
    uint8_t id;
    uint32_t delay;
    uint32_t period;
    unsigned char run_me;
} SCH_Task;

void SCH_Init(void);
void SCH_Update(void);
void SCH_Dispatch(void);

uint8_t SCH_Add_Task(void (*pTask)(void), uint32_t delay, uint32_t period);
unsigned char SCH_DeleteTask(uint8_t id);

#endif /* INC_SCHEDULER_H_ */
