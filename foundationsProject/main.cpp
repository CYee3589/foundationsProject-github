//
//  foundationsProject
//
//  Task #1: A alphabet -> vector of ints (std::vector<int> alphabet)
//  Task #2: A string -> list of ints (std::list<int> string)

#include "permutations.hpp"
#include "DFA.hpp"
#include "DFA_Examples.hpp"
#include "DFA_testing.hpp"

#include <iostream>
#include <vector>
#include <list>
//#include <optional>


int main(int argc, const char * argv[]) {

    // Test case for permuations (Task 3)
//    std::vector<int> alphabet;
//    alphabet.push_back(1);
//    alphabet.push_back(2);
//    alphabet.push_back(3);
//
//    int n = 26;
//
//    std::list<int> answer = getNthPermutation(alphabet, n);
//
//    for (auto x = answer.begin(); x != answer.end(); ++x) {
//        std::cout << *x << " ";
//    }
//
//    std::cout << std::endl;
    
    
    // Test case for 3 DFAs (Tasks 5-7)
//    DFA acceptNothing = outputAcceptNoString();
//    DFA onlyEmpty = outputAcceptEmptyString();
//    DFA onlyOneInt = generateOneCharDFA(1);
//
//    std::list<int> example = {1,0,1};
//    std::list<int> example1;
//    std::list<int> example2 = {1};
//    std::list<int> example3 = {0, 1, 1, 1};
//    traceStringInDFA(onlyOneInt, example);
    
    
    //************************************************************
    // DFA Sample 1 - accepts only strings that start with "1"
    //************************************************************
    //std::vector<int> alphabet0_1 {0,1};
    DFA<int> dfa1(
            [](int state) { return state >= 0 && state <= 2; },
            std::vector<int> {0,1},
            [](int currentState, int charcterInAlphabet) {
                if (currentState == 0 && charcterInAlphabet == 1) return 1;
                else if (currentState == 1) return 1;
                else return 2;
            },
            0,
            [](int state){return state == 1;}
    );
    
    DFA<int> dfa1c = generateComplement(dfa1);
    
    //************************************************************
    // DFA Sample 2 - accepts only strings that end with "1"
    //************************************************************
    DFA<int> dfa2 = outputDFA2();
    
    // DFA Sample 7 - accepts only strings with an even number of 0s and 1s
    DFA<int> dfa7 = outputDFA2();

    
    DFA<std::pair<int,int>> dfaU = generateUnion(dfa1, dfa2);
    DFA<std::pair<int,int>> dfaI = generateIntercept(dfa1, dfa2);
    
//    std::list<int> stuff = generateViableString(dfa7);
    std::list<int> stuff2 = generateViableString(dfaU);
    //

    traceStringInDFA(dfaU, stuff2);
    
//    generateViableString(dfaU).value_or(false)

    
    std::vector<std::list<int>> passCases1 {
        {1}, {1,0,1}, {1,1,1,1}, {1,0,0}, {1,1,0,0}, {1,0}
    };
    
    std::vector<std::list<int>> failCases1 {
        {0,0,0}, {0}, {}, {0,1,1}, {0,0,1,1}, {0,1,1,1}
    };
    
    std::vector<std::list<int>> passCases2 {
        {1}, {1,0,1}, {1,1,1,1}, {1,0,0}, {1,1,0,0}, {1,0,1}, {0,1,0,0,0,1}
    };

    std::vector<std::list<int>> failCases2 {
        {0,0,0}, {0}, {}, {0,1,0}, {0,0,1,0}, {0,1,1,0}
    };
    
    std::vector<std::list<int>> passCases3 {
        {1}, {1,0,0,1}, {1,1,1,1}, {1,0,1,1}, {1,0,1,0,1}, {1,0,0,0,1,1}, {1,1,1,0,0,0,1}
    };

    std::vector<std::list<int>> failCases3 {
        {0,0,1}, {0}, {}, {0,1,0}, {1,0,1,0}, {0,1,1,0}, {1,1,1,0}
    };
    
    
    // Tests
//    testingDFA(dfa1, 1, passCases1, failCases1);
//    testingDFA(dfa1c, 1, failCases1, passCases1);
//    testingDFA(dfaU, 2, passCases2, failCases2);
//    testingDFA(dfaI, 3, passCases3, failCases3);



    
    

    

//    // Testing grounds for Dozen DFAs (Tasks 8-9)
//    //************************************************************
//    // DFA Sample 1 - accepts only strings that start with "1"
//    //************************************************************
//    std::vector<std::list<int>> passCases1 {
//        {1}, {1,0,1}, {1,1,1,1}, {1,0,0}, {1,1,0,0}, {1,0}
//    };
//
//    std::vector<std::list<int>> failCases1 {
//        {0,0,0}, {0}, {}, {0,1,1}, {0,0,1,1}, {0,1,1,1}
//    };
//
//    DFA dfa1 = outputDFA1();
//    testingDFA(dfa1, 1, passCases1, failCases1);
//
//
//
//    //************************************************************
//    // DFA Sample 2 - accepts only strings that end with "1"
//    //************************************************************
//    std::vector<std::list<int>> passCases2 {
//        {1}, {1,0,1}, {1,1,1,1}, {0,0,1}, {0,0,0,1}, {1,1,0,0,1}
//    };
//
//    std::vector<std::list<int>> failCases2 {
//        {1,1,0}, {1,0,0,0}, {}, {0,1,0,0}, {0,0,0,0}, {0,0,1,0}
//    };
//
//    DFA dfa2 = outputDFA2();
//    testingDFA(dfa2, 2, passCases2, failCases2);
//
//
//    //************************************************************
//    // DFA Sample 3 - accepts only strings of all "0"
//    //************************************************************
//    std::vector<std::list<int>> passCases3 {
//        {0}, {0,0}, {0,0,0}, {0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0,0,0,0,0}
//    };
//
//    std::vector<std::list<int>> failCases3 {
//        {}, {1,0,0,0}, {0,0,1}, {1,1,1,1}, {0,0,1,0,0}, {1,0,0}
//    };
//
//    DFA dfa3 = outputDFA3();
//    testingDFA(dfa3, 3, passCases3, failCases3);
//
//
//
//    //************************************************************
//    // DFA Sample 4 - accepts only strings with "01" in it
//    //************************************************************
//    std::vector<std::list<int>> passCases4 {
//        {0,1}, {0,0,0,1}, {0,1,1}, {0,1,0,1}, {0,1,1,1,0}, {1,1,1,0,1}
//    };
//
//    std::vector<std::list<int>> failCases4 {
//        {}, {1,0,0,0}, {0,0,0}, {1,1,1,1}, {1,0,0,0,0}, {1,1,0}
//    };
//
//    DFA dfa4 = outputDFA4();
//    testingDFA(dfa4, 4, passCases4, failCases4);
//
//
//    //************************************************************
//    // DFA Sample 5 - accepts only strings with an odd number of 1s
//    //************************************************************
//    std::vector<std::list<int>> passCases5 {
//        {0,1}, {0,0,0,1}, {1,1,1}, {0,1,0,1,0,1}, {0,1,1,1,0}, {0,1,1,0,1,0}
//    };
//
//    std::vector<std::list<int>> failCases5 {
//        {}, {1,0,1,0}, {0,0,0,0}, {1,1,1,1}, {1,1,0,1,1}, {1,0,0,0,1}
//    };
//
//    DFA dfa5 = outputDFA5();
//    testingDFA(dfa5, 5, passCases5, failCases5);
//
//
//    //************************************************************
//    // DFA Sample 6 - accepts only strings that starts with 1 and end with 1
//    //************************************************************
//    std::vector<std::list<int>> passCases6 {
//        {1,1}, {1,0,0,1}, {1,1,1,1}, {1,0,1,0,1}, {1,1,1,0,1}, {1,0,1,0,1,0,1,1}
//    };
//
//    std::vector<std::list<int>> failCases6 {
//        {}, {0,0,1,1}, {0,0,0,0}, {1,1,1,0}, {0,0,1,0,1}, {1,1,0,1,0}
//    };
//
//    DFA dfa6 = outputDFA6();
//    testingDFA(dfa6, 6, passCases6, failCases6);
//
//
//
//    //************************************************************
//    // DFA Sample 7 - accepts only strings with an even number of 0s and 1s
//    //************************************************************
//    std::vector<std::list<int>> passCases7 {
//        {1,1}, {0,0}, {}, {1,0,1,0,1,0,0,1}, {1,1,0,0,1,0,1,0}, {0,1,0,1,0,0}
//    };
//
//    std::vector<std::list<int>> failCases7 {
//        {1}, {0,0,1}, {0}, {1,1,0,0,0}, {0,0,1,1,0}, {1,1,0,1,0}
//    };
//
//    DFA dfa7 = outputDFA7();
//    testingDFA(dfa7, 7, passCases7, failCases7);
//
//
//
//    //************************************************************
//    // DFA Sample 8 - accepts the strings with an even number of leading 0's followed by single 1
//    //************************************************************
//    std::vector<std::list<int>> passCases8 {
//        {0,0,1}, {1}, {0,0,0,0,0,0,1}, {0,0,0,0,1}, {0,0,0,0,0,0,0,0,1}, {0,0,0,0,0,0,0,0,0,0,1}
//    };
//
//    std::vector<std::list<int>> failCases8 {
//        {0,1}, {0,0,1,1}, {1,0,0,1}, {0,0,0,0}, {0,0,0,1}, {1,1,1,1}
//    };
//
//    DFA dfa8 = outputDFA8();
//    testingDFA(dfa8, 8, passCases8, failCases8);
//
//
//
//
//    //************************************************************
//    // DFA Sample 9 - accepting strings ending with ‘00’ over input alphabets
//    //************************************************************
//    std::vector<std::list<int>> passCases9 {
//        {0,0}, {0,0,0}, {1,1,0,0}, {0,1,1,0,0}, {1,1,1,0,0}, {1,0,0,1,0,0}
//    };
//
//    std::vector<std::list<int>> failCases9 {
//        {}, {1,0}, {0,1,0}, {1,1,0,0,1}, {0,1,1}, {1,1,1,0}
//    };
//
//    DFA dfa9 = outputDFA9();
//    testingDFA(dfa9, 9, passCases9, failCases9);
//
//
//    //************************************************************
//    // DFA Sample 10 - accepting strings starting with ‘11’
//    //************************************************************
//    std::vector<std::list<int>> passCases10 {
//        {1,1}, {1,1,1}, {1,1,0,0}, {1,1,0,1,0}, {1,1,0,0,1,1}, {1,1,0,1,1,0}
//    };
//
//    std::vector<std::list<int>> failCases10 {
//        {}, {0,0}, {0,1,1}, {1,0,1,1,1}, {1,0,0}, {0,1,1,0}
//    };
//
//    DFA dfa10 = outputDFA10();
//    testingDFA(dfa10, 10, passCases10, failCases10);
//
//
//
//    //************************************************************
//    // DFA Sample 11 - accepting strings over the length of 3
//    //************************************************************
//    std::vector<std::list<int>> passCases11 {
//        {0,0,0,0}, {1,1,1,1}, {1,0,1,0,1}, {0,0,0,1,1}, {1,1,1,1,0,1}, {1,1,0,1,1,0,0,0,0}
//    };
//
//    std::vector<std::list<int>> failCases11 {
//        {}, {0}, {0,1,1}, {1,0}, {1,1,1}, {1,1,0}
//    };
//
//    DFA dfa11 = outputDFA11();
//    testingDFA(dfa11, 11, passCases11, failCases11);
//
//
//    //************************************************************
//    // DFA Sample 12 - accepting strings less or equal to the length of 3
//    //************************************************************
//
//    std::vector<std::list<int>> passCases12 {
//        {}, {1}, {0}, {1,0,1}, {1,1}, {0,0,0}
//    };
//
//    std::vector<std::list<int>> failCases12 {
//        {1,1,1,1}, {0,0,0,0}, {1,0,0,1,1,1}, {1,0,1,0,1}, {1,0,0,0,1}, {1,0,1,0,0}
//    };
//
//    DFA dfa12 = outputDFA12();
//    testingDFA(dfa12, 12, passCases12, failCases12);

    return 0;
}

