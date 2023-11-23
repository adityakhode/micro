#include <p18f4520.h>
#include <stdio.h>
#include <delays.h>
#pragma config OSC = HS // High-speed oscillator
#pragma config WDT = OFF // Watchdog Timer disabled
#pragma config LVP = OFF // Low-voltage Programming disabled
void InitUSART()
{
TRISCbits.TRISC6 = 1; //make Tx Pin of UART
TRISCbits.TRISC7 = 1; //make Rx Pin of UART
SPBRG = 31 ; //9600 baud @ 20MHz(HS MODE)
TXSTA = 0x20; //Transmitter Enable
RCSTAbits.SPEN =1; //Serial Port Enble
RCSTAbits.CREN =1; //Continues Receive Enable bit
}
unsigned char getchar(void)
{
unsigned char ch;
while (!(PIR1bits.RCIF==1)); //wait until there's a character to be read ch=RCREG;
//then read from the Receiver Buffer Register return ch;
}
unsigned char putchar(unsigned char ch)
{
while (!(PIR1bits.TXIF==1)); //wait until Transmitter Buffer Register Empty TXREG=ch;
//then write to the Transmitter Buffer Register return ch;
}
void main (void)
{
InitUSART() ;
printf("Hello PIC18f4520!\r\n") ;
while(1)
{
putchar(getchar());
}
}
