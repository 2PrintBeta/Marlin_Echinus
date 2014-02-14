#include "lcd_ks0073.h"

#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "Arduino.h"
#include  <util/delay.h>

#include "Marlin.h"

//pin defines
#define LCD_DATA0_PORT   	PORTC    /**< port for 4bit data bit 0 */
#define LCD_DATA0_PIN		PINC
#define LCD_DATA0_DDR		DDRC
#define LCD_DATA0			0

#define LCD_DATA1_PORT   	PORTC     /**< port for 4bit data bit 1 */
#define LCD_DATA1_PIN		PINC
#define LCD_DATA1_DDR		DDRC
#define LCD_DATA1			1

#define LCD_DATA2_PORT   	PORTD    /**< port for 4bit data bit 2 */
#define LCD_DATA2_PIN		PIND
#define LCD_DATA2_DDR		DDRD
#define LCD_DATA2			3

#define LCD_DATA3_PORT   	PORTD     /**< port for 4bit data bit 3 */
#define LCD_DATA3_PIN		PIND
#define LCD_DATA3_DDR		DDRD
#define LCD_DATA3			4

#define LCD_RS_PORT      	PORTD     /**< port for RS line         */
#define LCD_RS_PIN       	PIND            /**< pin-port  for RS line         */
#define LCD_RS_DDR			DDRD
#define LCD_RS				5

#define LCD_RW_PORT      	PORTD     /**< port for RW line         */
#define LCD_RW_PIN       	PIND           /**< pin-port  for RW line         */
#define LCD_RW_DDR			DDRD
#define LCD_RW				6

#define LCD_E_PORT       	PORTD     /**< port for Enable line     */
#define LCD_E_PIN        	PIND            /**< pin-port  for Enable line     */
#define LCD_E_DDR			DDRD
#define LCD_E				7

#define MIN_PULLUPDELAY		10  	/*< delay used for the display to pullup the datalines  */


#define lcd_e_delay()   delay(MIN_PULLUPDELAY); __asm__ __volatile__( "rjmp 1f\n 1:" );   
#define lcd_e_high()    LCD_E_PORT  |=  (1 << LCD_E);
#define lcd_e_low()     LCD_E_PORT  &= ~(1 << LCD_E);
#define lcd_rw_high()   LCD_RW_PORT |=  (1 << LCD_RW)
#define lcd_rw_low()    LCD_RW_PORT &= ~(1 << LCD_RW)
#define lcd_rs_high()   LCD_RS_PORT |=  (1 << LCD_RS)
#define lcd_rs_low()    LCD_RS_PORT &= ~(1 << LCD_RS)

#define KS0073_EXTENDED_FUNCTION_REGISTER_ON  0x2C   // |0|010|1100 4-bit mode, extension-bit RE = 1 //
#define KS0073_EXTENDED_FUNCTION_REGISTER_OFF 0x28   // |0|010|1000 4-bit mode, extension-bit RE = 0 //
#define KS0073_4LINES_MODE                    0x09   // |0|000|1001 4 lines mode //

/**
 *  @name Definitions for LCD command instructions
 *  The constants define the various LCD controller instructions which can be passed to the 
 *  function lcd_command(), see HD44780 data sheet for a complete description.
 */

/* instruction register bit positions, see HD44780U data sheet */
#define LCD_CLR               0      /* DB0: clear display                  */
#define LCD_HOME              1      /* DB1: return to home position        */
#define LCD_ENTRY_MODE        2      /* DB2: set entry mode                 */
#define LCD_ENTRY_INC         1      /*   DB1: 1=increment, 0=decrement     */
#define LCD_ENTRY_SHIFT       0      /*   DB2: 1=display shift on           */
#define LCD_ON                3      /* DB3: turn lcd/cursor on             */
#define LCD_ON_DISPLAY        2      /*   DB2: turn display on              */
#define LCD_ON_CURSOR         1      /*   DB1: turn cursor on               */
#define LCD_ON_BLINK          0      /*     DB0: blinking cursor ?          */
#define LCD_MOVE              4      /* DB4: move cursor/display            */
#define LCD_MOVE_DISP         3      /*   DB3: move display (0-> cursor) ?  */
#define LCD_MOVE_RIGHT        2      /*   DB2: move right (0-> left) ?      */
#define LCD_FUNCTION          5      /* DB5: function set                   */
#define LCD_FUNCTION_8BIT     4      /*   DB4: set 8BIT mode (0->4BIT mode) */
#define LCD_FUNCTION_2LINES   3      /*   DB3: two lines (0->one line)      */
#define LCD_FUNCTION_10DOTS   2      /*   DB2: 5x10 font (0->5x7 font)      */
#define LCD_CGRAM             6      /* DB6: set CG RAM address             */
#define LCD_DDRAM             7      /* DB7: set DD RAM address             */
#define LCD_BUSY              7      /* DB7: LCD is busy                    */

