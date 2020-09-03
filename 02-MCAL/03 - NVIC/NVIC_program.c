/************************************/
/*Author   :  Ahmed Ali             */
/*Date     :  19 AUG 2020           */
/*Version  :  V01                   */
/************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"



void NVIC_voidEnableInterrupt(u8 Copy_u8IntNumber)
	{

		if (Copy_u8IntNumber  <=31)
			{  
				NVIC_ISER0 = (1<<Copy_u8IntNumber);
			}
		else if (Copy_u8IntNumber  <=59)
			{
				Copy_u8IntNumber -= 32;
				NVIC_ISER1 = (1<<Copy_u8IntNumber);
			}
		else
			{
				/*return error*/
			}
	}
	
	
void NVIC_voidDisableInterrupt(u8 Copy_u8IntNumber)
	{

		if (Copy_u8IntNumber  <=31)
			{  
				NVIC_ICER0 = (1<<Copy_u8IntNumber);
			}
		else if (Copy_u8IntNumber  <=59)
			{
				Copy_u8IntNumber -= 32;
				NVIC_ICER1 = (1<<Copy_u8IntNumber);
			}
		else
			{
				/*return error*/
			}
	}


void NVIC_voidSetPendingFlag (u8 Copy_u8IntNumber)
	{

		if (Copy_u8IntNumber  <=31)
			{  
				NVIC_ISPR0 = (1<<Copy_u8IntNumber);
			}
		else if (Copy_u8IntNumber  <=59)
			{
				Copy_u8IntNumber -= 32;
				NVIC_ISPR1 = (1<<Copy_u8IntNumber);
			}
		else
			{
				/*return error*/
			}
	}


void NVIC_voidClearPendingFlag (u8 Copy_u8IntNumber)
	{

		if (Copy_u8IntNumber  <=31)
			{  
				NVIC_ICPR0 = (1<<Copy_u8IntNumber);
			}
		else if (Copy_u8IntNumber  <=59)
			{
				Copy_u8IntNumber -= 32;
				NVIC_ICPR1 = (1<<Copy_u8IntNumber);
			}
		else
			{
				/*return error*/
			}
	}

u8 NVIC_u8GetActiveFlage(u8 Copy_u8IntNumber)
	{
		u8 Loc_u8Result;
		
		if (Copy_u8IntNumber  <=31)
			{  
				Loc_u8Result = GET_BIT(NVIC_IABR0,Copy_u8IntNumber);
			}
		else if (Copy_u8IntNumber  <=59)
			{
				Copy_u8IntNumber -= 32;
				Loc_u8Result = GET_BIT(NVIC_IABR1,Copy_u8IntNumber);
			}
		else
			{
				/*return error*/
			}
			
	return  Loc_u8Result;
	}
