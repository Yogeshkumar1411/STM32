/*Name: Yogesh
Date: 22-02-2022
Concept: Clock*/
#include<stm32f10x.h>
void delay(unsigned int ms)
{
	while(ms--);
}
int main()
{
	int i,a,b,c,d,e,f;
	char seg[20]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};
		RCC->APB2ENR=1<<2|1<<3;
		GPIOA->CRH=0X22222222;
		GPIOB->CRL=0X00002222;
		while(1)
		{
			for(i=0;i<1440;i++)
			{
				a=i/600;
				b=i%600;
				c=b/60;
				d=b%60;
				e=d/10;
				f=d%10;
				GPIOB->BRR|=1<<0;
				GPIOB->ODR|=1<<1|1<<2|1<<3;				
				GPIOA->ODR|=seg[a];
				delay(65000);
				GPIOA->BRR|=seg[a];
				delay(65000);
				
				GPIOB->BRR|=1<<1;
				GPIOB->ODR|=1<<0|1<<2|1<<3;
				GPIOA->ODR|=seg[c];
				delay(65000);
				GPIOA->BRR|=seg[c];
				delay(65000);
				
				
				GPIOB->BRR|=1<<2;
				GPIOB->ODR|=1<<0|1<<1|1<<3;				
				GPIOA->ODR|=seg[e];
				delay(65000);
				GPIOA->BRR|=seg[e];
				delay(65000);
				
				
				GPIOB->BRR|=1<<3;
				GPIOB->ODR|=1<<1|1<<2|1<<0;				
				GPIOA->ODR|=seg[f];
				delay(65000);
				GPIOA->BRR|=seg[f];
				delay(65000);
			}
		}
	}
				