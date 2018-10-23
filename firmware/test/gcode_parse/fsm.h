class Fsm;
typedef void (*State)(void);

class Fsm
{
    public:
        Fsm(State state) :
        state__(state) {}

        void FsmInitialize(State init_);
        void FsmCall();
        void FsmTrans(State targ_);

        State state__;
};
