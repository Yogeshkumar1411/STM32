#include<stm32f10x.h>
void delay(unsigned int ms)
{
	while(ms--);
}

void lcd_cmd(char a,char b)
{
	if(a==0)
	{
		GPIOC->BRR=1<<13;//rs=0;		
	}
	if(a==1)
	{
	GPIOC->ODR=1<<13;//rs=1;
	delay(65000);
	GPIOC->BRR=1<<13;
	delay(65000);		
	}
	GPIOA->ODR=b;
	delay(65000);
	GPIOA->BRR=b;
	delay(65000);
	GPIOC->ODR=1<<15;
	delay(65000);
	GPIOC->BRR=1<<15;
	delay(65000);
}

	
	
int main()
{
	RCC->APB2ENR=1<<2|1<<4;
	GPIOA->CRL=0X22222222;
	GPIOC->CRH=0X22200000;
	lcd_cmd(0,0X38);	
	lcd_cmd(0,0X0F);
	while(1)
	{
		lcd_cmd(0,0X80);
		lcd_cmd(1,'A');
	}
}
