#include<lpc214x.h>
#define LED_ON (IO0CLR=1U<<31)
#define LED_OF (IO0SET=1U<<31)
void  elevator();
void delay(unsigned int j);
int main()
{
  IO0DIR=0xFF<<16;
	IO1DIR=1<<24;
	LED_ON;
	elevator();
	while(1);

}

void elevator()
{
  unsigned int count;
	int i,j;
	IO1CLR=1<<24;
	
	int val;
	do{
	   IO0CLR=0x0F<<20;
		 delay(1);
		IO0SET=0x0F<<20;
		
		do{
		  count=((IO1PIN>>16)&0x0F);
		
		}while(count==0x0F);
		
		
		if(count==0x0e)
			val=3;
		if(count==0x0d)
			val=6;
		if(count==0x09)
			val=8;
		if(count==0x07)
			val=10;
		
	   
	for(i=0;i<val;i++)
		{
		   IO0CLR=0x0F<<16;
			IO0SET=i<<16;
			delay(250);
		
		}
		for(i=val;i>=0;i--)
		{
		   IO0CLR=0x0F<<16;
			IO0SET=i<<16;
			delay(250);
		
		}
	
	
	}while(1);


}

void delay(unsigned int x)
{
     int i,j;
	for(i=0;i<x;i++)
	{
	      for(j=0;j<10000;j++);
	
	}



}