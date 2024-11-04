#include "Fire_Interface.h"

u8 flag_fire=0;

void Emergency(void)
{
	u8 i=0,k,num=0,password=123,c=0;
	
	LCD_Writestr_GOTO(0,11,"Fire");
	DIO_WritePin(RED_LED,HIGH);// red led on
	MOTOR_CW(MOTOR);//motor on
	LCD_Goto(1,0);
	LCD_Write_string("Enter Password");
	/**********************************************KeyPad********************/
	k=Keypad_GetKey();
	if(k>='0'&&k<='9')
	{
		c=1;
		num=0;
		num=num*10+(k-'0');
		LCD_Clear_Position(1,0,15);
		LCD_Goto(1,0);
		LCD_Write_char(k);
		i++;
		while(c)
		{
			k=Keypad_GetKey();
			if(k>='0'&&k<='9')
			{
				
				LCD_Goto(1,i);
				LCD_Write_char(k);
				num=num*10+(k-'0');
				i++;
			}
			
			if(k=='=')
			{
				LCD_Goto(1,i);
				LCD_Write_char(k);
				c=0;
			}
			
			
			
		}
	}
	if(k=='=')
	{
		if (num==password)
		{
			DIO_WritePin(RED_LED,LOW);
			MOTOR_STOP(MOTOR);
			LCD_Clear_Position(1,0,15);
			num=0;
			flag_fire=0;
		}
		else
		{
			num=0;
			LCD_Writestr_GOTO(1,0,"Wrong input plz enter again");
			_delay_ms(500);
			LCD_Clear_Position(1,0,15);
		}
	}
	/***************************************************end****************/
}
void Fire_SystemRunnable(void)
{
	u16 temp,smoke;
	LCD_Goto(0,0);
	LCD_Write_string("Temp :");
	temp=LM35_Gettemp();
	LCD_Goto(0,6);
	LCD_Write_number(temp/10);
	LCD_Write_char('.');
	LCD_Write_number(temp%10);
	LCD_Write_string(" ");
	if(temp<400)
	{
		if(flag_fire==1)
		{
			
			Emergency();
		}
		else
		{
			LCD_Clear_Position(0,11,6);
			LCD_Writestr_GOTO(1,5,"Fine");
			MOTOR_STOP(MOTOR);//motor off
			DIO_WritePin(GREEN_LED,LOW);//green led off
		}
	}
	else if(temp>400&&temp<450)
	{
		if(flag_fire==1)
		{
			
			Emergency();
		}
		else
		{
			LCD_Clear_Position(0,11,6);
			LCD_Writestr_GOTO(1,5,"Fine");
			MOTOR_STOP(MOTOR);//motor off
			DIO_WritePin(GREEN_LED,LOW);//green led off
		}
	}
	else if(temp>450)
	{
		if(flag_fire==1)
		{
			Emergency();
		}
		else
		{
			smoke=POTHG_Getpercent();
			LCD_Writestr_GOTO(1,5,"Heat");
			MOTOR_STOP(MOTOR);// motor off
			DIO_WritePin(GREEN_LED,HIGH);//green led on
			LCD_Goto(0,11);
			LCD_Write_number(smoke);
			LCD_Write_char('%');
			LCD_Write_string("  ");
			if(smoke>50)
			{
				flag_fire=1;
				Emergency();
			}
		}
	}
}