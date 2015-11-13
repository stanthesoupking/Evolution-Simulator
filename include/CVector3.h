#pragma once

class CVector3
{
  public:
    CVector3();
    CVector3( float _x, float _y, float _z );
    ~CVector3();

    void displace( float dX, float dY, float dZ );
    void displace( CVector3 disp );

    float x;
    float y;
    float z;
};
