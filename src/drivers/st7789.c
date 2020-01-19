#include "st7789.h"

// Pins
const uint8_t pinSCK = 2;
const uint8_t pinMOSI = 3;
const uint8_t pinMISO = 4;
const uint8_t pinCS = 25;
const uint8_t pinBacklightLow = 14;
const uint8_t pinBacklightMid = 22;
const uint8_t pinBacklightHigh = 23;

// Commands
const uint8_t SoftwareReset = 0x01;
const uint8_t SleepIn = 0x10;
const uint8_t SleepOut = 0x11;
const uint8_t NormalModeOn = 0x13;
const uint8_t DisplayInversionOn = 0x21;
const uint8_t DisplayOff = 0x28;
const uint8_t DisplayOn = 0x29;
const uint8_t ColumnAddressSet = 0x2a;
const uint8_t RowAddressSet = 0x2b;
const uint8_t WriteToRam = 0x2c;
const uint8_t MemoryDataAccessControl = 036;
const uint8_t ColMod = 0x3a;
const uint8_t pinDataCommand = 18;

// Other
const uint32_t frequency = 0x80000000;
const uint8_t screenWidth = 240;
const uint8_t screenHeight = 240;

int spiInit()
{
	/* Configure GPIO pins used for pselsck, pselmosi, pselmiso and pselss for SPI0 */
	nrf_gpio_cfg_output(pinSCK);
	nrf_gpio_cfg_output(pinMOSI);
	nrf_gpio_cfg_input(pinMISO, NRF_GPIO_PIN_NOPULL);
	nrf_gpio_cfg_output(pinCS);

	// Use SPI0
	spiBaseAddress = NRF_SPI0;
		
	// Configure pins, frequency and mode
	spiBaseAddress->PSELSCK = pinSCK;
	spiBaseAddress->PSELMOSI = pinMOSI;
	spiBaseAddress->PSELMISO = pinMISO;
	
	// Disable Set slave select (inactive high)
	nrf_gpio_pin_set(pinCS);

	// Use frequency 8mHz
	spiBaseAddress->FREQUENCY = frequency;

	uint32_t regConfig = 0;

	// Use mode 3;
	regConfig |= (0x03 << 1);

	spiBaseAddress->CONFIG = regConfig;
	spiBaseAddress->EVENTS_READY = 0;
	spiBaseAddress->ENABLE = (SPI_ENABLE_ENABLE_Enabled << SPI_ENABLE_ENABLE_Pos);

	return true;
}

int spiWrite(const uint8_t *data, size_t size)
{
	volatile uint32_t dummyread;

	if(data == NULL) return false;

	// enable slave (slave select active low)
	nrf_gpio_pin_clear(pinCS);

	spiBaseAddress->EVENTS_READY = 0;

	spiBaseAddress->TXD = (uint32_t)*data++;

	while(size > 0)
	{
		spiBaseAddress->TXD =  (uint32_t)*data++;

		/* Wait for the transaction complete or timeout (about 10ms - 20 ms) */
		while (spiBaseAddress->EVENTS_READY == 0);

		/* clear the event to be ready to receive next messages */
		spiBaseAddress->EVENTS_READY = 0;

		dummyread = spiBaseAddress->RXD;
		
		size--;
	}

	/* Wait for the transaction complete or timeout (about 10ms - 20 ms) */
	while (spiBaseAddress->EVENTS_READY == 0);

	dummyread = spiBaseAddress->RXD;

	/* disable slave (slave select active low) */
	nrf_gpio_pin_set(pinCS);

	return true;
}

void stInit()
{
	spiInit();
	nrf_gpio_cfg_output(pinDataCommand);
	
	// Display reset pin
	nrf_gpio_cfg_output(26);
	nrf_gpio_pin_set(26);
	
	stHardwareReset();
	stSoftwareReset();
	stSleepOut();
	stColMod();
	stMemoryDataAccessControl();
	stColumnAddressSet();
	stRowAddressSet();
	stDisplayInversionOn();
	stNormalModeOn();
	stDisplayOn();
	
	// Initialize brightness pins
	nrf_gpio_cfg_output(pinBacklightLow);
	nrf_gpio_cfg_output(pinBacklightMid);
	nrf_gpio_cfg_output(pinBacklightHigh);
}

