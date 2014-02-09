
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

/** variable, holding the boards PCA9555-data **/
// holds also default values at start
volatile uint8_t i2cPortBuf[NUM_OF_I2C_EXPANDERS][8] = {	
	//	inL, 	inH, 	outL, 	outH, 	polL, 	polH, 	dirL, 	dirH, 	
		 {0, 	0, 		255, 	0, 		0, 		0, 		0,    127},	    // Device 1 (L: Mot1+2, H: ExternalPort)
		 {0, 	0, 		255,  255, 		0, 		0, 		0, 		0}		// Device 2 (L: Mot5+6, H: Mot3+4)
		 };	
	
/***********
@brief Initialize all PCA9555-devices
***********/
void init_PCA9555()
{	
	//init i2c 
	Wire.begin();
/*
	for(int i =0; i < NUM_OF_I2C_EXPANDERS; i++)	// only 2 expanders in echinus 
	{		
		Wire.beginTransmission(i2cPort[i].i2cAddr);  //output register
		Wire.write(REG_OUT);
		Wire.write(i2cPortBuf[i][REG_OUT]);
		Wire.write(i2cPortBuf[i][REG_OUT+1]);
		Wire.endTransmission();
		
		Wire.beginTransmission(i2cPort[i].i2cAddr);  //polaritiy register
		Wire.write(REG_POL);
		Wire.write(i2cPortBuf[i][REG_POL]);
		Wire.write(i2cPortBuf[i][REG_POL+1]);
		Wire.endTransmission();

		Wire.beginTransmission(i2cPort[i].i2cAddr);   //direction register
		Wire.write(REG_DIR);
		Wire.write(i2cPortBuf[i][REG_DIR]);
		Wire.write( i2cPortBuf[i][REG_DIR+1]);
		Wire.endTransmission();
	}	
	*/
}

void write_i2c(uint8_t reg, uint32_t pin, uint8_t value)
{
	uint8_t highbyte =0;
	
	//extract i2c data
	uint8_t chipaddr = (pin & I2C_ADDRMASK) >> I2C_ADDROFFSET;
	uint8_t chipnum = (pin & I2C_CHIPNUMMASK) >> I2C_CHIPNUMOFFSET;
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

void setoutput_PCA9555(uint32_t pin)
{
	write_i2c(pin,REG_DIR,1);
}

void setinput_PCA9555(uint32_t pin)
{
 	write_i2c(pin,REG_DIR,0);
}

void write_PCA9555(uint32_t pin, uint8_t value)
{
	write_i2c(pin,REG_OUT,value);
}


uint8_t read_PCA9555(uint32_t pin)
{
	uint8_t highbyte =0;
  //extract i2c data
	uint8_t chipaddr = (pin & I2C_ADDRMASK) >> I2C_ADDROFFSET;
	uint8_t chipnum = (pin & I2C_CHIPNUMMASK) >> I2C_CHIPNUMOFFSET;
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
