#pragma once

#include "typedefs.h"

byte FindClosestColor(const byte *palette, uint paletteSize, byte r, byte g, byte b);
uint StringHash(const char *str, int divisor);
