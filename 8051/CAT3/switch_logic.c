#include<reg51.h>
sbit prt20=P2^0;
sbit prt25=P2^5;
sbit led=P1^0;

//Delay function.
void delay(int ms)
{
	unsigned char j;
	int i;
	for(i=0;i<ms;i++)
	{
		for(j=0;j<127;j++);	
}}

//Main method..
	void main()
	{
		prt20=1;
		prt25=0;
		led=0;
		while(1)
		{
			if(prt20==0)
			{led=1;
			}
			else
			{led=0;}
	}
}