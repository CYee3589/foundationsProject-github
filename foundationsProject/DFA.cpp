//
//  DFA.cpp
//  foundationsProject
//
// Q - set of states
// delta - alphabet
// element of Q thats the staring state
// delta - transition table
// acceptying states

#include "DFA.hpp"
#include <iostream>


bool doesStringFollowDFA(DFA dfa, std::list<int> string){
    int currentState = dfa.startState;
    
    for (int const &c: string) {
        if (!(dfa.isStateValid(currentState))) {
            return false;
        }
        currentState = dfa.transitionFunction(currentState, c);
    }
    return dfa.isAcceptedState(currentState);
}

void traceStringInDFA(DFA dfa, std::list<int> string){
    int currentState = dfa.startState;
    std::cout << currentState;
    
    for (int const &c: string) {
        if (!(dfa.isStateValid(currentState))) {
            std::cout << std::endl << c << " - not part of alphabet TRACE ENDS" << std::endl;
            return;
        }
        currentState = dfa.transitionFunction(currentState, c);
        std::cout << " -> " << currentState;
    }
    std::cout << std::endl;
}
