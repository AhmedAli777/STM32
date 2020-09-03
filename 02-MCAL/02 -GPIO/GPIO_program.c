/************************************/
/*Author   :  Ahmed Ali             */
/*Date     :  12 AUG 2020           */
/*Version  :  V01                   */
/************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"




void GPIO_voidSetPinDirection( u8 copy_u8PORT, u8 copy_u8PIN , u8 copy_u8Mode)
	{
			switch (copy_u8PORT)
			{
			case GPIOA :
						if (copy_u8PIN <= 7)
						{
						GPIOA_CRL &=~((0b1111)      << (copy_u8PIN * 4)); //reset GPIO_CRL FOR ANYPIN
						GPIOA_CRL |= ((copy_u8Mode) << (copy_u8PIN * 4)); //write mode  FOR ANYPIN
						}
						else if (copy_u8PIN <= 15)
						{
						copy_u8PIN = copy_u8PIN -8;
                        GPIOA_CRH &=~((0b1111)      << (copy_u8PIN * 4)); //reset GPIO_CRL FOR ANYPIN
						GPIOA_CRH |= ((copy_u8Mode) << (copy_u8PIN * 4)); //write mode  FOR ANYPIN
						}
						break;
						
			case GPIOB :
						if (copy_u8PIN <= 7)
						{
						GPIOB_CRL &=~((0b1111)      << (copy_u8PIN * 4)); //reset GPIO_CRL FOR ANYPIN
						GPIOB_CRL |= ((copy_u8Mode) << (copy_u8PIN * 4)); //write mode  FOR ANYPIN
						}
						else if (copy_u8PIN <= 15)
						{
						copy_u8PIN = copy_u8PIN -8;
                        GPIOB_CRH &=~((0b1111)      << ((copy_u8PIN-8) * 4)); //reset GPIO_CRL FOR ANYPIN
						GPIOB_CRH |= ((copy_u8Mode) << ((copy_u8PIN-8) * 4)); //write mode  FOR ANYPIN
						}
						break;
			case GPIOC : // generic code for all STM " Some STMs has 32 pins on PORTC
						if (copy_u8PIN <= 7)
						{
						GPIOC_CRL &=~((0b1111)      << (copy_u8PIN * 4));//reset GPIO_CRL FOR ANYPIN
						GPIOC_CRL |= ((copy_u8Mode) << (copy_u8PIN * 4)); //write mode  FOR ANYPIN
						}
						else if (copy_u8PIN <= 15)
						{
						copy_u8PIN = copy_u8PIN -8;
                        GPIOC_CRH &=~((0b1111)      << (copy_u8PIN * 4)); //reset GPIO_CRL FOR ANYPIN
						GPIOC_CRH |= ((copy_u8Mode) << (copy_u8PIN * 4)); //write mode  FOR ANYPIN
						}
						break;
			default :break;
			
			}
			
		
	}

void GPIO_voidSetPinValue( u8 copy_u8PORT, u8 copy_u8PIN , u8 copy_u8Value)
	{
	switch (copy_u8PORT)
			{
			case GPIOA :
						if (copy_u8Value == GPIO_HIGH)
						{
							//SET_BIT(GPIOA_ODR ,copy_u8PIN);
							GPIOA_BSR = (1<<copy_u8PIN);
						}
						else if (copy_u8Value == GPIO_LOW)
						{
							//CLR_BIT(GPIOA_ODR ,copy_u8PIN);
							GPIOA_BRR = (1<<copy_u8PIN);
						}
						break;
			case GPIOB :
						if (copy_u8Value == GPIO_HIGH)
						{
							//SET_BIT(GPIOB_ODR ,copy_u8PIN);
							GPIOB_BSR = (1<<copy_u8PIN);
						}
						else if (copy_u8Value == GPIO_LOW)
						{
							//CLR_BIT(GPIOB_ODR ,copy_u8PIN);
							GPIOB_BRR = (1<<copy_u8PIN);
						}
						break;	
			case GPIOC :
						if (copy_u8Value == GPIO_HIGH)
						{
							//SET_BIT(GPIOC_ODR ,copy_u8PIN);
							GPIOC_BSR = (1<<copy_u8PIN);
						}
						else if (copy_u8Value == GPIO_LOW)
						{
							//CLR_BIT(GPIOC_ODR ,copy_u8PIN);
							GPIOC_BRR = (1<<copy_u8PIN);
						}
						break;							
			
			default :break;
			}
			
	
	}

void GPIO_voidSetPortValue( u8 copy_u8PORT , u16 copy_u16Value)
	{
	switch (copy_u8PORT)
			{
			case GPIOA :
						GPIOA_ODR = copy_u16Value;
						break;
			case GPIOB :
						GPIOB_ODR =copy_u16Value;
						break;
			case GPIOC :
						GPIOC_ODR =copy_u16Value;
						break;
			default :break;
			}


	}

u8 GPIO_u8GetPinValue( u8 copy_u8PORT, u8 copy_u8PIN)
	{
	u8 LOC_u8Result=0;
	
		switch (copy_u8PORT)
			{
			case GPIOA :
						LOC_u8Result = GET_BIT(GPIOA_IDR, copy_u8PIN);
						break;
			case GPIOB :
						LOC_u8Result = GET_BIT(GPIOB_IDR, copy_u8PIN);
						break;	
			case GPIOC :
						LOC_u8Result = GET_BIT(GPIOC_IDR, copy_u8PIN);
						break;							
			default :break;
			}
			
	
	return LOC_u8Result;
	}
	
