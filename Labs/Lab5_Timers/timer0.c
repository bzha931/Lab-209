/*
 * timer0.c
 *
 * Created: 20/09/2026 5:09:35 pm
 *  Author: bohan
 */ 
#include "timer0.h"
#include "led.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

void timer0_init(){
	OCR0A = 77;
	TCCR0A = (1 << WGM01); //CTC mode 010
	TCCR0B = (1 << CS02); // Prescaler 256
	//TODO: initialise and configure timer0 to count to 10ms
}

uint8_t timer0_check_clear_compare(){
	if( TIFR0 & (1 << OCF0A )){ //TODO: check compare flag
		//TODO: clear compare flag.
		//Note: in datasheet this is done by writing 1 to the compare flag
		TIFR0 |= (1 << OCF0A);
		return 1;
	}
	return 0;
}