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

void removeDuplicatesFromVector(std::vector<int> &v)
{
    auto end = v.end();
    for (auto it = v.begin(); it != end; ++it) {
        end = std::remove(it + 1, end, *it);
    }
 
    v.erase(end, v.end());
}
