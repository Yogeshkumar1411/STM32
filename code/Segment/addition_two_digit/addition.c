#include<stm32f10x.h>
int count=0,i,a,b;
char seg[20]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};
void delay(unsigned int ms)
{
	while(ms--);
}
int main()
{	
	RCC->APB2ENR=1<<2|1<<3|1<<4;
	GPIOA->CRL=0X22222222;
	GPIOB->CRL=0X00008888;
	GPIOC->CRH=0X02200000;
	while(1)
	{
		if(GPIOB->IDR&1<<0)
		{
			count++;
			while(GPIOB->IDR&1<<0);
		}
		if(GPIOB->IDR&1<<1)
		{
			count++;
			while(GPIOB->IDR&1<<1);
		}
		if(GPIOB->IDR&1<<2)
		{
			for(i=0;i<count;i++)
			{
				a=i/10;
				b=1%10;
				GPIOC->BRR|=1<<13;
				GPIOC->ODR|=1<<14;
				GPIOA->ODR|=seg[a];
				delay(65000);
				GPIOA->BRR|=seg[a];
				delay(65000);
				
				GPIOC->BRR|=1<<14;
				GPIOC->ODR|=1<<13;
				GPIOA->ODR|=seg[b];
				delay(65000);
				GPIOA->BRR|=seg[b];
				delay(65000);
			}
			//while(GPIOB->IDR&1<<2);
		}
		if(GPIOB->IDR&1<<3)
		{
			count=0;
			//while(GPIOB->IDR&1<<3);
		}
	}
}
				