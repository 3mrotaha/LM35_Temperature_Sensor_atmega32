/*
 * APP_prog.c
 *
 *  Created on: Sep 25, 2021
 *      Author: amrmo
 */

#include "../LIB/ErrorStates.h"
#include "../LIB/std_Types.h"
#include <util/delay.h>

#include "../HAL/LCD/LCD_int.h"

#include "../HAL/LM35/LM35_int.h"

#include "APP_config.h"
#include "APP_priv.h"

extern f32 LM35_CurrentTemp;
extern f32 LM35_CheckCurrentTemp;
void LM35_enuViewTemperature(void);
ES_t APP_enuInit(void){
	ES_t Local_enuErrorState = ES_NOK;

	LM35_enuInit();
	LCD_enuInit();
	LM35_enuCallingForInterrupt(LM35_enuViewTemperature);
	LCD_enuSendCommand(0X80);
	LCD_enuDisplayString("Temp:", 5);

	return Local_enuErrorState = ES_OK;
}

ES_t APP_enuGetTemperature(u16 Copy_FirstVal, u16 Copy_SecondVal){
	ES_t Local_enuErrorState = ES_NOK;


		LM35_enuReadSignal(&Copy_FirstVal, &Copy_SecondVal);
		LM35_enuGetTempValue(Copy_FirstVal, Copy_SecondVal);

	return Local_enuErrorState = ES_OK;
}

void LM35_enuViewTemperature(void){
	if(LM35_CurrentTemp != LM35_CheckCurrentTemp){
		LCD_enuSendCommand(0xC9);
		LCD_enuSendCommand(0x85);
		LCD_DisplayFloatNumber(LM35_CurrentTemp);
		LCD_enuDisplayString(" C ", 3);

		LCD_enuSendCommand(0xC0);
		LCD_DisplayFloatNumber(LM35_CurrentTemp + KELVIN_CONV);
		LCD_enuDisplayString(" K/", 3);

		LCD_DisplayFloatNumber(LM35_CurrentTemp * FEHRENHEIT_CONV);
		LCD_enuDisplayString(" F", 2);

	}
}

