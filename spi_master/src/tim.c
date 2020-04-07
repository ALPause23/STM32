#include "tim.h"
#include "button.h"
#include "global.h"

TIM_TimeBaseInitTypeDef base_timer;
struct FlagsPrj *f;

void InitTim3()
{
	RCC_HSEConfig(RCC_HSE_ON);
	RCC_SYSCLKConfig(RCC_SYSCLKSource_HSE);
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	TIM_TimeBaseStructInit(&base_timer);
	base_timer.TIM_CounterMode = TIM_CounterMode_Up;
  base_timer.TIM_Prescaler = 8000;
	base_timer.TIM_Period = 2000;
	base_timer.TIM_ClockDivision = 0;
  TIM_TimeBaseInit(TIM3, &base_timer);

	TIM_OCInitTypeDef timer_oc;
	TIM_OCStructInit(&timer_oc);
	timer_oc.TIM_OCMode = TIM_OCMode_PWM1;
	timer_oc.TIM_OutputState = TIM_OutputState_Enable;
	timer_oc.TIM_Pulse = 1000;
	timer_oc.TIM_OCPolarity = TIM_OCPolarity_High;
	
	TIM_OC3Init(TIM3, &timer_oc);
	TIM_OC3PreloadConfig(TIM3,ENABLE);
	TIM_ARRPreloadConfig(TIM3, ENABLE);
  
  TIM_Cmd(TIM3, ENABLE);
}

void InitTim2(void)
{
	f = &FLAG;	
	
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	RCC_HSEConfig(RCC_HSE_ON);
	RCC_SYSCLKConfig(RCC_SYSCLKSource_HSE);
		
  TIM_TimeBaseStructInit(&base_timer);
	base_timer.TIM_CounterMode = TIM_CounterMode_Up;
  base_timer.TIM_Prescaler = 8-1;
	base_timer.TIM_Period = 1000;
	base_timer.TIM_ClockDivision = 0;
  TIM_TimeBaseInit(TIM2, &base_timer);
  
  TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
  
	NVIC_EnableIRQ(TIM2_IRQn);
	TIM_Cmd(TIM2, ENABLE);
}

void TIM2_IRQHandler(void)
{
	//TIM_Cmd(TIM2, DISABLE);
	if(TIM_GetITStatus(TIM2,TIM_IT_Update) != RESET)
	{
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
		
		button.status_now = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0);	
		if((button.status_now == UP) && (button.status_after == 0))
		{
			if(button.count == false)
			{
					button.count = true;
			}
			else 
			{
				button.a++;
				if(button.a == 40)
				{
					button.a = 0;
					button.count = false;
					button.status_after = 1;
					GPIO_SetBits(GPIOC, GPIO_Pin_9);
					//EventForButton();
					f->ButtonIRQ = true;
					//EXTI_GenerateSWInterrupt(EXTI_Line0);
				}
			}
		}
		else if((button.status_now == DOWN) && (button.status_after == 1))
		{
			if(button.count == false)
			{
					button.count = true;
			}
			else 
			{
				button.b++;
				if(button.b == 40)
				{
					button.count = false;
					button.status_after = 0;
					button.b = 0;
					GPIO_ResetBits(GPIOC, GPIO_Pin_9);
					//EXTI_GenerateSWInterrupt(EXTI_Line0);
				}
			}
		}
	}
	//TIM_Cmd(TIM2, ENABLE);
}
