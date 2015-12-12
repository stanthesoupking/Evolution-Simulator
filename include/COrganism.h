#pragma once
#include <vector>

#include "CStateMachine.h"
#include "CColor.h"
#include "CVector3.h"

class CWorld;

class COrganism
{
  public:
    COrganism( CStateMachine const &_brain, stateId _state, CVector3 _position, CColor _color):
        brain(_brain, _state),
        position(_position), 
        color(_color), 
        energy(100.0f)
        {}
    ~COrganism() = default;
    
    //maybe just make color public? it isn't likely to change from being in-line
    CColor getColor()
        {return color;}
    void setColor( CColor _color )
        {color = _color;}

    CVector3 position;

    //public member, because brain is mostly private anyway (COrganism is a friend)
    CStateMachine brain;
    
    float getEnergy()
        {return energy;}
        
    void act(double deltaTime, CWorld* world);

  private:
    float energy;
    float health;
    CColor color;
    
};
