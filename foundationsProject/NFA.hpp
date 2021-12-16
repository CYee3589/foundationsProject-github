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
    
    // Constructor that turns a DFA into a NFA
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
    
    // The alphabet set being used for this NFA
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

// KleeneStar generator
// Remeber: a State is a pair that holds the position (int) and the set of states (std::list<>)
template<typename T>
NFA<std::pair<int, T>> generateKleeneStar(NFA<T> nfa){
    // Start State is {0,X} (first: position 0, second: anything)
    // In machine State is {1,Y} (first: position 1, second: state from nfa)
    
    // Create start State
    std::pair<int, T> startState;
    startState.first = 0;
//    startState.second = nfa.startState;
    
    NFA<std::pair<int, T>> temp{
        // Is state valid function
        [nfa](std::pair<int, T> state){
            if (state.first == 0) {
                return true;
            }
            else if (state.first == 1){
                return nfa.isStateValid(state.second);
            }
            return false;
        },
        
        // Alphabet
        nfa.alphabet,
        
        // Transition Function
        [nfa](std::pair<int, T> state, int charcterInAlphabet) -> std::set<std::pair<int, T>>{
            // output pair
            std::set<std::pair<int, T>> outputSet;
            std::pair<int, T> outputPair;
            
            if (state.first == 1){
                // Loop through transition function set and insert them into new set
                auto temp = nfa.transitionFunction(state.second, charcterInAlphabet);
                for(auto tempState : temp){
                    outputPair.first = 1;
                    outputPair.second = tempState;
                    outputSet.insert(outputPair);
                }
            }
            return outputSet;
        },
        
        // Function that excepts episolon
        [nfa](std::pair<int, T> state) -> std::set<std::pair<int, T>>{
            // output pair
            std::set<std::pair<int, T>> outputSet;
            std::pair<int, T> outputPair;
            
            // If in position 0, go to position 1 at start state
            if (state.first == 0){
                outputPair.first = 1;
                outputPair.second = nfa.startState;
                outputSet.insert(outputPair);
            }
            
            // If in position 1, output the epsolon states
            else if (state.first == 1){
                
                // If the state is accepted, go back to postion 0
                if (nfa.isAcceptedState(state.second)) {
                    outputPair.first = 0;
                    outputSet.insert(outputPair);
                }
                
                // Loop through the epsolon set, and insert each state
                auto hammy = nfa.epislonFunction(state.second);
                for(auto tempState : hammy){
                    outputPair.first = 1;
                    outputPair.second = tempState;
                    outputSet.insert(outputPair);
                }
            }
            
            return outputSet;
        },
        
        // Starting State
        startState,
        
        // Is state accepted function
        [nfa](std::pair<int, T> state){
            if (state.first == 0){
                return true;
            }
            if (state.first == 1){
                return nfa.isAcceptedState(state.second);
            }
            return false;
        }
    };
    
    return temp;
}

template<typename A, typename B>
NFA<std::pair<int, std::pair<A, B>>> generateNFAUnion(const NFA<A> &n1, const NFA<B> &n2)
{
    // "X" indicates unused field

    // Start state is {2, {X, X}}
    // End state is {3, {X, X}}

    // n1 states are {0, {state, X}}
    // n2 states are {1, {X, state}}

    // Construct unioned NFA
    return NFA<std::pair<int, std::pair<A, B>>>(
        [n1,n2](std::pair<int, std::pair<A, B>> qi)
        {
            if(qi.first == 2 || qi.first == 3)
                return true;
            if(qi.first == 0)
                return n1.states(qi.second.first);
            if(qi.first == 1)
                return n2.states(qi.second.second);
            return false;
        },
        combine2Vectors(n1.alphabet, n2.alphabet),
        {2, {}},
        [n1,n2](std::pair<int, std::pair<A, B>> qi, int c) -> std::vector<std::pair<int, std::pair<A, B>>>
        {
            std::pair<A,B> outPair;
            std::vector<std::pair<int, std::pair<A, B>>> outVec;
            if(qi.first == 0)
            {
                auto inVec = n1.delta(qi.second.first, c);
                for(auto state : inVec)
                {
                    outPair.first = state;
                    outVec.push_back({0, outPair});
                }
            }
            else if(qi.first == 1)
            {
                auto inVec = n2.delta(qi.second.second, c);
                for(auto state : inVec)
                {
                    outPair.second = state;
                    outVec.push_back({1, outPair});
                }
            }

            return outVec;
        },
        [n1,n2](std::pair<int, std::pair<A, B>> qi) -> std::vector<std::pair<int, std::pair<A, B>>>
        {
            std::vector<std::pair<int, std::pair<A, B>>> outVec;
            std::pair<int, std::pair<A,B>> p1;
            std::pair<int, std::pair<A,B>> p2;
            std::pair<A,B> outPair;
            
            if(qi.first == 2)
            {
                p1.first = 0; p1.second.first = n1.startState;
                outVec.push_back(p1);

                p2.first = 1; p2.second.second = n2.startState;
                outVec.push_back(p2);
            }
            else if(qi.first == 0)
            {
                auto inVec = n1.deltaE(qi.second.first);
                for(auto state : inVec)
                {
                    outPair.first = state;
                    outVec.push_back({0, outPair});
                }
                if(n1.acceptingStates(qi.second.first))
                    outVec.push_back({3, {}});
            }
            else if(qi.first == 1)
            {
                auto inVec = n2.deltaE(qi.second.second);
                for(auto state : inVec)
                {
                    outPair.second = state;
                    outVec.push_back({1, outPair});
                }
                if(n2.acceptingStates(qi.second.second))
                    outVec.push_back({3, {}});
            }

            return outVec;
        },
        [](std::pair<int, std::pair<A, B>> qi) { return qi.first == 3; }
    );
}

