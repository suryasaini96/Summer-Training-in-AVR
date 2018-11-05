#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>
#define lcd_port PORTD
#define en PC2
#define rw PC1
#define rs PC0

void LCD_cmd(unsigned char cmd);
void LCD_data(unsigned char data);
void LCD_init();
void LCD_clear();
void LCD_string(unsigned char *str);

int main()
{
	DDRC=0xff;
	DDRD=0xff;                 
	LCD_init();
    while(1)
  	{ 
		LCD_cmd(0x80); // For first bit position on LCD
		//LCD_data('a');
        LCD_string("Surya");
   		//LCD_cmd(0xC0);
		_delay_ms(1);
	}
  return 0;
}

void LCD_init()
{
  LCD_cmd(0x02); // Return home
  LCD_cmd(0x38); // For 8 bit mode
  LCD_cmd(0x06); // Increment cursor
  LCD_cmd(0x0c); // Display on cursor off 
}
 

void LCD_cmd(unsigned char cmd)
{           
	lcd_port=cmd;
    PORTC&=~(1<<rs);
    PORTC&=~(1<<rw);
    PORTC|=(1<<en);
   	_delay_ms(1);
    PORTC&=~(1<<en);
	_delay_ms(5);
}

void LCD_data(unsigned char	data)
{           
	lcd_port=data;
	PORTC|=(1<<rs);
    PORTC&=~(1<<rw);
    PORTC|=(1<<en);
    _delay_ms(1); //delay for transmitting data
    PORTC&=~(1<<en);
}

void LCD_string(unsigned char *str)
{
	int i=0;
    while(str[i]!='\0')
    {
		LCD_data(str[i]);
        i++;
	}
}

void LCD_clear()
{           
	LCD_cmd(0x01);
	_delay_ms(200); 
}




