
// *************************************************************************
//  @brief		Functions for controlling the PC9555 chips
// 				
//
//
//
//
//
// *************************************************************************


#include <inttypes.h>
#include <compat/twi.h>

#include "pca9555.h"
#include <Wire.h>
#include "Marlin.h"
#include "pins.h"

// define register offsets
#define REG_IN 0
#define REG_OUT 2
#define REG_POL 4
#define REG_DIR 6
#define I2C_ADDR 8

/** variable, holding the boards PCA9555-data **/
// holds also default values at start
volatile uint8_t i2cPortBuf[NUM_OF_I2C_EXPANDERS][9] = {	
	//	inL, 	inH, 	outL, 	outH, 	polL, 	polH, 	dirL, 	dirH,addr 	
		 {0, 	0, 		255, 	0, 		0, 		0, 		0,    127, 	64},	    // Device 1 (L: Mot1+2, H: ExternalPort)
		 {0, 	0, 		255,  255, 		0, 		0, 		0, 		0, 	68}		// Device 2 (L: Mot5+6, H: Mot3+4)
		 };	
	
/***********
@brief Initialize all PCA9555-devices
***********/
void init_PCA9555()
{	
	//init i2c 
	Wire.begin();

	for(int i =0; i < NUM_OF_I2C_EXPANDERS; i++)	// only 2 expanders in echinus 
	{		
		Wire.beginTransmission(i2cPortBuf[i][I2C_ADDR]);  //output register
		Wire.write(REG_OUT);
		Wire.write(i2cPortBuf[i][REG_OUT]);
		Wire.write(i2cPortBuf[i][REG_OUT+1]);
		Wire.endTransmission();
		
		Wire.beginTransmission(i2cPortBuf[i][I2C_ADDR]);  //polaritiy register
		Wire.write(REG_POL);
		Wire.write(i2cPortBuf[i][REG_POL]);
		Wire.write(i2cPortBuf[i][REG_POL+1]);
		Wire.endTransmission();

		Wire.beginTransmission(i2cPortBuf[i][I2C_ADDR]);   //direction register
		Wire.write(REG_DIR);
		Wire.write(i2cPortBuf[i][REG_DIR]);
		Wire.write( i2cPortBuf[i][REG_DIR+1]);
		Wire.endTransmission();
	}	
}

void write_i2c(uint8_t reg, uint16_t pin, uint8_t value)
{
	uint8_t highbyte =0;
	
	//extract i2c data
	uint8_t chipnum = (pin & I2C_CHIPNUMMASK) >> I2C_CHIPNUMOFFSET;
	uint8_t chipaddr = i2cPortBuf[chipnum][I2C_ADDR];
	uint16_t bit = pin & I2C_BITMASK;
    
	//find out if bit is in high or low byte
	if(bit & 0xff00)
		highbyte =1;
		
	if( value != 0)
	{
		// check if bit is not already set
		if(	i2cPortBuf[chipnum][reg+highbyte] & bit)
			return;
			
		//set bit in bufer
		if(highbyte)
			i2cPortBuf[chipnum][reg] |= (1<< (bit>>8));
		else
			i2cPortBuf[chipnum][reg+highbyte] |= (1<< bit);
	}
	else
	{
		// check if bit is not already set
		if(	!(i2cPortBuf[chipnum][reg+highbyte] & bit))
			return;
			
		//set bit in bufer
		if(highbyte)
			i2cPortBuf[chipnum][reg] &= ~(1<< (bit>>8));
		else
			i2cPortBuf[chipnum][reg+highbyte] &= ~(1<< bit);	
	}
		
	//send over i2c
	Wire.beginTransmission(chipaddr);
	Wire.write(reg+highbyte);
	Wire.write(i2cPortBuf[chipnum][reg+highbyte]);
	Wire.endTransmission();
}

void setoutput_PCA9555(uint16_t pin)
{
	write_i2c(pin,REG_DIR,1);
}

void setinput_PCA9555(uint16_t pin)
{
 	write_i2c(pin,REG_DIR,0);
}

void write_PCA9555(uint16_t pin, uint8_t value)
{
	write_i2c(pin,REG_OUT,value);
}


uint8_t read_PCA9555(uint16_t pin)
{
	uint8_t highbyte =0;
  //extract i2c data
	uint8_t chipnum = (pin & I2C_CHIPNUMMASK) >> I2C_CHIPNUMOFFSET;
	uint8_t chipaddr = i2cPortBuf[chipnum][I2C_ADDR];
	uint16_t bit = pin & I2C_BITMASK;
    
	//find out if bit is in high or low byte
	if(bit & 0xff00)
		highbyte =1;

	//TODO update buffer from i2c ?
		
	// check if bit is set in buffer
	if(	i2cPortBuf[chipnum][REG_IN+highbyte] & bit)
		return true;
	else
		return false;	
}

uint8_t read_PCA9555_inputs()
{
	uint8_t inputs[2];
	uint8_t i=0;
	
	// inputs are on chip 1 - highbyte
	Wire.requestFrom(i2cPortBuf[0][I2C_ADDR],(uint8_t) 2);
	while(Wire.available())    // slave may send less than requested
	{
		inputs[i] = Wire.read();    // receive a byte as character
		i++;
		if(i > 1)
			break;
	}
	
	//TODO update internal buffer ?
	
	return inputs[1];	
}