// CPU IO library
#include <hal/nrf_gpio.h>

unsigned short frameBuffer[240][240];
unsigned short frameBufferNext[240][240];
int rotation = 0;

int main()
{
	return 1;
}

// Write a single pixel to the frame buffer
void writePixel(int x, int y, unsigned short colour)
{
	framebuffer[x][y] = colour;
}

// Make the entire frame buffer one color (clear the screen)
void writeScreen(unsigned short colour)
{
	for(int x = 0; x <= 240; x++)
	{
		for(int y = 0; y <= 240; y++)
		{
			writePixel(x, y, colour);
		}
	}
}

// Draw a pixel to the display
void drawPixel(int x, int y, unsigned short colour)
{
	
}

// Draw the the frame buffer (frameBufferNext) to the display
void drawScreen()
{
	for(int x = 0; x <= 240; x++)
	{
		for(int y = 0; y <= 240; y++)
		{
			// Only draw the new pixel on the display if the pixel changed
			if(frameBufferNext[x][y] != frameBuffer[x][y])
				drawPixel(x, y, frameBufferNext[x][y]);
		}
	}
	frameBuffer = frameBufferNext;
}
