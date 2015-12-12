#pragma once

class CVector3
{
  public:
    CVector3( float _x, float _y, float _z ):
	    x(_x), 
        y(_y), 
        z(_z) {}
    CVector3():
	    x(0.0), 
        y(0.0), 
        z(0.0) {}
    ~CVector3() = default;

    void displace( float dX, float dY, float dZ );
    void displace( CVector3 disp );

    float x;
    float y;
    float z;
};
