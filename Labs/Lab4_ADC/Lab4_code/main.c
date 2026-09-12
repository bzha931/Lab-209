/*
 * Lab4_code.c
 *
 * Created: 12/09/2026 2:22:57 pm
 * Author : bohan
 */ 

#include <avr/io.h>
#include "adc.h"
#include "common.h"
#include <util/delay.h>


int main(void)
{
    /* Replace with your application code */
	adc_init();
	
	volatile uint16_t raw_adc = 0;
	volatile uint16_t voltage_mv = 0;
	
    while (1) 
    {
		raw_adc = adc_read(2);
		voltage_mv = adc_convert_mv(raw_adc);
		_delay_ms(1);
    }
	return 0;
}

