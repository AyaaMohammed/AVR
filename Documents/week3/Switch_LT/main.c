/*
 * main.c
 *
 *  Created on: Feb 6, 2023
 *      Author: 00214
 */
#include "errorStates.h"
#include "stdTypes.h"
#include "DIO_int.h"
#include  "Switch_config.h"
#include  "Switch_int.h"


extern SW_t Switch_AstrSwitchState [SW_NUM];
int main(void)
{
	DIO_enuInit();
	Switch_enuInit(Switch_AstrSwitchState);
	u8 pinstate = 0;
	while(1){
		Switch_enuGetState(&Switch_AstrSwitchState[1],&pinstate);
		if(pinstate == 0){
			DIO_enuSetPinValue(DIO_u8PORTA ,DIO_u8PIN0,DIO_u8HIGH);

		}
		else{
			DIO_enuSetPinValue(DIO_u8PORTA ,DIO_u8PIN0,DIO_u8LOW);
		}
	}


return 0;
}
