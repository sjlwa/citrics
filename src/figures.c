#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "figures.h"

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
    printf(" (%d, %d) ", point.x, point.y);
  }
  printf("\n");
}

int cmp_points_equal(Point *p1, Point *p2) {
  return (p1->x == p2->x) || (p1->y == p2->y);
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
  Point p1 = { .x=0, .y=1 };
  Point p2 = { .x=0, .y=2 };
  Point p3 = { .x=1, .y=2 };
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