/*
 * EXIT_int.h
 *
 *  Created on: Sep 25, 2021
 *      Author: amrmo
 */

#ifndef MCAL_EX_INTERRUPT_EXIT_INT_H_
#define MCAL_EX_INTERRUPT_EXIT_INT_H_

ES_t EXTI_enuInit (EXTI_t * Copy_pstrEXTIConfig);

ES_t EXTI_enuSetSenceMode(u8 Copy_u8EXTI_ID , u8 Copy_u8SenseLevel);

ES_t EXTI_enuEnableINT(u8 Copy_u8EXTI_ID);

ES_t EXTI_enuDisableINT(u8 Copy_u8EXTI_ID);

ES_t EXTI_enuCallBack(void (*Copy_pfunAppFun)(void*), void * Copy_pvidParameter , u8 Copy_u8EXTI_ID);


#endif /* MCAL_EX_INTERRUPT_EXIT_INT_H_ */
