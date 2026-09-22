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

ISR(TIMER0_COMPA_vect){
	static uint8_t counter = 0;
	counter++;
	
	if(counter >= 10){
		led_toggle();
		counter = 0;
	}
}
void timer0_init(){
	OCR0A = 77;
	TCCR0A = (1 << WGM01); //CTC mode 010
	TCCR0B = (1 << CS02); // Prescaler 256
	//TODO: initialise and configure timer0 to count to 10ms
	TIMSK0 |= (1 << OCIE0A);
}