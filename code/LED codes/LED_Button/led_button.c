#include<stm32f10x.h>
int main()
{
	RCC->APB2ENR|=0X00000010;
	GPIOC->CRH=0X00200000;
	RCC->APB2ENR|=0X00000004;
	GPIOA->CRL=0X00000008;
	while(1)
	{
	if(GPIOA->IDR&1<<0)
	{
		GPIOC->ODR=1<<13;
	}
	else
	{
		GPIOC->BRR=1<<13;
	}
	}
	return 0;
}
	
	