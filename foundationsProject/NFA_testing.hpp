//
//  NFA_testing.hpp
//  foundationsProject
//
//  Created by Calvin Yee on 11/14/21.
//

#ifndef NFA_testing_hpp
#define NFA_testing_hpp

#include "NFA.hpp"
#include "trace_tree.hpp"


#include <stdio.h>

template<typename T>
bool Oracle(NFA<T> nfa, std::list<int> string, std::list<T> trace, bool isTrue){
    
    // Check for trace is empty
    if (trace.empty()) {
        return (isTrue == string.empty());
    }
    
    // Set the currentStates with the starting state
    std::set<T> currentStates;
    std::set<T> tempCurrentStates;
    currentStates.insert(nfa.startState);
    
    
    std::list<int> tracker = string;
    std::list<T> traceTracker = trace;
    T tempTracer;
    
    // Check if the starting state is accepted first
    if (!(nfa.isAcceptedState(nfa.startState))) {
        return true;
    }
    
    while(!(tracker.empty())){
        int tempTracker = tracker.front();
        tracker.pop_front();
        tempTracer = trace.front();
        trace.pop_front();
        
        // Loop through the states in currentStates to fill in tempCurrentStates
        for (T const &c: currentStates) {
            // Put new states in tempEpislon and tempFunc and amass them in tempCurrentStates
            std::set<T> tempEpislon = nfa.epislonFunction(c);
            std::set<T> tempFunc = nfa.transitionFunction(c, tempTracker);
            tempCurrentStates.insert(tempFunc.begin(), tempFunc.end());
            tempCurrentStates.insert(tempEpislon.begin(), tempEpislon.end());
        }
        
        // Update currentStates and clear tempCurrentStates
        currentStates = tempCurrentStates;
        tempCurrentStates.clear();
        
        // Check if the states in current states is in the trace
        if(!(currentStates.find(tempTracer) != currentStates.end())){
            return false;
        }
    }
    
    // Check Again if the states in current states is in the trace
    if(currentStates.find(tempTracer) != currentStates.end()){
        return true == isTrue;
    }
    
    // The loop didn't detect anything, so return false
    return false;
}


template<typename T>
std::list<traceTreeBranch<T>> Forking(NFA<T> nfa, std::list<int> string){
    // Set temp
    std::list<traceTreeBranch<T>> answer;               // Returned Tree
    std::list<traceTreeBranch<T>> branchHolder;         // Temparary holds the current branches
    std::list<traceTreeBranch<T>> branchHolderTemp;     // Temparary holds the current branches

    std::list<int> updatedStringtemp;
    
    int branchCounter = 1;
    
    // Puts first branch into answer
    answer.push_back(traceTreeBranch<T>(string, nfa.startState, nfa.isAcceptedState(nfa.startState)));
    branchHolder.push_back(traceTreeBranch<T>(string, nfa.startState, nfa.isAcceptedState(nfa.startState)));

    do {
        // c is a traceTreeBranch Object
        for (traceTreeBranch<T> &c: branchHolder){

            // Checks for epsilon first
            std::set<T> tempEpsilon = nfa.epislonFunction(c.getCurrentState());
            // d is the state from the tempEpsilon
            for (T const &d: tempEpsilon){
                // Pushes a trace_tree_branch that holds branchCounter, c's current string, c's current state, d (the new state), and weither d is accepted or not
                answer.push_back(traceTreeBranch<T>(branchCounter, c.getCurrentString(), c.getCurrentState(), d, nfa.isAcceptedState(d)));
                branchHolderTemp.push_back(traceTreeBranch<T>(branchCounter, c.getCurrentString(), c.getCurrentState(), d, nfa.isAcceptedState(d)));
                                
            }
            
            // Checks for the transition next
            std::set<T> tempTrans = nfa.transitionFunction(c.getCurrentState(), c.getCurrentString().front());
            
            // Creates a temp updated string with the first element removed
            updatedStringtemp = c.getCurrentString();
            updatedStringtemp.pop_front();
            
            for (T const &e: tempTrans){
                // Pushes a trace_tree_branch that holds branchCounter, updated string, c's current state, d (the new state), and weither d is accepted or not
                answer.push_back(traceTreeBranch<T>(branchCounter, updatedStringtemp, c.getCurrentState(), e, nfa.isAcceptedState(e)));
                branchHolderTemp.push_back(traceTreeBranch<T>(branchCounter, updatedStringtemp, c.getCurrentState(), e, nfa.isAcceptedState(e)));
            
            }
        }
        // Updates branch
        branchHolder.clear();
        branchHolder = branchHolderTemp;
        branchHolderTemp.clear();
        branchCounter++;

    } while(!(updatedStringtemp.empty()));

    return answer;
}


