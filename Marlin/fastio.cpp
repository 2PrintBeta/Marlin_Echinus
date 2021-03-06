
#include "fastio.h"

#include "Marlin.h"
/* 
   Pin defs for AVR_ATmega128
   in .cpp and structs (no macros) because of i2c redirection
*/ 
#if defined (__AVR_ATmega128__)

#include "pca9555.h"

unsigned char timsk_save=0;
unsigned char etimsk_save=0;
unsigned char adcsra_save=0;
unsigned char eimsk_save =0;
unsigned char do_restore = 0;

void enable_uart_interrupt()
{
	if((SREG & (1<<7)) == 0)
	{
		etimsk_save = ETIMSK;
		timsk_save = TIMSK;
		adcsra_save = ADCSRA;
		eimsk_save = EIMSK;
		ETIMSK = 0; // (1 << OCIE3B);	// system clock must 
		TIMSK = 0;  			// be set enabled always for security reasons
		EIMSK = 0;
		sei();	
		do_restore=1;
	}	
}

void restore_interrupt_state()
{
	if(do_restore)
	{
		cli();
		ETIMSK = etimsk_save;
		TIMSK = timsk_save;
		EIMSK = eimsk_save;
		do_restore = 0;
	}
}

struct pindef_t pindef[] = 
{
	{PINE0,&PINE,&PORTE,&DDRE,NULL},
	{PINE1,&PINE,&PORTE,&DDRE,NULL},
	{PINE2,&PINE,&PORTE,&DDRE,NULL},
	{PINE3,&PINE,&PORTE,&DDRE,(volatile uint16_t*)&OCR3A},
	{PINE4,&PINE,&PORTE,&DDRE,(volatile uint16_t*)&OCR3B},
	{PINE5,&PINE,&PORTE,&DDRE,(volatile uint16_t*)&OCR3C},
	{PINE6,&PINE,&PORTE,&DDRE,NULL},
	{PINE7,&PINE,&PORTE,&DDRE,NULL},
	{PINB0,&PINB,&PORTB,&DDRB,NULL},
	{PINB1,&PINB,&PORTB,&DDRB,NULL},
	{PINB2,&PINB,&PORTB,&DDRB,NULL},
	{PINB3,&PINB,&PORTB,&DDRB,NULL},
	{PINB4,&PINB,&PORTB,&DDRB,(volatile uint16_t*)&OCR0},
	{PINB5,&PINB,&PORTB,&DDRB,(volatile uint16_t*)&OCR1A},
	{PINB6,&PINB,&PORTB,&DDRB,(volatile uint16_t*)&OCR1B},
	{PINB7,&PINB,&PORTB,&DDRB,(volatile uint16_t*)&OCR2},
	{PIND0,&PIND,&PORTD,&DDRD,NULL},
	{PIND1,&PIND,&PORTD,&DDRD,NULL},
	{PIND2,&PIND,&PORTD,&DDRD,NULL},
	{PIND3,&PIND,&PORTD,&DDRD,NULL},
	{PIND4,&PIND,&PORTD,&DDRD,NULL},
	{PIND5,&PIND,&PORTD,&DDRD,NULL},
	{PIND6,&PIND,&PORTD,&DDRD,NULL},
	{PIND7,&PIND,&PORTD,&DDRD,NULL},
	{PING0,&PING,&PORTG,&DDRG,NULL},
	{PING1,&PING,&PORTG,&DDRG,NULL},
	{PINC0,&PINC,&PORTC,&DDRC,NULL},
	{PINC1,&PINC,&PORTC,&DDRC,NULL},
	{PINC2,&PINC,&PORTC,&DDRC,NULL},
	{PINC3,&PINC,&PORTC,&DDRC,NULL},
	{PINC4,&PINC,&PORTC,&DDRC,NULL},
	{PINC5,&PINC,&PORTC,&DDRC,NULL},
	{PINC6,&PINC,&PORTC,&DDRC,NULL},
	{PINC7,&PINC,&PORTC,&DDRC,NULL},
	{PING2,&PING,&PORTG,&DDRG,NULL},
	{PINA7,&PINA,&PORTA,&DDRA,NULL},
	{PINA6,&PINA,&PORTA,&DDRA,NULL},
	{PINA5,&PINA,&PORTA,&DDRA,NULL},
	{PINA4,&PINA,&PORTA,&DDRA,NULL},
	{PINA3,&PINA,&PORTA,&DDRA,NULL},
	{PINA2,&PINA,&PORTA,&DDRA,NULL},
	{PINA1,&PINA,&PORTA,&DDRA,NULL},
	{PINA0,&PINA,&PORTA,&DDRA,NULL},
	
};

void setoutput(uint32_t io)
{
    if(io & I2C_PIN)
	{
		setoutput_PCA9555(io);
	}
	else
	{
		(*pindef[io].ddr) |= MASK(pindef[io].pin);
	}

}

void setinput(uint32_t io)
{
	if(io & I2C_PIN)
	{
		setinput_PCA9555(io);
	}
	else
	{
		(*pindef[io].ddr) &= ~MASK(pindef[io].pin);
	}
}

void write_bit(uint32_t io, uint8_t value)
{

	if(io & I2C_PIN)
	{
		unsigned char _sreg = SREG; cli();
        enable_uart_interrupt();
		write_PCA9555(io,value);
        restore_interrupt_state();
		SREG = _sreg; 
	}
	else
	{
		
		if( (pindef[io].rport) >= (volatile uint8_t *)0x100)
		{
			if(value)
			{
				unsigned char _sreg = SREG; cli();
				(*pindef[io].wport) |= MASK(pindef[io].pin);
				SREG = _sreg; 				
			}
			else
			{
				unsigned char _sreg = SREG; cli();
				(*pindef[io].wport) &= ~MASK(pindef[io].pin);
				SREG = _sreg; 		
			}
		}
		else
		{
			if(value)
			{
				(*pindef[io].wport) |= MASK(pindef[io].pin); 				
			}
			else
			{
				(*pindef[io].wport) &= ~MASK(pindef[io].pin);		
			}
		}
	}
}

bool read_bit(uint32_t io)
{
	if(io & I2C_PIN)
	{
		return false; //read_PCA9555(io);
	}
	else
	{
		return  (*pindef[io].rport) & MASK(pindef[io].pin);
	}


}


#endif

