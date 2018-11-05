#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>
#define lcd_port PORTC
#define en PC2
#define rw PC1
#define rs PC0

void LCD_cmd(unsigned char cmd);
void LCD_data(unsigned char data);
void disp_cmd(unsigned char cmd);
void disp_data(unsigned char data);
void LCD_init();
void LCD_clear();
void LCD_num(unsigned int num);
void LCD_string(unsigned char *str);

int main()
{   
	DDRC=0xff;
	DDRB=0xff;             
	LCD_init();
    while(1)
  	{   
		disp_cmd(0x80);
	    LCD_string("Surya");
		_delay_ms(1);
	}
  return 0;
}

void LCD_init()
{
  LCD_cmd(0x02); // Return home
  LCD_cmd(0x28); // For 4 bit mode
  LCD_cmd(0x06); // Increment cursor
  LCD_cmd(0x0c); // Display on cursor off 
}
 

void LCD_cmd(unsigned char cmd)
{           
    lcd_port=cmd;
	PORTC&=~(1<<rs);
	PORTC&=~(1<<rw);
	PORTC|=(1<<en);
	_delay_ms(1); //delay for cmd transmit
	PORTC&=~(1<<en);
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

/*void disp_cmd(unsigned char cmd)
{
	char text;
	text=(cmd&0xF0);
	LCD_cmd(text);
	text=((cmd<<4)&0xF0);
	LCD_cmd(text);
	_delay_ms(1);
}*/

/*void disp_data(unsigned char data)
{
	char text1;
	text1=(data&0xF0); //transmit first 4 bits first 
	LCD_data(text1);
	text1=((data<<4)&0xF0); // transmit last 4 bits
	LCD_data(text1);
	_delay_ms(1);
}*/

void LCD_string(unsigned char *str)
{
	int i=0;
    while(str[i]!='\0')
    {
		disp_data(str[i]);
        i++;
	}
}

void LCD_num(unsigned int num)
{           
	  disp_cmd(0x04);          
	  int d=0;
	  while(num!=0)
	  {
	  	d=num%10;
	    disp_data(d+48);
	    num=num/10;
		disp_cmd(0x06);
	  }
	  
}


void LCD_clear()
{           
	disp_cmd(0x01);
	_delay_ms(1); 
}




