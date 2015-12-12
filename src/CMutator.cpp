#include "CMutator.h"

//note that CStateMachine trusts CMutator
#include "CStateMachine.h"

#include "COrganism.h"
#include "base_stimuli.h"
#include "base_behaviours.h"

//@static
COrganism* CMutator::newRockCreature (CVector3 position, CColor color) {
    CStateMachine brain;
    brain.states.resize(1);
    brain.states[0].abort_delay = 1.0;
    brain.states[0].abort_state = 0;
    brain.states[0].action = nullptr;
    //brain.states.emplace_back(1.0f, 0, new Behaviour::Idle());
    return new COrganism (brain, 0, position, color);
}

//@static
COrganism* CMutator::newLemmingCreature (CVector3 position, CColor color) {
    CStateMachine brain;
    brain.states.resize(1);
    brain.states[0].abort_delay = 1.0;
    brain.states[0].abort_state = 0;
    brain.states[0].action = new Behaviour::WalkSouthEast();
    //brain.states.emplace_back(1.0f, 0, new Behaviour::Idle());
    return new COrganism (brain, 0, position, color);
}

void CMutator::ReplaceBehaviour (COrganism* organism, stateId todo, CBehaviour* new_action) {
    CStateMachine::CBehaviourState& state = organism->brain.states[todo];
    delete state.action;
    state.action = new_action;
}
