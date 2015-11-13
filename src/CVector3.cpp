#include "CVector3.h"

CVector3::CVector3() {
    x = 0;
    y = 0;
    z = 0;
};

CVector3::CVector3( float _x, float _y, float _z ) {
    x = _x;
    y = _y;
    z = _z;
}

CVector3::~CVector3() {

}

void CVector3::displace(  float dX, float dY, float dZ ) {
    x += dX;
    y += dY;
    z += dZ;
}

void CVector3::displace( CVector3 disp ) {
    x += disp.x;
    y += disp.y;
    z += disp.z;
}
