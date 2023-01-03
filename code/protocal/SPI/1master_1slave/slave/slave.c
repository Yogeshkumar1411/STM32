#include<stm32f10x.h>
void slave()
{
	char data1;
	while(!(SPI1->SR&1<<0));
	data1=SPI1->DR;	
	SPI1->SR=0;
}
int main()
{
	RCC->APB2ENR|=RCC_APB2ENR_IOPAEN|RCC_APB2ENR_AFIOEN|RCC_APB2ENR_SPI1EN;
	GPIOA->CRL=0XA8AA0000;
	SPI1->CR1=0X0033;
	SPI1->CR1|=1<<6;
	SPI1->CR2|=1<<2;
	while(1)
	{
		slave();
	}
}