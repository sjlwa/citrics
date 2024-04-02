#include <SDL2/SDL_render.h>
#include <stdlib.h>
#include "citrics.h"
#include "color.h"
#include "constants.h"
#include "figures.h"

Citrics * new_game(void) {

  Citrics * game = malloc(sizeof(Citrics));
  
  game->running = true;
  game->current_figure = new_figure_LNormal();
  game->static_figures = new_figure_list();

  return game;
}

void free_game(Citrics *game) {
  free_figure(game->current_figure);
  game->current_figure = NULL;
  free_figure_list(game->static_figures);
  game->static_figures = NULL;
  free(game);
}

void draw_game(SDL_Renderer *renderer, Citrics *game) {
  RGBColor color = parse_hex_rgb(0x22AAAAFF);
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
  SDL_RenderClear(renderer);

  draw_figure(renderer, game->current_figure);
  draw_figures_list(renderer, game->static_figures);

  SDL_RenderPresent(renderer);
}

void update_game(Citrics *game) {
  update_figure_fall(game->current_figure);
}

void check_collisions(Citrics *game) {
  for (int i=0; i<game->current_figure->points_length; i++) {
    Point point = game->current_figure->points[i];
      if (point.y >= FLOOR_LIMIT) {
        stop_current_figure(game);
      }
  }
}

void stop_current_figure(Citrics *game) {
  figure_list_insert(game->static_figures, game->current_figure);
  game->current_figure = new_figure_LNormal();
}
