#ifndef FIGURES_H
#define FIGURES_H

#include "color.h"
#include <SDL2/SDL_render.h>

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

typedef struct { float x; float y; } Point;

typedef struct {
  FigureType type;
  uint points_length;
  Point *points;
  Point center;
} Figure;

typedef struct {
  Figure **figures;
  size_t length;
} FigureList;

FigureList *new_figure_list(void);
void figure_list_insert(FigureList *list, Figure*figure);

Figure *new_figure(FigureType type);
Figure *new_figure_LNormal(void);
Figure *new_figure_LInverted(void);
Figure *new_figure_Line(void);
Figure *new_figure_ZNormal(void);
Figure *new_figure_ZInverted(void);
Figure *new_figure_Step(void);

void free_figure(Figure *figure);
void free_figure_list(FigureList *list);

Point * new_points_figure_LNormal(void);

void print_figure(Figure *fig);
void print_figure_list(FigureList *list);

void draw_rect(SDL_Renderer *renderer, SDL_Rect *rect, RGBColor *color);
void draw_figure(SDL_Renderer *renderer, Figure *fig);
void draw_figures_list(SDL_Renderer *renderer, FigureList *list);

bool cmp_figures_equal(Figure *fig1, Figure *fig2);

void rotate_point(Point *point, Point *center);
void rotate_figure(Figure *figure);

void update_figure_fall(Figure *figure);

#endif // FIGURES_H
