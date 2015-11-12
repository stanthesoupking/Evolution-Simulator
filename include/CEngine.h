#pragma once
#include <SDL/SDL.h>
#include "CRenderer.h"

class CEngine
{
  public:
    CEngine( int _sWidth, int _sHeight );
    ~CEngine();
    CRenderer* getRenderer();
  private:
    CRenderer* renderer;
};
