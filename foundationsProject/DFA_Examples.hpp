//  DFA_Examples.hpp
//
//  ISV = is state valid
//  TF = transition function
//  ISA = is state accepted
//
//  Source 1 - https://www.javatpoint.com/examples-of-deterministic-finite-automata
//  Source 2 - https://www.gatevidyalay.com/construction-of-dfa-examples-dfa-solved-examples/
//
//
//
//

#ifndef DFA_Examples_hpp
#define DFA_Examples_hpp

#include "DFA.hpp"

#include <stdio.h>
#include <string>

// Function that ouputs a DFA that only accepts strings of only that alphabet int (Ex.)
DFA generateOneCharDFA(int onlyAlphabet);

// functions and constructor for acceptNoString DFA
bool acceptNoStringISV(int state);
int acceptNoStringTF(int currentState, int charcterInAlphabet);
bool acceptNoStringISA(int state);
DFA outputAcceptNoString(void);

// functions and constructor for acceptEmptyString DFA
bool acceptEmptyStringISV(int state);
int acceptEmptyStringTF(int currentState, int alphabetCharcter);
bool acceptEmptyStringISA(int state);
DFA outputAcceptEmptyString(void);

// DFA Examples
DFA outputDFA1(void);
DFA outputDFA2(void);
DFA outputDFA3(void);
DFA outputDFA4(void);
DFA outputDFA5(void);
DFA outputDFA6(void);
DFA outputDFA7(void);
DFA outputDFA8(void);
DFA outputDFA9(void);
DFA outputDFA10(void);
DFA outputDFA11(void);
DFA outputDFA12(void);





#endif /* DFA_Examples_hpp */
