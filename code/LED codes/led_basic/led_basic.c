#include<stm32f10x.h>
void delay(unsigned int ms)
{
	int i,j;
	for(i=0;i<ms;i++)
	{
		for(j=0;j<65535;j++);
	}
}
int main()
{
	RCC->APB2ENR|=1<<2|1<<3;
	GPIOA->CRL=0X00000088;
	GPIOB->CRH=0X00000020;
	while(1)
	{
		if(GPIOA->IDR&1<<0)
		{
		GPIOB->ODR|=1<<9;
		}
		if(GPIOA->IDR&1<<1)
		{
		GPIOB->BRR|=1<<9;
		}
	}
}