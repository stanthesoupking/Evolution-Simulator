#include "CStimulus.h"

CStimulus::CStimulus( COrganism* _self, CWorld* _world ) {
    self = _self;
    world = _world;
}

CStimulus::~CStimulus() {

}

bool isActive() {
    return false;
}
