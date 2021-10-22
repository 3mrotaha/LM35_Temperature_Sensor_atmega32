/*
 * main.c
 *
 *  Created on: Sep 25, 2021
 *      Author: amrmo
 */


#include "LIB/std_Types.h"
#include "LIB/ErrorStates.h"

#include "APP/APP_config.h"
#include "APP/APP_priv.h"
#include "APP/APP_int.h"


int main(void){

	APP_enuInit();
	u16 Local_u16ADCFirstVal, Local_u16ADCSecondVal;
	while(1){
		APP_enuGetTemperature(Local_u16ADCFirstVal, Local_u16ADCSecondVal);
	}
	return 0;
}


