#pragma once
#include "CVector3.h"
#include "CColor.h"

class COrganism;
class CBehaviour;
typedef unsigned char stateId;

class CMutator {
  public:
    static COrganism* newRockCreature (CVector3 position, CColor color);
    static COrganism* newLemmingCreature (CVector3 position, CColor color);
    static void ReplaceBehaviour (COrganism* organism, stateId todo, CBehaviour* new_action);
};
