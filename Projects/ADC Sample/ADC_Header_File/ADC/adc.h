//Micricontroller		:All 8-bit AVR Micricontrollers with Similar Register Configuration with ATmega16
//System Clock			:1 MHz - 16 MHz
//Header File Version 		:1.1
//Author			:Arun Kumar Garg 
//				:ABLab Solutions
//				:www.ablab.in
//				:info@ablab.in
//Date				:1st August 2011

/*Copyright (c) 2011 ABLab Solutions All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
   * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the 	following disclaimer in the documentation 
     and/or other materials provided with the distribution.
   * Neither the name of the copyright holders nor the names of contributors may be used to endorse or promote products derived from this software without 
     specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */


/*The functions and macros defined in this header file are for Analog to Digital Converter of all 8-bit AVR Micricontrollers with Similar Register Configuration with ATmega16.*/

#ifndef _ADC_H_
#define _ADC_H_		1



#include<avr/io.h>
#include<util/delay.h>


/*This function is declared to initialize the Analog to Digital Converter of AVR microcontrollers. The Analog to Digital Converter is initialized with the following features:-
Auto Triggering mode is enabled,
Free running mode is the source of trigger,
ADC conversion is started,
ADC frequency is 62.5 KHz at 1 MHz system frequency.*/

void adc_init(void);


/*This function is declared to read the digital value of the ADC conversion of the selected channel with follwoing conditions:-
AVCC is selected as the refence voltage and ADC output is right adjusted.*/	

int read_adc_channel(unsigned char channel);



/*Function definations*/
void adc_init(void)
{                    
ADCSRA=(1<<ADEN)|(1<<ADSC)|(1<<ADATE)|(1<<ADPS2);
SFIOR=0x00;
}


int read_adc_channel(unsigned char channel)
{
	int adc_value;
	unsigned char temp;
  	 ADMUX=(1<<REFS0)|channel;
  	 _delay_ms(1);
	temp=ADCL;
	adc_value=ADCH;
	adc_value=(adc_value<<8)|temp;
  	 return adc_value;
}  
#endif
