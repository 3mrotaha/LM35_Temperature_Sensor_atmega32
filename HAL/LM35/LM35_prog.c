/*
 * APP_prog.c
 *
 *  Created on: Sep 25, 2021
 *      Author: amrmo
 */

#include "../../LIB/ErrorStates.h"
#include "../../LIB/std_Types.h"
#include <util/delay.h>

#include "../../MCAL/ADC/ADC_config.h"
#include "../../MCAL/ADC/ADC_priv.h"
#include "../../MCAL/ADC/ADC_int.h"

#include "../LCD/LCD_int.h"


#include "LM35_config.h"
#include "LM35_priv.h"

f32 LM35_CurrentTemp;
f32 LM35_CheckCurrentTemp;

ES_t LM35_enuInit(void){
	ES_t Local_enuErrorState = ES_NOK;

	ADC_enuInit();
	ADC_enuADCEnable();
	ADC_InterruptEnable();
	ADC_enuEnableAutoTrigger();

	return Local_enuErrorState;
}

ES_t LM35_enuReadSignal(s16 *Copy_u16ADCSignal1, s16 *Copy_u16ADCSignal2){
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u16ADCSignal1 != NULL && Copy_u16ADCSignal2 != NULL){
		if(SENSOR_POS_CHANNEL <= ADC_enuSingleEndedChannel7 && SENSOR_NEG_CHANNEL <= ADC_enuSingleEndedChannel7){
			ADC_enuStartConversion();
			ADC_enuSelectChannel(SENSOR_POS_CHANNEL);
			ADC_enuReadADCValue(Copy_u16ADCSignal1);

			ADC_enuStartConversion();
			ADC_enuSelectChannel(SENSOR_NEG_CHANNEL);
			ADC_enuReadADCValue(Copy_u16ADCSignal2);

			Local_enuErrorState = ES_OK;
		}
		else{
			Local_enuErrorState = ES_COMPONENT_OUT_OF_RANGE;
		}
	}
	else{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}

ES_t LM35_enuGetTempValue(s16 _Copy_u16ADCSignal1, s16 _Copy_u16ADCSignal2){
	ES_t Local_enuErrorState = ES_NOK;
#if	SELECT_REFERENCE == AVCC
	LM35_CheckCurrentTemp = LM35_CurrentTemp;
	LM35_CurrentTemp = (_Copy_u16ADCSignal1 - _Copy_u16ADCSignal2) * AVCC_VALUE;
	LM35_CurrentTemp /= 10;
	Local_enuErrorState = ES_OK;
#elif	SELECT_REFERENCE == AREF
	LM35_CheckCurrentTemp = LM35_CurrentTemp;
	LM35_CurrentTemp = (_Copy_u16ADCSignal1 - _Copy_u16ADCSignal2) * AREF_VALUE;
	LM35_CurrentTemp /= 10;
	Local_enuErrorState = ES_OK;
#else
	#error Attention Here !! Selection Error.
#endif
	return Local_enuErrorState;
}

ES_t LM35_enuCallingForInterrupt(void (*Copy_PfuncCallBack) (void)){
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_PfuncCallBack != NULL){

		ADC_InterruptCallBack(Copy_PfuncCallBack);

		Local_enuErrorState = ES_OK;
	}
	else{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;

}
