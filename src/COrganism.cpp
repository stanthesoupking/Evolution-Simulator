#include "COrganism.h"
#include "CStimulus.h"

COrganism::~COrganism() {
    for (CStimulus* stimulus: stimuli)
		delete stimulus;
}

void COrganism::update( double deltaTime, CWorld* world ) {
    //Do organism actions here
	for (CStimulus* stimulus: stimuli)
        stimulus->update(world);
}

void COrganism::addStimulus( CStimulus* stimulus ) {
    stimulus->setOwner(this);
    stimuli.push_back(stimulus);
}
