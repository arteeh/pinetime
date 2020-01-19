#include "button.h"

const uint8_t buttonInitPin = 15;
const uint8_t buttonReadPin = 13;

void buttonInit()
{
	nrf_gpio_cfg_output(buttonInitPin);
	nrf_gpio_pin_set(buttonInitPin);
	nrf_gpio_cfg_input(buttonReadPin, NRF_GPIO_PIN_NOPULL);
}

int buttonPressed()
{
	return nrf_gpio_pin_read(buttonReadPin);
}
