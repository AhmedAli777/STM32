/************************************/
/*Author   :  Ahmed Ali             */
/*Date     :  14 AUG 2020           */
/*Version  :  V01                   */
/************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"

#include "SEVSEG_interface.h"
#include "SEVSEG_config.h"

void SEVSEG_voidInit()
{
		for ( u8 i=0 ; i<8 ;i++)
		{
		GPIO_voidSetPinDirection(GPIOA, i, OUTPUT_SPEED_10MHZ_PP);
		}
}

void SEVSEG_voidDisplay(u8 copy_u8Number)
{

    u8 loc_NumArray[]= {0x3F ,0x06,0x5B,0x4F,0x66, 0x6D,0x7D,0x07,0x7F,0x6F};

	#if SEVSEG_TYPE == SEVSEG_COM_CATH
	GPIO_voidSetPortValue ( GPIOA, (loc_NumArray[copy_u8Number]));

	#elif SEVSEG_TYPE == SEVSEG_COM_ANOD
	GPIO_voidSetPortValue ( GPIOA, ~(loc_NumArray[copy_u8Number]));

	#endif
}
