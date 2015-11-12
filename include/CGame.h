#pragma once
#include <SDL/SDL.h>
#include "CEngine.h"
#include "CRenderer.h"

class CGame
{
  private:
    CEngine* engine;
    CRenderer* renderer;
    void doEvents();
  public:
    CGame( CEngine* _engine );
    ~CGame();

    bool running;

    void start();
    void update();
};
