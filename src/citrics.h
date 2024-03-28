#ifndef CITRICS_H
#define CITRICS_H

#include <stdbool.h>
#include "figures.h"

typedef struct {
  Figure *current_figure;
  bool running;
} Citrics;

Citrics *new_game(void);
void free_game(Citrics *game);
void draw_game(SDL_Renderer *renderer, Citrics *game);

#endif // CITRICS_H
