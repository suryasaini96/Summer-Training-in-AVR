#define lcd_port PORTB
#define rs PB0
#define rw PB1
#define en PB2
void init()
{
	lcd_cmd(0X02);
	lcd_cmd(0X28);
	lcd_cmd(0X06);
	lcd_cmd(0X0C);
}

void lcd_cmd(unsigned char cmd)
{
	lcd_port=cmd&0xf0;
	lcd_port&=~(1<<rs);
	lcd_port&=~(1<<rw);
	lcd_port|=(1<<en);
	_delay_ms(1);
	lcd_port&=~(1<<en);
	lcd_port=(cmd<<4)&0xf0;
	lcd_port&=~(1<<rs);
	lcd_port&=~(1<<rw);
	lcd_port|=(1<<en);
	_delay_ms(1);
	lcd_port&=~(1<<en);
	
}

void lcd_data( unsigned char data)
{
	lcd_port=data&0xf0;
	lcd_port|=(1<<rs);
	lcd_port&=~(1<<rw);
	lcd_port|=(1<<en);
	_delay_ms(1);
	lcd_port&=~(1<<en);
	lcd_port=(data<<4)&0xf0;
	lcd_port|=(1<<rs);
	lcd_port&=~(1<<rw);
	lcd_port|=(1<<en);
	_delay_ms(1);
	lcd_port&=~(1<<en);
}

void lcd_string(unsigned char *str)
{
	int i=0;
	while(str[i]!='\0')
	{
		lcd_data(str[i]);
		i++;
	}
}

void lcd_number(unsigned int abc)       
 { 
        lcd_cmd(0x04);         // auto decrement mode
        unsigned int d=0;  
	if(abc==0)
	{
		lcd_data('0');
	}                 
	else
	{
		while(abc!=0)
	   	{ 
	         d=abc%10;
          	 lcd_data(d+48);       // display digit
       		 abc=abc/10;
        	 }
	}	 
          lcd_cmd(0x06);         //auto increment mode	

}

lcd_clear()
{
	lcd_cmd(0x01);
	_delay_ms(1);
}
