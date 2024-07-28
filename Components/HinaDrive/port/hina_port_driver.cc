#include "hina_driver.hpp"

namespace hina {
inline void Inverter::portSetFloat(ePhase phase)
{
    *hardware.pfloat_pin_register = hardware.float_pin_register_set[phase];
}

inline void Inverter::portSetDuty(ePhase phase, float duty)
{
    *hardware.ptimer_duty_register[phase] = (uint16_t)(duty * hardware.duty_max);
}

inline void Inverter::portSetDuty(float duty_a, float duty_b, float duty_c) 
{
    *hardware.ptimer_duty_register[ePhaseA] = (uint16_t)(duty_a * hardware.duty_max);
    *hardware.ptimer_duty_register[ePhaseB] = (uint16_t)(duty_b * hardware.duty_max);
    *hardware.ptimer_duty_register[ePhaseC] = (uint16_t)(duty_c * hardware.duty_max);
}

inline float Inverter::portGetDuty(ePhase phase)
{
    return ((float)*hardware.ptimer_duty_register[phase] / (float)hardware.duty_max);
}
}

