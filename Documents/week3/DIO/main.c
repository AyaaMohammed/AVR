/*
 * main.c
 *
 *  Created on: Feb 2, 2023
 *      Author: 00214
 */

#include "stdTypes.h"
#include "errorStates.h"
#include "DIO_int.h"
#include "util/delay.h"
int main(void){
	s8 i=0;
	DIO_enuInit();
	DIO_enuSetValue(DIO_u8PORTA,0x00);
		while(1){
			for(i=7 ;i>=0 ;i--){
				DIO_enuSetPinValue(DIO_u8PORTA,i,DIO_u8HIGH);
				_delay_ms(500);
			}

		}
			return 0;
}
