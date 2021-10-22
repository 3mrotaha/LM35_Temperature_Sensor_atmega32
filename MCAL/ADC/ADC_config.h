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


/*
 * Range :
 *
 * SINGLE_ENDED_MODE
 * DEFERENTIAL_MODE
 *
 * */
#define SELECT_ADC_MODE		SINGLE_ENDED_MODE

/*This Enum Is Used To Select Channel In Function ADC_enuSelectChannel();*/
typedef enum{

	ADC_enuSingleEndedChannel0,
	ADC_enuSingleEndedChannel1,
	ADC_enuSingleEndedChannel2,
	ADC_enuSingleEndedChannel3,
	ADC_enuSingleEndedChannel4,
	ADC_enuSingleEndedChannel5,
	ADC_enuSingleEndedChannel6,
	ADC_enuSingleEndedChannel7,

	// GAIN x10
	ADC_enuDifferentialChannel00_x10,  //01000 ADC0 ADC0 10x
	ADC_enuDifferentialChannel10_x10,  //01001 ADC1 ADC0 10x

	// GAIN x200
	ADC_enuDifferentialChannel00_x200, //01010 ADC0 ADC0 200x
	ADC_enuDifferentialChannel10_x200, //01011 ADC1 ADC0 200x

	// GAIN x10
	ADC_enuDifferentialChannel22_x10,  //01100 ADC2 ADC2 10x
	ADC_enuDifferentialChannel32_x10,  //01101 ADC3 ADC2 10x

	// GAIN x200
	ADC_enuDifferentialChannel22_x200, //01110 ADC2 ADC2 200x
	ADC_enuDifferentialChannel32_x200, //01111 ADC3 ADC2 200x

	// GAIN x1
	ADC_enuDifferentialChannel01_x1,   //10000 ADC0 ADC1 1x
	ADC_enuDifferentialChannel11_x1,   //10001 ADC1 ADC1 1x
	ADC_enuDifferentialChannel21_x1,   //10010 ADC2 ADC1 1x
	ADC_enuDifferentialChannel31_x1,   //10011 ADC3 ADC1 1x
	ADC_enuDifferentialChannel41_x1,   //10100 ADC4 ADC1 1x
	ADC_enuDifferentialChannel51_x1,   //10101 ADC5 ADC1 1x
	ADC_enuDifferentialChannel61_x1,   //10110 ADC6 ADC1 1x
	ADC_enuDifferentialChannel71_x1,   //10111 ADC7 ADC1 1x
	ADC_enuDifferentialChannel02_x1,   //11000 ADC0 ADC2 1x
	ADC_enuDifferentialChannel12_x1,   //11001 ADC1 ADC2 1x
	ADC_enuDifferentialChannel22_x1,   //11010 ADC2 ADC2 1x
	ADC_enuDifferentialChannel32_x1,   //11011 ADC3 ADC2 1x
	ADC_enuDifferentialChannel42_x1,   //11100 ADC4 ADC2 1x
	ADC_enuDifferentialChannel52_x1,   //11101 ADC5 ADC2 1x

}ADC_Channel;

#endif /* MCAL_ADC_ADC_CONFIG_H_ */
