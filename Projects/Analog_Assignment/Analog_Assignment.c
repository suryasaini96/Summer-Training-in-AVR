#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000

void ADC_init(void) 
{
	ADMUX=(1<<REFS1)|(1<<REFS0);
	ADCSRA=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0); //Using prescalar of 128													//So ADC freq is 16000000/128
}

int ADC_read(unsigned char channel)
{
	channel=channel&0x07; // Keeping channel between 0 to 7
	ADMUX|=channel; // OR ADMUX with channel with cleared last 3 bits
	ADCSRA|=(1<<ADSC); // In ADC Control and Status register A
					 // start the conversion of Analog to Digital
	while(!(ADCSRA|=(1<<ADIF))); //Using a loop until ADSC is true i.e. waiting for 
								// conversion to complete
	return ADC;					  
}


int main()
{
	DDRD=0xff;
	int ADC_output;
	ADC_init();
	while(1)
	{
		ADC_output=ADC_read(0); // Read analog signal from Port A0
		if(ADC_output<1024)		// ADC_output is in 10 bit resolution from 0 to 1023
		{
			PORTD=0xff;	
			_delay_ms(2000);
			PORTD=0x03;  
			_delay_ms(2000);
		}
		else
		{
			PORTD=0x00;
		}
	}
	return 0;
}
			

			




