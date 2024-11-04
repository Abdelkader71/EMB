

#ifndef TEMP_FILTERINTERFACE_H_
#define TEMP_FILTERINTERFACE_H_
#include "Std_Type.h"
#include "LCD_Interface.h"
#include "ADC_interface.h"
#include "Sensors_Cfg.h"
#include "Sensors_interface.h"

void Temp_Filter_Init(void);
void Temp_Filter_Runnable(void);
u16 Get_FilteredTemp(void);
u16 Get_UnfilteredTemp(void);



#endif /* TEMP_FILTERINTERFACE_H_ */