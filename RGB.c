
#include "RGB_Interface.h"


void RGB_Init(void)
{
	TIMER0_Init(TIMER0_FASTPWM_MODE,TIMER0_SCALER_8);
	TIMER0_OC0Mode(OC0_NON_INVERTING);
	Timer1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1_SCALER_8);
	ICR1=255;
	Timer1_OCRA1Mode(OCRA_NON_INVERTING);
	Timer1_OCRB1Mode(OCRB_NON_INVERTING);
	
}
void Choose_Color(Color_type color)
{
	TCNT1=0;
	TCNT0=0;
	OCR0=ARRColors[color][RE];
	OCR1A=ARRColors[color][GR];
	OCR1B=ARRColors[color][BL];
}
void SHOWROOM_Mode(Color_type color_f,Color_type color_t)
{
	u8 i=0,flag0=0,flag1=0,flag2=0;
	u16 c=0;
	u8 x0=ARRColors[color_f][RE] ,y0=ARRColors[color_t][RE] ,x1=ARRColors[color_f][GR] ;
	u8 y1=ARRColors[color_t][GR] ,x2=ARRColors[color_f][BL] ,y2=ARRColors[color_t][BL] ;
	for(i=0;i<255;i++)
	{
		if((x0<y0)&&(flag0<=1))
		{
			c++;
			x0++;
			
			OCR0=x0;
			flag0=1;
		}
		else if((ARRColors[color_f][RE]>ARRColors[color_t][RE])&&(flag0==0||flag0==2))
		{
			c++;
			x0--;
			
			OCR0=x0;
			flag0=2;
		}
		if((x1<y1)&&(flag1<=1))
		{
			c++;
			x1++;
			
			OCR1A=x1;
			flag1=1;
		}
		else if((x1>y1)&&(flag1==0||flag1==2))
		{
			c++;
			x1--;
			
			OCR1A=x1;
			flag1=2;
		}
		if((x2<y2)&&(flag2<=1))
		{
			c++;
			x2++;
			
			OCR1B=x2;
			flag2=1;
		}
		else if((x2>y2)&&(flag2==0||flag2==2))
		{
			c++;
			x2--;
			
			OCR1B=x2;
			flag2=2;
		}
		if(c==0)
		{
			break;
		}
		_delay_ms(5);
	}
}