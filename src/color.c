#include "color.h"

RGBColor parse_hex_rgb(int hexrgb) {
  int r = (hexrgb >> 24) & 0xFF;
  int g = (hexrgb >> 16) & 0xFF;
  int b = (hexrgb >> 8) & 0xFF;
  int a = hexrgb & 0xFF;
  RGBColor color = {.r=r,.g=g,.b=b,.a=a};
  return color;
}
