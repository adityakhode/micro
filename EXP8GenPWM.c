*/ #include <p18f4520.h>
#include <delays.h>
#pragma config OSC = HS // High-speed oscillator
#pragma config WDT = OFF // Watchdog Timer disabled
#pragma config LVP = OFF // Low-voltage Programming disabled
#pragma config PBADEN = OFF
void main()
{
//RC1= interfacing with STK
//RC3= interfacing with Ultralite
unsigned char dc ;
TRISC = 0 ; // set PORTC as output RC1,RC2,RC3 Configure as a PWM PORTC = 0 ; // clear
PORTC
/*
* configure CCP module as 10000 Hz PWM output
*/
PR2 = 0b01111100 ;
T2CON = 0b00000101 ;
CCP1CON = 0b00001100 ;
CCP2CON = 0b00111100 ;
for(;;) // forever
{
/*
* PWM resolution is 10 bits
* don't use last 2 less significant bits CCPxCON,
* so only CCPRxL have to be touched to change duty cycle
*/
for(dc = 0 ; dc < 128 ; dc++)
{
CCPR1L = dc ;
CCPR2L = 128 - dc ;
Delay10KTCYx(50);//200mS
}
for(dc = 127 ; dc > 0 ; dc--)
{
CCPR1L = dc ;
CCPR2L = 128 - dc ;
Delay10KTCYx(50);//200mS
}
}
}
