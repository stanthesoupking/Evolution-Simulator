#pragma once
#include "CStimulus.h"

namespace Stimulus {

// Base-Stimuli header file:
// Classes stored in here are the base stimuli that can be used by organisms.


//SEnergyInRange Stimulus
// - Is true when energy of owner is greater than parameter 'a' and less than prameter 'b'
class SEnergyInRange: public CStimulus
{
  public:
    SEnergyInRange ():
      CStimulus () {}
    SEnergyInRange (SEnergyInRange const * base):
        a(base->a),
        b(base->b)
        {}
    using CStimulus::CStimulus;
    void setParam( float _a, float _b );
    bool isActive(COrganism* self, CWorld* world);
    SEnergyInRange* newCopy() const
        {return new SEnergyInRange (this);}
  private:
    float a, b;
};

//End namespace: Stimulus
}
