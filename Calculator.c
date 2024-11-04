#include "Std_Type.h"
#include "DIO_Interface.h"
#include "KeyPad_Interface.h"
#include "KeyPad_Cfg.h"
#include "LCD_Interface.h"
#include "Cal_Interface.h"

u8 k,flag=0,acculm=0,counter_flag=0;
Operand_Type flag_op=NO_Operation;
s32 num=0,sum=0,sub=0,mul=0,devion=0,result=0;
void Calc_Runnable(void)
{
	
	k=Keypad_GetKey();
	switch(k)
	{
		case '=':// equal mode
		switch(flag_op)
		{
			case SUM://Summation
			sum+=num;
			result=sum;
			LCD_Goto(1,0);
			LCD_Write_number(sum);
			LCD_Write_string("    ");
			
			break;
			case SUB://Subtraction
			sub-=num;
			result=sub;
			LCD_Goto(1,0);
			LCD_Write_number(sub);
			LCD_Write_string("    ");
			
			break;
			case MUL://Multiplication
			mul*=num;
			result=mul;
			LCD_Goto(1,0);
			LCD_Write_number(mul);
			LCD_Write_string("    ");
			
			break;
			case DEV://Devision
			devion/=num;
			result=devion;
			LCD_Goto(1,0);
			LCD_Write_number(devion);
			LCD_Write_string("    ");
			
			
			break;
		}
		
		flag=0;
		acculm=1;
		flag_op=NO_Operation;
		
		num=0;
		break;
		/******************************************************************/
		case '+'://summation
		if(acculm==1)
		{
			LCD_Clear_Screen();
			LCD_Goto(0,0);
			LCD_Write_number(result);
			sum=result;
			LCD_Write_char(k);
			flag_op=SUM;
			num=0;
			flag=1;
		}
		else
		{
			
			LCD_Write_char(k);
			sum+=num;
			flag_op=SUM;
			num=0;
		}
		
		break;
		case '-':// SUBTRACTION
		if(acculm==1)
		{
			LCD_Clear_Screen();
			LCD_Goto(0,0);
			LCD_Write_number(result);
			sub=result;
			LCD_Write_char(k);
			flag_op=SUB;
			num=0;
			flag=1;
			
		}
		else
		{
			LCD_Write_char(k);
			sub=num;
			flag_op=SUB;
			num=0;
		}
		
		break;
		case '*'://Multiplication
		if(acculm==1)
		{
			LCD_Clear_Screen();
			LCD_Goto(0,0);
			LCD_Write_number(result);
			mul=result;
			LCD_Write_char(k);
			flag_op=MUL;
			num=0;
			flag=1;
		}
		else
		{
			LCD_Write_char(k);
			mul=num;
			flag_op=MUL;
			num=0;
		}
		
		break;
		case '/'://Devision
		if(acculm==1)
		{
			LCD_Clear_Screen();
			LCD_Goto(0,0);
			LCD_Write_number(result);
			devion=result;
			LCD_Write_char(k);
			flag_op=DEV;
			num=0;
			flag=1;
		}
		else
		{
			LCD_Write_char(k);
			devion=num;
			flag_op=DEV;
			num=0;
			
		}
		
		break;
		case 'C':
		
		LCD_Clear_Screen();
		LCD_Goto(0,0);
		num=0;
		sum=0;
		sub=0;
		mul=0;
		devion=0;
		break;
		default:
		
		if(k!=NO_KEY)
		{
			if(flag==0)
			{
				
				sum=0;
				sub=0;
				mul=0;
				devion=0;
				
				
				LCD_Clear_Screen();
				
				flag=1;
			}
			LCD_Write_char(k);
			num=(num*10)+(k-'0');
			acculm=0;
		}
		
		break;
	}
	
}
