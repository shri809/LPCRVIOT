#include <lpc214x.h>
#include <stdio.h>

#define LED_OFF (IO0SET = 1U << 31)
#define LED_ON (IO0CLR = 1U << 31)
#define SW2 (IO0PIN & (1 << 14))
#define SW3 (IO0PIN & (1 << 15))
#define SW4 (IO1PIN & (1 << 18))
#define SW5 (IO1PIN & (1 << 19))
#define SW6 (IO1PIN & (1 << 20))
 
static void delay_ms(unsigned int j);//millisecond delay
short int sine_table[ ] =
{512+0,512+53,512+106,512+158,512+208,512+256,512+300,512+342,512+380,512+413,
512+442,512+467,512+486,512+503,512+510,512+511,
512+510,512+503,512+486,512+467,512+442,512+413,512+380,512+342,512+300,512+256,512+208,512+158,512+106,512+53,512+0,
512-53,512-106,512-158,512-208,512-256,512-300,512-342,512-380,512-413,512-442,512-
467,512-486,512-503,512-510,512-511,
512-510,512-503,512-486,512-467,512-442,512-413,512-380,512-342,512-300,512-
256,512-208,512-158,512-106,512-53};
short int sine_rect_table[ ] =
{512+0,512+53,512+106,512+158,512+208,512+256,512+300,512+342,512+380,512+413,
512+442,512+467,512+486,512+503,512+510,512+511,
512+510,512+503,512+486,512+467,512+442,512+413,512+380,512+342,512+300,512+256,512+208,512+158,512+106,512+53,512+0};

	
int main()
{
   PINSEL1=0x00080000;
    int i=0;
  int value;
 if(!SW2)
 {
      while(i!=60)
			{
			   value=sine_table[i++];
				DACR=(1<<16 | value<<6);
				delay_ms(10);
			
			}
			i=0;
 
 }
 
 else if(!SW3)
 {
      while(i!=30)
			{
			   value=sine_rect_table[i++];
				DACR=(1<<16 | value<<6);
				delay_ms(10);
			
			}
			i=0;
 
 }
 else if(!SW4)
 {
	   value=0;
      while(value!=1023)
			{
			   
				DACR=(1<<16 | value<<6);
				value++;
		 
			
			}
			while(value!=0)
			{
			   
				DACR=(1<<16 | value<<6);
				value--;
				 
			
			}
			 
 
 }
 else if(!SW5)
 {
	 value=0;
      while(value!=1023)
			{
			   
				DACR=(1<<16 | value<<6);
				value++;
				 
			
			}
			 
			 
 
 }
  else if(!SW6)
 {
	 value=1023;
       
			   
				DACR=(1<<16 | value<<6);
				 
				delay_ms(1);
	 value=0;
	 DACR=(1<<16 | value<<6);
	 delay_ms(1);
			
			} 
			 
			 
 
 
 else{
 
  value=1023;
	 DACR=(1<<16 | value<<6);
 }

   	
	
	
}
		void delay_ms(unsigned int j)
{
unsigned int x,i;
for(i=0;i<j;i++)
{
for(x=0; x<10000; x++);
}
}