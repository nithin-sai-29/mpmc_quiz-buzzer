#include<reg51.h>

#define SEGMENT P2 // PORT2 to Segments of 7-Segment Display
#define SWITCH P1  // Input Switches (buttons) to PORT1

sbit buzz=P3^0; // Buzzer
sbit rst=P3^3; // Reset Switch (Reset the display) - not the microcontroller
sbit digit=P3^7; // 7-Segment Display Common Pin (to enable)


void delay (int); // Delay function

int x=0,y,z;
unsigned char ch[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x98}; // Hexadecimal values from 0 to 9.

void delay (int d)
{
	unsigned char i;
	for(;d>0;d--)
	{
		for(i=250;i>0;i--);
		for(i=248;i>0;i--);
	}
}

void main()
{
	SWITCH=0xff;
	SEGMENT=0xff;
	digit=1;
	buzz=0;
	rst=1;
	
	while(1)
	{
		while(SWITCH==0xff); // wait until any button is pressed.
		
		while (SWITCH==0xfe) // Button 1 is pressed.
		{
			SEGMENT=ch[1];
			buzz=1;
			delay(1000); // Activate buzzer for 1 second.
			buzz=0;
			while(rst!=0); // display the digit until the reset is pressed.
		}
		
		while (SWITCH==0xfd) // Button 2 is pressed.
		{
			SEGMENT=ch[2];
			buzz=1;
			delay(1000);
			buzz=0;
			while(rst!=0);
		}
		
		while (SWITCH==0xfb) // Button 3 is pressed.
		{
			SEGMENT=ch[3];
			buzz=1;
			delay(1000);
			buzz=0;
			while(rst!=0);
		}
		
		while (SWITCH==0xf7) // Button 4 is pressed.
		{
			SEGMENT=ch[4];
			buzz=1;
			delay(1000);
			buzz=0;
			while(rst!=0);
		}
		
		while (SWITCH==0xef) // Button 5 is pressed.
		{
			SEGMENT=ch[5];
			buzz=1;
			delay(1000);
			buzz=0;
			while(rst!=0);
		}
		
		while (SWITCH==0xdf) // Button 6 is pressed.
		{
			SEGMENT=ch[6];
			buzz=1;
			delay(1000);
			buzz=0;
			while(rst!=0);
		}
		
		while (SWITCH==0xbf) // Button 7 is pressed.
		{
			SEGMENT=ch[7];
			buzz=1;
			delay(1000);
			buzz=0;
			while(rst!=0);
		}
		
		while (SWITCH==0x7f) // Button 8 is pressed.
		{
			SEGMENT=ch[8];
			buzz=1;
			delay(1000);
			buzz=0;
			while(rst!=0);
		}
		
		SEGMENT=0xff;
		rst=1;
		
}
}