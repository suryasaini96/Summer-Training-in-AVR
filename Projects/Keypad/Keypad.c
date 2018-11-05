#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 16000000
#define LCDPort PORTB
#define rs PA0
#define rw PA1
#define en PA2

void LCDcmd(unsigned char cmd)
{
	LCDPort=cmd;
	PORTA&=~(1<<rs);
	PORTA&=~(1<<rw);
	PORTA|=(1<<en);
	_delay_ms(1);
	PORTA&=~(1<<en);
	_delay_ms(1);
}

void LCDinit()
{
	LCDcmd(0x02); // Return home for LCD
	LCDcmd(0x38); // Using 8-bit mode 
	LCDcmd(0x06); // Increment cursor
	LCDcmd(0x0c); // Set cursor off
}	

void LCDdata(unsigned char data)
{
	LCDPort=data;
	PORTA|=(1<<rs);
	PORTA&=~(1<<rw);
	PORTA|=(1<<en);
	_delay_ms(1);
	PORTA&=~(1<<en);
	_delay_ms(1);
}

void LCDstring(char *string)
{
	int i=0;
	while(string[i]!='\0')
	{
		LCDdata(string[i]);
		i++;
	}
}	

void LCDclear()
{
	LCDcmd(0x01); //Clear LCD
	_delay_ms(1);
}

/*void bitCheck(unsigned char port)
{
	if(port&0xff)
}
*/

int main()
{
	DDRA=0xff;
	DDRB=0xff;
	DDRC=0x00;
	DDRD=0xff;
	PORTC=0x00;
	PORTD=0x00;
	LCDinit();
	int i=0;
	while(1)
	{
		if(i==4)
		{	
			i=0;
		}		
		if((PINC&0x01)==1) //if first bit is true
		{
			if((PIND&0x01)==1)
			{
				LCDclear();
				LCDstring("One");
				_delay_ms(1);	
			}
			if((PIND&0x02)==1)
			{
				LCDclear();
				LCDstring("Four");
				_delay_ms(1);
			}
			if((PIND&0x04)==1)
			{
				LCDclear();
				LCDstring("Seven");
			}
			if((PIND&0x08)==1)
			{
				LCDclear();
				LCDstring("Seven");
			}
		}	
		if((PINC&0x02)==1)
		{
			if((PIND&0x01)==1)
			{
				LCDclear();
				LCDstring("Two");

			}
			if((PIND&0x02)==1)
			{
				LCDclear();
				LCDstring("Five");
			}
			if((PIND&0x04)==1)
			{
				LCDclear();
				LCDstring("Eight");
			}
			if((PIND&0x08)==1)
			{
				LCDclear();
				LCDstring("Seven");
			}
		}
		if((PINC&0x04)==1)
		{
			if((PIND&0x01)==1)
			{
				LCDclear();
				LCDstring("Three");
			}
			if((PIND&0x02)==1)
			{
				LCDclear();
				LCDstring("Six");
			}
			if((PIND&0x04)==1)
			{
				LCDclear();
				LCDstring("Nine");
			}
			if((PIND&0x08)==1)
			{
				LCDclear();
				LCDstring("Seven");
			}
		}
		PORTD|=(1<<i);
		i++;
	}
	return 0;
}




	

	
