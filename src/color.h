#ifndef COLOR_H
#define COLOR_H

#include <sys/types.h>

typedef struct {
  uint r; uint g; uint b; uint a;
} RGBColor;

RGBColor parse_hex_rgb(int hexrgb);

#endif // COLOR_H
