/*
 * Seven_segment_prog.c
 *
 *  Created on: Feb 8, 2023
 *      Author: 00214
 */
#include "stdTypes.h"
#include  "errorStates.h"

#include "DIO_int.h"

#include "Seven_segment_config.h"
#include "Seven_segment_priv.h"


ES_t Seven_Segment_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	u32 Local_u32Check = 0;
	Local_u32Check |= (DIO_enuSetPinDirection(SEG_APORT,DIO_u8OUTPUT,SEG_APIN )<< 0);
	Local_u32Check |= (DIO_enuSetPinDirection(SEG_BPORT,DIO_u8OUTPUT,SEG_BPIN )<< 2);
	Local_u32Check |= (DIO_enuSetPinDirection(SEG_CPORT,DIO_u8OUTPUT,SEG_CPIN )<< 4);
	Local_u32Check |= (DIO_enuSetPinDirection(SEG_DPORT,DIO_u8OUTPUT,SEG_DPIN )<< 6);
	Local_u32Check |= (DIO_enuSetPinDirection(SEG_EPORT,DIO_u8OUTPUT,SEG_EPIN )<< 8);
	Local_u32Check |= (DIO_enuSetPinDirection(SEG_FPORT,DIO_u8OUTPUT,SEG_FPIN )<< 10);
	Local_u32Check |= (DIO_enuSetPinDirection(SEG_GPORT,DIO_u8OUTPUT,SEG_GPIN )<< 12);

#if  SEG_CMN  <=  DIO_u8PIN7	&& SEG_CMN_PORT <= DIO_u8PORTD
	DIO_enuSetPinDirection(SEG_CMN_PORT,DIO_u8OUTPUT,SEG_CMN);
#elif SEG_CMN == NOT_CONNECTED || SEG_CMN_PORT == NOT_CONNECTED

#else
#error"your common pin has a wrong selection "
#endif

#if  SEG_DOT  <=  DIO_u8PIN7	&& SEG_DOT_PORT <= DIO_u8PORTD
	DIO_enuSetPinDirection(SEG_DOT_PORT,DIO_u8OUTPUT,SEG_DOT);
#elif SEG_DOT == NOT_CONNECTED || SEG_DOT_PORT == NOT_CONNECTED

#else
#error"your DOT pin has a wrong selection "
#endif

	u8 Local_u8Iter = 0;
	for(Local_u8Iter=0 ; Local_u8Iter < 12 ; Local_u8Iter +=2)
	{
		if( ( ( (Local_u32Check)>>Local_u8Iter)&3) != ES_OK )
		{
			return Local_enuErrorState;
		}
	}
	Local_enuErrorState	 =	ES_OK;
	return Local_enuErrorState;
}

