void ST7789Init();
void ST7789DrawPixel(uint16_t x, uint16_t y, uint32_t color);
void ST7789FillRectangle(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t color);

void ST7789BeginDrawBuffer(uint16_t x, uint16_t y, uint16_t width, uint16_t height);
void ST7789NextDrawBuffer(const uint8_t* data, size_t size);
void ST7789EndDrawBuffer();

void ST7789DisplayOn();
void ST7789DisplayOff();

SpiMaster& spi;
uint8_t pinDataCommand;

void ST7789HardwareReset();
void ST7789SoftwareReset();
void ST7789SleepOut();
void ST7789ColMod();
void ST7789MemoryDataAccessControl();
void ST7789DisplayInversionOn();
void ST7789NormalModeOn();
void ST7789WriteToRam();

void ST7789SetAddrWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);

void ST7789WriteCommand(uint8_t cmd);
void ST7789WriteSpi(const uint8_t* data, size_t size);

enum Commands : uint8_t
{
	SoftwareReset = 0x01,
	SleepOut = 0x11,
	NormalModeOn = 0x13,
	DisplayInversionOn = 0x21,
	DisplayOff = 0x28,
	DisplayOn = 0x29,
	ColumnAddressSet = 0x2a,
	RowAddressSet = 0x2b,
	WriteToRam = 0x2c,
	MemoryDataAccessControl = 036,
	ColMod = 0x3a,
};

void WriteData(uint8_t data);
void ColumnAddressSet();

static uint16_t Width = 240;
static uint16_t Height = 240;
void RowAddressSet();

