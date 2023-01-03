#include<stm32f10x.h>
char seg[20]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};
void delay(unsigned int ms)
{
	while(ms--);
}
int main()
{
	int i,j,a,b;
	RCC->APB2ENR=1<<2|1<<3;
	GPIOA->CRL=0X22222222;
	GPIOC->CRH=0X02200000;
	while(1)
	{
		for(i=0;i<=99;i++)
		{
			a=i/10;
			b=i%10;
			for(j=0;j<=5;j++)
			{
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
		}
	}
}