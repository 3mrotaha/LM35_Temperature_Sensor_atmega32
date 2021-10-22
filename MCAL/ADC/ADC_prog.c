/*
 * ADC_prog.c
 *
 *  Created on: Sep 25, 2021
 *      Author: amrmo
 */
#include "../../LIB/std_Types.h"
#include "../../LIB/ErrorStates.h"

#include "ADC_priv.h"
#include "ADC_config.h"

static void (*ADC_PfuncCallBack) (void) = NULL;

ES_t ADC_enuInit(void){
	ES_t Local_enuErrorState = ES_NOK;
	ADMUX &= INITIAL_VALUE;
	ADCSRA &= INITIAL_VALUE;

	SREG |= (BIT_MASK << L_BIT);

#if PRESCALLER == PRE_TWO
	ADCSRA |= PRE_TWO;
	Local_enuErrorState = ES_OK;

#elif PRESCALLER == PRE_FOUR
	ADCSRA |= PRE_FOUR;
	Local_enuErrorState = ES_OK;

#elif PRESCALLER == PRE_EIGHT
	ADCSRA |= PRE_EIGHT;
	Local_enuErrorState = ES_OK;

#elif PRESCALLER == PRE_SIXTEEN
	ADCSRA |= PRE_SIXTEEN;
	Local_enuErrorState = ES_OK;

#elif PRESCALLER == PRE_THIRTY_TWO
	ADCSRA |= PRE_THIRTY_TWO;
	Local_enuErrorState = ES_OK;

#elif PRESCALLER == PRE_SIXTY_FOUR
	ADCSRA |= PRE_SIXTY_FOUR;
	Local_enuErrorState = ES_OK;

#elif PRESCALLER == PRE_ONE_TWENTY_EIGHT
	ADCSRA |= PRE_ONE_TWENTY_EIGHT;
	Local_enuErrorState = ES_OK;

#else
	#error You Entered A Wrong Selection!!

#endif

#if SELECT_REFERENCE == AREF
	ADMUX |= (AREF << REFS_BITS);
	Local_enuErrorState = ES_OK;

#elif	SELECT_REFERENCE == AVCC
	ADMUX |= (AVCC << REFS_BITS);
	Local_enuErrorState = ES_OK;

#elif	SELECT_REFERENCE == INTERNAL_AREF
	ADMUX |= (INTERNAL_AREF << REFS_BITS);
	Local_enuErrorState = ES_OK;

#else
	#error You Entered A Wrong Selection!!
#endif

#if ADJUSTMENT == RIGHT_ADJ
	ADMUX &= ~(BIT_MASK << ADLAR_BIT);
	Local_enuErrorState = ES_OK;

#elif ADJUSTMENT == LEFT_ADJ
	ADMUX |= (BIT_MASK << ADLAR_BIT);
	Local_enuErrorState = ES_OK;

#else
	#error You Entered A Wrong Selection!!

#endif
	return Local_enuErrorState;
}


ES_t ADC_enuADCEnable(void){
	ES_t Local_enuErrorState = ES_NOK;

	ADCSRA |= (BIT_MASK << ADEN_BIT);

	return Local_enuErrorState = ES_OK;
}


ES_t ADC_enuADCDisable(void){
	ES_t Local_enuErrorState = ES_NOK;

	ADCSRA &= ~(BIT_MASK << ADEN_BIT);

	return Local_enuErrorState = ES_OK;
}

ES_t ADC_enuSelectChannel(ADC_Channel Copy_ADCChannel){
	ES_t Local_enuErrorState = ES_NOK;
	ADMUX &= 0b11100000;
	ADMUX |= Copy_ADCChannel;

	return Local_enuErrorState = ES_OK;
}


ES_t ADC_enuStartConversion(void){
	ES_t Local_enuErrorState = ES_NOK;

	ADCSRA &= ~(BIT_MASK << ADIF_BIT);
	ADCSRA |= (BIT_MASK << ADSC_BIT);

	return Local_enuErrorState = ES_OK;
}

ES_t ADC_enuWaitOnFlag(void){
	ES_t Local_enuErrorState = ES_NOK;

	while(!((ADCSRA >> ADIF_BIT) & BIT_MASK));


	return Local_enuErrorState  = ES_OK;
}

ES_t ADC_enuReadADCValue(volatile s16* Copy_u16ADCValue){

	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_u16ADCValue != NULL){
#if ADJUSTMENT == RIGHT_ADJ
		*Copy_u16ADCValue = ADC_DATA_REGISTER;

#elif	ADJUSTMENT == LEFT_ADJ
		*Copy_u16ADCValue = (ADC_DATA_REGISTER >> 6);

#else
	#error You Entered A Wrong Selection!!
#endif
	}
	else{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}


ES_t ADC_enuEnableAutoTrigger(void){
	ES_t Local_enuErrorState = ES_NOK;
	if(!((ADCSRA >> ADATE_BIT) & BIT_MASK)){
		ADCSRA |= (BIT_MASK << ADATE_BIT);
		Local_enuErrorState = ES_OK;
	}
	return Local_enuErrorState;
}


ES_t ADC_enuDisableAutoTrigger(void){
	ES_t Local_enuErrorState = ES_NOK;

	if(((ADCSRA >> ADATE_BIT) & BIT_MASK)){
		ADCSRA &= ~(BIT_MASK << ADATE_BIT);
		Local_enuErrorState = ES_OK;
	}

	return Local_enuErrorState;
}

ES_t ADC_InterruptEnable(void){
	ES_t Local_enuErrorState = ES_NOK;

	ADCSRA |= (BIT_MASK << ADIE_BIT);

	return Local_enuErrorState = ES_OK;
}

ES_t ADC_InterruptDisable(void){
	ES_t Local_enuErrorState = ES_NOK;

	ADCSRA &= ~(BIT_MASK << ADIE_BIT);

	return Local_enuErrorState;
}

ES_t ADC_InterruptCallBack(void (*Copy_PfuncCallBack) (void)){
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_PfuncCallBack != NULL){
		ADC_PfuncCallBack = Copy_PfuncCallBack;
		Local_enuErrorState = ES_OK;
	}
	else{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}

ADC_ISR{
	if(ADC_PfuncCallBack != NULL){
		ADC_PfuncCallBack();
	}
}
