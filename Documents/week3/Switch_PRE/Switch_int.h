/*
 * Switch_int.h
 *
 *  Created on: Feb 6, 2023
 *      Author: 00214
 */

#ifndef SWITCH_INT_H_
#define SWITCH_INT_H_

ES_t Switch_enuInit(void);
ES_t Switch_enuGetState(u8 Copy_u8SWPortID,u8 Copy_u8SWPinID,u8 * Copy_u8SWStatus);

#endif /* SWITCH_INT_H_ */
