#pragma once
#include <vector>
#include <ctime>
#include <SDL2/SDL.h>

#include "CVector3.h"

//forward declarations for pointers
//so that the full advantages of headers are felt
class CEngine;
class CRenderer;
class CWorld;
class COrganism;


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
