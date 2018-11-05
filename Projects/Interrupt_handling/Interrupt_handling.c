#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define F_CPU 16000000UL

//Interrupt Service Routine

ISR(INT0_vect)
{
	unsigned char i,temp;
	_delay_ms(500);
	temp=PORTC; //Save current data value of PORTC
	for(i=0;i<5;i++)
	{
		PORTC=0x00;
		_delay_ms(500);
		PORTC=0xff;
		_delay_ms(500);
	}
	PORTC=temp; //Restore old value in PORTC (i.e. resume earlier task)
}

int main(void)
{
	DDRD=(1<<PD0);
	PORTD=(0<<PD0);
	
	DDRC=0xff;
	PORTC=0x01;

	GICR=1<<INT0;
	MCUCR=1<<ISC00|1<<ISC01;
	
	sei(); // Enable global interrupt
	
	while(1)
	{
		if(PORTC>=0x80)
			PORTC = 1;
		else
			PORTC = PORTC << 1;	// Shift to the left
 
		_delay_ms(500);	// Wait 5 seconds
	}
	
}
