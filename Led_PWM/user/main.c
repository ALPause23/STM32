#include "stm32f4xx.h"
#include "misc.h"

#define HSE_VALUE    ((uint32_t)8000000)

TIM_TimeBaseInitTypeDef base_timer;

void init_gpio(void);
void init_timer(void);

int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	
	init_gpio();
  
	GPIO_SetBits(GPIOD, GPIO_Pin_14);
	
	init_timer();
	
	while(1)
	{
		
	}
}


void init_gpio(void)
{
  GPIO_InitTypeDef gpio;
  GPIO_StructInit(&gpio);

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
  gpio.GPIO_Mode = GPIO_Mode_OUT;
  gpio.GPIO_Pin = GPIO_Pin_14;
	gpio.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOD, &gpio);
}

void init_timer(void)
{
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	RCC_HSEConfig(RCC_HSE_ON);
	RCC_SYSCLKConfig(RCC_SYSCLKSource_HSE);
		
  TIM_TimeBaseStructInit(&base_timer);
	base_timer.TIM_CounterMode = TIM_CounterMode_Up;
  base_timer.TIM_Prescaler = 8000;
	base_timer.TIM_Period = 3000;
	base_timer.TIM_ClockDivision = 0;
  TIM_TimeBaseInit(TIM3, &base_timer);

  
  TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
  TIM_Cmd(TIM3, ENABLE);

  NVIC_EnableIRQ(TIM3_IRQn);
}

// ?????????? ???????
void TIM3_IRQHandler(void)
{
	TIM_Cmd(TIM3, DISABLE);
  if(TIM_GetITStatus(TIM3,TIM_IT_Update) != RESET)
	{
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
		if(GPIOD->IDR & GPIO_IDR_IDR_14)
		{
			GPIO_ResetBits(GPIOD, GPIO_Pin_14);
			
			//base_timer.TIM_Period = 1000;
			TIM_SetAutoreload(TIM3, 1000);
			//TIM_TimeBaseInit(TIM3, &base_timer);
			
		}
		else
		{
			GPIO_SetBits(GPIOD, GPIO_Pin_14);
			
			//base_timer.TIM_Period = 3000;
			TIM_SetAutoreload(TIM3, 3000);
			//TIM_TimeBaseInit(TIM3, &base_timer);
		}
	}
	TIM_Cmd(TIM3, ENABLE);	
		
}
