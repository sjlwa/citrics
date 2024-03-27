#include "events.h"
#include <SDL2/SDL_log.h>
#include <SDL2/SDL_video.h>

DONE_EVENT handle_main_event(SDL_Event *event) {

  if (event->type == SDL_WINDOWEVENT) {

    switch (event->window.event) {
      case SDL_WINDOWEVENT_CLOSE:
        SDL_Log("Window %d closed", event->window.windowID);
        return QUIT_GAME;
      break;
    }

  } else if (event->type == SDL_KEYDOWN) {
    return KEY;
  }

  return NONE;
}
