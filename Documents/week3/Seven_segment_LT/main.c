/*
 * main.c
 *
 *  Created on: Feb 8, 2023
 *      Author: 00214
 */
#include "stdTypes.h"
#include "errorStates.h"

#include  "DIO_int.h"
#include  "Seven_segment_config.h"
#include  "Seven_segment_int.h"


#define   F_CPU   1000000UL
#include   <util/delay.h>

extern SEG_t SEVSEG_AstrSegConfig [SEG_NUM];
int main(void)
{
	DIO_enuInit();
	Seven_Segment_enuInit(SEVSEG_AstrSegConfig);
	while(1)
	{
		Seven_Segment_enuDisableCommon(0);
		Seven_Segment_enuDisplayNum(0,9);
		Seven_Segment_enuEnableCommon(0);
		_delay_ms(50);
		Seven_Segment_enuDisableCommon(0);
		Seven_Segment_enuDisplayNum(1,6);
		Seven_Segment_enuEnableCommon(1);
		_delay_ms(50);
		Seven_Segment_enuDisableCommon(1);
	}
	return 0;
}







