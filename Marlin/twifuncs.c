#include <inttypes.h>
#include <compat/twi.h>

#include "twifuncs.h"

#ifndef F_CPU
	#error "define CPU frequency in Mhz if not defined in Makefile"
#endif
/* I2C clock in Hz */
#define SCL_CLOCK  400000UL
#define I2C_TIMEOUT 100

#define I2C_ERROR_START 	1
#define I2C_ERROR_ACK		2
#define I2C_ERROR_DATA		3

unsigned char m_i2c_timeout;
typedef unsigned char errorData;

typedef enum {

	NO_ERROR, I2C_ERROR
} ErrorTypes;

/*************************************************************************
 @brief		Highlevelfunctions 
*************************************************************************/


/***************
 Initialization of the I2C bus interface. Need to be called only once
****************/
void i2c_init(void)
{
  /* initialize TWI clock: 100 kHz clock, TWPS = 1 => prescaler = 4 */
  
  TWSR = 0;                         /* no prescaler */
  TWBR = (((unsigned long int) F_CPU/SCL_CLOCK)-16)/2;  /* must be > 10 for stable operation */

}/* i2c_init */





/***************
 Write number of Bytes to the I2C device, 

@param   	addr 		I2C -Adresse mit Bit 0 = 0 (Write)800
@param    	data		Daten f?r Versand

 Return:  0 = No Error ; 1 = Error
****************/

int writeI2Ccmd(unsigned char addr, unsigned char data)
{
	int ret = 0;
	ret = i2c_start(addr);       // set device address and write mode
	if ( ret ) 
	{
	    /* failed to issue start condition, possibly no device found */	
	    i2c_stop();
		return 1;
	}
	else
	{
	    /* issuing start condition ok, device accessible */
	   // i2c_write(addr);                       // write address 
		ret = i2c_write(data);                       // ret=0 -> Ok, ret=1 -> no ACK 
		if ( ret ) 
		{
	    /* failed to issue start condition, possibly no device found */
	    	i2c_stop();
			return 1;
		}
    	else i2c_stop();                            // set stop conditon = release bus		
	}
	return ret;
}

/***************
 Write array of Bytes to the I2C device, 

@param   	addr 			I2C -Adresse mit Bit 0 = 0 (Write)800
@param    	data			Daten f?r Versand
@param		noOfDatabytes	anz der Datenbytes
 Return:  0 = No Error ; 1 = Error
****************/

int writeI2Ccmds(unsigned char addr, unsigned char *data,int noOfDatabytes)
{
	int ret = 0;
	int i = 0;

	ret = i2c_start(addr);       // set device address and write mode
	if ( ret ) 
	{
	    /* failed to issue start condition, possibly no device found */	
	    i2c_stop();
		return I2C_ERROR_START;
	}
	else
	{
		/* issuing start condition ok, device accessible 
		ret = i2c_write(addr);                       // write address 
		if ( ret ) 
		{
	    // failed to issue start condition, possibly no device found 
	    	i2c_stop();
			return I2C_ERROR_ACK;
		} */
		for (i = 0; i < noOfDatabytes; i++)
		{
			ret = i2c_write(*(((unsigned char*) data)+i));                       // ret=0 -> Ok, ret=1 -> no ACK 
			if ( ret ) 
			{
		    /* failed to issue start condition, possibly no device found */
		    	i2c_stop();
				return I2C_ERROR_DATA;
			}
    	}
		i2c_stop();                            // set stop conditon = release bus		
	}
	return ret;
}

/*************************************************************************
 @brief		LowLevelfunctions 
*************************************************************************/
 
/****************
 Read one byte from the I2C device, read is followed by a stop condition 
 
 Return:  byte read from I2C device
*****************/
unsigned char i2c_readNak(void)
{
	TWCR = (1<<TWINT) | (1<<TWEN);
	
	while(!(TWCR & (1<<TWINT)));
	

    return TWDR;

}

