#include <criterion/criterion.h>

#include "../src/figures.h"

Test(figures_suite, test_figures) {
  Figure *fig = new_figure_LNormal();
  print_figure(fig);
  free_figure(fig);
}
