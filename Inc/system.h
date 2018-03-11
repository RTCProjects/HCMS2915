#ifndef _SYSTEM_H
#define _SYSTEM_H

#include "stm32f4xx_hal.h"

typedef enum
{
	SYS_TIME			 = 0x01,
	SYS_SETTINGS	 = 0x02
}eSystemState;

void System_Init(void);
void System_Process(void);
#endif
