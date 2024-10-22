#include "ch32v20x_it.h"
#include "ch32v20x.h"
#include "main.h"
#include "timeslice_task.h"

void NMI_Handler(void)       __attribute__((interrupt("WCH-Interrupt-fast")));
void HardFault_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void TIM2_IRQHandler(void)   __attribute__((interrupt("WCH-Interrupt-fast")));
void TIM3_IRQHandler(void)   __attribute__((interrupt("WCH-Interrupt-fast")));
void TIM4_IRQHandler(void)   __attribute__((interrupt("WCH-Interrupt-fast")));
void EXTI2_IRQHandler(void)  __attribute__((interrupt("WCH-Interrupt-fast")));
void SysTick_Handler(void)   __attribute__((interrupt("WCH-Interrupt-fast")));

void SysTick_Handler(void)
{
    timeslice_tick();
    timeslice_exec();
    SysTick->SR = 0;
}

void NMI_Handler(void)
{
    TIM_PWM->CCER = 0;
    __disable_irq();
    while (1)
    {
    }
}

void HardFault_Handler(void)
{
    TIM_PWM->CCER = 0;
    __disable_irq();
    while (1)
    {
    }
}

void TIM2_IRQHandler(void)
{
}

void TIM3_IRQHandler(void)
{
}

void TIM4_IRQHandler(void)
{
}

void EXTI2_IRQHandler(void)
{
}
