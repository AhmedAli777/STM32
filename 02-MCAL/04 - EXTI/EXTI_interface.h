/************************************/
/*Author   :  Ahmed Ali             */
/*Date     :  22 AUG 2020           */
/*Version  :  V01                   */
/************************************/


#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


void EXTI_voidInit();
void EXTI_voidEnableEXTI  (u8 copy_u8Line);
void EXTI_voidDisableEXTI (u8 copy_u8Line);
void EXTI_voidSwTrigger   (u8 copy_u8Line);
void EXTI_voidSetSignalLatch( u8 copy_u8Line , u8 copy_u8Mode);
void EXTI_voidSetCallBack(void (*ptr) (void));
#endif