// How to draw the Pine64 logo in C using existing simple graphics functions

uint8_t mid = 120;
uint8_t y = 240;

fillTriangle(30, 99,   7, mid, 37, mid, 0x52accd);
fillTriangle(30, y-99, 7, mid, 37, mid, 0x52accd);

fillTriangle(58, 72,   34, 81,   103, 44,   0x2f82c4);
fillTriangle(55, y-72, 34, y-81, 103, y-44, 0x2f82c4);

fillTriangle(72, 71,   48, mid, 93, mid, 0x2f7ec1);
fillTriangle(72, y-71, 48, mid, 93, mid, 0x2f7ec1);

fillTriangle(72, 48,   122, 48,   97, 104,   0x2969b1);
fillTriangle(72, y-48, 122, y-48, 97, y-104, 0x2969b1);

fillTriangle(128, 63,   102, mid, 153, mid, 0x3d5c8b);
fillTriangle(128, y-63, 102, mid, 153, mid, 0x3d5c8b);

fillTriangle(129, 36,   178, 58,   158, 104,   0x475677);
fillTriangle(129, y-36, 178, y-58, 158, y-104, 0x475677);

fillTriangle(185, 69,   162, mid, 209, mid, 0x475677);
fillTriangle(185, y-69, 162, mid, 209, mid, 0x475677);

fillRectangle(204, 114, 11, 30, 0x475677);
