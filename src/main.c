#include <stdint.h>
#include <st7789.h>

int main()
{
	
	stInit();
	stSetBrightness(2);
	
	stBeginDrawBuffer(0,0,240,240);
	
	uint16_t color = 0;
	uint8_t drawWhite = 0;
	
	nrf_gpio_cfg_output(14);
	nrf_gpio_cfg_output(22);
	nrf_gpio_cfg_output(23);
	nrf_gpio_cfg_output(27);
	
	while(1)
	{
		if(drawWhite)
		{
			color = 0;
			drawWhite = 0;
		}
		else
		{
			color = 65535;
			drawWhite = 1;
		}
		
		for(uint16_t x = 0; x <= 240; x++)
		{
			for(uint16_t y = 0; y <= 240; y++)
			{
				stDrawPixel(x,y,color);
			}
		}
		
		nrf_gpio_pin_toggle(14);
		nrf_gpio_pin_toggle(22);
		nrf_gpio_pin_toggle(23);
		nrf_gpio_pin_toggle(27);
		
		nrf_delay_ms(500);
	}
	
	return 1;
}
