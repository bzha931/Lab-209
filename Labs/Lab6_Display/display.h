/*
 * display.h
 *
 * Created: 29/09/2026 7:35:14 pm
 *  Author: bohan
 */ 


#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <avr/io.h>
#include <stdint.h>

void init_display(void);
void seperate_and_load_characters(uint16_t number, uint8_t decimal_pos);
void send_next_character_to_display(void);

#endif /* DISPLAY_H_ */