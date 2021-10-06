/*
 * APP_int.h
 *
 *  Created on: Sep 25, 2021
 *      Author: amrmo
 */

#ifndef APP_APP_INT_H_
#define APP_APP_INT_H_

ES_t LM35_enuInit(void);

ES_t LM35_enuReadSignal(u16 *Copy_u16ADCSignal);

ES_t LM35_enuGetTempValue(u16 Copy_u16ADCSignal);

#endif /* APP_APP_INT_H_ */
