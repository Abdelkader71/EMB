#include "Temp_FilterInterface.h"
u16 TEMPARR[10]={0};
static u16 Reading=0;
static u16 Filtered_Reading;
static u8 Current_Reading=0;
	
void Temp_Filter_Init(void)
{
	u8 i;
	u16 temp=LM35_Gettemp();
	for (i=0;i<10;i++)
	{
		TEMPARR[i]=temp;
	}
}

void Temp_Filter_Runnable(void)
{
	u8 i;
	Reading=0;
	if(Current_Reading==10)
	{
		Current_Reading=0;
	}
	TEMPARR[Current_Reading]=LM35_Gettemp();
	Current_Reading++;
	for (i=0;i<10;i++)
	{
		Reading+=TEMPARR[i];
	}
	
	Filtered_Reading=Reading/10;
	
}
u16 Get_FilteredTemp(void)
{
	
	return Filtered_Reading;
}
u16 Get_UnfilteredTemp(void)
{
	
	return TEMPARR[Current_Reading-1];
}