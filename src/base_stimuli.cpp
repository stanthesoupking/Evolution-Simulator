#include "base_stimuli.h"

//SEnergyInRange Stimulus
// - Is true when energy of owner is greater than parameter 'a' and less than prameter 'b'
void SEnergyInRange::setParam( float _a, float _b ) {
    a = _a; //Min range
    b = _b; //Max range
};

bool SEnergyInRange::isActive() {
    //Return true if energy is in range.
    float oEnergy = getOwner()->getEnergy();
    return (oEnergy > a) && (oEnergy < b);
}
