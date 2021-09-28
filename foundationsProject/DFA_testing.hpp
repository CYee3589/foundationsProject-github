//
//  DFA_testing.hpp
//  foundationsProject
//
//  Created by Calvin Yee on 9/27/21.
//

#ifndef DFA_testing_hpp
#define DFA_testing_hpp

#include "DFA.hpp"

#include <stdio.h>

void traceStringInDFA(DFA dfa, std::list<int> string);

void testingDFA(DFA subject, int testNumber, std::vector<std::list<int>> correctCases, std::vector<std::list<int>> incorrectCases);

#endif /* DFA_testing_hpp */
