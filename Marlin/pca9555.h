#ifndef _PCA9555_H_
#define _PCA9555_H_

#include <avr/io.h>

typedef struct							/** struct for the software-mirror of PCA9555- devices **/
{
	uint8_t inRegL;						// status of input is saved here, when dirReg-pin is set (in)
	uint8_t inRegH;						// status of input is saved here, when dirReg-pin is set (in)
	uint8_t outRegL;					// when written to 1 and dirReg-pin is cleared (out), the pin is set
	uint8_t outRegH;					// when written to 1 and dirReg-pin is cleared (out), the pin is set
	uint8_t polRegL;					// when written to 1, the pin-polarity is inverted
	uint8_t polRegH;					// when written to 1, the pin-polarity is inverted
	uint8_t dirRegL;					// when written to 1, pin is input
	uint8_t dirRegH;					// when written to 1, pin is input
	uint8_t i2cAddr;					// Adress of the device
}tPCA9555_Set;

uint8_t init_PCA9555 () __attribute__ ((cold));

void setoutput_PCA9555(uint16_t i);
void setinput_PCA9555(uint16_t pin);  
void write_PCA9555(uint16_t i,uint8_t v);  
uint8_t read_PCA9555_inputs();

#endif





