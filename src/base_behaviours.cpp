#include "base_behaviours.h"
#include "COrganism.h"

namespace Behaviour {

void WalkSouthEast::perform (double deltaTime, COrganism* self) {
    self->position.displace(CVector3(-10.0 * deltaTime, -10.0 * deltaTime, 0));
}

//End namespace: Behaviour
}
