#pragma once
#include <SDL2/SDL.h>
#include "CRenderer.h"

class CEngine
{
  public:
    CEngine( int sWidth, int sHeight, const char* title );
    ~CEngine();
    CRenderer* getRenderer();
  private:
    CRenderer* renderer;
    SDL_Window* window;
};