template<typename T>
bool Backtrack(NFA<T> nfa, std::list<int> string){
        
    // Set the currentStates with the starting state
    std::set<T> currentStates;
    std::set<T> tempCurrentStates;

    currentStates.insert(nfa.startState);
    std::list<int> tracker = string;
    
    // Check if the starting state is accepted first
    if (nfa.isAcceptedState(nfa.startState)) {
        return true;
    }
    
    while(!(tracker.empty())){
        int temp = tracker.front();
        tracker.pop_front();
        
        // Loop through the states in currentStates to fill in tempCurrentStates
        for (T const &c: currentStates) {
            // Put new states in tempEpislon and tempFunc and amass them in tempCurrentStates
            std::set<T> tempEpislon = nfa.epislonFunction(c);
            std::set<T> tempFunc = nfa.transitionFunction(c, temp);
            tempCurrentStates.insert(tempFunc.begin(), tempFunc.end());
            tempCurrentStates.insert(tempEpislon.begin(), tempEpislon.end());
        }
        
        // Update currentStates and clear tempCurrentStates
        currentStates = tempCurrentStates;
        tempCurrentStates.clear();
        
//        for (int const &d: currentStates) {
//            std::cout << d << std::endl;
//        }
//        std::cout << std::endl;
        
    }
    
    // After when loop is done, check through the states in currentStates to see if any of them are accepting
    for (int const &d: currentStates) {
        if (nfa.isAcceptedState(d)) {
            return true;
        }
    }
    
    // The loop didn't detect anything, so return false
    return false;
    
}


template<typename T>
void printTraceTree(std::list<traceTreeBranch<T>> traceTree){
    // "1: 0->2 {0,1,0} 0"
    for (traceTreeBranch<T> &c: traceTree){
        std::cout << c.getRank() << ": ";
        std::cout << c.getPreviousState() << "->" << c.getCurrentState();
        std::cout << "{";
        for (int const &d: c.getCurrentString()){
            std::cout << d << ",";
        }
        std::cout << "}";
        std::cout << " " << c.getIsAccepting();
        std::cout << std::endl;
    }
}


// Function that checks if 2 traceTreeBranch Objects are the same
template<typename T>
bool doTraceTreesBranchesEqual(traceTreeBranch<T> left, traceTreeBranch<T> right){
    bool test1 = left.getRank() == right.getRank();
    bool test2 = left.getIsAccepting() == right.getIsAccepting();
    bool test3 = left.getCurrentState() == right.getCurrentState();
    bool test4 = left.getCurrentString() == right.getCurrentString();
    bool test5 = left.getPreviousState() == right.getPreviousState();
    
    return test1 & test2 & test3 & test4 & test5;
}

// Function that checks if 2 traceTrees are the same
template<typename T>
bool doTraceTreesEqual(std::list<traceTreeBranch<T>> left, std::list<traceTreeBranch<T>> right){
    // Check if the sizes of both trace trees are equal
    if(left.size() != right.size()){
        std::cout << "Trace Trees aren't the same sizes" << std::endl;
        return false;
    }
    int x = (int)left.size();
    
    // Set iterators for both left and right
    typename std::list<traceTreeBranch<T>>::iterator itleft = left.begin();
    typename std::list<traceTreeBranch<T>>::iterator itright = right.begin();
    
    // Loop through the trees and compare both iterators
    for (int i = 0; i < x; i++) {
        if (!(doTraceTreesBranchesEqual(*itleft, *itright))) {
            std::cout << "Trace Branches in index " << i << " didn't match" << std::endl;
            return false;
        }
        itleft++;
        itright++;
    }
    
    return true;
}

#endif /* NFA_testing_hpp */
