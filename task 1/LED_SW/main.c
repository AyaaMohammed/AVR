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
		DDRA |=(1<<0);
		DDRA |=(1<<1);
		PORTA &=~(1<<0);
		PORTA &=~(1<<1);

		DDRB &=~(1<<1);
		DDRB &=~(1<<2);
		DDRB &=~(1<<3);
		PORTB |=(1<<1);
		PORTB |=(1<<2);
		PORTB |=(1<<3);
		u8 swState1=0 ,swState2=0 ,swState3=0 ;
   	   while(1){
   	    swState1 = ((PINB>>1)&1);
   	    swState2 = ((PINB>>2)&1);
   	    swState3 = ((PINB>>3)&1);

   	    if(swState1==0){
   	    	PORTA |=(1<<0);
   	    	PORTA &=~(1<<1);
   	    }
   	    else if(swState2==0){
   	    	PORTA &=~(1<<0);
   	    	PORTA |=(1<<1);
   	    }
   	    else if(swState3 ==0){
   	    	PORTA |=(1<<0);
   	    	PORTA |=(1<<1);
   	    }
   	    else{
   	      	PORTA &=~(1<<0);
		    PORTA &=~(1<<1);
   	    }
   	   }
 return 0;
}

