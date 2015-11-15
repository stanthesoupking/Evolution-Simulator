#pragma once
#include <vector>
#include "CColor.h"
#include "CVector3.h"

class CStimulus; //Forward Declaration

class COrganism
{
  public:
    COrganism( CVector3 _position, CColor* _color );
    ~COrganism();
    void update( double deltaTime );
    
    float getEnergy();
    CColor* getColor();
    void setColor( CColor* _color );

    CVector3 position;

    void addStimulus( CStimulus* stimulus );
  private:
    float energy;
    float health;
    CColor* color;

    std::vector< CStimulus* >* stimuli;
};

#include "CStimulus.h"
