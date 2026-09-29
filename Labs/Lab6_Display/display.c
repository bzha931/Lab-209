/*
 * Lab6_part2.c
 *
 * Created: 29/09/2026 7:23:31 pm
 * Author : bohan
 */ 

#include "display.h"
#include <avr/io.h>


const uint8_t seg_pattern[10] = {
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
static volatile uint8_t disp_characters[4] = {0, 0, 0, 0};

// ?????????? (0=Ds1, 1=Ds2, 2=Ds3, 3=Ds4)[cite: 9]
static volatile uint8_t disp_position = 0;

// ???????[cite: 7, 9]
void init_display(void) {
	// ?? PC3(SH_CP), PC4(SH_DS), PC5(SH_ST) ???
	DDRC |= (1 << PORTC3) | (1 << PORTC4) | (1 << PORTC5);
	
	// ?? PD4(Ds1), PD5(Ds2), PD6(Ds3), PD7(Ds4) ???[cite: 5, 7]
	DDRD |= (1 << PORTD4) | (1 << PORTD5) | (1 << PORTD6) | (1 << PORTD7);
	
	// ??????????? (?????1)[cite: 7]
	PORTD |= (1 << PORTD4) | (1 << PORTD5) | (1 << PORTD6) | (1 << PORTD7);
	
	// ????????????????[cite: 7]
	PORTC &= ~((1 << PORTC3) | (1 << PORTC4) | (1 << PORTC5));
}

// ?????????[cite: 8, 9]
void seperate_and_load_characters(uint16_t number, uint8_t decimal_pos) {
	// 1. ?????????????[cite: 9]
	uint8_t thousands = (number / 1000) % 10;
	uint8_t hundreds  = (number / 100) % 10;
	uint8_t tens      = (number / 10) % 10;
	uint8_t units     = number % 10;
	
	// 2. ???????? disp_characters ??[cite: 9]
	disp_characters[0] = seg_pattern[thousands]; // Ds1
	disp_characters[1] = seg_pattern[hundreds];  // Ds2
	disp_characters[2] = seg_pattern[tens];      // Ds3
	disp_characters[3] = seg_pattern[units];     // Ds4
	
	// 3. ??????? decimal_pos ? 1~4?????????? (0x80)[cite: 8, 9]
	if (decimal_pos >= 1 && decimal_pos <= 4) {
		disp_characters[decimal_pos - 1] |= 0x80;
	}
}

// ??????????????[cite: 8, 9]
void send_next_character_to_display(void) {
	// 1. ??????????[cite: 9]
	uint8_t pattern = disp_characters[disp_position];
	
	// 2. ?? 74HC595 ???? 8 ???????? MSB ???[cite: 8, 9]
	for (int8_t i = 7; i >= 0; i--) {
		// ????? SH_DS (PC4)
		if (pattern & (1 << i)) {
			PORTC |= (1 << PORTC4);
			} else {
			PORTC &= ~(1 << PORTC4);
		}
		
		// ?????? SH_CP (PC3): 0 -> 1 -> 0
		PORTC |= (1 << PORTC3);
		PORTC &= ~(1 << PORTC3);
	}
	
	// 3. ??????????????????????[cite: 7, 9]
	PORTD |= (1 << PORTD4) | (1 << PORTD5) | (1 << PORTD6) | (1 << PORTD7);
	
	// 4. ?????? SH_ST (PC5): 0 -> 1 -> 0??????????[cite: 5, 8, 9]
	PORTC |= (1 << PORTC5);
	PORTC &= ~(1 << PORTC5);
	
	// 5. ?????????????????[cite: 7, 9]
	switch (disp_position) {
		case 0: PORTD &= ~(1 << PORTD4); break; // ?? Ds1[cite: 5, 7, 9]
		case 1: PORTD &= ~(1 << PORTD5); break; // ?? Ds2[cite: 5, 7, 9]
		case 2: PORTD &= ~(1 << PORTD6); break; // ?? Ds3[cite: 5, 7, 9]
		case 3: PORTD &= ~(1 << PORTD7); break; // ?? Ds4[cite: 5, 7, 9]
	}
	
	// 6. ??????????? (0->1->2->3->0)[cite: 8, 9]
	disp_position++;
	if (disp_position > 3) {
		disp_position = 0; // ?4???[cite: 9]
	}
}