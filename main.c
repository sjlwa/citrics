#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stdbool.h>
#include "src/events.h"
#include "src/citrics.h"
#include "src/constants.h"


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
    draw_game(renderer, game);
  }

  free_game(game);
  game = NULL;

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  
  return 0;
}