ES_t Seven_Segment_enuDisplayNum(u8 Copy_u8Num)
{
	ES_t Local_enuErrorState = ES_NOK;
	u32 Local_u32Check = 0;
	if(Copy_u8Num < 10)
	{
#if   SEG_TYPE == COMMON_CATHODE
		Local_u32Check = (DIO_enuSetPinValue(SEG_APORT , SEG_APIN ,((SEG_Au8NumDisplay[Copy_u8Num]>>0)&1))<< 0);
		Local_u32Check|= (DIO_enuSetPinValue(SEG_BPORT , SEG_BPIN ,((SEG_Au8NumDisplay[Copy_u8Num]>>1)&1))<< 2);
		Local_u32Check|= (DIO_enuSetPinValue(SEG_CPORT , SEG_CPIN ,((SEG_Au8NumDisplay[Copy_u8Num]>>2)&1))<< 4);
		Local_u32Check|= (DIO_enuSetPinValue(SEG_DPORT , SEG_DPIN ,((SEG_Au8NumDisplay[Copy_u8Num]>>3)&1))<< 6);
		Local_u32Check|= (DIO_enuSetPinValue(SEG_EPORT , SEG_EPIN ,((SEG_Au8NumDisplay[Copy_u8Num]>>4)&1))<< 8);
		Local_u32Check|= (DIO_enuSetPinValue(SEG_FPORT , SEG_FPIN ,((SEG_Au8NumDisplay[Copy_u8Num]>>5)&1))<< 10);
		Local_u32Check|= (DIO_enuSetPinValue(SEG_GPORT , SEG_GPIN ,((SEG_Au8NumDisplay[Copy_u8Num]>>6)&1))<< 12);
#elif 	SEG_TYPE == COMMON_ANODE
		Local_u32Check|= (DIO_enuSetPinValue(SEG_APORT , SEG_APIN ,!((SEG_Au8NumDisplay[Copy_u8Num]>>0)&1))<< 0);
		Local_u32Check|= (DIO_enuSetPinValue(SEG_BPORT , SEG_BPIN ,!((SEG_Au8NumDisplay[Copy_u8Num]>>1)&1))<< 2);
		Local_u32Check|= (DIO_enuSetPinValue(SEG_CPORT , SEG_CPIN ,!((SEG_Au8NumDisplay[Copy_u8Num]>>2)&1))<< 4);
		Local_u32Check|= (DIO_enuSetPinValue(SEG_DPORT , SEG_DPIN ,!((SEG_Au8NumDisplay[Copy_u8Num]>>3)&1))<< 6);
		Local_u32Check|= (DIO_enuSetPinValue(SEG_EPORT , SEG_EPIN ,!((SEG_Au8NumDisplay[Copy_u8Num]>>4)&1))<< 8);
		Local_u32Check|= (DIO_enuSetPinValue(SEG_FPORT , SEG_FPIN ,!((SEG_Au8NumDisplay[Copy_u8Num]>>5)&1))<< 10);
		Local_u32Check|= (DIO_enuSetPinValue(SEG_GPORT , SEG_GPIN ,!((SEG_Au8NumDisplay[Copy_u8Num]>>6)&1))<< 12);
#else
#error 		"SEG type has a wrong selection"
#endif
}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}
	u8 Local_u8Iter = 0;
	for(Local_u8Iter=0 ; Local_u8Iter < 12 ; Local_u8Iter +=2)
	{
		if( ( ( (Local_u32Check)>>Local_u8Iter)&3) != ES_OK )
		{
			return Local_enuErrorState;
		}
	}
	Local_enuErrorState	 =	ES_OK;
	return Local_enuErrorState;
}
ES_t Seven_Segment_enuEnableCommon(void)
{
	ES_t Local_enuErrorState = ES_NOK;
#if    SEG_CMN <=IO_u8PIN7 && SEG_CMN_PORT <= DIO_u8PORTD
	#if    SEG_TYPE == COOMON_CATHODE
	Local_enuErrorState = DIO_enuSetPinValue(SEG_CMN_PORT ,SEG_CMN,DIO_u8LOW);
	#elif  SEG_CMN  == COMMON_ANODE
	Local_enuErrorState = 	DIO_enuSetPinValue(SEG_CMN_PORT ,SEG_CMN,DIO_u8HIGH);
	#else
	#error "SEG type has a wrong selection"
	#endif
#elif  SEG_CMN == NOT_CONNECTED || SEG_CMN_PORT == NOT_CONNECTED

#else
 #error  "your common pin has a wrong selection"
#endif

	return Local_enuErrorState;
}

ES_t Seven_Segment_enuDisableCommon(void)
{
	ES_t Local_enuErrorState = ES_NOK;
#if    SEG_CMN <=IO_u8PIN7 && SEG_CMN_PORT <= DIO_u8PORTD
	#if    SEG_TYPE == COOMON_CATHODE
	Local_enuErrorState = DIO_enuSetPinValue(SEG_CMN_PORT ,SEG_CMN,DIO_u8HIGH);
	#elif  SEG_CMN  == COMMON_ANODE
	Local_enuErrorState = 	DIO_enuSetPinValue(SEG_CMN_PORT ,SEG_CMN,DIO_u8LOW);
	#else
	#error "SEG type has a wrong selection"
	#endif
#elif  SEG_CMN == NOT_CONNECTED || SEG_CMN_PORT == NOT_CONNECTED

#else
 #error  "your common pin has a wrong selection"
#endif
	return Local_enuErrorState;
}

