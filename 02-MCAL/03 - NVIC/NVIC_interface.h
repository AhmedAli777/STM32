/************************************/
/*Author   :  Ahmed Ali             */
/*Date     :  19 AUG 2020           */
/*Version  :  V01                   */
/************************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H




void NVIC_voidEnableInterrupt ( u8 Copy_u8IntNumber );
void NVIC_voidDisableInterrupt( u8 Copy_u8IntNumber );
void NVIC_voidSetPendingFlag  ( u8 Copy_u8IntNumber );
void NVIC_voidClearPendingFlag( u8 Copy_u8IntNumber );
u8   NVIC_u8GetActiveFlage    ( u8 Copy_u8IntNumber );

#endif 

