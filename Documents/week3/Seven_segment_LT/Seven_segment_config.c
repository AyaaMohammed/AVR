/*
 * Seven_segment_config.c
 *
 *  Created on: Feb 9, 2023
 *      Author: 00214
 */

#include "stdTypes.h"
#include "errorStates.h"
#include  "DIO_int.h"
#include "Seven_segment_config.h"
#include "Seven_segment_priv.h"


 SEG_t  SEVSEG_AstrSegConfig [SEG_NUM] =
{
		{DIO_u8PORTC , DIO_u8PIN0 ,DIO_u8PORTC,DIO_u8PIN1,DIO_u8PORTC,DIO_u8PIN2,DIO_u8PORTC,DIO_u8PIN3,DIO_u8PORTC,DIO_u8PIN4,DIO_u8PORTC,DIO_u8PIN5,DIO_u8PORTC,DIO_u8PIN6
		,NOT_CONNECTED,NOT_CONNECTED,NOT_CONNECTED,NOT_CONNECTED,COMMON_ANODE },
		{DIO_u8PORTB , DIO_u8PIN0 ,DIO_u8PORTB,DIO_u8PIN1,DIO_u8PORTB,DIO_u8PIN2,DIO_u8PORTB,DIO_u8PIN3,DIO_u8PORTB,DIO_u8PIN4,DIO_u8PORTB,DIO_u8PIN5,DIO_u8PORTB,DIO_u8PIN6
		,NOT_CONNECTED,NOT_CONNECTED,NOT_CONNECTED,NOT_CONNECTED,COMMON_CATHODE }
};