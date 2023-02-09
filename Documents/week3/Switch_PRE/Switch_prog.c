/*
 * Switch_prog.c
 *
 *  Created on: Feb 6, 2023
 *      Author: 00214
 */
#include "stdTypes.h"
#include "errorStates.h"
#include "Switch_priv.h"
#include  "Switch_config.h"


#include  "DIO_int.h"

ES_t Switch_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(SW_u8PortID <= DIO_u8PoRTD && SW_u8PinID<= DIO_u8PIN7){
		Local_enuErrorState =DIO_enuSetPinDirection(SW_u8PortID,DIO_u8INPUT,SW_u8PinID);
		Local_enuErrorState =DIO_enuSetPinValue(SW_u8PortID,SW_u8PinID,SW_u8Status);
	}
	else{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}
	return Local_enuErrorState;
}
ES_t Switch_enuGetState(u8 Copy_u8SWPortID,u8 Copy_u8SWPinID,u8 * Copy_u8SWStatus)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(SW_u8PortID <= DIO_u8PoRTD && SW_u8PinID<= DIO_u8PIN7){
		Local_enuErrorState = DIO_enuGetPinValue(Copy_u8SWPortID,Copy_u8SWStatus,Copy_u8SWPortID);
	}
	else{
		Local_enuErrorState =ES_OUT_OF_RANGE;
	}
	return Local_enuErrorState;
}




