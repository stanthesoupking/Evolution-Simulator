#include "CVector3.h"

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
