/*
 * APP_config.h
 *
 *  Created on: Sep 25, 2021
 *      Author: amrmo
 */

#ifndef APP_APP_CONFIG_H_
#define APP_APP_CONFIG_H_


/* USE One Channel Of Range :
 *
 *	  	ADC_enuSingleEndedChannel0
 *    	ADC_enuSingleEndedChannel1
 *    	ADC_enuSingleEndedChannel2
 *    	ADC_enuSingleEndedChannel3
 *    	ADC_enuSingleEndedChannel4
 *    	ADC_enuSingleEndedChannel5
 *    	ADC_enuSingleEndedChannel6
 *    	ADC_enuSingleEndedChannel7
 *
 *    	// GAIN x10
 *    	ADC_enuDifferentialChannel00_x10
 *    	ADC_enuDifferentialChannel10_x10
 *
 *    	// GAIN x200
 *    	ADC_enuDifferentialChannel00_x200
 *    	ADC_enuDifferentialChannel10_x200
 *
 *    	// GAIN x10
 *    	ADC_enuDifferentialChannel22_x10
 *    	ADC_enuDifferentialChannel32_x10
 *
 *    	// GAIN x200
 *    	ADC_enuDifferentialChannel22_x200
 *    	ADC_enuDifferentialChannel32_x200
 *
 *    	// GAIN x1
 *    	ADC_enuDifferentialChannel01_x1
 *    	ADC_enuDifferentialChannel11_x1
 *    	ADC_enuDifferentialChannel21_x1
 *    	ADC_enuDifferentialChannel31_x1
 *    	ADC_enuDifferentialChannel41_x1
 *    	ADC_enuDifferentialChannel51_x1
 *    	ADC_enuDifferentialChannel61_x1
 *    	ADC_enuDifferentialChannel71_x1
 *    	ADC_enuDifferentialChannel02_x1
 *    	ADC_enuDifferentialChannel12_x1
 *    	ADC_enuDifferentialChannel22_x1
 *    	ADC_enuDifferentialChannel32_x1
 *    	ADC_enuDifferentialChannel42_x1
 *    	ADC_enuDifferentialChannel52_x1
 *
 */
#define SENSOR_POS_CHANNEL		ADC_enuSingleEndedChannel1
#define SENSOR_NEG_CHANNEL		ADC_enuSingleEndedChannel2


#endif /* APP_APP_CONFIG_H_ */