void stSetBrightness(uint8_t brightness)
{
	nrf_gpio_pin_set(pinBacklightLow);
	nrf_gpio_pin_set(pinBacklightMid);
	nrf_gpio_pin_set(pinBacklightHigh);
	
	switch(brightness)
	{
		case 1:	nrf_gpio_pin_clear(pinBacklightLow); break;
		case 2:	nrf_gpio_pin_clear(pinBacklightMid); break;
		case 3:	nrf_gpio_pin_clear(pinBacklightHigh); break;
	}
}

void stWriteCommand(uint8_t cmd)
{
	nrf_gpio_pin_clear(pinDataCommand);
	spiWrite(&cmd, 1);
}

void stWriteData(uint8_t data)
{
	nrf_gpio_pin_set(pinDataCommand);
	spiWrite(&data, 1);
}

void stSoftwareReset()
{
	stWriteCommand(SoftwareReset);
	nrf_delay_ms(150);
}

void stSleepOut()
{
	stWriteCommand(SleepOut);
}

void stColMod()
{
	stWriteCommand(ColMod);
	stWriteData(0x55);
	nrf_delay_ms(10);
}

void stMemoryDataAccessControl()
{
	stWriteCommand(MemoryDataAccessControl);
	stWriteData(0x00);
}

void stColumnAddressSet()
{
	stWriteCommand(ColumnAddressSet);
	stWriteData(0x00);
	stWriteData(0x00);
	stWriteData(screenHeight >> 8);
	stWriteData(screenHeight & 0xff);
}

void stRowAddressSet()
{
	stWriteCommand(RowAddressSet);
	stWriteData(0x00);
	stWriteData(0x00);
	stWriteData(screenWidth >> 8);
	stWriteData(screenWidth & 0xff);
}

void stDisplayInversionOn()
{
	stWriteCommand(DisplayInversionOn);
	nrf_delay_ms(10);
}

void stNormalModeOn()
{
	stWriteCommand(NormalModeOn);
	nrf_delay_ms(10);
}

void stDisplayOn()
{
	stWriteCommand(DisplayOn);
}

void stSetAddrWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
	stWriteCommand(ColumnAddressSet);
	stWriteData(x0 >> 8);
	stWriteData(x0 & 0xff);
	stWriteData(x1 >> 8);
	stWriteData(x1 & 0xff);

	stWriteCommand(RowAddressSet);
	stWriteData(y0>>8);
	stWriteData(y0 & 0xff);
	stWriteData(y1 >> 8);
	stWriteData(y1 & 0xff);

	stWriteCommand(WriteToRam);
}

void stDrawPixel(uint16_t x, uint16_t y, uint32_t color)
{
	if((x < 0) ||(x >= screenWidth) || (y < 0) || (y >= screenHeight)) return;

	stSetAddrWindow(x, y, x+1, y+1);

	nrf_gpio_pin_set(pinDataCommand);
	spiWrite((const uint8_t *) &color, 2);
}

void stBeginDrawBuffer(uint16_t x, uint16_t y, uint16_t screenWidth, uint16_t screenHeight)
{
	if((x >= screenWidth) || (y >= screenHeight)) return;
	if((x + screenWidth - 1) >= screenWidth)  screenWidth = screenWidth  - x;
	if((y + screenHeight - 1) >= screenHeight) screenHeight = screenHeight - y;

	stSetAddrWindow(0+x, 0+y, x+screenWidth-1, y+screenHeight-1);
	nrf_gpio_pin_set(pinDataCommand);
}

void stHardwareReset()
{
	nrf_gpio_pin_clear(26);
	nrf_delay_ms(10);
	nrf_gpio_pin_set(26);
}

void stWakeup()
{
	nrf_gpio_cfg_output(pinDataCommand);
	// TODO: Why do we need to reset the controller?
	stHardwareReset();
	stSoftwareReset();
	stSleepOut();
	stColMod();
	stMemoryDataAccessControl();
	stColumnAddressSet();
	stRowAddressSet();
	stDisplayInversionOn();
	stNormalModeOn();
	stDisplayOn();
}
