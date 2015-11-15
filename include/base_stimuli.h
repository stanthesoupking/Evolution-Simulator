#pragma once
#include "CStimulus.h"

// Base-Stimuli header file:
// Classes stored in here are the base stimuli that can be used by organisms.


//SEnergyInRange Stimulus
// - Is true when energy of owner is greater than parameter 'a' and less than prameter 'b'
class SEnergyInRange: public CStimulus
{
  public:
    virtual void setParam( float _a, float _b );
    virtual bool isActive();
  private:
    float a, b;
};
