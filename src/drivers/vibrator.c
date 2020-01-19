#include "vibrator.h"

const uint8_t vibratorPin = 16;

void vibratorInit()
{
	nrf_gpio_cfg_output(vibratorPin);
}

void vibratorOn()
{
	nrf_gpio_pin_set(vibratorPin);
}

void vibratorOff()
{
	nrf_gpio_pin_clear(vibratorPin);
}
