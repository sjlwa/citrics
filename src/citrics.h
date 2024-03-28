#ifndef CITRICS_H
#define CITRICS_H

#include <stdbool.h>
#include "figures.h"

#define WIDTH 500
#define HEIGHT 700
#define CELL_SIZE WIDTH / 12

typedef struct {
  Figure *current_figure;
  bool running;
} Citrics;

Citrics *new_game(void);
void free_game(Citrics *game);

#endif // CITRICS_H
