#pragma once
#include <SDL2/SDL.h>

class CRenderer
{
  private:
    SDL_Window* window;     //Main Window
    SDL_Renderer* renderer; //Main Renderer
  public:
    CRenderer( SDL_Window* _window );
    ~CRenderer();

    void clear();
    void present();
};
