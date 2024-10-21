 
#include <lpc214x.h>
 
#define LED_OFF (IO0SET = 1U << 31)
#define LED_ON (IO0CLR = 1U << 31)
#define COL0 (IO1PIN & 1 <<19)
#define COL1 (IO1PIN & 1 <<18)
#define COL2 (IO1PIN & 1 <<17)
#define COL3 (IO1PIN & 1 <<16)
 
void delay_ms(unsigned int j);
void uart_init(void);
unsigned char lookup_table[4][4]={ {'0', '1', '2','3'},
{'4', '5', '6','7'},
{'8', '9', 'a','b'},
{'c', 'd', 'e','f'}};
unsigned char rowsel=0,colsel=0;


int main()
{
   IO0DIR=0x0f<<16;
	uart_init();
	
	do{
		
		while(1)
		{
			
			
	rowsel=0;IO0SET = 0X000F0000;IO0CLR = 1 << 16;
if(COL0==0){colsel=0;break;};if(COL1==0){colsel=1;break;};
if(COL2==0){colsel=2;break;};if(COL3==0){colsel=3;break;};
 

rowsel=1;IO0SET = 0X000F0000;IO0CLR = 1 << 17;
if(COL0==0){colsel=0;break;};if(COL1==0){colsel=1;break;};
if(COL2==0){colsel=2;break;};if(COL3==0){colsel=3;break;};

 
rowsel=2;IO0SET = 0X000F0000;IO0CLR = 1 << 18;//make row2 '0'
if(COL0==0){colsel=0;break;};if(COL1==0){colsel=1;break;};
if(COL2==0){colsel=2;break;};if(COL3==0){colsel=3;break;};

 

rowsel=3;IO0SET = 0X000F0000;IO0CLR = 1 << 19;//make row3 '0'
if(COL0==0){colsel=0;break;};if(COL1==0){colsel=1;break;};
if(COL2==0){colsel=2;break;};if(COL3==0){colsel=3;break;};
		
		}
		delay_ms(50);
		while(COL0==0 | COL1==0 | COL2==0 |COL3==0 );
	
	delay_ms(50);
		IO0SET=0x0f<<16;
		U0THR=lookup_table[rowsel][colsel];
	
	}while(1);
	

}

void uart_init(void)
{
 PINSEL0|=0x00000005;
	U0LCR=0x83;
	U0DLL=8;
	U0DLM=0;
	U0LCR=0x03;
	U0FCR=0x07;
	


}

void delay_ms(unsigned int j)
{
unsigned int x,i;
for(i=0;i<j;i++)
{
for(x=0; x<10000; x++);
}
}