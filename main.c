#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stdbool.h>
#include <sys/types.h>
#include "events.h"

#define WIDTH 500
#define HEIGHT 700
#define CELL_SIZE WIDTH / 12


typedef struct {
  uint r; uint g; uint b; uint a;
} RGBColor;


RGBColor parse_hex_rgb(int hexrgb) {
  int r = (hexrgb >> 24) & 0xFF;
  int g = (hexrgb >> 16) & 0xFF;
  int b = (hexrgb >> 8) & 0xFF;
  int a = hexrgb & 0xFF;
  RGBColor color = {.r=r,.g=g,.b=b,.a=a};
  return color;
}


void draw_rect(SDL_Renderer *renderer) {
  SDL_Rect rect = { .x=CELL_SIZE, .y=CELL_SIZE, .w=CELL_SIZE, .h=CELL_SIZE };
  RGBColor color = parse_hex_rgb(0x333333FF );
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
  SDL_RenderFillRect(renderer, &rect);
}


int main(void) {

  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_CreateWindowAndRenderer(
                              WIDTH, HEIGHT,
                              SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE,
                              &window,
                              &renderer);
  
  bool running = true;
  SDL_Event event;


  while (running) {

    while (SDL_PollEvent(&event)) {
      if (handle_main_event(&event) == QUIT_GAME) {
        running = false;
      }
    }

    RGBColor color = parse_hex_rgb(0x22AAAAFF);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(renderer);
    draw_rect(renderer);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  
  return 0;
}
