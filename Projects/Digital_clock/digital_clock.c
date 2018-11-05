#include<avr/io.h>
#include<util/delay.h>
#define F_CPU 16000000 UL>
#include<hmritm/lcd_my.h>

int main()
{
	DDRB=0XFF;
	int sec=0;
	int hr=0;
	int min=0;
	init();
	while(1)
	{
		start:
		for(hr=0;hr<=24;hr++)
		{
			for(min=0;min<=60;min++)
			{
				if(min==60)
				{	
					lcd_clear();
					break;
				}
				for(sec=0;sec<=60;sec++)
				{
					if(sec==60)
					{	
						lcd_clear();
						break;
					}
					if(hr==24)
					{	
						lcd_clear();
						goto start;
					}							
					lcd_cmd(0x81);
					lcd_number(hr);
					lcd_cmd(0x82);
					lcd_data(':');
					lcd_cmd(0x84);
					lcd_number(min);
					lcd_cmd(0x85);
					lcd_data(':');
					lcd_cmd(0x87);
					lcd_number(sec);
					_delay_ms(100);
				}
			}
		}
	}
	return 0;
}

