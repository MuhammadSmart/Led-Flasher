/*
 * Modules.c
 *
 * Created: 6/20/2022 1:59:44 PM
 *  Author: Smart
 */ 
#include "Modules.h"


/*void GPS_Init()
{
	if(stringReceived == 1)
	{
		cli();
		for(int i=0;i<ind;i++)
		serialwrite(buf[i]);
		ind=0;
		stringReceived=0;
	}
}

u8* GPS_GetLatitude()
{
for(int i=18;i<27;i++)
{							//[NMEA] $GPGGA,230854.041,5404.2675,N,00159.7569,W,1,10,4.00,100.0,M,50.0,M,,*71 [GPS1]

	latitude[i]=buf[i];
	//LCD_WriteChar(latitude[i]);
	serialwrite(latitude[i]);
	if(i==27)
	{
		latitude[i]=',';
		i++;
		latitude[i]='N';
	}
}
latitude[i]=0; //to make it a string

return latitude;
}


char* GPS_GetLogitude()
{
	for(int i=30;i<41;i++)
	{
		logitude[i]=buf[i];
		//LCD_WriteChar(logitude[i]);
		serialwrite(logitude[i]);
		if(i==40)
		{
			logitude[i]=',';
			i++;
			logitude[i]='W';
		}
	}
	logitude[i]=0;
	return logitude;
}

*/