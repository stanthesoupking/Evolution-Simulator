#pragma once
#include <vector>

//Forward Declaration:
class CWorld;
class COrganism;
//END

class CStimulus
{
  public:
    CStimulus() = default;
    ~CStimulus() = default;
    
    virtual void setParam() {}
    virtual bool isActive(COrganism* self, CWorld* world) = 0;
    virtual CStimulus* newCopy() const = 0;
};
