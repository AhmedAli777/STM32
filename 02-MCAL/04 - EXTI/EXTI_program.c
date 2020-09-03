/************************************/
/*Author   :  Ahmed Ali             */
/*Date     :  22 AUG 2020           */
/*Version  :  V01                   */
/************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"



static void (*EXTI0_CallBack) (void) = NULL ; /*global var , its type : pointer to function*/


void EXTI_voidInit()
	{
		#if  EXTI_MODE == RISING
		SET_BIT( EXTI->RTSR , EXTI_LINE);
		
		#elif  EXTI_MODE == FALLING
		SET_BIT( EXTI->FTSR , EXTI_LINE);
		
		#elif  EXTI_MODE == ON_CHANG
		SET_BIT( EXTI->RTSR , EXTI_LINE);
		SET_BIT( EXTI->FTSR , EXTI_LINE);
		
		#endif
		
		CLR_BIT( EXTI->IMR , EXTI_LINE); //DISABLE BY DEFAULT 
	}

void EXTI_voidEnableEXTI  (u8 copy_u8Line)
	{
		SET_BIT( EXTI->IMR , copy_u8Line);
	}

void EXTI_voidDisableEXTI (u8 copy_u8Line)
	{
		CLR_BIT( EXTI->IMR , copy_u8Line);
	}

void EXTI_voidSwTrigger   (u8 copy_u8Line) /*SW Interrupt*/
	{
		SET_BIT( EXTI->SWIER , copy_u8Line);
	}
	
void EXTI_voidSetSignlLatch( u8 copy_u8Line , u8 copy_u8Mode) /* Change Mode on Run Time*/
	{
		switch (copy_u8Mode)
		{
		case   RISING:  SET_BIT( EXTI->RTSR , copy_u8Line); break;
		
		case  FALLING:  SET_BIT( EXTI->FTSR , copy_u8Line); break;
		
		case ON_CHANG:  SET_BIT( EXTI->RTSR , copy_u8Line);
						SET_BIT( EXTI->FTSR , copy_u8Line); break;
		}
	
		SET_BIT( EXTI->IMR , copy_u8Line);
	}

void EXTI_voidSetCallBack(void (*ptr) (void))
{
	EXTI0_CallBack = ptr;
}


void EXTI0_IRQHandler (void)
{
		EXTI0_CallBack();
		SET_BIT (EXTI-> PR,0) //Clear Pending Bit.
}