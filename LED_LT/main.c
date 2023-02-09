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
extern LED_t LED_AstrLedConfig [LED_NUM];


int main(void){
	DIO_enuInit();
	LED_enuInit(LED_AstrLedConfig);


	while(1)
	{

			LED_enuTurnON(&LED_AstrLedConfig[0]);
			_delay_ms(500);
			LED_enuTurnOFF(&LED_AstrLedConfig[0]);
			_delay_ms(500);
	}
	return 0;
}
