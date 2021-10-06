/*
 * ADC_config.h
 *
 *  Created on: Sep 25, 2021
 *      Author: amrmo
 */

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_

/* Use PRE_(FACTOR) */
#define PRESCALLER	PRE_EIGHT

/*Use RIGHT_ADJ OR LEFT_ADJ*/
#define ADJUSTMENT	LEFT_ADJ

#define SELECT_REFERENCE	AVCC

/*This Enum Is Used To Select Channel In Function ADC_enuSelectChannel();*/
typedef enum{

	ADC_enuChannel0,
	ADC_enuChannel1,
	ADC_enuChannel2,
	ADC_enuChannel3,
	ADC_enuChannel4,
	ADC_enuChannel5,
	ADC_enuChannel6,
	ADC_enuChannel7

}ADC_Channel;

#endif /* MCAL_ADC_ADC_CONFIG_H_ */
