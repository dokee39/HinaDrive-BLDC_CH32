#include "led_task.hpp"
#include "main.h"
#include "FreeRTOS.h"
#include "task.h"

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

void LedTask(void *arg)
{
    TickType_t xLastWakeTime;

    led::Led led(LED_PIN_PORT, LED_PIN);

    xLastWakeTime = xTaskGetTickCount();

    for (;;) {
        led.Toggle();
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(500));
    }
}