ES_t Seven_Segment_enuEnableDot(void)
{
	ES_t Local_enuErrorState = ES_NOK;
#if    SEG_DOT <=IO_u8PIN7 && SEG_DOT_PORT <= DIO_u8PORTD
	#if    SEG_TYPE == COOMON_CATHODE
	Local_enuErrorState = DIO_enuSetPinValue(SEG_DOT_PORT ,SEG_DOT,DIO_u8HIGH);
	#elif  SEG_CMN  == COMMON_ANODE
	Local_enuErrorState = DIO_enuSetPinValue(SEG_DOT_PORT ,SEG_DOT,DIO_u8LOW);
	#else
	#error "SEG type has a wrong selection"
	#endif
#elif  SEG_DOT == NOT_CONNECTED || SEG_DOT_PORT == NOT_CONNECTED

#else
 #error  "your DOT pin has a wrong selection"
#endif
	return Local_enuErrorState;
}
ES_t Seven_Segment_enuDisableDot(void)
{
	ES_t Local_enuErrorState = ES_NOK;
#if    SEG_DOT <=IO_u8PIN7 && SEG_DOT_PORT <= DIO_u8PORTD
	#if    SEG_TYPE == COOMON_CATHODE
	Local_enuErrorState = DIO_enuSetPinValue(SEG_DOT_PORT ,SEG_DOT,DIO_u8LOW);
	#elif  SEG_CMN  == COMMON_ANODE
	Local_enuErrorState = DIO_enuSetPinValue(SEG_DOT_PORT ,SEG_DOT,DIO_u8HIGH);
	#else
	#error "SEG type has a wrong selection"
	#endif
#elif  SEG_DOT == NOT_CONNECTED || SEG_DOT_PORT == NOT_CONNECTED

#else
 #error  "your DOT pin has a wrong selection"
#endif
	return Local_enuErrorState;
}
ES_t Seven_Segment_enuClearDisplay(void)
{

	ES_t Local_enuErrorState = ES_NOK;
#if   SEG_TYPE == COMMON_CATHODE
	Local_enuErrorState = DIO_enuSetPinValue(SEG_APORT , SEG_APIN , DIO_u8LOW);
	Local_enuErrorState = DIO_enuSetPinValue(SEG_BPORT , SEG_BPIN ,DIO_u8LOW);
	Local_enuErrorState = DIO_enuSetPinValue(SEG_CPORT , SEG_CPIN ,DIO_u8LOW);
	Local_enuErrorState = DIO_enuSetPinValue(SEG_DPORT , SEG_DPIN ,DIO_u8LOW);
	Local_enuErrorState = DIO_enuSetPinValue(SEG_EPORT , SEG_EPIN ,DIO_u8LOW);
	Local_enuErrorState = DIO_enuSetPinValue(SEG_FPORT , SEG_FPIN ,DIO_u8LOW);
	Local_enuErrorState = DIO_enuSetPinValue(SEG_GPORT , SEG_GPIN ,DIO_u8LOW);
#elif 	SEG_TYPE == COMMON_ANODE
	Local_enuErrorState = DIO_enuSetPinValue(SEG_APORT , SEG_APIN ,DIO_u8HIGH);
	Local_enuErrorState = DIO_enuSetPinValue(SEG_BPORT , SEG_BPIN ,DIO_u8HIGH);
	Local_enuErrorState = DIO_enuSetPinValue(SEG_CPORT , SEG_CPIN ,DIO_u8HIGH);
	Local_enuErrorState = DIO_enuSetPinValue(SEG_DPORT , SEG_DPIN ,DIO_u8HIGH);
	Local_enuErrorState = DIO_enuSetPinValue(SEG_EPORT , SEG_EPIN ,DIO_u8HIGH);
	Local_enuErrorState = DIO_enuSetPinValue(SEG_FPORT , SEG_FPIN ,DIO_u8HIGH);
	Local_enuErrorState = DIO_enuSetPinValue(SEG_GPORT , SEG_GPIN ,DIO_u8HIGH);
#else
#error 		"SEG type has a wrong selection"
#endif
	return Local_enuErrorState;
}







