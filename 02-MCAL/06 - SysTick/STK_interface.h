/************************************/
/*Author   :  Ahmed Ali             */
/*Date     :  25 AUG 2020           */
/*Version  :  V01                   */
/************************************/

#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

void STK_delay(u32 stk_time);


void STK_voidInit();

void STK_voidSetBusyWait(u32 copy_u32Ticks); /* near delay - Sync. Function */

void STK_voidSetIntervalSingel(u32 copy_u32Ticks, void(*copy_ptr)(void));    /* Async. Function */

void STK_voidSetIntervalPeriodic(u32 copy_u32Ticks, void(*copy_ptr)(void));  /* Async. Function */

void STK_voidStopTimer();

u32  STK_u32GetElapsedTime();

u32  STK_u32GetRemainingTime();

#endif
