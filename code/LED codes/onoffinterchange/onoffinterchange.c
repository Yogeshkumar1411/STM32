#include<stm32f10x.h>
int main()
{
	int a=1<<11;
	int b=1<<12;
	int c;
	RCC->APB2ENR=1<<2|1<<3;
	GPIOA->CRH=0X00000200;
	GPIOB->CRH=0X00888000;
	while(1)
	{
		if(GPIOB->IDR&a)
		{
			GPIOA->ODR|=1<<10;
		}
		if(GPIOB->IDR&b)
		{
			GPIOA->BRR|=1<<10;
		}
		if(GPIOB->IDR&1<<13)
		{
			c=a;
			a=b;
			b=c;
		}
	}
}