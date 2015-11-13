#pragma once
#include <vector>
#include <SDL2/SDL.h>
#include "CEngine.h"
#include "CRenderer.h"
#include "CWorld.h"
#include "CColor.h"
#include "COrganism.h"
#include "CVector3.h"

class CGame
{
  private:
    CEngine* engine;
    CRenderer* renderer;
    CWorld* world;
    
    COrganism* testOrganism;

    CVector3 cameraPos;

    void doEvents();
  public:
    CGame( CEngine* _engine );
    ~CGame();

    bool running;    

    void start();
    void update();
};
