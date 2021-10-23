//
//  DFA_testing.cpp
//  foundationsProject
//
//  Created by Calvin Yee on 9/27/21.
//

#include "DFA_testing.hpp"

// Shows the state progression of the inputted string through inputted DFA (accepted states are in parentheses)
//template<typename T>
//void traceStringInDFA(DFA<T> dfa, std::list<int> string){
//    int currentState = dfa.startState;
//    
//    //Checks if DFA is a accepted state/ give parentheses if so
//    if (dfa.isAcceptedState(currentState)) {
//        std::cout << "(" << currentState << ")";
//    } else {
//        std::cout << currentState;
//    }
//    
//    // Goes through entire list and updates and prints current state
//    for (int const &c: string) {
//        if (!(dfa.isStateValid(currentState))) {
//            std::cout << std::endl << c << " - not part of alphabet TRACE ENDS" << std::endl;
//            return;
//        }
//        currentState = dfa.transitionFunction(currentState, c);
//        
//        if (dfa.isAcceptedState(currentState)) {
//            std::cout << " -> (" << currentState << ")";
//        } else {
//            std::cout << " -> " << currentState;
//        }
//    }
//    std::cout << std::endl;
//}
//
//// Tests pass and fail cases (both are vectors of strings) for a DFA
//template<typename T>
//void testingDFA(DFA<T> subject, int testNumber, std::vector<std::list<int>> correctCases, std::vector<std::list<int>> incorrectCases){
//    int passCorrectCases = 0;
//    int failCorrectCases = 0;
//    int passIncorrectCases = 0;
//    int failIncorrectCases = 0;
//    int i = 0;
//    int j = 0;
//    
//    std::cout << "DFA " << testNumber << " Testing" << std::endl;
//    
//    // Goes through vector of strings and sees weither the pass cases are accepted
//    for (std::list<int> const &c: correctCases) {
//        if(doesStringFollowDFA(subject, c)){
//            passCorrectCases++;
//        } else {
//            failCorrectCases++;
//        }
//        if (i == 5) {
//            // For the 6th list (or last list, it prints out the trace of the list)
//            std::cout << "Trace for last string from passCase" << testNumber << std::endl;
//            traceStringInDFA(subject, c);
//        }
//        i++;
//    }
//    
//    // Goes through vector of strings and sees weither the fail cases are rejected
//    for (std::list<int> const &c: incorrectCases) {
//        if(doesStringFollowDFA(subject, c)){
//            failIncorrectCases++;
//        } else {
//            passIncorrectCases++;
//        }
//        // For the 6th list (or last list, it prints out the trace of the list)
//        if (j == 5) {
//            std::cout << "Trace for last string from failCase" << testNumber << std::endl;
//            traceStringInDFA(subject, c);
//        }
//        j++;
//    }
//    
//    // Prints out results
//    std::cout << "Number of Passed Correct Cases: " << passCorrectCases << std::endl;
//    std::cout << "Number of Failed Correct Cases: " << failCorrectCases << std::endl;
//    std::cout << "Number of Passed Incorrect Cases: " << passIncorrectCases << std::endl;
//    std::cout << "Number of Failed Incorrect Cases: " << failIncorrectCases << std::endl;
//    std::cout << std::endl;
//
//}

//template<typename T>
// Tests pass and fail cases (both are vectors of strings) for a DFA
//void testingDFA2(DFA<T> subject, int testNumber, std::vector<std::list<int>> correctCases, std::vector<std::list<int>> incorrectCases){
//    int passCorrectCases = 0;
//    int failCorrectCases = 0;
//    int passIncorrectCases = 0;
//    int failIncorrectCases = 0;
//    int i = 0;
//    int j = 0;
//
//    std::cout << "DFA " << testNumber << " Testing" << std::endl;
//
//    // Goes through vector of strings and sees weither the pass cases are accepted
//    for (std::list<int> const &c: correctCases) {
//        if(doesStringFollowDFA(subject, c)){
//            passCorrectCases++;
//        } else {
//            failCorrectCases++;
//        }
//        if (i == 5) {
//            // For the 6th list (or last list, it prints out the trace of the list)
//            std::cout << "Trace for last string from passCase" << testNumber << std::endl;
//            traceStringInDFA(subject, c);
//        }
//        i++;
//    }
//
//    // Goes through vector of strings and sees weither the fail cases are rejected
//    for (std::list<int> const &c: incorrectCases) {
//        if(doesStringFollowDFA(subject, c)){
//            failIncorrectCases++;
//        } else {
//            passIncorrectCases++;
//        }
//        // For the 6th list (or last list, it prints out the trace of the list)
//        if (j == 5) {
//            std::cout << "Trace for last string from failCase" << testNumber << std::endl;
//            traceStringInDFA(subject, c);
//        }
//        j++;
//    }
//
//    // Prints out results
//    std::cout << "Number of Passed Correct Cases: " << passCorrectCases << std::endl;
//    std::cout << "Number of Failed Correct Cases: " << failCorrectCases << std::endl;
//    std::cout << "Number of Passed Incorrect Cases: " << passIncorrectCases << std::endl;
//    std::cout << "Number of Failed Incorrect Cases: " << failIncorrectCases << std::endl;
//    std::cout << std::endl;
//
//}
