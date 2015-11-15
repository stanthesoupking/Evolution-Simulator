#pragma once
#include <vector>
#include "COrganism.h"

//Forward Declaration:
class CBehaviour;  
class CWorld;
//END

class CStimulus
{
  public:
    CStimulus( COrganism* _self, CWorld* _world );
    CStimulus( CWorld* _world );
    ~CStimulus();
    
    virtual void setParam() = 0;

    void setOwner( COrganism* _self );
    COrganism* getOwner();

    virtual bool isActive() = 0;
    void update();

    void addBehaviour( CBehaviour* behaviour );
  private:
    COrganism* self;
    CWorld* world;

    std::vector< CBehaviour* >* behaviours;
};

#include "CBehaviour.h"
#include "CWorld.h"
