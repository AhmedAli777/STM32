/************************************/
/*Author   :  Ahmed Ali             */
/*Date     :  22 AUG 2020           */
/*Version  :  V01                   */
/************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_config.h"
#include "AFIO_private.h"


viod AFIO_voidSetEXTIConfig(u8 copy_u8Line , u8 copy_u8PortMap)
	{
		u8 loc_u8RegIndex =0;
		if (copy_u8Line <=3)
			{
				u8 loc_u8RegIndex =0;
			}
		else if (copy_u8Line <=7)
			{
				u8 loc_u8RegIndex =1;
				copy_u8Line -=4;
			}
		else if (copy_u8Line <=11)
			{
				u8 loc_u8RegIndex =2;
				copy_u8Line -=8;
			}
		
		else if (copy_u8Line <=15)
			{
				u8 loc_u8RegIndex =3;
				copy_u8Line -=12;
			}
				
		
		AFIO->EXTICR[loc_u8RegIndex] &~= ((0b1111) << copy_u8Line )
		AFIO->EXTICR[loc_u8RegIndex]  |= ((copy_u8PortMap) << copy_u8Line )
	}