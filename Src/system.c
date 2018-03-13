#include "system.h"
#include "graphic.h"

RTC_HandleTypeDef hrtc;

static eSystemState			eCurrentSysState;
static eSettingsState		eCurrentSettingsState;
static RTC_TimeTypeDef	rtcTime;
static RTC_DateTypeDef	rtcDate;

uint8_t		btnPressCnt;
uint32_t	sleepCounter;

void	System_GetDateTimeFromRTC(void);

void System_Init()
{
	//RTC Init
	hrtc.Instance = RTC;
  hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
  hrtc.Init.AsynchPrediv = 127;
  hrtc.Init.SynchPrediv = 255;
  hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
  hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
  hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
  if (HAL_RTC_Init(&hrtc) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }
	
	eCurrentSysState = SYS_TIME;
	eCurrentSettingsState = SET_DEFAULT;
	
	sleepCounter = 0;
	btnPressCnt = 0;
}

void System_Process()
{
	GPIO_PinState pinState = HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13);
	
	if(pinState == GPIO_PIN_RESET)//нажата кнопка
	{
		switch(eCurrentSysState)
		{
			case SYS_TIME:
			{
				if(btnPressCnt > 100)
					System_SetState(SYS_SETTINGS);					
			}break;
			
			case SYS_DATE:
			{
				
			}break;
			
			case SYS_SETTINGS:
			{
				Graphic_ResetSettingsScroll();
			}break;
		}
		

			
		
		btnPressCnt++;
	}

	
	  sleepCounter++;
	
		//if(sleepCounter > SLEEP_VALUE)
			//HAL_PWR_EnterSTANDBYMode();
			//HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);
}

void	System_GetDateTimeFromRTC()
{
	HAL_RTC_GetTime(&hrtc,&rtcTime,RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc,&rtcDate, RTC_FORMAT_BIN);
}

RTC_TimeTypeDef System_GetRTCTime()
{
	System_GetDateTimeFromRTC();
	
	return rtcTime;
}

RTC_DateTypeDef System_GetRTCDate()
{
	System_GetDateTimeFromRTC();
	
	return rtcDate;	
}

void System_SetState(eSystemState State)
{
	eCurrentSysState = State;
}
eSystemState	System_GetState(void){return eCurrentSysState;}

void System_SetSettingsState(eSettingsState State)
{
	eCurrentSettingsState = State;
}
eSettingsState	System_GetSettingsState(void){return eCurrentSettingsState;}
