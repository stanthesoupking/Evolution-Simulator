#pragma once
#include <SDL2/SDL.h>
#include "COrganism.h"
#include "CVector3.h"
#include "CColor.h"

class CRenderer
{
  private:
    float MARKER_SIZE; //The size of a marker displaying an organism

    SDL_Window* window;     //Main Window
    SDL_Renderer* renderer; //Main Renderer

    CColor* grass_color;
  public:
    CRenderer( SDL_Window* _window );
    ~CRenderer();

    void clear();
    void present();
    
    void setRenderColor( CColor* color );
    void renderOrganism( COrganism* organism, CVector3 cameraPos );
};
