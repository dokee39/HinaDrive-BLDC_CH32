#include "led_task.hpp"
#include "main.h"

namespace led {
void Led::Init(void)
{
    Control(eOn);
}

void Led::Control(eState state)
{
    if(state == eOn)
    {
        port_->BCR = pin_;
    }
    else
    {
        port_->BSHR = pin_;
    }
}

void Led::Toggle(void)
{
    ((port_))->OUTDR ^= pin_;
}
}

void LedTask(void)
{
    static led::Led led(LED_PIN_PORT, LED_PIN);
    led.Toggle();
}
