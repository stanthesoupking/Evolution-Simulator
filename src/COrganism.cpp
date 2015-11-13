#include "COrganism.h"

COrganism::COrganism( int _x, int _y, CColor* _color ) {
    x = _x;
    y = _y;
    color = _color;
}

COrganism::~COrganism() {
    
}

void COrganism::update() {
    
}

int COrganism::getX() {
    return x;
}

int COrganism::getY() {
    return y;
}

void COrganism::setPosition( int _x, int _y ) {
    x = _x;
    y = _y;
}

void COrganism::displace( int dX, int dY ) {
    x += dX;
    y += dY;
}
