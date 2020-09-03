/************************************/
/*Author   :  Ahmed Ali             */
/*Date     :  22 AUG 2020           */
/*Version  :  V01                   */
/************************************/

#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H


typedef struct {
	volatile u32 EVCR        ;
	volatile u32 MAPR        ;
	volatile u32 EXTICR[4]   ; 
	volatile u32 MAPR2       ; 
} AFIO_t;

#define EXTI ((volatile AFIO_t *)(0x40010000))


#endif 