#include<stm32f10x.h>
#define RS 1<<14
#define EN 1<<15
void delay(unsigned int ms)
{
	int i,j;
	for(i=0;i<=ms;i++)
	{
		for(j=0;j<=65535;j++);
	}
}
void pulse()
{
	GPIOC->ODR|=EN;
	delay(2);
	GPIOC->BRR|=EN;
	delay(2);
}
void lcd_cmd(int a,char data)
{
	if(a==0)
	{
		GPIOC->BRR|=RS;
	}
	if(a==1)
	{
		GPIOC->ODR|=RS;
	}
	
	GPIOA->BRR=0X0000001E;
	
	GPIOA->ODR=(data & 0XF0)>>3;
	pulse();
	GPIOA->ODR=(data & 0X0F)<<1;
	pulse();
	
}	
void adc()
{
	int adc,result1,result2,result3,result4,result5,result6;
			if(ADC1->SR&0X00000002)
		{
			adc=ADC1->DR;			
		}
	result1=adc/1000;
	result2=adc%1000;
	result3=result2/100;
	result4=result2%100;
	result5=result4/10;
	result6=result4%10;
		lcd_cmd(0,0X80);
		lcd_cmd(1,0X30+result1);
		lcd_cmd(1,0X30+result3);
		lcd_cmd(1,0X30+result5);
		lcd_cmd(1,0X30+result6);
	
}



int main()
{
	RCC->APB2ENR=1<<2|1<<4;//Enabling the ports
	RCC->APB2ENR=0X00000200;//Enabling the ADC  by giving clock, ADC1; by enabling the ADC1 we can use all the adcs in 
	//PORT A and by enabling the ADC2 we can use the reamining two adcs in PORT B
	RCC->CFGR=0X00008000;//ADC prescalar in the 14 and 15th bit; frequency divided by 6; and, notedly not more than 14 MHz
	GPIOA->CRL=0X80022220;//IO port enable, 7th pin for adc and rest of the enable pins for lcd
	GPIOC->CRH=0X22200000;
	ADC1->SMPR2=0X00E00000;//Sampling time; which is selecting the cycles for the respective channel
	ADC1->SQR1=0X00000000;//Selecting the number of conversion in 20 to 23 bits; here 1 conversion
	ADC1->SQR3=0X00000007;//Selecting first sequence
	ADC1->CR2=0X00000003;//Enabling the ADC ON and contiuous conversion 
	delay(1);
	ADC1->CR2=0X00000001;//ADC ON
	delay(1);
	ADC1->CR2=0X00000004;//Calibration starts
	while(ADC1->CR2&0x00000004);
	lcd_cmd(0,0X28);
	lcd_cmd(0,0X02);
	lcd_cmd(0,0X0E);
	while(1)
	{
		lcd_cmd(0,0XC0);
		lcd_cmd(1,'a');
		adc();			
	}
}
