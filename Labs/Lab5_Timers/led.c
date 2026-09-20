/*
 * led.c
 *
 * Created: 20/09/2026 5:11:45 pm
 *  Author: bohan
 */ 

#include "led.h"

#include <avr/io.h>

void led_toggle(){
	//TODO: LED toggle code
	PINB = (1 << PINB5);
}