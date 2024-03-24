#include "gpio.h"

void ez_gpio_init(const int *pins, int npins)
{
    for (int i = 0; i < npins; i++)
    {
        gpio_reset_pin(pins[i]);
        gpio_set_direction(pins[i], GPIO_MODE_OUTPUT);
    }
}

void ez_gpio_set_level(int pin, int level)
{
    gpio_set_level(pin, level);
}
