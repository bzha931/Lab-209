/*
 * IncFile1.h
 *
 * Created: 11/08/2026 4:33:27 PM
 *  Author: bzha931
 */ 


#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#include <stdint.h>

void usart_init(uint16_t ubrr);



void usart_transmit(uint8_t data);

#endif