/*
 * ADC_priv.h
 *
 *  Created on: Sep 25, 2021
 *      Author: amrmo
 */

#ifndef MCAL_ADC_ADC_PRIV_H_
#define MCAL_ADC_ADC_PRIV_H_

/* ADC Multiplexer Selection Register */
#define ADMUX 				*((volatile u8*) 0x27)
#define RIGHT_ADJ					0
#define LEFT_ADJ					1

#define ADLAR_BIT					5

#define AVCC						1
#define AREF						0
#define INTERNAL_AREF				3

#define REFS_BITS					6
/* ADC Control and Status Register A */
#define ADCSRA 				*((volatile u8*) 0x26)
#define ADEN_BIT					7
#define ADSC_BIT					6
#define ADATE_BIT					5
#define ADIF_BIT					4
#define ADIE_BIT					3
	// Values That ADC Prescaler Selection Bits May Have
#define PRE_TWO						0
#define PRE_FOUR					2
#define PRE_EIGHT					3
#define PRE_SIXTEEN					4
#define PRE_THIRTY_TWO				5
#define PRE_SIXTY_FOUR				6
#define PRE_ONE_TWENTY_EIGHT		7

/* ADCH and ADCL Register for the Adjustment Detected By ADLAR in ADMUX */
#define ADC_DATA_REGISTER 	*((volatile s16*) 0x24)

/* Special FunctionIO Register */
#define SFIOR 				*((volatile u8*) 0x50)
#define ADTS_BITS					5
/* Status Register */
#define SREG  				*((u8*) 0x5F)
#define L_BIT						7

#define INITIAL_VALUE				0

#define BIT_MASK					1

#define ADC_ISR		void __vector_16(void) __attribute__((signal, used));\
					void __vector_16(void)

#endif /* MCAL_ADC_ADC_PRIV_H_ */
