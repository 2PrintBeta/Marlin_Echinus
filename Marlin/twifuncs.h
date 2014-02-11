#ifndef __TWI_FUNCS_H_
#define __TWI_FUNCS_H_

#include <avr/io.h>

#define I2C_READ    1	/** defines the data direction (reading from I2C device) in i2c_start(),i2c_rep_start() */
#define I2C_WRITE   0   /** defines the data direction (writing to I2C device) in i2c_start(),i2c_rep_start() */


/*************************************************************************
 @brief		Highlevelfunction 

 Write number of Bytes to the I2C device, 

@param   	addr 		I2C -Adresse mit Bit 0 = 0 (Write)
@param    	data		Databyte

 Return:  0 = No Error ; 1 = Error
*************************************************************************/
int writeI2Ccmd(unsigned char addr, unsigned char data);


/*************************************************************************
 @brief		Highlevelfunction 

 Write Array of Bytes to the I2C device, 

@param   	addr 			I2C -Adresse mit Bit 0 = 0 (Write)
@param    	data			Array mit Daten für Versand
@param    	noOfDatabytes	Anzahl der Datenbytes in Array

 Return:  0 = No Error ; 1 = Error
*************************************************************************/
int writeI2Ccmds(unsigned char addr, unsigned char *data, int noOfDatabytes);


/*************************************************************************
 @brief		LowLevelfunctions 

 Especially used for TWI-Hardware
*************************************************************************/

/**
 @brief initialize the I2C master interace. Need to be called only once 
 @param  void
 @return none
 */
extern void i2c_init(void) __attribute__ ((cold));


/** 
 @brief Terminates the data transfer and releases the I2C bus 
 @param void
 @return none
 */
extern void i2c_stop(void);


/** 
 @brief Issues a start condition and sends address and transfer direction 
  
 @param    addr address and transfer direction of I2C device
 @retval   0   device accessible 
 @retval   1   failed to access device 
 */
extern unsigned char i2c_start(unsigned char addr);


/**
 @brief Issues a repeated start condition and sends address and transfer direction 

 @param   addr address and transfer direction of I2C device
 @retval  0 device accessible
 @retval  1 failed to access device
 */
extern unsigned char i2c_rep_start(unsigned char addr);


/**
 @brief Issues a start condition and sends address and transfer direction 
   
 If device is busy, use ack polling to wait until device ready 
 @param    addr address and transfer direction of I2C device
 @return   none
 */
extern void i2c_start_wait(unsigned char addr);

 
/**
 @brief Send one byte to I2C device
 @param    data  byte to be transfered
 @retval   0 write successful
 @retval   1 write failed
 */
extern unsigned char i2c_write(unsigned char data);


/**
 @brief    read one byte from the I2C device, request more data from device 
 @return   byte read from I2C device
 */
extern unsigned char i2c_readAck(void);

/**
 @brief    read one byte from the I2C device, read is followed by a stop condition 
 @return   byte read from I2C device
 */
extern unsigned char i2c_readNak(void);

/** 
 @brief    read one byte from the I2C device
 
 Implemented as a macro, which calls either i2c_readAck or i2c_readNak
 
 @param    ack 1 send ack, request more data from device<br>
               0 send nak, read is followed by a stop condition 
 @return   byte read from I2C device
 */
extern unsigned char i2c_read(unsigned char ack);


#define i2c_read(ack)  (ack) ? i2c_readAck() : i2c_readNak(); 

#endif
