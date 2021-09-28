//
//  DFA.hpp
//  foundationsProject
//
//  States are ints,

#ifndef DFA_hpp
#define DFA_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <functional>

// Task #4:
class DFA{
public:
    // Constructor
    DFA(std::function<bool(int state)> initIsStateValid,
        std::vector<int> initAlphabet,
        std::function<int(int currentState, int charcterInAlphabet)> initTransitionFunction,
        int initStartState,
        std::function<bool(int state)> initIsAcceptedState):
     isStateValid(initIsStateValid), alphabet(initAlphabet), transitionFunction(initTransitionFunction), startState(initStartState), isAcceptedState(initIsAcceptedState) {};
    
    //Bool function that checks if the inputed state is valid
    std::function<bool(int state)> isStateValid;
    
    // The alphabet set being used for this DFA
    std::vector<int> alphabet;
    
    //Really long if else function that outputs the next state given the currentstate and the currrentAlphabet char
    std::function<int(int currentState, int charcterInAlphabet)> transitionFunction;
    
    // the starting state
    int startState;
    
    // Bool function that checks if the inputed state is accepted
    std::function<bool(int state)> isAcceptedState;
};

// Bool function that sees weither the inputted string is accepted by the DFA
bool doesStringFollowDFA(DFA dfa, std::list<int> string);


#endif /* DFA_hpp */
