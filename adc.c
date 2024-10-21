#include <lpc214x.h>
#define LED_ON (IO0CLR=1<<31)
#define LED_OFF (IO0SET=1<<31)

void delay_ms(unsigned int j);
unsigned int adc(int no,int ch);
void runDCMotor(int direction, int dutycycle);

int main(){
	int dig_val;
	IO0DIR|=1U<<31|0x00FF0000;
	do{
		dig_val=adc(1,3)/10;
		if(dig_val>100) dig_val=100;
		runDCMotor(2,dig_val);
	}while(1);
}

void runDCMotor(int direction,int dutycycle){
	IO0DIR|=1U<<28;
	PINSEL0|=2<<18;
	if(direction==1) IO0SET|=1<<28;
	else IO0CLR|=1<<28;
	
	PWMMCR=0x02;
	PWMPCR=(1<<14);
	PWMMR0=1000;
	PWMMR6=(1000*dutycycle)/100;
	PWMTCR=0x09;
	PWMLER=0x70;
}
unsigned int adc(int no,int ch){
	PINSEL0|=0x0F300000;
	int val;
	switch(no){
		case 0:AD0CR=(0x00200600|1<<ch);
		AD0CR|=1<<24;
		while((AD0GDR&(1U<<31))==0);
		val=AD0GDR;
		break;
		
		case 1:AD1CR=(0x00200600|1<<ch);
		AD1CR|=1<<24;
		while((AD1GDR&(1U<<31))==0);
		val=AD1GDR;
		break;
	}
	val=(val>>6)&0x3FF;
	return val;
}

void delay(unsigned int j){
	unsigned int i,x;
	for(i=0;i<j;i++)
		for(x=0;x<1000;x++);
}