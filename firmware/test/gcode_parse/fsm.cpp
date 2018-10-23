#include "fsm.h"
void Fsm::FsmInitialize(State init_)
{
    // Set the initial state handler function
    state__ = (State)init_;
}

void Fsm::FsmCall()
{
    // Execute the state handler function
    (*state__) ();
}

void Fsm::FsmTrans(State targ_)
{
    // Transition between different state handler function
    state__ = (State)targ_;
}