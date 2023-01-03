#include<stm32f10x.h>
void timer()
{
	TIM2->PSC=10000-1;
	TIM2->ARR=7200-1;
	TIM2->CR1|=1<<0;
	TIM2->CNT=0;
}
void timer2(int d)
{
	while(d)
	{	
	while(!(TIM2->SR&1<<0));
	
		TIM2->SR=0;
		d--;
	}
}

int main()
{
	RCC->APB1ENR|=1<<0;
	RCC->APB2ENR|=1<<2;
	GPIOA->CRL=0X00000002;
	timer();
	while(1)
	{		
		GPIOA->ODR|=1<<0;
		timer2(60);			
		GPIOA->BRR|=1<<0;
		timer2(60);
	}
}
		
