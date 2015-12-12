#pragma once

class SDL_Window;

class CRenderer;

class CEngine
{
  public:
    CEngine( int sWidth, int sHeight, const char* title );
    ~CEngine();

    CRenderer* getRenderer() 
        {return renderer;}

  private:
    CRenderer* renderer;
    SDL_Window* window;
};
