/*
 * LM35_int.h
 *
 *  Created on: Oct 9, 2021
 *      Author: amrmo
 */

#ifndef HAL_LM35_LM35_INT_H_
#define HAL_LM35_LM35_INT_H_

ES_t LM35_enuInit(void);

ES_t LM35_enuReadSignal(s16 *Copy_u16ADCSignal1, s16 *Copy_u16ADCSignal2);

ES_t LM35_enuGetTempValue(s16 _Copy_u16ADCSignal1, s16 _Copy_u16ADCSignal2);

ES_t LM35_enuCallingForInterrupt(void (*Copy_PfuncCallBack) (void));

#endif /* HAL_LM35_LM35_INT_H_ */
