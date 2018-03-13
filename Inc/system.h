#ifndef _SYSTEM_H
#define _SYSTEM_H

#include "stm32f4xx_hal.h"

#define SLEEP_VALUE 100000

typedef enum
{
	SYS_TIME			 = 0x01,
	SYS_DATE	 		 = 0x02,
	SYS_SETTINGS	 = 0x03
}eSystemState;

typedef enum
{
	SET_DEFAULT,
	SET_BRIGHT,
	SET_TIME,
	SET_DATE
}eSettingsState;

void System_Init(void);
void System_Process(void);
void System_SetState(eSystemState State);
void System_SetSettingsState(eSettingsState State);

RTC_TimeTypeDef System_GetRTCTime(void);
RTC_DateTypeDef System_GetRTCDate(void);

eSystemState	System_GetState(void);
eSettingsState	System_GetSettingsState(void);

#endif
