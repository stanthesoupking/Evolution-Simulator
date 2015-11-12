#pragma once
#include <SDL/SDL.h>

class CRenderer
{
  private:
    int sWidth, sHeight;   //Window Dimensions
    SDL_Surface* vSurface; //Video Surface
  public:
    CRenderer( int _sWidth, int _sHeight );
    ~CRenderer();

    void update();
};
