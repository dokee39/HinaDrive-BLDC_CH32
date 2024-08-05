#pragma once

#include "hina_timer.hpp"
#include "hina_port_hardware.hpp"

namespace hina {
inline void Timer::portDisable()
{
    hardware_.timer->DMAINTENR &= ~TIM_IT_Update;
    hardware_.timer->INTFR = 0;
    hardware_.timer->CNT = 0;
}

inline void Timer::portEnable(uint32_t cnt)
{
    hardware_.timer->CNT = 0;
    hardware_.timer->ATRLR = cnt;
    hardware_.timer->INTFR = 0;
    hardware_.timer->DMAINTENR |= TIM_IT_Update;
}

inline uint32_t Timer::portGetCnt() const
{
    return hardware_.timer->CNT;
}
}
