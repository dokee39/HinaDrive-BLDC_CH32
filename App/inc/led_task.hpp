#pragma once

#include "main.h"

namespace led {
enum eState {
    eOn,
    eOff,
};

class Led final {
public:
    explicit Led(GPIO_TypeDef * const port, const uint16_t pin):
        port_(port),
        pin_(pin) {
    }
    Led() = delete;
    ~Led() = default;
    Led(const Led&) = delete; // not copyable or movable
    Led& operator=(const Led&) = delete; // not copyable or movable

    void Init(void);
    void Control(eState state);
    void Toggle(void);

private:
    GPIO_TypeDef * const port_;
    const uint16_t pin_;
};
}

void LedTask();

