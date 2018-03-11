#include "system.h"

uint32_t	sleepCounter;

void System_Init()
{
	  sleepCounter = 0;
}

void System_Process()
{
	  sleepCounter++;
	
		//if(sleepCounter > SLEEP_VALUE)
			//HAL_PWR_EnterSTANDBYMode();
			//HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);
}