/* set entry mode: display shift on/off, dec/inc cursor move direction */
#define LCD_ENTRY_DEC            0x04   /* display shift off, dec cursor move dir */
#define LCD_ENTRY_DEC_SHIFT      0x05   /* display shift on,  dec cursor move dir */
#define LCD_ENTRY_INC_           0x06   /* display shift off, inc cursor move dir */
#define LCD_ENTRY_INC_SHIFT      0x07   /* display shift on,  inc cursor move dir */

/* display on/off, cursor on/off, blinking char at cursor position */
#define LCD_DISP_OFF             0x08   /* display off                            */
#define LCD_DISP_ON              0x0C   /* display on, cursor off                 */
#define LCD_DISP_ON_BLINK        0x0D   /* display on, cursor off, blink char     */
#define LCD_DISP_ON_CURSOR       0x0E   /* display on, cursor on                  */
#define LCD_DISP_ON_CURSOR_BLINK 0x0F   /* display on, cursor on, blink char      */

/* move cursor/shift display */
#define LCD_MOVE_CURSOR_LEFT     0x10   /* move cursor left  (decrement)          */
#define LCD_MOVE_CURSOR_RIGHT    0x14   /* move cursor right (increment)          */
#define LCD_MOVE_DISP_LEFT       0x18   /* shift display left                     */
#define LCD_MOVE_DISP_RIGHT      0x1C   /* shift display right                    */

/* function set: set interface data length and number of display lines */
#define LCD_FUNCTION_4BIT_1LINE  0x20   /* 4-bit interface, single line, 5x7 dots */
#define LCD_FUNCTION_4BIT_2LINES 0x28   /* 4-bit interface, dual line,   5x7 dots */
#define LCD_FUNCTION_8BIT_1LINE  0x30   /* 8-bit interface, single line, 5x7 dots */
#define LCD_FUNCTION_8BIT_2LINES 0x38   /* 8-bit interface, dual line,   5x7 dots */

#define LCD_START_LINE1  0x00     /**< DDRAM address of first char of line 1 */
#define LCD_START_LINE2  0x40     /**< DDRAM address of first char of line 2 */
#define LCD_START_LINE3  0x14     /**< DDRAM address of first char of line 3 */
#define LCD_START_LINE4  0x54     /**< DDRAM address of first char of line 4 */

#define LCD_MODE_DEFAULT     ((1<<LCD_ENTRY_MODE) | (1<<LCD_ENTRY_INC) )


#define XTAL 14474560 
/************************************************************************
 delay loop for small accurate delays: 16-bit counter, 4 cycles/loop
************************************************************************/
static inline void _delayFourCycles(unsigned int __count)
{
    if ( __count == 0 )    
        __asm__ __volatile__( "rjmp 1f\n 1:" );    // 2 cycles
    else
        __asm__ __volatile__ (
    	    "1: sbiw %0,1" "\n\t"                  
    	    "brne 1b"                              // 4 cycles/loop
    	    : "=w" (__count)
    	    : "0" (__count)
    	   );
}


/************************************************************************ 
/delay for a minimum of <us> microseconds
the number of loops is calculated at compile-time from MCU clock frequency
************************************************************************/
#define delay(us)  _delayFourCycles( ( ( 1*(XTAL/4000) )*us)/1000 )

