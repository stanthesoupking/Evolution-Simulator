#pragma once
#include "CStimulus.h"

class SEnergyInRange: public CStimulus
{
  public:
    virtual void setParam( float _a, float _b );
    virtual bool isActive();
  private:
    float a, b;
};
