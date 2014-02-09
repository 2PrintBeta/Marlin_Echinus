#ifndef _PCA9555_H_
#define _PCA9555_H_

#include <avr/io.h>

void init_PCA9555 () __attribute__ ((cold));
void write_PCA9555(uint16_t pin, uint8_t value);
uint8_t read_PCA9555(uint16_t pin);
void setoutput_PCA9555(uint16_t pin);
void setinput_PCA9555(uint16_t pin);
uint8_t read_PCA9555_inputs();

#endif




