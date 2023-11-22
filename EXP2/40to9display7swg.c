#include<reg51.h>
void delay(long int x)
{
	int i,j;
	for(i = 0; i<x; i++)
		for(j = 0; j<100; j++)
			{
				//nothing
			}
}

unsigned char arr[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void main()
{
	while(1)
	{
		int i;
		for (i =0;i<=9;i++)
			{
				P0 = arr[i];
				delay(10000);
			}
	}
}
