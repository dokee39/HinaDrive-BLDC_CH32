#pragma once

#include "ch32v20x.h"
#include "hina_param.hpp"

namespace hina {
struct portHardware final {
    volatile uint16_t *ptimer_duty_register[ePhaseNum];
    uint16_t duty_max;
    
    volatile uint16_t *pfloat_pin_register;
    uint16_t float_pin_register_mask[ePhaseNum];
};
}

