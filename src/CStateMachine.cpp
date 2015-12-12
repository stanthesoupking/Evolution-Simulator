#include "CStateMachine.h"

#include "CStimulus.h"
#include "CBehaviour.h"

CStateMachine::CStateMachine (CStateMachine const &base, stateId _state):
    state(_state),
    states(base.states.size()),
    stimuli(base.stimuli.size())
{
    for (CBehaviourState const &state: base.states)
        states.emplace_back(state);
    for (CStimulus* stimulus: base.stimuli)
        stimuli.push_back(stimulus->newCopy());
}

CStateMachine::~CStateMachine () {
    for (CBehaviourState& state: states)
        delete state.action;
    for (CStimulus* stimulus: stimuli)
        delete stimulus;
}

void CStateMachine::think( double deltaTime, COrganism* self, CWorld* world ) {
    //Get current state info
    CBehaviourState& current_state = getState();
    
    //test to see if it is too late to do something
    if (abort <= 0.0)
        //change state in response, and queue next abortion
        updateState(current_state.abort_state);
    else 
    //test all other stimuli, since it is still waiting/acting
    for (std::pair< stimId, stateId > attempt: getState().links)
    {
        //get the actual stimulus from the list
        CStimulus& stimulus = *stimuli[attempt.first];
        //test that stimulus against the current environment
        if (stimulus.isActive(self, world))
        {
            //upon succeeding follow this link in the state-machine
            updateState(attempt.second);
            //terminate the loop
            break;
        }
    }
    abort -= deltaTime;
}

CStateMachine::CBehaviourState::CBehaviourState (float _abort_delay, stateId _abort_state, CBehaviour* _action):
    links(),
    abort_delay(_abort_delay),
    abort_state(_abort_state),
    action(_action)
    {}

CStateMachine::CBehaviourState::CBehaviourState (CBehaviourState const &base):
    links(base.links),
    abort_delay(base.abort_delay),
    abort_state(base.abort_state),
    action(base.action?base.action->newCopy():nullptr)
    {}
