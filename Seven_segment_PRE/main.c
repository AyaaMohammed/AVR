/*
 * main.c
 *
 *  Created on: Feb 8, 2023
 *      Author: 00214
 */
#include "stdTypes.h"
#include "errorStates.h"

#include  "DIO_int.h"

#include  "Seven_segment_int.h"

#define   F_CPU   1000000UL
#include   <util/delay.h>

int main(void)
{

	DIO_enuInit();
	Seven_Segment_enuInit();
	while(1)
	{

			for(u8 i=0 ; i<10 ; i++)
			{
				Seven_Segment_enuDisplayNum(i);
				_delay_ms(500);
			}

	}
	return 0;
}
