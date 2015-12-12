#include "COrganism.h"

#include "CBehaviour.h"

void COrganism::act(double deltaTime, CWorld* world) {
    //get the current state, then its action, then do whatever that is
    CBehaviour* action = brain.getState().action;
    if (action)
        action->perform(deltaTime, this);
}
