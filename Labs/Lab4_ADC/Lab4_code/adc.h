/*
 * adc.h
 *
 * Created: 12/09/2026 2:26:54 pm
 *  Author: bohan
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>

void adc_init();
uint16_t adc_read(uint8_t chan);


#endif /* ADC_H_ */