/*
 * EXIT_config.h
 *
 *  Created on: Sep 25, 2021
 *      Author: amrmo
 */

#ifndef MCAL_EX_INTERRUPT_EXIT_CONFIG_H_
#define MCAL_EX_INTERRUPT_EXIT_CONFIG_H_


/*Set the Number of Interrupt you Can Use In the Project*/
#define EXINT_NUM	3

typedef struct
{
	u8 EXTI_u8State;
	u8 EXTI_u8SenceLevel;
}EXTI_t;




#endif /* MCAL_EX_INTERRUPT_EXIT_CONFIG_H_ */
