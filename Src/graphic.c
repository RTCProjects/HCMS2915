#include "graphic.h"
#include "system.h"
#include "hcms2915.h"

const char	*strSettingsText = "Настройки";
const char	*strBrightText	 = "Ярк:";
const char  *strBrightText2	 = "Текст 2";
const char  *strBrightText3	 = "Текст 3";


uint32_t	uSettingScrollCnt;

void Graphic_Init()
{
	uSettingScrollCnt = 0;
}

void Graphic_Process()
{
	char strOutBuf[8];
	
	HCMS_Clear();
	
	switch(System_GetState())
	{
		case SYS_TIME:
		{
			RTC_TimeTypeDef	currentTime = System_GetRTCTime();
			
			sprintf(strOutBuf, "%02d:%02d:%02d", currentTime.Hours,currentTime.Minutes,currentTime.Seconds);
			HCMS_PutStr(strOutBuf);
		}break;
		
		case SYS_DATE:
		{
			RTC_DateTypeDef	currentDate = System_GetRTCDate();
			
			sprintf(strOutBuf, "%02d/%02d/%02d", currentDate.Date,currentDate.Month,currentDate.Year);
			HCMS_PutStr(strOutBuf);
		}break;
		
		case SYS_SETTINGS:
		{	
			uSettingScrollCnt++;
			
			if(uSettingScrollCnt < 100)
				HCMS_PutStr((char*)strSettingsText);
			else if(uSettingScrollCnt >=100 && uSettingScrollCnt < 200)
				HCMS_PutStr((char*)strBrightText);
			else if(uSettingScrollCnt >= 200 && uSettingScrollCnt < 300)
				HCMS_PutStr((char*)strBrightText2);
			else if(uSettingScrollCnt >= 300 && uSettingScrollCnt < 400)
				HCMS_PutStr((char*)strBrightText3);
			else
				uSettingScrollCnt = 0;
		}break;
	}
}
void	Graphic_ResetSettingsScroll()
{
	uSettingScrollCnt = 0;
}
