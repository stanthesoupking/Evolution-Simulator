#include "CStimulus.h"

CStimulus::CStimulus( COrganism* _self, CWorld* _world ) {
    self = _self;
    world = _world;
}

CStimulus::CStimulus( CWorld* _world ) {
    self = 0;
    world = _world;
}

CStimulus::~CStimulus() {

}

void CStimulus::setOwner( COrganism* _self ) {
    self = _self;
}

COrganism* CStimulus::getOwner() {
    return self;
}

void CStimulus::addBehaviour( CBehaviour* behaviour ) {
    behaviours->push_back(behaviour);
}

bool CStimulus::isActive() {
    return false;
}

void CStimulus::update() {
    if ( isActive() ) {
        for(int i = 0; i < behaviours->size(); i++) {
            CBehaviour* behaviour = behaviours->at(i);
            behaviour->perform( self );
        }
    }
}
