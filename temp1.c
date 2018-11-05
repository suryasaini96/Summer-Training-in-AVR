#include<avr/io.h>
#include<util/delay.h>
#include<hmr/lcd.h>
#define F_CPU 1600000 UL
unsigned int val;
unsigned int temp;
void adc_init(); 
unsigned int adc_read(unsigned int ch);
void main()
{
DDRB=0xff;

DDRA=0x00;
adc_init();
init();
LCD_clear();
lcd_cmd(0x80);
lcd_string('Tem');
while(1)
{
temp=adc_read(0);
temp=temp*500;
temp=temp/1024;
lcd_cmd(0x87);
lcd_number(temp);
_delay_ms(10 );
}

}
void adc_init()
{

//ADMUX |=(1<<REFS1)|(1<<REFS0);
ADMUX=0b01000000;
ADCSRA |=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);


} 


unsigned int adc_read(unsigned int ch)
{
ch= ch&0x07;
ADMUX |=ch;
ADCSRA |=(1<<ADSC);
while(!(ADCSRA |=(1<<ADIF)));
return ADC;
}



