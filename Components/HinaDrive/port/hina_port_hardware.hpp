#pragma once

#include "ch32v20x.h"
#include "hina_param.hpp"

namespace hina {
struct portHardware final {
    volatile uint16_t *const ppwm_duty_reg[ePhaseNum];
    const uint16_t duty_max;

    volatile uint16_t &float_pin_reg;
    const uint16_t float_pin_reg_mask[ePhaseNum];

    const uint32_t opa_select[ePhaseNum + 1];
    const uint16_t opa_exit_pin[ePhaseNum];
    const uint16_t opa_exit_pin_all = opa_exit_pin[ePhaseA] | opa_exit_pin[ePhaseB] | opa_exit_pin[ePhaseC];

    TIM_TypeDef *const timer;
    
};
}

