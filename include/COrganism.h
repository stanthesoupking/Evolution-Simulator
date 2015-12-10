#pragma once
#include <vector>
#include "CColor.h"
#include "CVector3.h"

class CStimulus; //Forward Declaration
class CWorld;

class COrganism
{
  public:
    COrganism( CVector3 _position, CColor _color ):
	    position(_position), color(_color), energy(100), stimuli()
		{}
    ~COrganism();
    void update( double deltaTime, CWorld* world );
    
    float getEnergy()
    	{return energy;}
    CColor getColor()
	    {return color;}
    void setColor( CColor _color )
	    {color = _color;}

    CVector3 position;

    void addStimulus( CStimulus* stimulus );
  private:
    float energy;
    float health;
    CColor color;

    std::vector< CStimulus* > stimuli;
};
