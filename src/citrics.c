#include <stdlib.h>
#include "citrics.h"
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
