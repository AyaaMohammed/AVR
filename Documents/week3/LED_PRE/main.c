/*
 * main.c
 *
 *  Created on: Feb 7, 2023
 *      Author: 00214
 */
#include "stdTypes.h"
#include  "errorStates.h"

#include "DIO_int.h"
#include "LED_config.h"
#include "LED_int.h"

#include  <util/delay.h>



int main(void){
	DIO_enuInit();
	LED_enuInit();
	while(1)
	{
		LED_enuTurnON(DIO_u8PORTA,DIO_u8PIN3,LED_u8SINK);
		_delay_ms(500);
		LED_enuTurnOFF(DIO_u8PORTA,DIO_u8PIN3,LED_u8SINK);
		LED_enuTurnON(DIO_u8PORTA,DIO_u8PIN0,LED_u8SOURCE);
		_delay_ms(500);
		LED_enuTurnOFF(DIO_u8PORTA,DIO_u8PIN0,LED_u8SOURCE);
	}
	return 0;
}
