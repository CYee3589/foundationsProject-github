//
//  DFA.hpp
//  foundationsProject
//
//  States are ints,

#ifndef DFA_hpp
#define DFA_hpp

#include "permutations.hpp"
//#include "RE.hpp"


#include <stdio.h>

#include <iostream>
#include <vector>
#include <list>
#include <functional>
#include <utility>
#include <stack>
#include <algorithm>

const std::list<int> failcase = {-9999};

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


// Function that returns a string that fits with inputed DFA for returns false otherwise
template<typename T>
//std::optional<std::list<int>> generateViableString(DFA<T> dfa){
std::list<int> generateViableString(DFA<T> dfa){
    std::stack<T> stateChain;
    std::vector<T> visitedStates;
    std::list<int> output;
    
    stateChain.push(dfa.startState);
    visitedStates.push_back(dfa.startState);
    
    while (!(stateChain.empty())) {
        
        //Check if DFA will accept the output string. If so, return output
        if(doesStringFollowDFA(dfa, output)){
            return output;
        }
        
        //Check every element in the alphabet
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
                if (!output.empty()) {
                    output.pop_back();
                }
            }
            
        }
    }
    
    return failcase;
}


template<typename T>
DFA<T> generateComplement(DFA<T> dfa){
    return DFA<T>{
        [dfa](T state){return dfa.isStateValid(state);},
        dfa.alphabet,
        [dfa](T currentState, int charcterInAlphabet){return dfa.transitionFunction(currentState, charcterInAlphabet);},
        dfa.startState,
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

template<typename A, typename B>
bool isASubsetOfB(DFA<A> dfa1, DFA<B> dfa2){
    //std::list<int> failcase = {-9999};
    if (generateViableString(generateIntercept(generateComplement(dfa2), dfa1)) == failcase) {
        return true;
    } else {
        return false;
    }
}

//template<typename A, typename B>
//bool isAEqualityOfB(DFA<A> dfa1, DFA<B> dfa2){
//    return isASubsetOfB(dfa1, dfa2) && isASubsetOfB(dfa2, dfa1);
//}

template<typename A, typename B>
bool isAEqualityOfB(DFA<A> dfa1, DFA<B> dfa2){
    return true;
}


#endif /* DFA_hpp */
