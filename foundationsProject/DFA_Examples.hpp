//  DFA_Examples.hpp
//
//  ISV = is state valid
//  TF = transition function
//  ISA = is state accepted
//
//  Source for DFAs ideas - https://www.javatpoint.com/examples-of-deterministic-finite-automata
//  Source for DFAs ideas 2 - https://www.gatevidyalay.com/construction-of-dfa-examples-dfa-solved-examples/
//

#ifndef DFA_Examples_hpp
#define DFA_Examples_hpp

#include "DFA.hpp"

#include <stdio.h>
#include <string>

// Task #7: Function that ouputs a DFA that only accepts strings of only that alphabet int
//template<typename T>
DFA<int> generateOneCharDFA(int onlyAlphabet);


// functions and constructor for acceptNoString DFA
bool acceptNoStringISV(int state);
int acceptNoStringTF(int currentState, int charcterInAlphabet);
bool acceptNoStringISA(int state);

// Task #5: A DFA that accepts no strings
DFA<int> outputAcceptNoString(void);

// functions and constructor for acceptEmptyString DFA
bool acceptEmptyStringISV(int state);
int acceptEmptyStringTF(int currentState, int alphabetCharcter);
bool acceptEmptyStringISA(int state);

// Task #6: A DFA that only accepts the empty string
DFA<int> outputAcceptEmptyString(void);

// DFA Examples
DFA<int> outputDFA1(void);
DFA<int> outputDFA2(void);
DFA<int> outputDFA3(void);
DFA<int> outputDFA4(void);
DFA<int> outputDFA5(void);
DFA<int> outputDFA6(void);
DFA<int> outputDFA7(void);
DFA<int> outputDFA8(void);
DFA<int> outputDFA9(void);
DFA<int> outputDFA10(void);
DFA<int> outputDFA11(void);
DFA<int> outputDFA12(void);
DFA<int> outputDFA13(void);
DFA<int> outputDFA14(void);
DFA<int> outputDFA15(void);





#endif /* DFA_Examples_hpp */
