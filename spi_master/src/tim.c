#include "tim.h"
#include "button.h"
#include "global.h"

TIM_TimeBaseInitTypeDef base_timer;

void InitTim2(void)
{
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
	TIM_Cmd(TIM2, DISABLE);
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
					//f_in_tim->button_IRQ = FLAG_ENABLE;
					//SelectFlag(FLAG_BUTTON, FLAG_ENABLE);
					SelectFlag(FLAG_tim2_count_buttonUp, FLAG_ENABLE);
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
					//f_in_tim->button_IRQ = FLAG_ENABLE;
					SelectFlag(FLAG_tim2_count_buttonUp, FLAG_DISABLE);
					SelectFlag(FLAG_BUTTON, FLAG_ENABLE);
				}
			}
		}
		if(GetFlag(FLAG_tim2_count_buttonUp) == FLAG_ENABLE)
		{
			CountLedOn();
		}
		else SetTimeCountMs(0);
	}
	TIM_Cmd(TIM2, ENABLE);
}