/***********************
 Read one byte from the I2C device, request more data from device 
 
 Return:  byte read from I2C device
************************/
unsigned char i2c_readAck(void)
{
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	while(!(TWCR & (1<<TWINT)));    
    return TWDR;
}/* i2c_readAck */


/********************
  Issues a start condition and sends address and transfer direction.
  return 0 = device accessible, 1= failed to access device
*********************/
unsigned char i2c_start(unsigned char address)
{
    uint8_t   twst;

	// send START condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	m_i2c_timeout = I2C_TIMEOUT;
	// wait until transmission completed
	while(!(TWCR & (1<<TWINT))  && m_i2c_timeout >= 0);

	if(m_i2c_timeout == 0)
	{
		return I2C_ERROR;
	}
	// check value of TWI Status Register. Mask prescaler bits.
	twst = TW_STATUS & 0xF8;
	if ( (twst != TW_START) && (twst != TW_REP_START)) return I2C_ERROR;

	// send device address
	TWDR = address;
	TWCR = (1<<TWINT) | (1<<TWEN);

	// wail until transmission completed and ACK/NACK has been received
	while(!(TWCR & (1<<TWINT)));

	// check value of TWI Status Register. Mask prescaler bits.
	twst = TW_STATUS & 0xF8;
	if ( (twst != TW_MT_SLA_ACK) && (twst != TW_MR_SLA_ACK) ) return I2C_ERROR;

	return NO_ERROR;

}/* i2c_start */


/********************
 Issues a start condition and sends address and transfer direction.
 If device is busy, use ack polling to wait until device is ready
 
 Input:   address and transfer direction of I2C device
*********************/
void i2c_start_wait(unsigned char address)
{
    uint8_t   twst;


    while ( 1 )
    {
	    // send START condition
	    TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
    
    	// wait until transmission completed
    	while(!(TWCR & (1<<TWINT)));
    
    	// check value of TWI Status Register. Mask prescaler bits.
    	twst = TW_STATUS & 0xF8;
    	if ( (twst != TW_START) && (twst != TW_REP_START)) continue;
    
    	// send device address
    	TWDR = address;
    	TWCR = (1<<TWINT) | (1<<TWEN);
    
    	// wail until transmission completed
    	while(!(TWCR & (1<<TWINT)));
    
    	// check value of TWI Status Register. Mask prescaler bits.
    	twst = TW_STATUS & 0xF8;
    	if ( (twst == TW_MT_SLA_NACK )||(twst ==TW_MR_DATA_NACK) ) 
    	{    	    
    	    /* device busy, send stop condition to terminate write operation */
	        TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	        
	        // wait until stop condition is executed and bus released
	        while(TWCR & (1<<TWSTO));
	        
    	    continue;
    	}
    	//if( twst != TW_MT_SLA_ACK) return 1;
    	break;
     }

}/* i2c_start_wait */


/********************
 Issues a repeated start condition and sends address and transfer direction 

 Input:   address and transfer direction of I2C device
 
 Return:  0 device accessible
          1 failed to access device
*********************/
unsigned char i2c_rep_start(unsigned char address)
{
    return i2c_start( address );

}/* i2c_rep_start */


/*********************
 Terminates the data transfer and releases the I2C bus
**********************/
void i2c_stop(void)
{
    /* send stop condition */
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	
	// wait until stop condition is executed and bus released
	while(TWCR & (1<<TWSTO));

}/* i2c_stop */


/**********************
  Send one byte to I2C device
  
  Input:    byte to be transfered
  Return:   0 write successful 
            1 write failed
***********************/
unsigned char i2c_write( unsigned char data )
{	
    uint8_t   twst;
    
	// send data to the previously addressed device
	TWDR = data;
	TWCR = (1<<TWINT) | (1<<TWEN);

	// wait until transmission completed
	while(!(TWCR & (1<<TWINT)));

	// check value of TWI Status Register. Mask prescaler bits
	twst = TW_STATUS & 0xF8;
	if( twst != TW_MT_DATA_ACK) return I2C_ERROR;
	return NO_ERROR;

}/* i2c_write */







