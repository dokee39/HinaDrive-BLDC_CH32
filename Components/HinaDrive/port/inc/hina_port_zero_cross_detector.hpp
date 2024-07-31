#pragma once

#include "hina_zero_cross_detector.hpp"
#include "main.h"

namespace hina {
inline void ZeroCrossDetector::portSelect(ePhase phase, eMode mode)
{
    EXTI->INTENR &= ~hardware_.opa_exit_pin_all;
    EXTI->INTFR = hardware_.opa_exit_pin_all;
    switch (mode) {
        case eUp:
            EXTI->FTENR &= ~hardware_.opa_exit_pin[phase];
            EXTI->RTENR |= hardware_.opa_exit_pin[phase];
            break;
        case eDown:
            EXTI->RTENR &= ~hardware_.opa_exit_pin[phase];
            EXTI->FTENR |= hardware_.opa_exit_pin[phase];
            break;
        case eUpDown:
            EXTI->FTENR |= hardware_.opa_exit_pin[phase];
            EXTI->RTENR |= hardware_.opa_exit_pin[phase];
            break;
        default:
            EXTI->FTENR &= ~hardware_.opa_exit_pin[phase];
            EXTI->RTENR &= ~hardware_.opa_exit_pin[phase];
            break;
    }
    EXTI->INTENR |= ~hardware_.opa_exit_pin[phase];
    OPA_CHANNEL = hardware_.opa_select[phase];
}

[[deprecated("CH32 does not support enabling all zero-crossing detectors")]] 
inline void ZeroCrossDetector::portEnableAll()
{
    portSelect(ePhaseA, eUpDown);
}

inline void ZeroCrossDetector::portDisable()
{
    EXTI->INTENR &= ~hardware_.opa_exit_pin_all;
    EXTI->INTFR = hardware_.opa_exit_pin_all;
    EXTI->RTENR &= ~hardware_.opa_exit_pin_all;
    EXTI->FTENR &= ~hardware_.opa_exit_pin_all;
    OPA_CHANNEL = hardware_.opa_select[ePhaseNum];
}
}
