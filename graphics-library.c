/*
This file contains pseudocode for a simple graphics library that does the following:
- Keep a linked list of every element on the screen.
- There's a linked list for every type of element (because they're in a different format)
- Draws every element on the screen using a drawPixel() function
*/

/*
The shade of green that you can see in my png's. 
This is the designated 'transparent color' I use. 
The bitmap drawing function should skip the drawing of a pixel if it's this color (or draw black, or something).
*/
#define TRANSPARENT_COLOR 0x6cfc6a


// The linked lists for each of the 3 types of element
struct ActiveElementsBitmap32 * ActiveElementsBitmap32_head;
struct ActiveElementsBitmap64 * ActiveElementsBitmap64_head;
struct ActiveElementsText * ActiveElementsText_head;
struct ActiveElementsDrawing * ActiveElementsDrawing_head;

// Definition of the structures of each node
struct ActiveElementsBitmap32
{
	int x;
	int y;
	unsigned short bitmap[(32*32)];
	struct ActiveElementsBitmap64 * next;
};

struct ActiveElementsBitmap64
{
	int x;
	int y;
	unsigned short bitmap[(64*64)];
	struct ActiveElementsBitmap64 * next;
};

struct ActiveElementsText
{
	int x;
	int y;
	unsigned short bitmap[];
	struct ActiveElementsText * next;
};

struct ActiveElementsDrawing
{
	int x;
	int y;
	int function;
	int param1;
	int param2;
	int param3;
	int param4;
	struct ActiveElementsDrawing * next;
};

// Array that tells whether a pixel is part of an element or not.
int PixelElement[1800]; // 1800 = 240x240 bits in integers

void setElementOnPixel()
{
	PixelElement[(k/32)] |= (1 << (k%32));
}

void clearElementOnPixel()
{
	PixelElement[(k/32)] &= ~(1 << (k%32));
}

int PixelHasElement()
{
	return ( PixelElement[(k/32)] & (1 << (k%32)) );
}

// Add/remove bitmap32 element to its linked list TODO: and set the element in the PixelElement array
void addElementBitmap32() { }
void removeElementBitmap32() { }

// Add/remove bitmap64 element to its linked list
void addElementBitmap64() { }
void removeElementBitmap64() { }

// Add/remove text element to its linked list
void addElementText() { }
void removeElementText() { }

// Add/remove drawing element to its linked list
void addElementDrawing() { }
void removeElementDrawing() { }

// Draw a 64 by 64 bitmap using the drawPixel function. Features transparency.
void drawBitmap64(uint8_t screenX, uint8_t screenY, uint16_t[] bitmap)
{
	for(uint8_t bitmapX = 0; bitmapX < 64; bitmapX++)
	{
		for(uint8_t bitmapY = 0; bitmapY < 64; bitmapY++)
		{
			uint16_t color = getColorFromBitmap(bitmap, bitmapX, bitmapY);
			if(color == TRANSPARENT_COLOR)
			{
				// TODO: Set this pixel as NOT part of this element in the PixelElement array
			}
			else
			{
				drawPixel(screenX, screenY, color);
			}
		}
	}
}

uint16_t getColorFromBitmap(uint16_t[] bitmap, uint8_t bitmapX, uint8_t bitmapY)
{
	uint16_t color;
	/*
	TODO: Get the color from the bitmap array and place it in the color variable. 
	This is a bit more complicated if you store the bitmaps in the external flash.
	*/
	return color;
}

void drawElements()
{
	// Draw every 64x64 bitmap element.
	// Check every new element list if there is an element on this pixel
	struct ActiveElementsBitmap64 * ActiveElementsBitmap64_current = ActiveElementsBitmap64_head;
	
	while(ActiveElementsBitmap64_current)
	{
		uint8_t x = ActiveElementsBitmap64_current->x;
		uint8_t y = ActiveElementsBitmap64_current->y;
		uint8_t bitmap = ActiveElementsBitmap64_current->bitmap;

		drawBitmap64(x, y, bitmap);

		ActiveElementsBitmap64_current = ActiveElementsBitmap64_current->next;
	}

	// TODO: Draw every 32x32 bitmap element
	
	// TODO: Draw every text element
	
	// TODO: Draw every Drawing element
	
	// Draw all non-element pixels black 
	// TODO: unless they already are? Make a second PixelElement array and compare old with new! This way you can have framerates faster than 8hz!
	for(int x = 0; x <=240; x++)
	{
		for(int y = 0; y <=240; y++)
		{
			if(PixelHasElement(PixelElement,(240*x)+y) == 0)
			{
				drawPixel(x, y, 0);
			}
		}
	}
}

