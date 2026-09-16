#ifndef UART_H_
#define UART_H_

#include <stdint.h>

void usart_init(uint16_t ubrr);
void usart_transmit(uint8_t data);
void usart_send_string(const char* str);
void usart_send_number(uint16_t num);

#endif /* UART_H_ */