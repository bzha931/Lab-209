/*
 * timer0.h
 *
 * Created: 20/09/2026 4:10:44 pm
 *  Author: bohan
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include <stdbool.h>
#include <stdint.h>

void timer0_init();

uint8_t timer0_check_clear_compare();

#endif /* TIMER0_H_ */