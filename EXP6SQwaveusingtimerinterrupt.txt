*/ /*
Cal = for 20MHz oscillator and 256 prescalar, the effective instruction execution speed is
(4*256)/20×10^6 which will give you 51.2uS (micro second) per instruction.
So for 1 second 19625(it is 1/51.2uS).
Since we know interrupt happens only when the timer buffer overflows,
for a 16 bit timer the preset value to achieve 1 second for overflow will be 65535 – 19625(0x4c4b) = 0xb3b4.
*/
#include <p18f4520.h>
#include <delays.h>

#pragma config OSC = HS // High-speed oscillator
#pragma config WDT = OFF // Watchdog Timer disabled
#pragma config LVP = OFF // Low-voltage Programming disabled
#pragma config PBADEN = OFF
#define BUZZER PORTAbits.RA3 //Buzzer connected to PORTA 3rd PIN
unsigned char TimerOnflag=0, Num=0;
void Timer0Init()
{
T0CON = 0x87; ; // Prescaler of 256, Timer Prescaler assigned , Increment on low to high transition,
//16 BIT MODE, Turns timer on
TMR0H =0xB3;
TMR0L = 0xB4;
// Interrupt Setup
RCONbits.IPEN = 1; // Interrupt priority enabled
INTCON = 0xE0; // Enables Global Interrupts, Peripheral Interrupts, Enables overflow Interrupt, Sets
//overflow bit to zero
INTCON2bits.TMR0IP = 1; // Timer 0 Interrupt is high priority
}
void TMRISR (void) ;
#pragma code InterruptVectorHigh=0x08
void InterruptVectorHigh (void)
{
_asm
goto TMRISR
_endasm
}
#pragma code
#pragma interrupt TMRISR
void TMRISR (void) //Timer ISR
{
if(INTCONbits.TMR0IF == 1)
{
INTCONbits.TMR0IF=0; //Clear Interrupt Flag to prevent reinitialisation of ISR
TMR0H =0xB3;
TMR0L = 0xB4;
if(TimerOnflag)
{
PORTD = 0x00;
TimerOnflag=0;
BUZZER =0;
Delay10KTCYx(700);
}
else
{
PORTD = 0xff;
TimerOnflag=1;
BUZZER =0;
Delay10KTCYx(700);
}
}
}
void main (void)
{
Timer0Init();
TimerOnflag=0;
TRISD = 0x00; //Port configured as Output
PORTD = 0x00; //PORTD = 0x00
while(1)
{
BUZZER =1;
}
}
