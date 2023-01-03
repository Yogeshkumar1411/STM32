#include<stm32f10x.h>
#include"lcd.h"
void print(char *p)
{
	while(*p)
	{
		lcd_dat(*p);
		p++;
	}
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
		lcd_cmd(0X80);
		lcd_dat(0X30+result1);
		lcd_dat(0X30+result3);
		lcd_dat(0X30+result5);
		lcd_dat(0X30+result6);	
}

void lcd_init()
{
	GPIOA->CRL=0X00022222;//IO port enable, 7th pin for adc and rest of the enable pins for lcd
	GPIOC->CRH=0X22200000;
	lcd_cmd(0X02);
	lcd_cmd(0X28);	
	lcd_cmd(0X0E);	
}


int main()
{
	RCC->APB2ENR|=1<<2|1<<4;//Enabling the ports
	RCC->APB2ENR|=1<<9;//Enabling the ADC  by giving clock, ADC1; by enabling the ADC1 we can use all the adcs in 
	//PORT A and by enabling the ADC2 we can use the reamining two adcs in PORT B
	RCC->CFGR=0X00100000;//ADC prescalar in the 14 and 15th bit; frequency divided by 6; and, notedly not more than 14 MHz
	GPIOA->CRL=0X80000000;
lcd_init();
	ADC1->SMPR2=0X00E00000;//Sampling time; which is selecting the cycles for the respective channel
	ADC1->SQR1=0X00000000;//Selecting the number of conversion in 20 to 23 bits; here 1 conversion
	ADC1->SQR3=0X00000007;//Selecting first sequence
	ADC1->CR2=0X00000003;//Enabling the ADC ON and contiuous conversion 
	delay(1);
	ADC1->CR2=0X00000001;//ADC ON
	delay(1);
	ADC1->CR2=0X00000004;//Calibration starts
	while(ADC1->CR2&0x00000004);	
	
	
	lcd_cmd(0Xc6);
	print("hai");
	while(1)
	{
		lcd_cmd(0XC0);
		lcd_dat('a');
		adc();			
	}
}
