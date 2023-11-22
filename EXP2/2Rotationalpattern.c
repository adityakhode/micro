#include <reg51.h>

void delay(int x);

void main()
{
	P2 = 0x00;
	while (1)
	{
		int i;
		P2 = 0x01;
		for (i = 0;i<=7; i++)
		{
			P2 = P2<<1;
			delay(1000);
			
		}
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
