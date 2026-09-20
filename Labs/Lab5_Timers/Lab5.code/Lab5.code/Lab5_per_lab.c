/*
 * Lab5.code.c
 *
 * Created: 20/09/2026 1:03:54 pm
 * Author : bohan
 */ 
#define F_CPU 2000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	DDRB = 0XFF;
	DDRC = 0X00;
	DDRD = 0X00;
    while (1) 
    {
		PORTB |= (1 << PORTB5);
		_delay_ms(375);
		PORTB &= ~(1 << PORTB5);
		_delay_ms(125);
    }
	return 0;
}

