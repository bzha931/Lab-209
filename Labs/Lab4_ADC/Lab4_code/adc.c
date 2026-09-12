/*
 * CFile1.c
 *
 * Created: 12/09/2026 2:25:39 pm
 *  Author: bohan
 */ 
#include "common.h"
#include "adc.h"
#include <avr/io.h>
#include "uart.h"

void adc_init() {
	ADMUX = 0b01000010;
	ADCSRA = 0b10000100;
	ADCSRB = 0b00000000;
	DIDR0 = 0b00000000;
}

uint16_t adc_read(uint8_t chan){
	ADMUX = (ADMUX & 0b11110000) | (chan & 0b00000111);
	 
	ADCSRA = (1 << ADSC);
	 while (ADCSRA & (1 << ADSC))
	 {
	 }
	 return ADC;
}