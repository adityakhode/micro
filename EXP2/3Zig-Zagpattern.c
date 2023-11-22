#include <reg51.h>

void delay(int x);

void main()
{
	P2 = 0x00;
	while (1)
	{
		P2 = 0x55;
    delay(1000);
    P2 = 0xAA;
    delay(1000);
	}
}

void delay(int x)
{
	int i,j;
	for(i = 0; i<=x ; i++)
		{
			for(j = 0; j<= 1000; j++)
				{
					//do nothing
				}
			
		}
}
