


#ifndef RGB_INTERFACE_H_
#define RGB_INTERFACE_H_
#include "Std_Type.h"
#include "Memory_Map.h"
#include "DIO_Interface.h"
#include "Timers.h"
#include "RBB_Cfg.h"
#define F_CPU   8000000
#include <util/delay.h>
typedef enum
{
	Red=0,
	Green=1,
	Blue=2,
	Orange,
	Pink,
	Cyan,
	Magenta,
	Yellow	,
	Black	,
	White,
	Gray,
	Light_Gray,
	Dark_gray,
	Total_Colors
}Color_type;
extern  u8 const ARRColors[Total_Colors][3];
void RGB_Init(void);
void Choose_Color(Color_type color);
void SHOWROOM_Mode(Color_type color_f,Color_type color_t);

#endif /* RGB_INTERFACE_H_ */