LcdKS0073::LcdKS0073()
{
  
}

void LcdKS0073::begin(uint8_t cols, uint8_t rows) 
{
  // configure all port bits as output (LCD data and control lines on different ports //
    LCD_RS_DDR    |= (1 << LCD_RS);
    LCD_RW_DDR    |= (1 << LCD_RW);
    LCD_E_DDR     |= (1 << LCD_E);
    LCD_DATA0_DDR |= (1 << LCD_DATA0);
    LCD_DATA1_DDR |= (1 << LCD_DATA1);
    LCD_DATA2_DDR |= (1 << LCD_DATA2);
    LCD_DATA3_DDR |= (1 << LCD_DATA3);

	LCD_RS_PORT    &= ~(1<< LCD_RS);
    LCD_RW_PORT    &= ~(1<< LCD_RW);
    LCD_E_PORT     &= ~(1<< LCD_E);
    LCD_DATA0_PORT &= ~(1<< LCD_DATA0);
    LCD_DATA1_PORT &= ~(1<< LCD_DATA1);
    LCD_DATA2_PORT &= ~(1<< LCD_DATA2);
    LCD_DATA3_PORT &= ~(1<< LCD_DATA3);

    delay(16000);        // wait 16ms or more after power-on       //
    
    // initial write to lcd is 8bit //
	LCD_DATA3_PORT &= ~(1<< LCD_DATA3);
	LCD_DATA2_PORT &= ~(1<< LCD_DATA2);
    LCD_DATA1_PORT |= (1<< LCD_DATA1);  // (1 << LCD_FUNCTION)>>4;
    LCD_DATA0_PORT &= ~(1<< LCD_DATA0);  // (1 << LCD_FUNCTION_8BIT)>>4;
	lcd_e_toggle();
    delay(5000);	// delay(4992);         // delay, busy flag can't be checked here //
   
 	 // repeat last command // 
    lcd_e_toggle();      
    delay(64);           // delay, busy flag can't be checked here //
    
    // repeat last command a third time //
    lcd_e_toggle();      
    delay(64);           // delay, busy flag can't be checked here //

    // now configure for 4bit mode //
    LCD_DATA0_PORT &= ~(1<<LCD_DATA0);   // LCD_FUNCTION_4BIT_1LINE>>4
    lcd_e_toggle();
    delay(64);           // some displays need this additional delay //
	if (!lcd_check_connection(10))	return; 			// checks busy bit for 100  ms - try to check display connection
														// todo: implement better detection

    // Display with KS0073 controller requires special commands for enabling 4 line mode //
	lcd_command(KS0073_EXTENDED_FUNCTION_REGISTER_ON);
	lcd_command(KS0073_4LINES_MODE);
	lcd_command(KS0073_EXTENDED_FUNCTION_REGISTER_OFF);

    lcd_command(LCD_DISP_OFF);              // display off                  //
    lcd_clrscr();                           // display clear                // 
    lcd_command(LCD_MODE_DEFAULT);          // set entry mode               //
	lcd_command(LCD_ON_CURSOR);				// show cursor
    lcd_command(LCD_DISP_ON);                  // display/cursor control       //

	return;

}

size_t LcdKS0073::write(uint8_t value) 
{
    lcd_waitbusy();
    lcd_write(value,1);
  return 1; // assume sucess
}

inline void LcdKS0073::command(uint8_t value) 
{
;
}

void LcdKS0073::home()
{ 
}

void LcdKS0073::noDisplay()
{ 

}
void LcdKS0073::display()
{ 

}
void LcdKS0073::noBlink()
{ 

}
void LcdKS0073::blink()
{ 
}
void LcdKS0073::noCursor()
{ 
}
void LcdKS0073::cursor()
{ 
}
void LcdKS0073::scrollDisplayLeft()
{ 
}
void LcdKS0073::scrollDisplayRight()
{ 
}
void LcdKS0073::leftToRight()
{ 
}
void LcdKS0073::rightToLeft()
{ 
}
void LcdKS0073::autoscroll()
{ 
}
void LcdKS0073::noAutoscroll()
{ 
}


