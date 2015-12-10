#pragma once
#include <vector>

//Forward Declaration:
class COrganism;
class CBehaviour;  
class CWorld;
//END

class CStimulus
{
  public:
    CStimulus():
	    self (nullptr), 
        behaviours() {}
    ~CStimulus();
    
    virtual void setParam() {}

    void setOwner( COrganism* _self )
	    {self = _self;}

    virtual bool isActive(CWorld* world) 
	    {return false;}
    void update(CWorld* world);

    void addBehaviour( CBehaviour* behaviour );
    COrganism* self;

    std::vector< CBehaviour* > behaviours;
};
