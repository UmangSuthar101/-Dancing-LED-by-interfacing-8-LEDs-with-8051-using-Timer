#include< reg51.h>

void delay()
{
int count=0;
 while(count!=500)
  {
   TMOD=0x01;  //16-bit timer0 selected
   TH0=0xF8;   // Loading high byte in TH
   TL0=0xCC;   // Loaded low byte in TL
   TR0=1;      // Running the timer
    while(!TF0);   //Checking the timer flag register if it is not equal to 1 
   TR0 = 0;      // If TF0=1 stop the timer
   TF0 = 0;      // Clear the Timer Flag bit for next calculation

   count++;
  }

}

void main()
{
int count=0;

while(1){

//Pattern one led blink and moves up to 8th one - Then moves back one by one to 1st
while(count!=2){ 
P1=0x01;delay();P1=0x02;delay();P1=0x04;delay();
P1=0x08;delay();P1=0x10;delay();P1=0x20;delay();
P1=0x40;delay();P1=0x80;delay();P1=0x80;delay();
P1=0x40;delay();P1=0x20;delay();P1=0x10;delay();
P1=0x08;delay();P1=0x04;delay();P1=0x02;delay();
P1=0x01;delay();
count++;
}

count=0;
//Eight leds divided in to two half
while(count!=2) // Four leds pattern same task like the above one with two halfs
{
delay();P1=0x18;delay();P1=0x24;delay();P1=0x42;
delay();P1=0x11;delay();P1=0x11;delay();P1=0x42;
delay();P1=0x24;delay();P1=0x18;delay();
count++;
}

count=0;
while(count!=2) //Leds blinking from the middle
{
delay();P1=0x18;delay();P1=0x3C;delay();P1=0x7E;
delay();P1=0xFF;delay();P1=0x00;delay();P1=0x81;
delay();P1=0xC3;delay();P1=0xE7;delay();P1=0xFF;
delay();
count++;
}

//Random blinking pattern
delay();P1=0x20;delay();P1=0x01;delay();P1=0x04;
delay();P1=0x80;delay();P1=0x04;delay();P1=0x02;
delay();P1=0x10;delay();P1=0x40;delay();P1=0x80;
delay();P1=0x08;delay();P1=0x04;delay();P1=0x01;
delay();P1=0x10;delay();P1=0x80;delay();P1=0x20;
delay();
count=0;
}

}