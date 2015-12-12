#pragma once
#include <map>
#include <vector>

//sentience probably needs a few more than 256 states but that's okay
typedef unsigned char stimId;
typedef unsigned char stateId;

//for friend declaration
class COrganism;
class CMutator;
//for pointers
class CBehaviour;
class CStimulus;
class CWorld;


struct CStateMachine
{
  //COrganism requires access to this struct, since it is effectively just an extra layer of encapsulation in Organism functionality
  friend COrganism;
  //CMutator is in turn an extension of StateMachine functionality, and since all constructors here are private, this friend is also necessary
  friend CMutator;
  
  private:
    CStateMachine () = default;
    CStateMachine (CStateMachine const &base, stateId _state);
    ~CStateMachine ();
    
    struct CBehaviourState
    {
        //all of the events that could make the organism change state
        std::map< stimId, stateId> links;
        //the amount of time required for the organism to 'give up' after switching to this state
        float abort_delay;
        //the state to switch to when giving up
        stateId abort_state;
        
        //The instructions associated with the state are stored in a polymorphic object
        CBehaviour* action;
        
        CBehaviourState (float _abort_delay = 1.0f, stateId _abort_state = 0, CBehaviour* _action = nullptr);
        CBehaviourState (CBehaviourState const &base);
    };
    
    float abort;
    stateId state;
    
    std::vector< CBehaviourState > states;
    std::vector< CStimulus* > stimuli;
    
    CBehaviourState& getState()
        {return states[state];}
    inline void updateState(stateId new_state);

  public:
    void think( double deltaTime, COrganism* self, CWorld* world );
};

inline void CStateMachine::updateState(stateId new_state)
{
    //update the state
    state = new_state;
    
    double new_abort = states[new_state].abort_delay;
    //if it had to abort then 'postpone' the next abort
    if (abort <= 0.0)
        abort += new_abort;
    //else reset the timer to prevent overwhelming patience
    else
        abort = new_abort;
}
