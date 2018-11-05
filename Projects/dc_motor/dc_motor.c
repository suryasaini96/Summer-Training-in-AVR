#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL

void main()
{
	DDRD=0xff;
	DDRC=0xff;
	PORTC=0x01;

	while(1)
	{	
		if(PORTC==0x00)
		{
		PORTD=0x01;
		_delay_ms(1);
		}
		
	}
}
