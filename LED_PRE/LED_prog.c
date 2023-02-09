/*
 * LED.prog.c
 *
 *  Created on: Feb 7, 2023
 *      Author: 00214
 */
#include  "stdTypes.h"
#include  "errorStates.h"
#include  "LED_priv.h"
#include  "LED_config.h"
#include  "DIO_int.h"

ES_t LED_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	if((LED_PORTID <= DIO_u8PORTD) && (LED_PINID <= DIO_u8PIN7))
	{
		DIO_enuSetPinDirection(LED_PORTID,DIO_u8OUTPUT,LED_PINID);
		if(LED_CONNECTION == LED_SINK)
		{
			if(LED_INITSATE == LED_ON)
			{
				DIO_enuSetPinValue(LED_PORTID,LED_PINID,DIO_u8LOW);
				Local_enuErrorState = ES_OK;
			}
			else if(LED_INITSATE == LED_OFF)
			{
				DIO_enuSetPinValue(LED_PORTID,LED_PINID,DIO_u8HIGH);
				Local_enuErrorState = ES_OK;
			}
			else
			{
				Local_enuErrorState =ES_OUT_OF_RANGE;
			}
		}
		if(LED_CONNECTION == LED_SOURCE)
		{
			if(LED_INITSATE == LED_ON)
			{
				DIO_enuSetPinValue(LED_PORTID,LED_PINID,DIO_u8HIGH);
				Local_enuErrorState = ES_OK;
			}
			else if(LED_INITSATE == LED_OFF)
			{
				DIO_enuSetPinValue(LED_PORTID,LED_PINID,DIO_u8LOW);
				Local_enuErrorState = ES_OK;
			}
			else
			{
				Local_enuErrorState =ES_OUT_OF_RANGE;
			}
		}
	}
	else
	{
		Local_enuErrorState =ES_OUT_OF_RANGE;
	}
	return Local_enuErrorState;

}
ES_t LED_enuTurnON(u8 Copy_u8LedPortID , u8 Copy_u8LedPinID , u8 Copy_u8LedConnection)
{
	ES_t Local_enuErrorState = ES_NOK;
	if((Copy_u8LedPortID <= DIO_u8PORTD) && (Copy_u8LedPinID <= DIO_u8PIN7))
	{
		if(Copy_u8LedConnection ==LED_SINK)
		{
			Local_enuErrorState =DIO_enuSetPinValue(Copy_u8LedPortID,Copy_u8LedPinID,DIO_u8LOW);
		}
		else if (Copy_u8LedConnection==LED_SOURCE)
		{
			Local_enuErrorState =DIO_enuSetPinValue(Copy_u8LedPinID,Copy_u8LedPinID,DIO_u8HIGH);
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}

	}
	return Local_enuErrorState;
}
ES_t LED_enuTurnOFF(u8 Copy_u8LedPortID , u8 Copy_u8LedPinID, u8 Copy_u8LedConnection)
{
	ES_t Local_enuErrorState = ES_NOK;
	if((Copy_u8LedPortID <= DIO_u8PORTD) && (Copy_u8LedPinID <= DIO_u8PIN7))
	{
		if(Copy_u8LedConnection ==LED_SINK)
		{
			Local_enuErrorState =DIO_enuSetPinValue(Copy_u8LedPortID,Copy_u8LedPinID,DIO_u8HIGH);
		}
		else if (Copy_u8LedConnection ==LED_SOURCE)
		{
			Local_enuErrorState =DIO_enuSetPinValue(Copy_u8LedPortID,Copy_u8LedPinID,DIO_u8LOW);
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}

	}

	return Local_enuErrorState;
}


