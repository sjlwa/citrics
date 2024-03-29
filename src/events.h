#ifndef HANDLER_MAIN_EVENT_H
#define HANDLER_MAIN_EVENT_H

#include "citrics.h"
#include <SDL2/SDL_events.h>

typedef enum {
  NONE,
  QUIT_GAME,
  KEY
} DONE_EVENT;

DONE_EVENT handle_main_event(SDL_Event *event, Citrics *game);

#endif // HANDLER_MAIN_EVENT_H
