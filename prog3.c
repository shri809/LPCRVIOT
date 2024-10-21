#include<lpc214x.h>
void delay(unsigned int j);
int main()
{
   IO0DIR=0x0f<<16;
	
	int clk=100;
	int aclk=100;
	
	do{
	
		IO0CLR=0x000F0000;IO0SET=0x00010000;if(--clk==0) break;
		delay(10);
		 IO0CLR=0x000F0000;IO0SET=0x00020000;if(--clk==0) break;
		delay(10);
		 IO0CLR=0x000F0000;IO0SET=0x00040000;if(--clk==0) break;
		delay(10);
		 IO0CLR=0x000F0000;IO0SET=0x00080000;if(--clk==0) break;
		delay(10);
		 
	
	}while(1);
	do{
	
	  IO0CLR=0x000F0000;IO0SET=0x00080000;if(--clk==0) break;
		delay(10);
		 IO0CLR=0x000F0000;IO0SET=0x00040000;if(--clk==0) break;
		delay(10);
				 IO0CLR=0x000F0000;IO0SET=0x00020000;if(--clk==0) break;
		delay(10);
		IO0CLR=0x000F0000;IO0SET=0x00010000;if(--clk==0) break;
		delay(10);
		
	
	}while(1);



}

void delay(unsigned int j)
{
 int i,x;
	for(i=0;i<j;i++)
	{
	  for(x=0;x<10000;x++);
	
	}



}