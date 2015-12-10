#include "base_stimuli.h"
#include "CWorld.h"
#include "COrganism.h"

//SEnergyInRange Stimulus
// - Is true when energy of owner is greater than parameter 'a' and less than prameter 'b'

void SEnergyInRange::setParam( float _a, float _b ) {
    a = _a; //Min range
    b = _b; //Max range
};

bool SEnergyInRange::isActive(CWorld* world) {
    //Return true if energy is in range.
    float oEnergy = self->getEnergy();
    return (oEnergy > a) && (oEnergy < b);
}
