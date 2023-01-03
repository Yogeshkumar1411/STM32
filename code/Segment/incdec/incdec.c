#include<stm32f10x.h>
void delay(unsigned int ms)
{
	while(ms--);
}
int main()
{
	int i,j;
	char seg[20]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};
	RCC->APB2ENR=1<<2|1<<3;
	GPIOA->CRL=0X22222222;
	GPIOB->CRL=0X00000088;
	while(1)
	{
		if(GPIOB->IDR&1<<0)
		{
			for(i=0;i<10;i++)
			{
				GPIOA->ODR|=seg[i];
				delay(65000);
				GPIOA->BRR|=seg[i];
				delay(65000);
			}
		}
		if(GPIOB->IDR&1<<1)
		{
			for(j=0;j<10;j++)
			{
				GPIOA->ODR|=seg[j];
				delay(65000);
				GPIOA->BRR|=seg[j];
				delay(65000);
			}
		}
	}
}