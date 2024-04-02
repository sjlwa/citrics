#ifndef CITRICS_H
#define CITRICS_H

#include <stdbool.h>
#include "figures.h"

typedef struct {
  Figure *current_figure;
  FigureList *static_figures;
  bool running;
} Citrics;

Citrics *new_game(void);
void free_game(Citrics *game);
void draw_game(SDL_Renderer *renderer, Citrics *game);
void update_game(Citrics *game);
void check_collisions(Citrics *game);
void stop_current_figure(Citrics *game);

#endif // CITRICS_H
