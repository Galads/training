#include "stm32f10x_delay.h"
#include "stm32f10x.h"                  


void gpioBegin()
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN | RCC_APB2ENR_IOPAEN;
	GPIOC->CRH 	&=~(GPIO_CRH_CNF8 | GPIO_CRH_MODE8);	/* reset port 8 */
	GPIOC->CRH 	|=	GPIO_CRH_MODE8;					/* port configured to output frequency 50MHz 0010 - 0x2 */
	GPIOC->CRH 	&=~(GPIO_CRH_CNF9 | GPIO_CRH_MODE9); 	/* reset port 9 */
	GPIOC->CRH 	|=	GPIO_CRH_MODE9; 					/* port configured to output frequency 50MHz 0011 - 0x3 */
	GPIOA->CRL 	&=~(GPIO_CRL_CNF0 | GPIO_CRL_MODE0);
	GPIOA->CRL 	|= GPIO_CRL_MODE0;
	GPIOA->CRL 	&=~(GPIO_CRL_CNF1 | GPIO_CRL_MODE1);
	GPIOA->CRL 	|= GPIO_CRL_MODE1;
	GPIOA->CRL 	&=~(GPIO_CRL_CNF2 | GPIO_CRL_MODE2);
	GPIOA->CRL 	|= GPIO_CRL_MODE2;
	GPIOA->CRL 	&=~(GPIO_CRL_CNF3 | GPIO_CRL_MODE3);
	GPIOA->CRL 	|= GPIO_CRL_MODE3;
	GPIOA->CRL 	&=~(GPIO_CRL_CNF3 | GPIO_CRL_MODE3);
	GPIOA->CRL 	|= GPIO_CRL_MODE3;
	GPIOA->CRL 	&=~(GPIO_CRL_CNF4 | GPIO_CRL_MODE4);
	GPIOA->CRL 	|= GPIO_CRL_MODE4;
	GPIOA->CRL 	&=~(GPIO_CRL_CNF5 | GPIO_CRL_MODE5);
	GPIOA->CRL 	|= GPIO_CRL_MODE5;
}


int main()
{

	gpioBegin();  						
	delayBegin(TIM2); 					
	
	while(1)
	{	
		GPIOC->BSRR = GPIO_BSRR_BR8; 	/* PC8 port LOW */
		GPIOC->BSRR = GPIO_BSRR_BS9;	/* PC9 port HIGH */
		GPIOA->BSRR = GPIO_BSRR_BS0;
		GPIOA->BSRR = GPIO_BSRR_BS1;
		GPIOA->BSRR = GPIO_BSRR_BS2;
		GPIOA->BSRR = GPIO_BSRR_BS3;
		GPIOA->BSRR = GPIO_BSRR_BS4;
		GPIOA->BSRR = GPIO_BSRR_BS5;
		delay(TIM2,100); 				/* delay 1 second */
		
		delay(TIM2,100); 				/*delay 100 milliseconds 0.1 second*/
	for(int i = 0; i<6; i++)
		{
				GPIOA->BSRR = GPIO_BSRR_BR0 << i ;
					delay(TIM2,100);
				
		}
		for(int p = 0; p<6; p++) 
		{
		GPIOA->BSRR = GPIO_BSRR_BS5 >> p;
					delay(TIM2,100);
		}
	
	
	}
}
