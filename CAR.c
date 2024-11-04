#include "Std_Type.h"
#include "Utils.h"
#include "Motor_Interface.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "CAR_Interface.h"
#include "CAR_Private.h"


static void CAR_Forward(void)
{
	MOTOR_CW(M1);
	MOTOR_CW(M2);
	MOTOR_CW(M3);
	MOTOR_CW(M4);
	
}
static void CAR_Backward(void)
{
	MOTOR_CCW(M1);
	MOTOR_CCW(M2);
	MOTOR_CCW(M3);
	MOTOR_CCW(M4);
	
}
static void CAR_Right(void)
{
	MOTOR_CW(M1);
	MOTOR_CW(M2);
	MOTOR_CCW(M3);
	MOTOR_CCW(M4);
	
}
static void CAR_Left(void)
{
	MOTOR_CCW(M1);
	MOTOR_CCW(M2);
	MOTOR_CW(M3);
	MOTOR_CW(M4);
	
}
static void CAR_STOP(void)
{
	MOTOR_STOP(M1);
	MOTOR_STOP(M2);
	MOTOR_STOP(M3);
	MOTOR_STOP(M4);
	
}



void CAR_Init(void)
{
	CAR_STOP();
	
}
void CAR_MOVEMENT(void)
{
	if(DIO_ReadPin(FB)==LOW)// forward mode
	{
		CAR_Forward();
		while(DIO_ReadPin(FB)==LOW);
		LCD_Goto(0,0);
		LCD_Write_string("forward mode");
		LCD_Write_string("       ");
	}
	if(DIO_ReadPin(BB)==LOW)// Backward Mode
	{
		CAR_Backward();
		while(DIO_ReadPin(BB)==LOW);
		LCD_Goto(0,0);
		LCD_Write_string("Backward Mode");
		LCD_Write_string("       ");
	}
	if(DIO_ReadPin(RB)==LOW)// turn Right Mode
	{
		while(DIO_ReadPin(RB)==LOW)
		{
			CAR_Right();
			LCD_Goto(0,0);
			LCD_Write_string("turn Right Mode");
			LCD_Write_string("       ");
		}
		LCD_Goto(0,0);
		LCD_Write_string("                    ");
		CAR_STOP();
		
	}
	if(DIO_ReadPin(LB)==LOW)// Turn Left Mode
	{
		while(DIO_ReadPin(LB)==LOW)
		{
			CAR_Left();
			LCD_Goto(0,0);
			LCD_Write_string("Turn Left Mode");
			LCD_Write_string("       ");
		}
		LCD_Goto(0,0);
		LCD_Write_string("                   ");
		CAR_STOP();
	}
	
}

