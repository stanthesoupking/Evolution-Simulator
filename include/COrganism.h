#pragma once
#include "CColor.h"

class COrganism
{
  public:
    COrganism( int _x, int _y, CColor* _color );
    ~COrganism();
    void update();
    
    CColor* getColor();
    void setColor( CColor* _color );

    int getX();
    int getY();
    void setPosition( int _x, int _y );
    void displace ( int dX, int dY );

  private:
    int x, y;
    float energy;
    float health;
    CColor* color;
};
