//
//  GNFA.hpp
//  foundationsProject
//
//  Created by Calvin Yee on 12/9/21.
//

#ifndef GNFA_hpp
#define GNFA_hpp

#include "RE.hpp"

#include <stdio.h>
#include <vector>
#include <map>
#include <functional>
#include <utility>

template<typename T>
class GNFA{
public:
   GNFA(std::function<bool(T)> initStates,
        std::vector<int> initAlphabet,
        T initStartState,
        T initEndState,
        std::map<std::pair<T, T>, RE*> initBDelta):
        states(initStates), alphabet(initAlphabet), startState(initStartState), endState(initEndState), bDelta(initBDelta){};
    
private:
    std::function<bool(T)> states;
    std::vector<int> alphabet;
    T startState;
    T endState;
    std::map<std::pair<T, T>, RE*> bDelta;
};

#endif /* GNFA_hpp */
