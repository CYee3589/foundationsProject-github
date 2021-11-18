//
//  NFA.hpp
//  foundationsProject
//
//  Created by Calvin Yee on 11/2/21.
//

#ifndef NFA_hpp
#define NFA_hpp

#include "DFA.hpp"

#include <stdio.h>

#include <iostream>
#include <vector>
#include <list>
#include <functional>
#include <utility>
#include <stack>
#include <algorithm>
#include <set>


const int epsolon = -9876;

// States are lists of T

template<typename T>
class NFA{
public:
    // Constructor
    NFA<T> (
        std::function<bool(T state)> initIsStateValid,
        std::vector<int> initAlphabet,
        std::function<std::set<T>(T currentState, int charcterInAlphabet)> initTransitionFunction,
        std::function<std::set<T>(T currentState)> initEpislonFunction,
        T initStartState,
        std::function<bool(T state)> initIsAcceptedState):
     isStateValid(initIsStateValid), alphabet(initAlphabet), transitionFunction(initTransitionFunction), epislonFunction(initEpislonFunction), startState(initStartState), isAcceptedState(initIsAcceptedState) {};
    
    NFA<T> (DFA<T> dfa):
        isStateValid(dfa.isStateValid),
        alphabet(dfa.alphabet),
        transitionFunction([dfa](T currentState, int charcterInAlphabet) -> std::set<T>
        {
            return {dfa.transitionFunction(currentState, charcterInAlphabet)};
//            return dfa.transitionFunction(currentState, charcterInAlphabet);
        }),
        epislonFunction([](T currentState) -> std::set<T>
        {
        return {};
        }),
        startState(dfa.startState),
        isAcceptedState(dfa.isAcceptedState) {};
    
    //Bool function that checks if the inputed state is valid
    std::function<bool(T state)> isStateValid;
    
    // The alphabet set being used for this DFA
    std::vector<int> alphabet;
    
    //Really long if else function that outputs the next state given the currentstate and the currrentAlphabet char
    std::function<std::set<T>(T currentState, int charcterInAlphabet)> transitionFunction;
    
    //Function that excepts episolon
    std::function<std::set<T>(T currentState)> epislonFunction;
        
    // the starting state
    T startState;
    
    // Bool function that checks if the inputed state is accepted
    std::function<bool(T state)> isAcceptedState;
};


//template<typename A, typename B>
//NFA<std::pair<int, std::pair<A, B>>> generateNFAUnion(NFA<A> left, NFA<B> right){
//    // Start State is {0,{X,Y}}
//    // left State is {1,{X,Y}}
//    // right State is {2,{X,Y}}
//    // End State is {3,{X,Y}}
//
//    NFA<std::pair<int, std::pair<A, B>>> temp(
//            [left, right](std::pair<int, std::pair<A, B>> state)
//            {
//                if (state.first == 0 || state.first == 3) {
//                    return true;
//                }
//                if (state.first == 1){
//                    return left.isStateValid(state.second.first);
//                }
//                if (state.first == 2) {
//                    return right.isStateValid(state.second.second);
//                }
//                return false;
//
//            },
//            {0,1},
//            [left, right](std::pair<int, std::pair<A, B>> state, int charcterInAlphabet) -> std::set<int> {
//                if (currentState == 0 && charcterInAlphabet == 0) return {0};
//                else if (currentState == 0 && charcterInAlphabet == 1) return {0,1};
//                else if (currentState == 1) return {2};
//                else if (currentState == 2) return {3};
//                else return {};
//            },
//            [left, right](std::pair<int, std::pair<A, B>> state) -> std::set<int> {
//                if(state.first == 0){
//
//                }
//
//                return {};
//            },
//            {0,{}},
//            [left, right](std::pair<int, std::pair<A, B>> state){return state.first == 3;}
//    );
//
//    return temp;
//}



#endif /* NFA_hpp */
