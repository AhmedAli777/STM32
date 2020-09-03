/************************************/
/*Author   :  Ahmed Ali             */
/*Date     :  25 AUG 2020           */
/*Version  :  V01                   */
/************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"


/* Define Callback Global Variable */
static void(*STK_CallBack)(void);

/* Define Variable for interval mode */
static u8 STK_u8ModeOfInterval;

void STK_delay(u32 stk_time)
{
	STK->VAL=0X00;
	STK->LOAD= stk_time;
	STK->CTRL= 0X00000001;
	while(STK->VAL);

}


void STK_voidInit()
{
#if STK_CLK_SRC == STK_SRC_AHB
    /* Disable STK - Disable STK Interrupt - Set clock source AHB */
	STK -> CTRL = 0x00000004;
#else
    /* Disable STK - Disable STK Interrupt - Set clock source AHB/8 */
	STK -> CTRL = 0;

#endif
}


void STK_voidSetBusyWait(u32 copy_u32Ticks) /* near delay - Sync. Function */
{
	/* Load ticks to load register */
	STK -> LOAD = copy_u32Ticks;

	/* Start Timer */
	SET_BIT(STK->CTRL, 0);

	/* Wait till flag is raised */
	while( (GET_BIT(STK->CTRL,16)) == 0);

	/* Stop Timer */
	SET_BIT(STK->CTRL, 0);
	STK -> LOAD = 0;
	STK -> VAL  = 0;
}

void STK_voidSetIntervalSingel(u32 copy_u32Ticks, void(*copy_ptr)(void))  /* Async. Function */
{
	/* Load ticks to load register */
	STK -> LOAD = copy_u32Ticks;

	/* Start Timer */
	SET_BIT(STK->CTRL, 0);

	/* Save CallBack */
	STK_CallBack = copy_ptr;

	/* Set Mode to Single */
	STK_u8ModeOfInterval = STK_SINGLE_INTERVAL;

	/* Enable STK Interrupt */
	SET_BIT(STK->CTRL, 1);
}

void STK_voidSetIntervalPeriodic(u32 copy_u32Ticks, void(*copy_ptr)(void))/* Async. Function */
{
	/* Load ticks to load register */
	STK -> LOAD = copy_u32Ticks;

	/* Start Timer */
	SET_BIT(STK->CTRL, 0);

	/* Save CallBack */
	STK_CallBack = copy_ptr;

	/* Set Mode to Single */
	STK_u8ModeOfInterval = STK_PERIOD_INTERVAL;

	/* Enable STK Interrupt */
	SET_BIT(STK->CTRL, 1);
}

void STK_voidStopTimer()
{
	/* Disable STK Interrupt */
	CLR_BIT(STK->CTRL, 1);

	/* Stop Timer */
	CLR_BIT(STK->CTRL, 0);
	STK -> LOAD = 0;
	STK -> VAL  = 0;
}

u32  STK_u32GetElapsedTime()
{
	u32 Local_u32ElapsedTime;

	Local_u32ElapsedTime = STK -> LOAD - STK -> VAL ;

	return Local_u32ElapsedTime;
}

u32  STK_u32GetRemainingTime()
{
	u32 Local_u32RemainTime;

	Local_u32RemainTime = STK -> VAL ;

	return Local_u32RemainTime;
}

void SysTick_Handler(void)
{
	u8 Local_u8Temporary=0;

	if (STK_u8ModeOfInterval == STK_SINGLE_INTERVAL)
	{
		/* Disable STK Interrupt */
		CLR_BIT(STK->CTRL, 1);

		/* Stop Timer */
		SET_BIT(STK->CTRL, 0);
		STK -> LOAD = 0;
		STK -> VAL  = 0;
	}

	/* Callback notification */
	STK_CallBack();

	/* Clear interrupt flag */
	Local_u8Temporary = GET_BIT(STK->CTRL,16);
}

