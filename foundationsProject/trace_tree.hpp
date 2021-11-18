//
//  trace_tree.hpp
//  foundationsProject
//
//  Created by Calvin Yee on 11/12/21.
//

#ifndef trace_tree_hpp
#define trace_tree_hpp

#include <stdio.h>
#include <list>

template<typename T>
class traceTreeBranch{
public:
    traceTreeBranch<T>(
        int initRank,
        std::list<int> initCurrentString,
        T initPreviousState,
        T initCurrentState,
        bool initIsAccepting):
    rank(initRank), currentString(initCurrentString), previousState(initPreviousState), currentState(initCurrentState), isAccepting(initIsAccepting) {};
    
    // For starting branch
    traceTreeBranch<T>(
        std::list<int> startingString,
        T startingState,
        bool initIsAccepting):
    rank(0), currentString(startingString), previousState(startingState), currentState(startingState), isAccepting(initIsAccepting) {};
    
    int getRank(void){
        return rank;
    };
    
    std::list<int> getCurrentString(void){
        return currentString;
    };
    
    T getPreviousState(void){
        return previousState;
    };
    
    T getCurrentState(void){
        return currentState;
    };
    
    bool getIsAccepting(void){
        return isAccepting;
    };

    
private:
    int rank;
    std::list<int> currentString;
    T previousState;
    T currentState;
    bool isAccepting;
};


#endif /* trace_tree_hpp */
