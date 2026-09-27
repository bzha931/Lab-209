#define F_CPU 2000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


volatile uint8_t count = 0;
volatile uint8_t digit_flag = 0;
uint16_t timer_ms = 0;

const uint8_t segment_codes[10] = {
	0x3F, // 0: 0b00111111
	0x06, // 1: 0b00000110
	0x5B, // 2: 0b01011011
	0x4F, // 3: 0b01001111
	0x66, // 4: 0b01100110
	0x6D, // 5: 0b01101101
	0x7D, // 6: 0b01111101
	0x07, // 7: 0b00000111
	0x7F, // 8: 0b01111111
	0x6F  // 9: 0b01101111
};

ISR(TIMER0_COMPA_vect){
	PORTB |= (1 << PB0) | (1 << PB1);
	
	uint8_t digit_value;
	
	if (digit_flag == 0)
	{
		digit_value = count / 10;
	} else{
		digit_value = count % 10;
	}
	
	uint8_t seg_now = segment_codes[digit_value];
	
	PORTC = seg_now & (0b00111111);
	
	if (seg_now & (0b01000000))
	{
		PORTB |= (1 << PB4);
	}else{
		PORTB &= ~(1 << PB4);
	}
	if (digit_flag == 0)
	{
		PORTB &= ~(1 << PB0);
		digit_flag = 1;
	}else{
		PORTB &= ~(1 << PB1);
		digit_flag = 0;
	}
}

int main(void) {
	DDRB &= ~(1 << PORTB7);
	DDRC = 0b00111111;
	DDRB |= (1 << PORTB0) | (1 << PORTB1) | (1 << PORTB4) | (1 << PORTB5);

	TCCR0A = (1 << WGM01);
	TCCR0B = (1 << CS02);
	OCR0A = 77;
	TIMSK0 |= (1 << OCIE0A);
	
	sei();
	
  while (1)
  {
	  _delay_ms(100);
	  timer_ms++;
	  
	  if (!(PINB & (1 << PORTB7))) {
		  count = 0;
		  timer_ms = 0;
		  
		  while (!(PINB & (1 << PORTB7)));
	  }
	  
	  if (timer_ms >= 10) {
		  timer_ms = 0;
		  
		  count++;
		  
		  if (count > 99) {
			  count = 0;
		  }
	  }
	  
  }
  }