#pragma once
#include <vector>
#include "COrganism.h"
#include "CBehaviour.h"

class CWorld; //Forward Declaration

class CStimulus
{
  public:
    CStimulus( COrganism* _self, CWorld* _world );
    ~CStimulus();

    virtual bool isActive() = 0;
  private:
    COrganism* self;
    CWorld* world;
};

#include "CWorld.h"
