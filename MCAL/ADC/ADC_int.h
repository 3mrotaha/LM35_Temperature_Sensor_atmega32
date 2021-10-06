/*
 * ADC_int.h
 *
 *  Created on: Sep 25, 2021
 *      Author: amrmo
 */

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_


ES_t ADC_enuInit(void);


ES_t ADC_enuADCEnable(void);


ES_t ADC_enuADCDisable(void);


ES_t ADC_enuSelectChannel(ADC_Channel Copy_u8Channel);

ES_t ADC_enuStartConversion(void);


ES_t ADC_enuWaitOnFlag(void);


ES_t ADC_enuReadADCValue(volatile u16* Copy_u16ADCValue);

ES_t ADC_enuEnableAutoTrigger(void);

ES_t ADC_enuDisableAutoTrigger(void);

ES_t ADC_InterruptEnable(void);

ES_t ADC_InterruptDisable(void);

ES_t ADC_InterruptCallBack(void (*Copy_PfuncCallBack) (void));


#endif /* MCAL_ADC_ADC_INT_H_ */
