#include<lpc214x.h>
#define LED_ON (IO0CLR=1U<<31);
#define LED_OF (IO0SET=1U<<31);
unsigned char getAlpha(unsigned char c);
void delay(unsigned int j);
void alphadisp( char *buf);

int main()
{
   IODIR0=1<<19 | 1<<20 | 1<<30;
	while(1)
	{alphadisp("fire ");
	delay(5);
	alphadisp("help");
		delay(5);
	}
	
   
}

unsigned char getAlpha(unsigned char c)
{
  switch(c)
	{
		case 'f':return 0x8e;
		case 'i':return 0xf9;
		case 'r':return 0xce;
		case 'e':return 0x86;
		case 'h':return 0x89;
		case 'p':return 0x8c;
		case 'l':return 0xc7;
		default:break;
	}
	return 0xff;
	


}

void alphadisp(char *buf)
{
    unsigned char i , j;
	unsigned char seg7;
	unsigned char temp=0;
	
	
	for(i=0;i<5;i++)
	{
	    seg7=getAlpha(*(buf+i));
		
		for (j=0;j<8;j++)
		{
		
		    temp=seg7 & 0x80;
			if(temp==0x80)
			{
			   IO0SET=1<<19;
				
			}
			else{
			  IOCLR0=1<<19;
			}
			IOSET0=1<<20;
			delay(1);
			IOCLR0=1<<20;
			seg7=seg7<<1;
			
		}
		IOSET0=1<<30;
		delay(1);
		IOCLR0=1<<30;
	
	
	
	}



}

void delay(unsigned int j)
{
   int i,x;
	for(i=0;i<j;i++)
	{
	   for(x=0;x<10000;x++);
	
	}
}