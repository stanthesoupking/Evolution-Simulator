#pragma once
#include "CBehaviour.h"

namespace Behaviour {

class WalkSouthEast: public CBehaviour {
  public:
    void perform (double deltaTime, COrganism* self);
    CBehaviour* newCopy () const
        {return new WalkSouthEast;}
};

//End namespace: Behaviour
}
