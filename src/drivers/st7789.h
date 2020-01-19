#ifndef ST7789_H
#define ST7789_H

#include <hal/nrf_gpio.h>
#include <nrf_delay.h>

NRF_SPI_Type *  spiBaseAddress;

int spiInit();
int spiWrite(const uint8_t *data, size_t size);

void stInit();
void stSetBrightness(uint8_t brightness);
void stWriteCommand(uint8_t cmd);
void stWriteData(uint8_t data);
void stSoftwareReset();
void stSleepOut();
void stColMod();
void stMemoryDataAccessControl();
void stColumnAddressSet();
void stRowAddressSet();
void stDisplayInversionOn();
void stNormalModeOn();
void stDisplayOn();
void stSetAddrWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);
void stDrawPixel(uint16_t x, uint16_t y, uint32_t color);
void stBeginDrawBuffer(uint16_t x, uint16_t y, uint16_t width, uint16_t height);
void stHardwareReset();
void stWakeup();

#endif // ST7789_H
