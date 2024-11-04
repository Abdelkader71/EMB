#ifndef FIRE_INTERFACE_H_
#define FIRE_INTERFACE_H_

#include "Std_Type.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "Motor_Cfg.h"
#include "Motor_Interface.h"
#include "ADC_interface.h"
#include "Sensors_Cfg.h"
#include "Sensors_interface.h"
#define F_CPU   8000000
#include <util/delay.h>



#define RED_LED    PINC5
#define GREEN_LED  PINC4
#define MOTOR      M2

void Emergency(void);
void Fire_SystemRunnable(void);


#endif /* FIRE_INTERFACE_H_ */