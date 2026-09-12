/*
 * uart.c
 *
 * Created: 12/09/2026 6:23:54 pm
 *  Author: bohan
 */ 
#include <avr/io.h>
#include <stdint.h>
#include "uart.h"

void usart_init(uint16_t ubrr) {
	UBRR0H = (uint8_t)(ubrr >> 8);
	UBRR0L = (uint8_t)ubrr;
	UCSR0A = 0;
	UCSR0B = (1 << TXEN0);                  
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); 
}

void usart_transmit(uint8_t data) {
	while (!(UCSR0A & (1 << UDRE0)));
	UDR0 = data;
}


void usart_send_string(const char* str) {
	while (*str) {
		usart_transmit(*str++);
	}
}


void usart_send_number(uint16_t num) {
	char buf[6];
	int8_t i = 0;
	
	if (num == 0) {
		usart_transmit('0');
		return;
	}
	
	while (num > 0) {
		buf[i++] = (num % 10) + '0';
		num /= 10;
	}
	
	while (--i >= 0) {
		usart_transmit(buf[i]);
	}
}