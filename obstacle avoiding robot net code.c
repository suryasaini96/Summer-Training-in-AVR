#define F_CPU 1000000UL     //set your clock speed
#include <avr/io.h>
#include <util/delay.h>

int right_turn=0b00001010;

int left_turn=0b00000101;

int left_sensor_on=0b0000001;
int right_sensor_on=0b0000010;

int left_sensor_off=0b0000000;
int right_sensor_off=0b0000000;


void wait(float x)
{
for(int i=0;i<(int)(1302*x);i++)
_delay_loop_1(0);
}


void main ()
{


DDRB = 0xFF; //Output port
DDRC = 0b0000000; //input port

  int left_sensor = 0;
  int right_sensor = 0;

while(1)   //create an infinite loop
{



 left_sensor = (PINC & 0b0000001);
 right_sensor = (PINC & 0b0000010);

  if((left_sensor==left_sensor_off) & (right_sensor==right_sensor_off))
    {
         PORTB=0b00001001;        //move forward

  }

      if(( left_sensor==left_sensor_on) & (right_sensor==right_sensor_off))

    {
       PORTB=0b00000110;
    wait(2.0);
    PORTB=right_turn;
     wait(1.0);

    }
 
   if(( left_sensor==left_sensor_off) & (right_sensor==right_sensor_on))
    {
      PORTB=0b00000110;
    wait(2.0);
    PORTB=left_turn;
    wait(1.0);

    }
if(( left_sensor==left_sensor_on) & (right_sensor==right_sensor_on))

    {
       PORTB=0b00000000;
    wait(1.0);
    PORTB=0b00000110;
    wait(2.0);
    PORTB=left_turn;
    wait(1.0);


}

}