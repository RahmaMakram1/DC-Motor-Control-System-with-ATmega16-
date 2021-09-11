
#include "ADC.h"

void ADC_Init(void)
{
	/*select the voltage reference for the ADC by setting the Reference Selection Bits REFS1=0 REFS0=0
	 * 1-to work with voltage: AREF, Internal Vref turned off
	 * 2-MUX4:0: Analog Channel and Gain Selection Bits to work with channel ADC0>> MUX4:0=0000*/
	ADMUX=0;
	/*Configure the ADC control and status register ADCSRA
	 * 1-Writing the ADEN bit to one to enable the ADC
	 * 2-Disable the ADC interrupt by clearing the bit ADIE: ADC Interrupt Enable
	 * 3-ADC Pre-scalar Select Bits ADPS2=0 ADPS1=1 ADPS0=1
	 *  to provide the ADC with with a clock source of frequency=F_CPU/8*/
	ADCSRA|= (1<<ADEN) | (1<<ADPS1) | (1<<ADPS0);
}

uint16 ADC_readChannel(uint8 channelNumber){
	/*Ensure that the channel number is in the range 0 - 7, because those are the only channels existing in the AVR ATmega16 MCU*/


	/*first 5 bits in ADMUX register MUX4:0: Analog Channel and Gain Selection Bits to work with channelNumber*/
	ADMUX=(ADMUX&0b11100000)|(channelNumber&00011111);

	/*Start conversion set the bit ADSC to 1*/
	ADCSRA|=(1<<ADSC);

	/*wait for conversion to complete and the ADC interrupt flag bit ADIF becomes 1*/
	/*؛Polling*/
	while(BIT_IS_CLEAR(ADCSRA,ADIF));

	/*When conversion has completed, clear the flag bit by writing 1 in it*/
	ADCSRA|=(1<<ADIF);

	/*Return the data that has been read by the ADC*/
	return ADC;
}
