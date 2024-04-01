#include "events.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_log.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include "citrics.h"
#include "figures.h"

DONE_EVENT handle_main_event(SDL_Event *event, Citrics *game) {

  if (event->type == SDL_WINDOWEVENT) {

    switch (event->window.event) {
      case SDL_WINDOWEVENT_CLOSE:
        game->running = false;
        SDL_Log("Window %d closed", event->window.windowID);
        return QUIT_GAME;
      break;
    }

  } else if (event->type == SDL_KEYDOWN) {

    switch (event->key.keysym.sym) {
      case SDLK_UP:
        rotate_figure(game->current_figure);
      break;
    }

    return KEY;
  }

  return NONE;
}
