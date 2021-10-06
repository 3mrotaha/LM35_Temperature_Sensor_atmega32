/*
 * EXIT_prog.c
 *
 *  Created on: Sep 25, 2021
 *      Author: amrmo
 */

#include "../../LIB/std_Types.h"
#include "../../LIB/ErrorStates.h"

#include "EXIT_config.h"
#include "EXIT_priv.h"

#include "../interrupt.h"

static volatile void (*EXTI_ApfunINTFun[3])(void*) = {NULL,NULL,NULL};

void * EXTI_ApvidGenericparameter[3] = {NULL,NULL,NULL};

ES_t EXTI_enuInit (EXTI_t * Copy_pstrEXTIConfig)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_pstrEXTIConfig != NULL)
	{
		u8 Local_u8Iter=0;
		for (Local_u8Iter =0; Local_u8Iter < 3 ; Local_u8Iter++)
		{
			if (Copy_pstrEXTIConfig[Local_u8Iter].EXTI_u8State == ACTIVE)
			{
				switch(Local_u8Iter)
				{
				case 0:
					MCUCR &=~ (3<<0);
					GICR |= (1<<6);
					switch (Copy_pstrEXTIConfig[Local_u8Iter].EXTI_u8SenceLevel)
					{
					case RISING_EDGE:
						MCUCR |= (3<<0);
						break;
					case FALLING_EDGE:
						MCUCR |= (1<<1);
						break;
					case ANY_LOGIC:
						MCUCR |= (1<<0);
						break;
					case LOW_LEVEL:
						break;
					default:
						Local_enuErrorState = ES_COMPONENT_OUT_OF_RANGE;
					}
					break;


					case 1:
						MCUCR &=~ (3<<2);
						GICR |= (1<<7);
						switch (Copy_pstrEXTIConfig[Local_u8Iter].EXTI_u8SenceLevel)
						{
						case RISING_EDGE:
							MCUCR |= (3<<2);
							break;
						case FALLING_EDGE:
							MCUCR |= (1<<3);
							break;
						case ANY_LOGIC:
							MCUCR |= (1<<2);
							break;
						case LOW_LEVEL:
							break;
						default:
							Local_enuErrorState = ES_COMPONENT_OUT_OF_RANGE;
						}

						break;
						case 2:
							MCUCSR &=~(1<<6);
							GICR |= (1<<5);
							switch (Copy_pstrEXTIConfig[Local_u8Iter].EXTI_u8SenceLevel)
							{
							case RISING_EDGE:
								MCUCSR |= (1<<6);
								break;
							case FALLING_EDGE:
								break;
							default:
								Local_enuErrorState = ES_COMPONENT_OUT_OF_RANGE;
							}
							break;
				}

			}
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}

ES_t EXTI_enuSetSenceMode(u8 Copy_u8EXTI_ID , u8 Copy_u8SenseLevel)
{
	ES_t Local_enuErrorState = ES_NOK;

	if (Copy_u8EXTI_ID < 3)
	{
		if (Copy_u8EXTI_ID ==0)
		{
			MCUCR &=~ (3<<0);
			switch (Copy_u8SenseLevel)
			{
			case RISING_EDGE:
				MCUCR |= (3<<0);
				break;
			case FALLING_EDGE:
				MCUCR |= (1<<1);
				break;
			case ANY_LOGIC:
				MCUCR |= (1<<0);
				break;
			case LOW_LEVEL:
				break;
			default:
				Local_enuErrorState = ES_COMPONENT_OUT_OF_RANGE;
			}
		}
		else if (Copy_u8EXTI_ID ==1)
		{
			MCUCR &=~ (3<<2);
			switch (Copy_u8SenseLevel)
			{
			case RISING_EDGE:
				MCUCR |= (3<<2);
				break;
			case FALLING_EDGE:
				MCUCR |= (1<<3);
				break;
			case ANY_LOGIC:
				MCUCR |= (1<<2);
				break;
			case LOW_LEVEL:
				break;
			default:
				Local_enuErrorState = ES_COMPONENT_OUT_OF_RANGE;
			}
		}
		else if (Copy_u8EXTI_ID ==2)
		{
			MCUCSR &=~(1<<6);
			switch (Copy_u8SenseLevel)
			{
			case RISING_EDGE:
				MCUCSR |= (1<<6);
				break;
			case FALLING_EDGE:
				break;
			default:
				Local_enuErrorState = ES_COMPONENT_OUT_OF_RANGE;
			}
		}
	}

	return Local_enuErrorState;
}


ES_t EXTI_enuEnableINT(u8 Copy_u8EXTI_ID)
{
	ES_t Local_enuErrorState = ES_NOK;

	if (Copy_u8EXTI_ID < 3)
	{
		if (Copy_u8EXTI_ID ==0)
		{
			GICR |= (1<<6);
		}
		else if (Copy_u8EXTI_ID ==1)
		{
			GICR |= (1<<7);
		}
		else if (Copy_u8EXTI_ID ==2)
		{
			GICR |= (1<<5);
		}
	}

	return Local_enuErrorState;
}

ES_t EXTI_enuDisableINT(u8 Copy_u8EXTI_ID)
{
	ES_t Local_enuErrorState = ES_NOK;

	if (Copy_u8EXTI_ID < 3)
	{
		if (Copy_u8EXTI_ID ==0)
		{
			GICR &=~(1<<6);
		}
		else if (Copy_u8EXTI_ID ==1)
		{
			GICR &=~(1<<7);
		}
		else if (Copy_u8EXTI_ID ==2)
		{
			GICR &=~(1<<5);
		}
	}

	return Local_enuErrorState;
}


ES_t EXTI_enuCallBack(void (*Copy_pfunAppFun)(void*) ,void * Copy_pvidParameter , u8 Copy_u8EXTI_ID)
{
	ES_t Local_enuErrorState = ES_NOK;

	if (Copy_pfunAppFun != NULL && Copy_u8EXTI_ID <3)
	{
		EXTI_ApfunINTFun[Copy_u8EXTI_ID] = Copy_pfunAppFun;
		EXTI_ApvidGenericparameter[Copy_u8EXTI_ID] = Copy_pvidParameter;
	}

	return Local_enuErrorState;
}



ISR(VECT_INT0)
{
	if (EXTI_ApfunINTFun[0] != NULL)
	{
		EXTI_ApfunINTFun[0] (EXTI_ApvidGenericparameter[0]);
	}
}

ISR(VECT_INT1)
{
	if (EXTI_ApfunINTFun[1] != NULL)
	{
		EXTI_ApfunINTFun[1] (EXTI_ApvidGenericparameter[1]);
	}
}

ISR(VECT_INT2)
{
	if (EXTI_ApfunINTFun[2] != NULL)
	{
		EXTI_ApfunINTFun[2] (EXTI_ApvidGenericparameter[2]);
	}
}
