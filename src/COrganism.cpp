#include "COrganism.h"

COrganism::COrganism( CVector3 _position, CColor* _color ) {
    position = _position;
    color = _color;
}

COrganism::~COrganism() {
    
}

void COrganism::update( double deltaTime ) {
    //Do organism actions here
}

CColor* COrganism::getColor() {
    return color;
}
