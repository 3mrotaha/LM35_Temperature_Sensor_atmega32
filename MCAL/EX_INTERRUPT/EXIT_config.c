/*
 * EXIT_config.c
 *
 *  Created on: Sep 25, 2021
 *      Author: amrmo
 */


#include "../../LIB/std_Types.h"
#include "../../LIB/ErrorStates.h"

#include "EXIT_config.h"
#include "EXIT_priv.h"

EXTI_t EXTI_AstrEXTIConfig [3] =
{
		{ACTIVE, FALLING_EDGE},
		{DEACTIVE},
		{DEACTIVE}
};
