#include <SDL2/SDL_render.h>
#include <stdlib.h>
#include "citrics.h"
#include "color.h"
#include "figures.h"

Citrics * new_game(void) {

  Citrics * game = malloc(sizeof(Citrics));
  
  game->running = true;
  game->current_figure = new_figure_LNormal();

  return game;
}

void free_game(Citrics *game) {
  free_figure(game->current_figure);
  game->current_figure = NULL;
  free(game);
}

void draw_game(SDL_Renderer *renderer, Citrics *game) {
  RGBColor color = parse_hex_rgb(0x22AAAAFF);
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
  SDL_RenderClear(renderer);

  draw_figure(renderer, game->current_figure);

  SDL_RenderPresent(renderer);
}

void update_game(Citrics *game) {
  update_figure_fall(game->current_figure);
}
