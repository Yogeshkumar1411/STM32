#include<stm32f10x.h>
int i,j;
void delay(unsigned int ms)
{
	
	for(i=0;i<ms;i++)
	{
		//for(j=0;j<65000;j++);
	}
}
int main()
{
	int count=0,k;
	RCC->APB2ENR=1<<2|1<<3;
	GPIOA->CRL=0X00008888;
	GPIOB->CRL=0X00000002;
	while(1)
	{
		if(GPIOA->IDR&1<<0)
		{
			count++;
			while(GPIOA->IDR&1<<0);
		}
		if(GPIOA->IDR&1<<1)
		{
			count++;
			while(GPIOA->IDR&1<<1);
		}
		if(GPIOA->IDR&1<<2)
		{
			for(k=0;k<count;k++)
		{
			GPIOB->ODR|=1<<0;
			delay(65000);delay(65000);delay(65000);delay(65000);delay(65000);delay(65000);delay(65000);delay(65000);
			GPIOB->BRR|=1<<0;
			delay(65000);delay(65000);delay(65000);delay(65000);delay(65000);delay(65000);delay(65000);delay(65000);delay(65000);delay(65000);
		}
		while(GPIOA->IDR&1<<2);
		}
		if(GPIOA->IDR&1<<3)
		{
			GPIOB->BRR|=1<<0;
			count=0;
			while(GPIOA->IDR&1<<3);
		}
	}
}
