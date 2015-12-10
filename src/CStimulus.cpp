#include "CStimulus.h"
#include "CBehaviour.h"

CStimulus::~CStimulus() {
	for (CBehaviour* behaviour: behaviours)
		delete behaviour;
}

void CStimulus::addBehaviour( CBehaviour* behaviour ) {
    behaviours.push_back(behaviour);
}

void CStimulus::update(CWorld* world) {
    if ( isActive(world) ) 
	{
		for (CBehaviour* behaviour: behaviours)
			behaviour->perform( self );
    }
}