// Allows us to fill the first 8 CGRAM locations
// with custom characters
void LcdKS0073::createChar(uint8_t location, uint8_t charmap[]) 
{
  location &= 0x7; // we only have 8 locations 0-7
  lcd_command((1<<LCD_CGRAM) | (location << 3));
  for (int i=0; i<8; i++) {
    write(charmap[i]);
  }
}

void LcdKS0073::clear()
{
  lcd_clrscr();
  delayMicroseconds(2000);  // this command takes a long time!
}

void LcdKS0073::setCursor(uint8_t col, uint8_t row)
{
   if ( row==0 )
        lcd_command((1<<LCD_DDRAM)+LCD_START_LINE1+col);
    else if ( row==1)
        lcd_command((1<<LCD_DDRAM)+LCD_START_LINE2+col);
    else if ( row==2)
        lcd_command((1<<LCD_DDRAM)+LCD_START_LINE3+col);
    else // y==3 //
        lcd_command((1<<LCD_DDRAM)+LCD_START_LINE4+col);
}

void LcdKS0073::lcd_e_toggle()
{
    lcd_e_high();
    lcd_e_delay();
    lcd_e_low();
}

uint8_t LcdKS0073::lcd_check_connection(uint8_t ms)
{
    uint8_t data;

    lcd_rs_low();                        // RS=0: read busy flag 
    lcd_rw_high();                           // RW=1  read mode      
    
     // configure data pins as input 
	LCD_DATA3_DDR &= ~(1 << LCD_DATA3);
    
	// enable pullups        
	LCD_DATA3_PORT |= (1 << LCD_DATA3);
	// read high nibble first 
    lcd_e_high();
	delay(MIN_PULLUPDELAY);
    lcd_e_delay();        
    data = 0;
    if ( LCD_DATA3_PIN & (1 << LCD_DATA3) ) data |= 0x80;
    lcd_e_low();

    //lcd_e_delay();                       // Enable 500ns low       
	delay(MIN_PULLUPDELAY);
    // read low nibble    
    lcd_e_high();
    lcd_e_delay();
    if ( LCD_DATA3_PIN & (1 << LCD_DATA3) ) data |= 0x08;        
    lcd_e_low();
	delay(MIN_PULLUPDELAY);
	// disable pullups        
  	LCD_DATA3_PORT &= ~(1 << LCD_DATA3);

	if(data) return 0;
	else return 1;

}

void LcdKS0073::lcd_command(uint8_t cmd)
{
    lcd_waitbusy();
    lcd_write(cmd,0);
}

void LcdKS0073::lcd_clrscr(void)
{
    lcd_command(1<<LCD_CLR);
}

uint8_t LcdKS0073::lcd_waitbusy(void)
{
    register uint8_t c;
    delay(MIN_PULLUPDELAY);
    // wait until busy flag is cleared //
	while ( (c=lcd_read(0)) & (1<<LCD_BUSY)) {}
    
    // the address counter is updated 4us after the busy flag is cleared //
    delay(8);
	delay(MIN_PULLUPDELAY);
    // now read the address counter //
    return (lcd_read(0));  // return address counter
}

