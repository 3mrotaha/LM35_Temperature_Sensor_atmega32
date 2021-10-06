/*
 * APP_prog.c
 *
 *  Created on: Sep 25, 2021
 *      Author: amrmo
 */

#include "../LIB/ErrorStates.h"
#include "../LIB/std_Types.h"

#include "../MCAL/ADC/ADC_config.h"
#include "../MCAL/ADC/ADC_priv.h"
#include "../MCAL/ADC/ADC_int.h"

#include "../HAL/LCD/LCD_int.h"


#include "APP_config.h"
#include "APP_priv.h"

f32 LM35_CurrentTemp;
f32 LM35_CheckCurrentTemp;
void LM35_enuViewTemperature(void);
ES_t LM35_enuInit(void){
	ES_t Local_enuErrorState = ES_NOK;

	ADC_enuInit();
	ADC_enuADCEnable();

	if(SENSOR_CHANNEL <= ADC_enuChannel7){
		ADC_enuSelectChannel(SENSOR_CHANNEL);
		Local_enuErrorState = ES_OK;
	}
	else{
		Local_enuErrorState = ES_COMPONENT_OUT_OF_RANGE;
	}

	ADC_InterruptEnable();
	ADC_InterruptCallBack(LM35_enuViewTemperature);
	ADC_enuEnableAutoTrigger();

	LCD_enuInit();
	LCD_enuSendCommand(0X80);
	LCD_enuDisplayString("Temp:", 5);

	return Local_enuErrorState;
}

ES_t LM35_enuReadSignal(u16 *Copy_u16ADCSignal){
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u16ADCSignal != NULL){
		ADC_enuStartConversion();
		ADC_enuReadADCValue(Copy_u16ADCSignal);
		Local_enuErrorState = ES_OK;
	}
	else{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}

ES_t LM35_enuGetTempValue(u16 Copy_u16ADCSignal){
	ES_t Local_enuErrorState = ES_NOK;
#if	SELECT_REFERENCE == AVCC
	LM35_CheckCurrentTemp = LM35_CurrentTemp;
	LM35_CurrentTemp = Copy_u16ADCSignal * AVCC_VALUE;
	LM35_CurrentTemp /= 10;
	Local_enuErrorState = ES_OK;
#elif	SELECT_REFERENCE == AREF
	LM35_CheckCurrentTemp = LM35_CurrentTemp;
	LM35_CurrentTemp = Copy_u16ADCSignal * AREF_VALUE;
	LM35_CurrentTemp /= 10;
	Local_enuErrorState = ES_OK;
#else
	#error Attention Here !! Selection Error.
#endif

	return Local_enuErrorState;
}

void LM35_enuViewTemperature(void){
	if(LM35_CurrentTemp != LM35_CheckCurrentTemp){
		LCD_enuSendCommand(0x85);
		LCD_DisplayFloatNumber(LM35_CurrentTemp);
		LCD_enuDisplayString(" C\\ ", 4);

		LCD_enuSendCommand(0xC0);
		LCD_DisplayFloatNumber(LM35_CurrentTemp + KELVIN_CONV);
		LCD_enuDisplayString(" K\\ ", 4);

		LCD_DisplayFloatNumber(LM35_CurrentTemp + FEHRENHEIT_CONV);
		LCD_enuDisplayString(" F\\ ", 4);
	}
}
