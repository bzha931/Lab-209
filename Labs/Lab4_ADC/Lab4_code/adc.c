#include <avr/io.h>
#include "adc.h"

void adc_init(void) {
	ADMUX = (1 << REFS0);
	ADCSRA = (1 << ADEN) | (1 << ADPS2); 
	ADCSRB = 0;
	DIDR0 = (1 << ADC0D) | (1 << ADC1D); 
}

uint16_t adc_read(uint8_t chan) {

	ADMUX = (ADMUX & 0xF0) | (chan & 0x0F);
	

	ADCSRA |= (1 << ADSC);
	

	while (ADCSRA & (1 << ADSC));
	
	return ADC;
}

uint16_t adc_convert_mv(uint16_t raw_value) {

	return (uint16_t)(((uint32_t)raw_value * 5000UL) / 1024UL);
}