/*
 * CFile1.c
 *
 * Created: 12/09/2026 2:25:39 pm
 *  Author: bohan
 */ 
#include "common.h"
#include "adc.h"
#include <avr/io.h>


void adc_init() {
	ADMUX = 0b01000010;
	ADCSRA = 0b10000100;
	ADCSRB = 0b00000000;
	DIDR0 = 0b00000000;
}

uint16_t adc_read(uint8_t chan){
	ADMUX = (ADMUX & 0b11110000) | (chan & 0b00000111);
	 
	ADCSRA |= (1 << ADSC);
	 while (ADCSRA & (1 << ADSC))
	 {
	 }
	 return ADC;
}
uint16_t adc_convert_mv(uint16_t raw_value){
	uint32_t voltage_mv = ((uint32_t)raw_value * 5000UL) /1024UL;
	
	return (uint16_t)voltage_mv;
}