/*
 * Lab5_code.c
 *
 * Created: 20/09/2026 4:06:46 pm
 * Author : bohan
 */ 
#define F_CPU 2000000UL

#include "timer0.h"
#include "led.h"

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
    /* Replace with your application code */
		DDRB = 0XFF;
		DDRC = 0X00;
		DDRD = 0X00;
	timer0_init();
	sei();
    while (1) 
    {
		
    }
}

