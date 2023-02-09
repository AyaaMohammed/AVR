/*
 * main.c
 *
 *  Created on: Dec 17, 2022
 *      Author: 00214
 */

#include <util/delay.h>
typedef unsigned char u8;
#define DDRA  *((u8*)0x3A)
#define PORTA *((u8*)0x3B)
#define PINA  *((volatile u8*)0x39)
typedef signed char     s8;
#define DDRB  *((u8*)0x37)
#define PORTB *((u8*)0x38)
#define PINB *((volatile u8*)0x36)

#define DDRC  *((u8*)0x34)
#define PORTC  *((u8*)0x35)

#define DDRD  *((u8*)0x31)
#define PORTD  *((u8*)0x32)

int main(void){
	DDRA = 0b11111111;
	PORTA = 0;
	s8 i=0;
	while(1){
		for(i=7 ;i>=0 ;i--){
			PORTA |=(1<<i);
			_delay_ms(500);

		}
		for(i=7 ;i>=0 ;i--){

			PORTA &=~(1<<i);
			_delay_ms(500);
		}
	}
	return 0;
}
