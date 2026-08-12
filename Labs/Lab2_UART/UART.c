/*
 * CFile1.c
 *
 * Created: 11/08/2026 4:33:34 PM
 *  Author: bzha931
 */ 
#include "UART.h"

void usart_init(uint16_t ubrr){
	UBRR0H = (uint8_t)(ubrr >> 8);
	UBRR0L = (uint8_t)ubrr;

	UCSR0B = (1 << TXEN0);
	//transmitter enable
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
	//8 data bits
}

void usart_transmit(uint8_t data){
	while (!(UCSR0A & (1 << UDRE0)));
	UDR0 = data;

}