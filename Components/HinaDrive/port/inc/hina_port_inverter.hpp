#include "hina_inverter.hpp"

namespace hina {
inline void Inverter::portSetFloat(ePhase phase)
{
    hardware_.float_pin_reg |= hardware_.float_pin_reg_mask[phase];
}

inline void Inverter::portUnsetFloat(ePhase phase)
{
    hardware_.float_pin_reg &= ~hardware_.float_pin_reg_mask[phase];
}

inline void Inverter::portSetDuty(ePhase phase, float duty)
{
    *hardware_.ptimer_duty_reg[phase] = (uint16_t)(duty * hardware_.duty_max);
}

inline void Inverter::portSetDuty(float duty_a, float duty_b, float duty_c) 
{
    *hardware_.ptimer_duty_reg[ePhaseA] = (uint16_t)(duty_a * hardware_.duty_max);
    *hardware_.ptimer_duty_reg[ePhaseB] = (uint16_t)(duty_b * hardware_.duty_max);
    *hardware_.ptimer_duty_reg[ePhaseC] = (uint16_t)(duty_c * hardware_.duty_max);
}

inline float Inverter::portGetDuty(ePhase phase)
{
    return ((float)*hardware_.ptimer_duty_reg[phase] / (float)hardware_.duty_max);
}
}

