#include "COrganism.h"

COrganism::COrganism( CVector3 _position, CColor* _color ) {
    position = _position;
    color = _color;

    stimuli = new std::vector< CStimulus* >();
}

COrganism::~COrganism() {
    
}

void COrganism::update( double deltaTime ) {
    //Do organism actions here
    for(int i = 0; i < stimuli->size(); i++) {
        CStimulus* stimulus = stimuli->at(i);
        stimulus->update();
    }
}

CColor* COrganism::getColor() {
    return color;
}

void COrganism::addStimulus( CStimulus* stimulus ) {
    stimulus->setOwner(this);
    stimuli->push_back(stimulus);
}
