#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <stdio.h>

#include "../src/figures.h"

Figure pre_rotated_figure;
Figure *rotated_figure;

void setup(void) {
  Point *points = malloc(sizeof(Point) * FIG_LNORMAL_SIZE);
  Point p0 = { .x=2, .y=0 };
  Point p1 = { .x=1, .y=0 };
  Point p2 = { .x=0, .y=0 };
  Point p3 = { .x=0, .y=1 };
  points[0] = p0;
  points[1] = p1;
  points[2] = p2;
  points[3] = p3;
  pre_rotated_figure.type = LNormal;
  pre_rotated_figure.points_length = 4;
  pre_rotated_figure.points = points;
  pre_rotated_figure.center = (Point) { .x=1, .y=1 };
}

Test(figures_suite, test_figures_rotation, .init=setup) {
  rotated_figure = new_figure_LNormal();
  rotate_figure(rotated_figure);

  /* print_figure(rotated_figure); */
  /* print_figure(&pre_rotated_figure); */

  cr_expect(cmp_figures_equal(rotated_figure, &pre_rotated_figure) == true);

  free_figure(rotated_figure);
  free_figure(&pre_rotated_figure);
}
