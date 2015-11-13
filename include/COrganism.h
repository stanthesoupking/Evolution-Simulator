#pragma once
#include "CColor.h"
#include "CVector3.h"

class COrganism
{
  public:
    COrganism( CVector3 _position, CColor* _color );
    ~COrganism();
    void update();
    
    CColor* getColor();
    void setColor( CColor* _color );

    CVector3 position;
  private:
    float energy;
    float health;
    CColor* color;
};
