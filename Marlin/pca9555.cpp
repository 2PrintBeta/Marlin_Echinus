
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
#include "Marlin.h"
#include "pins.h"


extern "C" {
    #include "twifuncs.h"
};

#define REG_IN 0
#define REG_OUT 2
#define REG_POL 4
#define REG_DIR 6
#define I2C_ADDR 8 


/** variable, holding the boards PCA9555-data **/
volatile uint8_t i2cPortBuf[NUM_OF_I2C_EXPANDERS][9] =
		//	inL, 	inH, 	outL, 	outH, 	polL, 	polH, 	dirL, 	dirH, 	address
		 {	{0, 	255, 		255, 	0, 		0, 		0, 		0, 		127, 	64},	// Device 1 (L: Mot1+2, H: ExternalPort)
			{0, 	0, 		255, 	255, 	0, 		0, 		0, 		0, 		68}};	// Device 2 (L: Mot5+6, H: Mot3+4)


/***********
@brief Initialize all PCA9555-devices
***********/
uint8_t init_PCA9555 ()
{	
    i2c_init();
	int8_t testi2c = 0;
	unsigned char databytes[3] = {00 , 00, 00};
    for(int i=0; i < NUM_OF_I2C_EXPANDERS; i++)
	{
		databytes[0] = REG_OUT;		// register-adress of outputport
		databytes[1] = i2cPortBuf[i][REG_OUT];
		databytes[2] = i2cPortBuf[i][REG_OUT+1];
        writeI2Ccmds(i2cPortBuf[i][I2C_ADDR], databytes , 3);

		databytes[0] = REG_POL;		// register-adress of polarity-port
		databytes[1] = i2cPortBuf[i][REG_POL];
		databytes[2] = i2cPortBuf[i][REG_POL+1];
        writeI2Ccmds(i2cPortBuf[i][I2C_ADDR], databytes , 3);

		databytes[0] = REG_DIR;		// register-adress of direction-port
		databytes[1] = i2cPortBuf[i][REG_DIR];
		databytes[2] = i2cPortBuf[i][REG_DIR+1];
		writeI2Ccmds(i2cPortBuf[i][I2C_ADDR], databytes , 3);

	}


    // enable interrupt on EXTINT
	DDRE &= ~(1 << 6);
	PORTE |= (1 << 6);		//pullup external Interrupt


	EICRB |= (1 << ISC61); 		// falling edge on external Int6 generates IntRequest INT6
	EIMSK |= (1 << INT6);


	return testi2c;	
}


void i2c_write(uint8_t reg,uint16_t pin,uint8_t value)
{

    uint8_t senddata[2];

    //extract i2c data from pin
    uint8_t bit = pin & I2C_BITMASK;
    uint8_t chipnum = (pin & I2C_CHIPMASK) >> I2C_CHIPOFFSET;
    uint8_t highbyte= (pin & I2C_HLMASK) >> I2C_HLOFFSET;
    uint8_t addr = i2cPortBuf[chipnum][I2C_ADDR];

    // set or reset bits in buffer
    if(value == 1)
    {
        //check if bit is not already set
        if(i2cPortBuf[chipnum][reg+highbyte] & (1 << bit))
        {
            return;
        }        
        //Set bit
        i2cPortBuf[chipnum][reg+highbyte] |= (1 << bit);           
    }
    else
    {
        //check if bit is not already cleared
        if(!(i2cPortBuf[chipnum][reg+highbyte] & (1 << bit)))
        {
            return;
        }        
        //clear bit
        i2cPortBuf[chipnum][reg+highbyte] &= ~(1 << bit);  
    }
    
    //send over i2c
    senddata[0] = reg+highbyte;
    senddata[1] = i2cPortBuf[chipnum][reg+highbyte];
 
    writeI2Ccmds(addr, senddata, 2);   
    

}

void setoutput_PCA9555(uint16_t pin)
{
    i2c_write(REG_DIR,pin,0);
}

void setinput_PCA9555(uint16_t pin)
{
    i2c_write(REG_DIR,pin,1);
}

void write_PCA9555(uint16_t pin, uint8_t value)
{
    i2c_write(REG_OUT,pin,value);
}


ISR(INT6_vect)	// // EXTERNAL INTERRUPT 6 used to get pin change information from PCA9555 
{
     // read from i2c chip 0, highbyte (EXTPORT)
	writeI2Ccmd(i2cPortBuf[0][I2C_ADDR], REG_IN+1);// set adress of input for external port
	i2c_start_wait(i2cPortBuf[0][I2C_ADDR] + 1); 		// read device
	i2cPortBuf[0][REG_IN+1] = i2c_readNak();
	i2c_stop();
} // EXTERNAL INTERRUPT 6

uint8_t read_PCA9555_inputs()
{
    return 0xff -i2cPortBuf[0][REG_IN+1];
}


