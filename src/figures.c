#include <SDL2/SDL_render.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "figures.h"
#include "color.h"
#include "constants.h"

Figure *new_figure(FigureType type) {
  switch (type) {
      case LNormal: return new_figure_LNormal(); break;
      case LInverted: return new_figure_LInverted(); break;
      case Line: return new_figure_Line(); break;
      case ZNormal: return new_figure_ZNormal(); break;
      case ZInverted: return new_figure_ZNormal(); break;
      case Step: return new_figure_ZNormal(); break;
  }
  return NULL;
}

void free_figure(Figure *figure) {
  free(figure->points);
}

FigureList *new_figure_list(void) {
  FigureList *list = malloc(sizeof(FigureList));
  list->figures = malloc(sizeof(Figure**));
  list->length = 0;
  return list;
}

void figure_list_insert(FigureList *list, Figure*figure) {
  size_t new_size = sizeof(Figure*) * (list->length + 1);
  list->figures = realloc(list->figures, new_size);
  list->figures[list->length++] = figure;
}

void free_figure_list(FigureList *list) {
  for (int i=0; i<list->length; i++) {
    free(list->figures[i]);
  }
  free(list);
}

char *figure_type_str(FigureType type) {
  switch (type) {
    case LNormal: return "LNormal";  break;
    case LInverted: return "LInverted";  break;
    case Line: return "Line";  break;
    case ZNormal: return "ZNormal";  break;
    case ZInverted: return "ZInverted";  break;
    case Step: return "Step";  break;
  }
  return "null";
}

void print_figure(Figure *fig) {
  printf("%s size: %d ", figure_type_str(fig->type), fig->points_length);
  for (int i=0; i<fig->points_length; i++) {
    Point point = fig->points[i];
    printf(" (%f, %f) ", point.x, point.y);
  }
  printf("\n");
}

void print_figure_list(FigureList *list) {
  printf("Figure [%d of length] {\n", (int) list->length);
  for (int i=0; i<list->length; i++) {
    Figure *figure = list->figures[i];
    print_figure(figure);
  }
  printf("}\n");
}

bool cmp_points_equal(Point *p1, Point *p2) {
  return (p1->x == p2->x) && (p1->y == p2->y);
}


bool cmp_figures_equal(Figure *fig1, Figure *fig2) {
  if (fig1->type != fig2->type) return 0;
  if (fig1->points_length != fig2->points_length) return 0;
  for (int i=0; i<fig1->points_length; i++) {
    Point p1 = fig1->points[i];
    Point p2 = fig2->points[i];
    if (!cmp_points_equal(&p1, &p2)) return false;
  }
  return true;
}

Point * new_points_figure_LNormal(void) {
  Point * points = malloc(sizeof(Point) * FIG_LNORMAL_SIZE);
  Point p0 = { .x=0, .y=0 };
  Point p1 = { .x=0, .y=CELL_SIZE };
  Point p2 = { .x=0, .y=2 * CELL_SIZE };
  Point p3 = { .x=CELL_SIZE, .y=2 * CELL_SIZE };
  points[0] = p0;
  points[1] = p1;
  points[2] = p2;
  points[3] = p3;
  return points;
}

Figure *new_figure_LNormal(void) {
  Figure * figure = malloc(sizeof(Figure));
  figure->type = LNormal;
  figure->points_length = FIG_LNORMAL_SIZE;
  Point *points = new_points_figure_LNormal();
  figure->points = points;
  figure->center = (Point) { .x=CELL_SIZE, .y=CELL_SIZE };
  return figure;
}


Figure *new_figure_LInverted(void) {
  return NULL;
}

Figure *new_figure_Line(void) {
  return NULL;
}

Figure *new_figure_ZNormal(void) {
  return NULL;
}

Figure *new_figure_ZInverted(void) {
  return NULL;
}

Figure *new_figure_Step(void) {
  return NULL;
}




void draw_rect(SDL_Renderer *renderer, SDL_Rect *rect, RGBColor *color) {
  SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, color->a);
  SDL_RenderFillRect(renderer, rect);
}


void draw_figure(SDL_Renderer *renderer, Figure *fig) {
  RGBColor color = parse_hex_rgb(0x333333FF );

  for(int i=0; i<fig->points_length; i++) {
    Point point = fig->points[i];
    SDL_Rect rect = {
      .x=point.x, .y=point.y, .w=CELL_SIZE, .h=CELL_SIZE
    };
    draw_rect(renderer, &rect, &color);
  }

}

void draw_figures_list(SDL_Renderer *renderer, FigureList *list) {
  for (int i = 0; i<list->length; i++) {
    Figure *figure = list->figures[i];
    draw_figure(renderer, figure);
  }
}

void rotate_point(Point *point, Point *center) {
  int new_x = -(point->y - center->y);
  int new_y = (point->x - center->x);
  point->y = center->y + new_y;
  point->x = center->x + new_x;
}


void rotate_figure(Figure *figure) {
  for (int i = 0; i<figure->points_length; i++) {
    rotate_point(&(figure->points[i]), &(figure->center));
  }
}


void update_figure_fall(Figure *figure) {
  for(int i=0; i<figure->points_length; i++) {
    figure->points[i].y+=SPEED;
  }
  figure->center.y+=SPEED;
}
