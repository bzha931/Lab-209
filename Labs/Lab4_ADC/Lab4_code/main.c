/*
 * Lab4_code.c
 *
 * Created: 12/09/2026 2:22:57 pm
 * Author : bohan
 */ 
#define F_CPU 2000000UL
#define BAUD 9600UL
#define UBRR_VALUE ((F_CPU / (16UL * BAUD)) - 1)

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include "adc.h"
#include "uart.h"

#define SAMPLES 40


int main(void)
{
    /* Replace with your application code */
	adc_init();
	usart_init(UBRR_VALUE);
	
	uint16_t adc0_mv[SAMPLES];
	uint16_t adc1_mv[SAMPLES];
	
    while (1) 
    {
		for (uint8_t i = 0; i < SAMPLES; i++) {
			adc0_mv[i] = adc_convert_mv(adc_read(0));
			adc1_mv[i] = adc_convert_mv(adc_read(1));
			_delay_ms(1);
    }
	
	usart_send_string("ADC0(mV),ADC1(mV)\r\n");
	
	for (uint8_t i = 0; i < SAMPLES; i++) {
		usart_send_number(adc0_mv[i]);
		usart_transmit(',');
		usart_send_number(adc1_mv[i]);
		usart_send_string("\r\n");
	}
	
	_delay_ms(2000);
	}
	return 0;
}

