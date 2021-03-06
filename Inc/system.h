#ifndef _SYSTEM_H
#define _SYSTEM_H

#include "stm32f4xx_hal.h"

#define SLEEP_VALUE 100000
#define LO_PRESS_TIME	10
#define HI_PRESS_TIME 200

typedef enum
{
	SYS_TIME			 = 0x01,
	SYS_DATE	 		 = 0x02,
	SYS_SETTINGS	 = 0x03,
	SYS_SET_HOUR	= 0x04,
	SYS_SET_MIN = 0x05,
	SYS_SET_SEC = 0x06,
	SYS_SET_DAY = 0x07,
	SYS_SET_MONTH = 0x08,
	SYS_SET_YEAR = 0x09
}eSystemState;

typedef enum
{
	SELECT_DEFAULT		= 0x00,
	SELECT_BRIGHT		= 0x01,
	SELECT_TIME		  = 0x02,
	SELECT_DATE			= 0x03,
	SELECT_EXIT 		= 0x04

}eSettingsState;

#define FIRST_SETTING SELECT_BRIGHT
#define LAST_SETTING 	SELECT_EXIT


void System_Init(void);
void System_Process(void);
void System_SetState(eSystemState State);
void System_SetSettingsState(eSettingsState State);

RTC_TimeTypeDef *System_GetRTCTime(void);
RTC_DateTypeDef *System_GetRTCDate(void);

eSystemState	System_GetState(void);
eSettingsState	System_GetSettingsState(void);

#endif
