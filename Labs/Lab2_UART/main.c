#define F_CPU 2000000UL
#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>
#include <util/delay.h>
#include "UART.h"


int main(void)
{
	uint16_t primeArray[62];
	uint16_t count = 0;

	for (uint16_t n = 2; n <= 300; n++){
		bool if_prime = true;

		for (uint16_t i = 2; i*i <= n; i++){
			if (n % i == 0){
				if_prime = false;
				break;
			}
		}
		if (if_prime) {
			primeArray[count] = n;
			count++;
		}
	}

	usart_init(12);

	
	while (1)
	{
		for (uint16_t i = 0; i < count; i++) {
			uint16_t num = primeArray[i];

			
			uint8_t hundred = (num / 100) + 48;
			uint8_t ten = ((num / 10) % 10) + 48;
			uint8_t one = (num % 10) + 48;
		
			usart_transmit(hundred);
			usart_transmit(ten);
			usart_transmit(one);
		
			usart_transmit(',');
			usart_transmit(' ');
			_delay_ms(500);
		}
	}
}