#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stdbool.h>
#include "src/events.h"
#include "src/color.h"
#include "src/citrics.h"

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
  
  
  SDL_Event event;

  Citrics *game = new_game();

  while (game->running) {

    while (SDL_PollEvent(&event)) {
      if (handle_main_event(&event) == QUIT_GAME) {
        game->running = false;
      }
    }

    RGBColor color = parse_hex_rgb(0x22AAAAFF);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(renderer);
    draw_rect(renderer);
    SDL_RenderPresent(renderer);
  }

  free_game(game);
  game = NULL;

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  
  return 0;
}
