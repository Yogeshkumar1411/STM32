#include<stm32f10x.h>
int main()
{
	int count=0;
	RCC->APB2ENR=1>>2|1>>3;
	GPIOA->CRH=0X00000022;
	GPIOB->CRL=0x88800000;
	while(1)
	{
		if((GPIOB->IDR&1<<5)&&(count==0))
		{
			GPIOA->ODR=1<<8;
			count++;
		}
		if((GPIOB->IDR&1<<6)&&(count==0))
		{
			GPIOA->ODR=1<<9;
			count++;
		}
		if(GPIOB->IDR&1<<7)
		{
			GPIOA->BRR=1<<8;
			GPIOA->BRR=1<<9;
			count=0;
		}
	}
}
		