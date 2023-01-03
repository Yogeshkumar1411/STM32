#include<stm32f10x.h>
void timer(int a)
{
	TIM2->PSC=10000-1;
	TIM2->ARR=(7200*a)-1;
	TIM2->CR1=1<<0;
	TIM2->CNT=0;
}
void timer2()
{
	while(!(TIM2->SR&1<<0))
	{
		TIM2->SR=0;
	}
}
int main()
{
	RCC->APB2ENR=1<<2;
	RCC->APB1ENR=1<<0;
	GPIOA->CRL=0X00000222;
	GPIOA->CRH=0X00000222;
	while(1)
	{
		timer(10);
		GPIOA->ODR=
d		
	
	