void LcdKS0073::lcd_write(uint8_t data,uint8_t rs) 
{
    if (rs) {   // write data        (RS=1, RW=0) //
       lcd_rs_high();
    } else {    // write instruction (RS=0, RW=0) //
       lcd_rs_low();
    }
    lcd_rw_low();

    // configure data pins as output //
    LCD_DATA0_DDR |= (1 << LCD_DATA0);
    LCD_DATA1_DDR |= (1 << LCD_DATA1);
    LCD_DATA2_DDR |= (1 << LCD_DATA2);
    LCD_DATA3_DDR |= (1 << LCD_DATA3);
    
    // output high nibble first //
    LCD_DATA3_PORT &= ~(1 << LCD_DATA3);
    LCD_DATA2_PORT &= ~(1 << LCD_DATA2);
    LCD_DATA1_PORT &= ~(1 << LCD_DATA1);
    LCD_DATA0_PORT &= ~(1 << LCD_DATA0);
	if(data & 0x80) LCD_DATA3_PORT |= (1 << LCD_DATA3);
	if(data & 0x40) LCD_DATA2_PORT |= (1 << LCD_DATA2);
	if(data & 0x20) LCD_DATA1_PORT |= (1 << LCD_DATA1);
	if(data & 0x10) LCD_DATA0_PORT |= (1 << LCD_DATA0);   
    lcd_e_toggle();
    
    // output low nibble //
    LCD_DATA3_PORT &= ~(1 << LCD_DATA3);
    LCD_DATA2_PORT &= ~(1 << LCD_DATA2);
    LCD_DATA1_PORT &= ~(1 << LCD_DATA1);
    LCD_DATA0_PORT &= ~(1 << LCD_DATA0);
	if(data & 0x08) LCD_DATA3_PORT |= (1 << LCD_DATA3);
	if(data & 0x04) LCD_DATA2_PORT |= (1 << LCD_DATA2);
	if(data & 0x02) LCD_DATA1_PORT |= (1 << LCD_DATA1);
	if(data & 0x01) LCD_DATA0_PORT |= (1 << LCD_DATA0);
    lcd_e_toggle();        
    
    // all data pins high (inactive) //
    LCD_DATA0_PORT |= (1 << LCD_DATA0);
    LCD_DATA1_PORT |= (1 << LCD_DATA1);
    LCD_DATA2_PORT |= (1 << LCD_DATA2);
    LCD_DATA3_PORT |= (1 << LCD_DATA3);
}

uint8_t LcdKS0073::lcd_read(uint8_t rs) 
{
   uint8_t data;
    
    if (rs)
        lcd_rs_high();                       // RS=1: read data      
    else
        lcd_rs_low();                        // RS=0: read busy flag 
    lcd_rw_high();                           // RW=1  read mode      
    
     // configure data pins as input 
    LCD_DATA0_DDR &= ~(1 << LCD_DATA0);
    LCD_DATA1_DDR &= ~(1 << LCD_DATA1);
    LCD_DATA2_DDR &= ~(1 << LCD_DATA2);
	LCD_DATA3_DDR &= ~(1 << LCD_DATA3);
    
	// enable pullups        
  	LCD_DATA0_PORT |= (1 << LCD_DATA0);
    LCD_DATA1_PORT |= (1 << LCD_DATA1);
    LCD_DATA2_PORT |= (1 << LCD_DATA2);
	LCD_DATA3_PORT |= (1 << LCD_DATA3);
	// read high nibble first 
    lcd_e_high();
	delay(MIN_PULLUPDELAY);
    lcd_e_delay();        
    data = 0;
    if ( LCD_DATA0_PIN & (1 << LCD_DATA0) ) data |= 0x10;
    if ( LCD_DATA1_PIN & (1 << LCD_DATA1) ) data |= 0x20;
    if ( LCD_DATA2_PIN & (1 << LCD_DATA2) ) data |= 0x40;
    if ( LCD_DATA3_PIN & (1 << LCD_DATA3) ) data |= 0x80;
    lcd_e_low();

    //lcd_e_delay();                       // Enable 500ns low       
	delay(MIN_PULLUPDELAY);
    // read low nibble    
    lcd_e_high();
    lcd_e_delay();
    if ( LCD_DATA0_PIN & (1 << LCD_DATA0) ) data |= 0x01;
    if ( LCD_DATA1_PIN & (1 << LCD_DATA1) ) data |= 0x02;
    if ( LCD_DATA2_PIN & (1 << LCD_DATA2) ) data |= 0x04;
    if ( LCD_DATA3_PIN & (1 << LCD_DATA3) ) data |= 0x08;        
    lcd_e_low();
	delay(MIN_PULLUPDELAY);
	// disable pullups        
  	LCD_DATA0_PORT &= ~(1 << LCD_DATA0);
    LCD_DATA1_PORT &= ~(1 << LCD_DATA1);
    LCD_DATA2_PORT &= ~(1 << LCD_DATA2);
    LCD_DATA3_PORT &= ~(1 << LCD_DATA3);

    return data;
}


