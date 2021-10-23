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
//#include <optional>


//template<typename T>
//void traceStringInDFA(DFA<T> dfa, std::list<int> string);
//
//template<typename T>
//void testingDFA(DFA<T> subject, int testNumber, std::vector<std::list<int>> correctCases, std::vector<std::list<int>> incorrectCases);
//
//template<typename T>
//void testingDFA2(DFA<T> subject, int testNumber, std::vector<std::list<int>> correctCases, std::vector<std::list<int>> incorrectCases);


template<typename T>
void traceStringInDFA(DFA<T> dfa, std::list<int> string){
    T currentState = dfa.startState;
    
    //Checks if DFA is a accepted state/ give parentheses if so
    if (dfa.isAcceptedState(currentState)) {
        std::cout << "(" << currentState << ")";
    } else {
        std::cout << currentState;
    }
    
    // Goes through entire list and updates and prints current state
    for (int const &c: string) {
        if (!(dfa.isStateValid(currentState))) {
            std::cout << std::endl << c << " - not part of alphabet TRACE ENDS" << std::endl;
            return;
        }
        currentState = dfa.transitionFunction(currentState, c);
        
        if (dfa.isAcceptedState(currentState)) {
            std::cout << " -> (" << currentState << ")";
        } else {
            std::cout << " -> " << currentState;
        }
    }
    std::cout << std::endl;
}

// For printing out pairs
template<typename A, typename B>
void outputPair(std::pair<A,B> pair){
    std::cout << "<" << pair.first << "," << pair.second << ">";
}

// Trace Function specially made for pairs
template<typename A, typename B>
void traceStringInDFA(DFA<std::pair<A,B>> dfa, std::list<int> string){
    std::pair<A,B> currentState = dfa.startState;
    
    //Checks if DFA is a accepted state/ give parentheses if so
    if (dfa.isAcceptedState(currentState)) {
        std::cout << "(";
        outputPair(currentState);
        std::cout << ")";
    } else {
        outputPair(currentState);
    }
    
    // Goes through entire list and updates and prints current state
    for (int const &c: string) {
        if (!(dfa.isStateValid(currentState))) {
            std::cout << std::endl << c << " - not part of alphabet TRACE ENDS" << std::endl;
            return;
        }
        currentState = dfa.transitionFunction(currentState, c);
        
        if (dfa.isAcceptedState(currentState)) {
            std::cout << " -> (";
            outputPair(currentState);
            std::cout << ")";
        } else {
            std::cout << " -> ";
            outputPair(currentState);
        }
    }
    std::cout << std::endl;
}

// Tests pass and fail cases (both are vectors of strings) for a DFA
template<typename T>
void testingDFA(DFA<T> subject, int testNumber, std::vector<std::list<int>> correctCases, std::vector<std::list<int>> incorrectCases){
    int passCorrectCases = 0;
    int failCorrectCases = 0;
    int passIncorrectCases = 0;
    int failIncorrectCases = 0;
    int i = 0;
    int j = 0;
    
    std::cout << "DFA " << testNumber << " Testing" << std::endl;
    
    // Goes through vector of strings and sees weither the pass cases are accepted
    for (std::list<int> const &c: correctCases) {
        if(doesStringFollowDFA(subject, c)){
            passCorrectCases++;
        } else {
            failCorrectCases++;
        }
        // For the 6th list (or last list, it prints out the trace of the list)
        if (i == 5) {
            std::cout << "Trace for last string from passCase" << testNumber << std::endl;
            traceStringInDFA(subject, c);
        }
        i++;
    }
    
    // Goes through vector of strings and sees weither the fail cases are rejected
    for (std::list<int> const &c: incorrectCases) {
        if(doesStringFollowDFA(subject, c)){
            failIncorrectCases++;
        } else {
            passIncorrectCases++;
        }
        // For the 6th list (or last list, it prints out the trace of the list)
        if (j == 5) {
            std::cout << "Trace for last string from failCase" << testNumber << std::endl;
            traceStringInDFA(subject, c);
        }
        j++;
    }
    
    // Prints out results
    std::cout << "Number of Passed Correct Cases: " << passCorrectCases << std::endl;
    std::cout << "Number of Failed Correct Cases: " << failCorrectCases << std::endl;
    std::cout << "Number of Passed Incorrect Cases: " << passIncorrectCases << std::endl;
    std::cout << "Number of Failed Incorrect Cases: " << failIncorrectCases << std::endl;
    std::cout << std::endl;

}

//template<typename T>
//std::optional<std::list<int>> generateViableString(DFA<T> dfa){
//
//}



#endif /* DFA_testing_hpp */