template<typename A, typename B>
NFA<std::pair<int, std::pair<A, B>>> generateConcatNFA(const NFA<A> &n1, const NFA<B> &n2)
{
    // "X" indicates unused field

    // n1 states are {0, {state, X}}
    // n2 states are {1, {X, state}}

    std::pair<int, std::pair<A, B>> startState;
    startState.first = 0; startState.second.first = n1.startState;

    return NFA<std::pair<int, std::pair<A, B>>>(
        [n1,n2](std::pair<int, std::pair<A, B>> qi)
        {
            if(qi.first == 0)
                return n1.states(qi.second.first);
            if(qi.first == 1)
                return n2.states(qi.second.second);
            return false;
        },
        combine2Vectors(n1.alphabet, n2.alphabet),
        startState,
        [n1,n2](std::pair<int, std::pair<A, B>> qi, int c) -> std::vector<std::pair<int, std::pair<A, B>>>
        {
            std::pair<A,B> outPair;
            std::vector<std::pair<int, std::pair<A, B>>> outVec;
            if(qi.first == 0)
            {
                auto inVec = n1.delta(qi.second.first, c);
                for(auto state : inVec)
                {
                    outPair.first = state;
                    outVec.push_back({0, outPair});
                }
            }
            else if(qi.first == 1)
            {
                auto inVec = n2.delta(qi.second.second, c);
                for(auto state : inVec)
                {
                    outPair.second = state;
                    outVec.push_back({1, outPair});
                }
            }

            return outVec;
        },
        [n1,n2](std::pair<int, std::pair<A, B>> qi) -> std::vector<std::pair<int, std::pair<A, B>>>
        {
            std::vector<std::pair<int, std::pair<A, B>>> outVec;
            std::pair<int, std::pair<A,B>> p1;
            std::pair<A,B> outPair;

            if(qi.first == 0)
            {
                if(n1.acceptingStates(qi.second.first))
                {
                    p1.first = 1; p1.second.second = n2.startState;
                    outVec.push_back(p1);
                }

                auto inVec = n1.deltaE(qi.second.first);
                for(auto state : inVec)
                {
                    outPair.first = state;
                    outVec.push_back({0, outPair});
                }
            }
            else if(qi.first == 1)
            {
                auto inVec = n2.deltaE(qi.second.second);
                for(auto state : inVec)
                {
                    outPair.second = state;
                    outVec.push_back({1, outPair});
                }
            }

            return outVec;
        },
        [n2](std::pair<int, std::pair<A, B>> qi)
        {
            if(qi.first == 1) return n2.acceptingStates(qi.second.second);
            return false;
        }
    );
}

template<typename T>
DFA<std::set<T>> NFAtoDFA(NFA<T> nfa){
    // Starting state
    std::set<T> startingStateSet;
    startingStateSet.insert(nfa.startState);
    std::set<T> startingEpsilonSet = nfa.epislonFunction(nfa.startState);
    startingStateSet.insert(startingEpsilonSet.begin(), startingEpsilonSet.end());
    
    DFA<std::set<T>> temp{
        // Bool function that checks if each states in the set is accepted
        [nfa](std::set<T> state){
            for(auto c : state){
                if (!(nfa.isStateValid(c))) {
                    return false;
                }
            }
            return true;
        },
        
        // The alphabet set being used for this DFA
        nfa.alphabet,
        
        //Really long if else function that outputs the next state given the currentstate and the currrentAlphabet char
        [nfa](std::set<T> state, int charcterInAlphabet) -> std::set<T>{
            std::set<T> outputSet;
            std::set<T> tempTrans;
            std::set<T> tempEpislon;
            
            // Go through each state in the set
            for(auto c : state){
                                
                // Add in the states from the transition function
                tempTrans = nfa.transitionFunction(c, charcterInAlphabet);
                outputSet.insert(tempTrans.begin(), tempTrans.end());
                
                // Add in the epsilon states
                tempEpislon = nfa.epislonFunction(c);
                outputSet.insert(tempEpislon.begin(), tempEpislon.end());
                
                tempTrans.empty();
                tempEpislon.empty();
            }

            return outputSet;
        },
        
        // the starting state
        startingStateSet,
        
        // Bool function that checks if any state in the set is accepted
        [nfa](std::set<T> state){
            for(auto c : state){
                if (nfa.isAcceptedState(c)) {
                    return true;
                }
            }
            return false;
        }

    };

    return temp;
}


#endif /* NFA_hpp */
