//
//  RE_testing.cpp
//  foundationsProject
//
//  Created by Calvin Yee on 12/5/21.
//

#include "RE_testing.hpp"


template<typename T>
bool isREEquality(RE left, RE right){
    auto tempLeft = REToNFAComplier<T>(left);
    auto tempRight = REToNFAComplier<T>(right);
    
    DFA<std::set<T>> DFAleft = NFAtoDFA(tempLeft);
    DFA<std::set<T>> DFAright = NFAtoDFA(tempRight);
    
    return isAEqualityOfB(DFAleft, DFAright);
}
