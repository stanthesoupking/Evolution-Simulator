#pragma once
#include <vector>
#include <ctime>
#include <SDL2/SDL.h>
#include "CEngine.h"
#include "CRenderer.h"
#include "CWorld.h"
#include "CColor.h"
#include "COrganism.h"
#include "CVector3.h"
#include "base_stimuli.h"


class CGame
{
  private:
    CEngine* engine;
    CRenderer* renderer;
    CWorld* world;
    
    COrganism* testOrganism;

    CVector3 cameraPos;

    void doEvents();

    long pTime;
  public:
    CGame( CEngine* _engine );
    ~CGame();

    bool running;    

    void start();
    void update();
};
