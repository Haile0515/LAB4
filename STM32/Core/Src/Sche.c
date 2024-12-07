/*
 * scheduler.c
 *
 *  Created on: Nov 20, 2024
 *      Author: ADMIN
 */

#include "Sche.h"

SCH_Task tasks[SCH_TASKNUMBER];

//hàm khởi tạo
void SCH_Init(void) {
    for (uint8_t i = 0; i < SCH_TASKNUMBER; i ++) {
        tasks[i].pTask = 0;
        tasks[i].id = SCH_TASKNUMBER - i - 1;//taskid theo thứ tự giảm dần
        tasks[i].delay = 0;
        tasks[i].period = 0;
        tasks[i].run_me = 0;
    }
}

void SCH_Update(void) {
    if (tasks[0].pTask == 0) return;
	if (tasks[0].delay > 0) {
		if (tasks[0].delay > SCH_TIMERTICK) {
			tasks[0].delay -= SCH_TIMERTICK;
		}
		else {
			tasks[0].delay = 0;
		}
	}
	if (tasks[0].delay == 0) {
		tasks[0].run_me = 1;
	}
}

void SCH_Dispatch(void) {
	if (tasks[0].pTask == 0 || tasks[0].run_me == 0) return; //check vị trí đầu tiên có trống hay đang thực hiện không
	(*tasks[0].pTask)();
	tasks[0].run_me = 0; //đặt lại run_me khi đã thực hiện xong
	SCH_Task newTask = tasks[0]; //lưu trữ thông tin task[0] vào biến tạm
	SCH_DeleteTask(tasks[0].id); //xóa task
	if (newTask.period > 0) {
		SCH_Add_Task(newTask.pTask, newTask.period, newTask.period); //cập nhật lại nếu cần dùng
		// delay = period
	}
}

uint8_t SCH_Add_Task(void (*pTask)(void), uint32_t delay, uint32_t period) {
    if (tasks[SCH_TASKNUMBER - 1].pTask != 0) return SCH_TASKNUMBER; //check danh sách đầy
    uint8_t currentID = tasks[SCH_TASKNUMBER - 1].id; //lấy id task cuối
    uint32_t currentDelay = 0; //biến tính tổng delay từ task đầu đến hiện tại
    for (uint8_t i = 0; i < SCH_TASKNUMBER; i ++) {
        currentDelay += tasks[i].delay;
        if (currentDelay > delay || tasks[i].pTask == 0) {
            for (uint8_t j = SCH_TASKNUMBER - 1; j > i; j --) {
                tasks[j] = tasks[j - 1];
            }
            tasks[i].pTask = pTask;
            tasks[i].id = currentID;
            tasks[i].period = period;
            tasks[i].run_me = 0;
            if (currentDelay > delay) {
                int newDelay = currentDelay - delay;
                tasks[i].delay = tasks[i + 1].delay - newDelay;
                if (tasks[i].delay == 0) {
                    tasks[i].run_me = 1;
                }
                tasks[i + 1].delay = newDelay;
                if (tasks[i + 1].delay == 0) {
                    tasks[i + 1].run_me = 1;
                }
            }
            else {
                tasks[i].delay = delay - currentDelay;
                if (tasks[i].delay == 0) {
                    tasks[i].run_me = 1;
                }
            }
            return tasks[i].id;
        }
    }
    return SCH_TASKNUMBER;
}

unsigned char SCH_DeleteTask(uint8_t id) {
    for (uint8_t i = 0; i < SCH_TASKNUMBER; i ++) {
        if (tasks[i].id == id) {
            uint8_t currentID = tasks[i].id;
            if (tasks[i + 1].pTask != 0) {
                tasks[i + 1].delay += tasks[i].delay;
            }
            for (uint8_t j = i; j < SCH_TASKNUMBER - 1; j ++) {
                tasks[j] = tasks[j + 1];
            }
            tasks[SCH_TASKNUMBER - 1].pTask = 0;
            tasks[SCH_TASKNUMBER - 1].id = currentID;
            tasks[SCH_TASKNUMBER - 1].delay = 0;
            tasks[SCH_TASKNUMBER - 1].period = 0;
            tasks[SCH_TASKNUMBER - 1].run_me = 0;
            return tasks[SCH_TASKNUMBER - 1].pTask == 0;
        }
    }
    return 0;
}
