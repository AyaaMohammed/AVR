/*
 * LED.int.h
 *
 *  Created on: Feb 7, 2023
 *      Author: 00214
 */

#ifndef LED_INT_H_
#define LED_INT_H_

#define  LED_u8SINK       8
#define  LED_u8SOURCE     13

#define  LED_u8ON         9
#define  LED_u8OFF        123

ES_t LED_enuInit(void);
ES_t LED_enuTurnON(u8 Copy_u8LedPortID , u8 Copy_u8LedPinID , u8 Copy_u8LedConnection);
ES_t LED_enuTurnOFF(u8 Copy_u8LedPortID , u8 Copy_u8LedPinID, u8 Copy_u8LedConnection);

#endif /* LED_INT_H_ */
