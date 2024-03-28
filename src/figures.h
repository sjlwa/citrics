#ifndef FIGURES_H
#define FIGURES_H

#include <sys/types.h>

typedef enum {
  LNormal,
  LInverted,
  Line,
  ZNormal,
  ZInverted,
  Step
} FigureType;

#define FIG_LNORMAL_SIZE 4
#define FIG_LINVERTED_SIZE 4
#define FIG_LINE_SIZE 4
#define FIG_ZNORMAL_SIZE 4
#define FIG_ZNORMAL_SIZE 4
#define FIG_STEP_SIZE 4

typedef struct { uint x; uint y; } Point;

typedef struct {
  FigureType type;
  uint points_length;
  Point *points;
} Figure;


Figure *new_figure(FigureType type);
Figure *new_figure_LNormal(void);
Figure *new_figure_LInverted(void);
Figure *new_figure_Line(void);
Figure *new_figure_ZNormal(void);
Figure *new_figure_ZInverted(void);
Figure *new_figure_Step(void);

void free_figure(Figure *figure);

Point * new_points_figure_LNormal(void);

void print_figure(Figure *fig);

#endif // FIGURES_H
