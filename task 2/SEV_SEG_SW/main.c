/*
 * main.c
 *
 *  Created on: Feb 2, 2023
 *      Author: 00214
 */
#include <util/delay.h>
#include "stdTypes.h"
#define DDRA   *((u8*)0x3A)
#define PORTA  *((u8*)0x3B)
#define PINA   *((volatile u8*)0x39)

#define DDRB   *((u8*)0x37)
#define PORTB  *((u8*)0x38)
#define PINB   *((volatile u8*)0x36)

#define DDRC   *((u8*)0x34)
#define PORTC  *((u8*)0x35)
#define PINC   *((volatile u8*)0x33)

#define DDRD   *((u8*)0x31)
#define PORTD  *((u8*)0x32)
#define PIND   *((volatile u8*)0x30)
int main(void){
	u8 arr1[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
	u8 swState1=0 ,swState2=0 , counter=0;
	DDRA &=~(1<<0);
	DDRA &=~(1<<1);
	PORTA |=(1<<0);
	PORTA |=(1<<1);

	DDRC =0xff;
	PORTC =arr1[counter];
	while(1){
		swState1 =((PINA>>0)&1);
		swState2 =((PINA>>1)&1);
		if(swState1==0){
			if(counter <9){
				counter++;
				while(((PINA>>0)&1)==0);
				PORTC =arr1[counter];
			}
		}
		else if(swState2==0){
			if(counter >0){
				counter--;
				while(((PINA>>1)&1)==0);
				PORTC =arr1[counter];
				}
		}

	}

	return 0;

}

