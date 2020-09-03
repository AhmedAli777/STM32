/************************************/
/*Author   :  Ahmed Ali             */
/*Date     :  19 AUG 2020           */
/*Version  :  V01                   */
/************************************/

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

/* NVIC Base Address 0xE000E100 */

#define NVIC_ISER0 *((u32*)(0xE000E100)) /*enable external interrupts from 0  to 31 */
#define NVIC_ISER1 *((u32*)(0xE000E104)) /*enable external interrupts from 32 to 59 */

#define NVIC_ICER0 *((u32*)(0xE000E180)) /*disable external interrupts from 0  to 31 */
#define NVIC_ICER1 *((u32*)(0xE000E184)) /*disable external interrupts from 32  to 59 */



#define NVIC_ISPR0 *((u32*)(0xE000E200))
#define NVIC_ISPR1 *((u32*)(0xE000E204))

#define NVIC_ICPR0 *((u32*)(0xE000E280))
#define NVIC_ICPR1 *((u32*)(0xE000E284))

#define NVIC_IABR0 *((volatile u32*)(0xE000E300))
#define NVIC_IABR1 *((volatile u32*)(0xE000E304))

#endif 
