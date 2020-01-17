// The new and old linked list for each of the 3 types of element
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

void drawElements()
{
	// Draw every 32x32 bitmap element
	struct ActiveElementsBitmap32 * ActiveElementsBitmap32OnThisPixel;
	// Check every new element list if there is an element on this pixel
	struct ActiveElementsBitmap32 * ActiveElementsBitmap32_current = ActiveElementsBitmap32_head;
	while(ActiveElementsBitmap32_current)
	{
		// Draw the bitmap
		for(int x = ActiveElementsBitmap32_current->x; x<=32; x++)
		{
			for(int y = ActiveElementsBitmap32_current->y; y<=32; y++)
			{
				drawPixel(x, y, ActiveElementsBitmap32_current->bitmap[(32*x)+y)]);
			}
		}
	}
	
	// Draw every 64x64 bitmap element.
	struct ActiveElementsBitmap64 * ActiveElementsBitmap64OnThisPixel;
	// Check every new element list if there is an element on this pixel
	struct ActiveElementsBitmap64 * ActiveElementsBitmap64_current = ActiveElementsBitmap64_head;
	while(ActiveElementsBitmap64_current)
	{
		// Draw the bitmap
		for(int x = ActiveElementsBitmap64_current->x; x<=64; x++)
		{
			for(int y = ActiveElementsBitmap64_current->y; y<=64; y++)
			{
				drawPixel(x, y, ActiveElementsBitmap64_current->bitmap[(64*x)+y)]);
			}
		}
	}
	
	// Draw every text element
	//TODO
	
	// Draw every Drawing element
	//TODO
	
	// Draw all non-element pixels black TODO: unless they already are?
	for(int x = 0; x <=240; x++)
	{
		for(int y = 0; y <=240; y++)
		{
			if(PixelHasElement(PixelElement,(240*x)+y) == 0)
			{
				drawPixel(x, y, 0x0000);
			}
		}
	}
}

