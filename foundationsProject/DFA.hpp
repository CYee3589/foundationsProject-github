//
//  DFA.hpp
//  foundationsProject
//
//  States are ints,

#ifndef DFA_hpp
#define DFA_hpp

#include "permutations.hpp"

#include <stdio.h>

#include <iostream>
#include <vector>
#include <list>
#include <functional>
#include <utility>
#include <stack>
#include <algorithm>
#include <optional>


//class DFA{
//public:
//    // Constructor
//    DFA(std::function<bool(int state)> initIsStateValid,
//        std::vector<int> initAlphabet,
//        std::function<int(int currentState, int charcterInAlphabet)> initTransitionFunction,
//        int initStartState,
//        std::function<bool(int state)> initIsAcceptedState):
//     isStateValid(initIsStateValid), alphabet(initAlphabet), transitionFunction(initTransitionFunction), startState(initStartState), isAcceptedState(initIsAcceptedState) {};
//
//    //Bool function that checks if the inputed state is valid
//    std::function<bool(int state)> isStateValid;
//
//    // The alphabet set being used for this DFA
//    std::vector<int> alphabet;
//
//    //Really long if else function that outputs the next state given the currentstate and the currrentAlphabet char
//    std::function<int(int currentState, int charcterInAlphabet)> transitionFunction;
//
//    // the starting state
//    int startState;
//
//    // Bool function that checks if the inputed state is accepted
//    std::function<bool(int state)> isAcceptedState;
//};

template<typename T>
class DFA{
public:
    // Constructor
    DFA<T> (
        std::function<bool(T state)> initIsStateValid,
        std::vector<int> initAlphabet,
        std::function<T(T currentState, int charcterInAlphabet)> initTransitionFunction,
        T initStartState,
        std::function<bool(T state)> initIsAcceptedState):
     isStateValid(initIsStateValid), alphabet(initAlphabet), transitionFunction(initTransitionFunction), startState(initStartState), isAcceptedState(initIsAcceptedState) {};
    
    //Bool function that checks if the inputed state is valid
    std::function<bool(T state)> isStateValid;
    
    // The alphabet set being used for this DFA
    std::vector<int> alphabet;
    
    //Really long if else function that outputs the next state given the currentstate and the currrentAlphabet char
    std::function<T(T currentState, int charcterInAlphabet)> transitionFunction;
    
    // the starting state
    T startState;
    
    // Bool function that checks if the inputed state is accepted
    std::function<bool(T state)> isAcceptedState;
};

template<typename T>
bool doesStringFollowDFA(DFA<T> dfa, std::list<int> string){
    T currentState = dfa.startState;
    
    for (int const &c: string) {
        if (!(dfa.isStateValid(currentState))) {
            return false;
        }
        currentState = dfa.transitionFunction(currentState, c);
    }
    return dfa.isAcceptedState(currentState);
}

template<typename T>
//std::optional<std::list<int>> generateViableString(DFA<T> dfa){
std::list<int> generateViableString(DFA<T> dfa){
    std::stack<T> stateChain;
    std::vector<T> visitedStates;
    std::list<int> output;
    
    stateChain.push(dfa.startState);
    
    while (!(stateChain.empty())) {
        
        //Check if DFA will accept the output string. If so, return output
        if(doesStringFollowDFA(dfa, output)){
            return output;
//            return std::optional<std::list<int>>(std::in_place, output);
        }
        
        for (int const &c: dfa.alphabet) {
            // Load the next state given the current state(top of stateChain) and element from alphabet(c)
            T temp = dfa.transitionFunction(stateChain.top(), c);
            
            // If temp ISN'T in visitedStates, then push temp into stateChain and visitedStates while also storing c into output
            if(!(std::count(visitedStates.begin(), visitedStates.end(), temp))){
                stateChain.push(temp);
                visitedStates.push_back(temp);
                output.push_back(c);
                break;
            }
            
            // Check if c is the last element in the DFA alphabet. If so, pop from stack and output
            if (dfa.alphabet.back() == c) {
                stateChain.pop();
                output.pop_back();
            }
        }
    }
    
//    std::cout << "DFA doens't accept anything" << std::endl;
//    return std::nullopt;
    return output;
}

//template<typename T>
std::optional<int> create(bool b) {
    if (b)
        return 1234;
    return std::nullopt;
}


template<typename T>
DFA<T> generateComplement(DFA<T> dfa){
    return DFA<T>{
        [dfa](T state){return dfa.isStateValid(state);},
        dfa.alphabet,
        [dfa](T currentState, int charcterInAlphabet){return dfa.transitionFunction(currentState, charcterInAlphabet);},
        0,
        [dfa](T state){return !(dfa.isAcceptedState(state));}
    };
}

//Function that removes any duplicate elements in a vector
void removeDuplicatesFromVector(std::vector<int> &v);

template<typename A, typename B>
DFA<std::pair<A, B>> generateUnion(DFA<A> dfa1, DFA<B> dfa2){
    // Creates combined alphabet
    std::vector<int> newAlphabet(dfa1.alphabet);
    newAlphabet.insert(newAlphabet.end(), dfa2.alphabet.begin(), dfa2.alphabet.end());
    removeDuplicatesFromVector(newAlphabet);

    //Union DFA
    return DFA<std::pair<A, B>>(
        // is state valid
        [dfa1, dfa2](std::pair<A, B> qi){return dfa1.isStateValid(qi.first) || dfa2.isStateValid(qi.second);},

        // new alphabet set
        newAlphabet,

        //combined transition table
        [dfa1, dfa2](std::pair<A, B> qi, int charcterInAlphabet)
            {return std::pair<A,B>(dfa1.transitionFunction(qi.first, charcterInAlphabet),
                                   dfa2.transitionFunction(qi.second, charcterInAlphabet));},

        //Start states
        std::pair<A,B>(dfa1.startState, dfa2.startState),

        //Accepting states
        [dfa1, dfa2](std::pair<A, B> qi)
            {return dfa1.isAcceptedState(qi.first) || dfa2.isAcceptedState(qi.second);}
    );
}

template<typename A, typename B>
DFA<std::pair<A, B>> generateIntercept(DFA<A> dfa1, DFA<B> dfa2){
    // Creates combined alphabet
    std::vector<int> newAlphabet(dfa1.alphabet);
    newAlphabet.insert(newAlphabet.end(), dfa2.alphabet.begin(), dfa2.alphabet.end());
    removeDuplicatesFromVector(newAlphabet);

    //Intercept DFA
    return DFA<std::pair<A, B>>(
        // is state valid
        [dfa1, dfa2](std::pair<A, B> qi){return dfa1.isStateValid(qi.first) || dfa2.isStateValid(qi.second);},

        // new alphabet set
        newAlphabet,

        //combined transition table
        [dfa1, dfa2](std::pair<A, B> qi, int charcterInAlphabet)
            {return std::pair<A,B>(dfa1.transitionFunction(qi.first, charcterInAlphabet),
                                   dfa2.transitionFunction(qi.second, charcterInAlphabet));},

        //Start states
        std::pair<A,B>(dfa1.startState, dfa2.startState),

        //Accepting states
        [dfa1, dfa2](std::pair<A, B> qi)
            {return dfa1.isAcceptedState(qi.first) && dfa2.isAcceptedState(qi.second);}
    );
}

#endif /* DFA_hpp */
