//
//  foundationsProject
//
//  Task #1: A alphabet -> vector of ints (std::vector<int> alphabet)
//  Task #2: A string -> list of ints (std::list<int> string)

#include "permutations.hpp"
#include "DFA.hpp"
#include "DFA_Examples.hpp"
#include "DFA_testing.hpp"
#include "NFA.hpp"
#include "NFA_examples.hpp"
#include "NFA_testing.hpp"
#include "RE.hpp"
#include "RE_examples.hpp"
#include "RE_testing.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <utility>

int main(int argc, const char * argv[]) {
    
    
    
        // All NFAs Used
        //************************************************************
        // NFA Sample 1 - Accepts all strings with the third element from the right being "1"
        //************************************************************
        NFA nfa1 = outputNFA1();

    
        // NFA Sample 2 - Accepts all strings ending with "01"
        //************************************************************
        NFA nfa2 = outputNFA2();
    
    
        // NFA Sample 3 - Accepts strings with a double "1" followed by a double "0" (1100) in it
        //************************************************************
        NFA nfa3 = outputNFA3();


        // DFA Sample 4 - Accepts strings with the third element from the right being "0"
        //************************************************************
        NFA nfa4 = outputNFA4();


        // DFA Sample 5 - Accepts strings either with odd 1s or even 0s
        //************************************************************
        NFA nfa5 = outputNFA5();

    
        // DFA Sample 6 - Accepts strings only ending with "11" or "00"
        //************************************************************
        NFA nfa6 = outputNFA6();
    
    
        // DFA Sample 7 - Accepts strings with a length of 2 or 4
        //************************************************************
        NFA nfa7 = outputNFA7();


        // DFA Sample 8 - Accepts strings either ending in 0 or has all "1"s
        //************************************************************
        NFA nfa8 = outputNFA8();

    
        // DFA Sample 9 - Accepts strings that start with 1 and either ends in 0 or has a length of 4
        //************************************************************
        NFA nfa9 = outputNFA9();

    
        // DFA Sample 10 - NFA = DFA Sample 4: accepts only strings with "01" in it
        //************************************************************
        NFA nfa10 = outputNFA10();


        // DFA Sample 11 - NFA = DFA Sample 10: accepting strings starting with ‘11’
        //************************************************************
        NFA nfa11 = outputNFA11();


        // DFA Sample 12 - NFA = DFA Sample 14: accepts only strings beginning and ending with "1"
        //************************************************************
        NFA nfa12 = outputNFA12();
    
  
    srand (time(NULL));

    
    //********************************************************************************************************
    // Testing grounds for Kleene Star (task 36-37)
    //***********************************************************************************
    NFA<std::pair<int, int>> star1 = generateKleeneStar(nfa1);
    NFA<std::pair<int, int>> star2 = generateKleeneStar(nfa2);
    NFA<std::pair<int, int>> star3 = generateKleeneStar(nfa3);
    NFA<std::pair<int, int>> star4 = generateKleeneStar(nfa4);
    NFA<std::pair<int, int>> star5 = generateKleeneStar(nfa5);
    NFA<std::pair<int, int>> star6 = generateKleeneStar(nfa6);
    NFA<std::pair<int, int>> star7 = generateKleeneStar(nfa7);
    NFA<std::pair<int, int>> star8 = generateKleeneStar(nfa8);
    NFA<std::pair<int, int>> star9 = generateKleeneStar(nfa9);
    NFA<std::pair<int, int>> star10 = generateKleeneStar(nfa10);
    NFA<std::pair<int, int>> star11 = generateKleeneStar(nfa11);
    NFA<std::pair<int, int>> star12 = generateKleeneStar(nfa12);

//    std::cout << "Finished Generating" << std::endl;
    std::vector<bool> task37Pass{
        Backtrack(star1, {1,1,0,0,1,0,0}),
        Backtrack(star2, {0,1,0,1,1,1,0,1}),
        Backtrack(star3, {1,1,0,0,1,1,0,0}),
        Backtrack(star4, {1,0,1,1,0,1,1}),
        Backtrack(star5, {1,1,0,1,0,0,0}),
        Backtrack(star6, {1,0,1,1,0,0}),
        Backtrack(star7, {0,1,0,1,1,1,0,0}),
        Backtrack(star8, {1,0,1,0}),
        Backtrack(star9, {1,1,0,1,1,1,1}),
        Backtrack(star10, {1,1,1,1,0,1,0}),
        Backtrack(star11, {1,1,1,1,0}),
        Backtrack(star12, {1,0,1,1,0,1}),
    };
    
//    boolCounter(task37Pass);
    
    
    
    //********************************************************************************************************
    // Testing grounds for NFA to DFA (task 38-40)
    //***********************************************************************************
    DFA<std::set<int>> nToD1 = NFAtoDFA(nfa1);
    DFA<std::set<int>> nToD2 = NFAtoDFA(nfa2);
    DFA<std::set<int>> nToD3 = NFAtoDFA(nfa3);
    DFA<std::set<int>> nToD4 = NFAtoDFA(nfa4);
    DFA<std::set<int>> nToD5 = NFAtoDFA(nfa5);
    DFA<std::set<int>> nToD6 = NFAtoDFA(nfa6);
    DFA<std::set<int>> nToD7 = NFAtoDFA(nfa7);
    DFA<std::set<int>> nToD8 = NFAtoDFA(nfa8);
    DFA<std::set<int>> nToD9 = NFAtoDFA(nfa9);
    DFA<std::set<int>> nToD10 = NFAtoDFA(nfa10);
    DFA<std::set<int>> nToD11 = NFAtoDFA(nfa11);
    DFA<std::set<int>> nToD12 = NFAtoDFA(nfa12);
    
    std::vector<bool> task39Pass{
        doesStringFollowDFA(nToD1, {0,0,1,1,0}),
        doesStringFollowDFA(nToD2, {0,1,0,1}),
        doesStringFollowDFA(nToD3, {1,1,0,0,0}),
        doesStringFollowDFA(nToD4, {0,0,1}),
        doesStringFollowDFA(nToD5, {0,0,1,0}),
        doesStringFollowDFA(nToD6, {0,0,1,1}),
        doesStringFollowDFA(nToD7, {0,0,0}),
        doesStringFollowDFA(nToD8, {1,1,1,1}),
        doesStringFollowDFA(nToD9, {1,0,0,0}),
        doesStringFollowDFA(nToD10, {1,1,1,0,1}),
        doesStringFollowDFA(nToD11, {1,1}),
        doesStringFollowDFA(nToD12, {1,0,1,0,1}),
    };
    
    boolCounter(task39Pass);
    
    
    // Task 40
    DFA<std::set<int>> nToD4Clone{
        [](std::set<int> state){
            for(auto c : state){
                if (!(c >= 0 && c <= 3)) {
                    return false;
                }
            }
            return true;
        },
        {0,1},
        [](std::set<int> state, int charcterInAlphabet) -> std::set<int>{
            std::set<int> outputSet;
            std::set<int> tempTrans;
            
            for(auto c : state){
                if (c == 0 && charcterInAlphabet == 0) {
                    tempTrans = {0,1};
                } else if (c == 0 && charcterInAlphabet == 1) {
                    tempTrans = {0};
                } else if (c == 1) {
                    tempTrans = {2};
                } else if (c == 2) {
                    tempTrans = {3};
                }

                outputSet.insert(tempTrans.begin(), tempTrans.end());
                tempTrans.empty();
            }
            return outputSet;
        },
        {0},
        [](std::set<int> state){
            for(auto c : state){
                if (c == 3) {
                    return true;
                }
            }
            return false;
        }
    };
    
    
    
    DFA<std::set<int>> nToD9Clone{
        [](std::set<int> state){
            for(auto c : state){
                if (!(c >= 0 && c <= 7)) {
                    return false;
                }
            }
            return true;
        },
        {0,1},
        [](std::set<int> state, int charcterInAlphabet) -> std::set<int>{
            std::set<int> outputSet;
            std::set<int> tempTrans;
            std::set<int> tempEpislon;
            
            for(auto c : state){
                if (c == 0 && charcterInAlphabet == 1) {
                    tempTrans = {1};
                } else if (c == 2 && charcterInAlphabet == 0) {
                    tempTrans = {2,3};
                } else if (c == 2 && charcterInAlphabet == 1) {
                    tempTrans = {2};
                } else if (c == 4) {
                    tempTrans = {5};
                } else if (c == 5) {
                    tempTrans = {6};
                } else if (c == 6) {
                    tempTrans = {7};
                }
                
                outputSet.insert(tempTrans.begin(), tempTrans.end());
                tempTrans.empty();
                
                if (c == 1){
                    tempEpislon = {2,4};
                }
                
                outputSet.insert(tempEpislon.begin(), tempEpislon.end());
                tempEpislon.empty();
            }
            return outputSet;
        },
        {0},
        [](std::set<int> state){
            for(auto c : state){
                if ((c == 3) || (c == 7)) {
                    return true;
                }
            }
            return false;
        }
    };
    
    DFA<std::set<int>> nToD12Clone{
        [](std::set<int> state){
            for(auto c : state){
                if (!(c >= 0 && c <= 3)) {
                    return false;
                }
            }
            return true;
        },
        {0,1},
        [](std::set<int> state, int charcterInAlphabet) -> std::set<int>{
            std::set<int> outputSet;
            std::set<int> tempTrans;
            
            for(auto c : state){
                if (c == 0 && charcterInAlphabet == 1){
                    tempTrans = {1};
                } else if (c == 1){
                    if (charcterInAlphabet == 0){
                        tempTrans = {1};
                    } else {
                        tempTrans = {2};
                    }
                } else if (c == 2){
                    if (charcterInAlphabet == 1) {
                        tempTrans = {2};
                    } else {
                        tempTrans = {1};
                    }
                } else {
                    tempTrans = {3};
                }
                
                outputSet.insert(tempTrans.begin(), tempTrans.end());
                tempTrans.empty();
            }
            return outputSet;
        },
        {0},
        [](std::set<int> state){
            for(auto c : state){
                if (c == 2) {
                    return true;
                }
            }
            return false;
        }
    };
    
    std::vector<bool> task40Pass{
        isAEqualityOfB(nToD4, nToD4Clone),
        isAEqualityOfB(nToD9, nToD9Clone),
        isAEqualityOfB(nToD12, nToD12Clone)
    };
    
    boolCounter(task40Pass);
    
    
    
    //********************************************************************************************************
    // Testing grounds for RE and printer (task 41-42)
    //***********************************************************************************
    outputRE1().printOutEquation();
    outputRE2().printOutEquation();
    outputRE3().printOutEquation();
    outputRE4().printOutEquation();
    outputRE5().printOutEquation();
    outputRE6().printOutEquation();
    outputRE7().printOutEquation();
    outputRE8().printOutEquation();
    outputRE9().printOutEquation();
    outputRE10().printOutEquation();
    outputRE11().printOutEquation();
    outputRE12().printOutEquation();
    
    
//    ********************************************************************************************************
//     Testing grounds for RE generator (task 43-45)
//    ***********************************************************************************
    for(auto c : outputRE1().generate()){
        std::cout << c << " ";
    }
    std::cout << std::endl;

    for(auto c : outputRE2().generate()){
        std::cout << c << " ";
    }
    std::cout << std::endl;

    for(auto c : outputRE3().generate()){
        std::cout << c << " ";
    }
    std::cout << std::endl;

    for(auto c : outputRE4().generate()){
        std::cout << c << " ";
    }
    std::cout << std::endl;

    for(auto c : outputRE5().generate()){
        std::cout << c << " ";
    }
    std::cout << std::endl;

    for(auto c : outputRE6().generate()){
        std::cout << c << " ";
    }
    std::cout << std::endl;

    for(auto c : outputRE7().generate()){
        std::cout << c << " ";
    }
    std::cout << std::endl;

    for(auto c : outputRE8().generate()){
        std::cout << c << " ";
    }
    std::cout << std::endl;

    for(auto c : outputRE9().generate()){
        std::cout << c << " ";
    }
    std::cout << std::endl;

    for(auto c : outputRE10().generate()){
        std::cout << c << " ";
    }
    std::cout << std::endl;

    for(auto c : outputRE11().generate()){
        std::cout << c << " ";
    }
    std::cout << std::endl;

    for(auto c : outputRE12().generate()){
        std::cout << c << " ";
    }
    std::cout << std::endl;

    
    //********************************************************************************************************
    // Testing grounds for RE compiler (task 46-47)
    //***********************************************************************************
    
    NFA<int> NFASample1(
        [](int state) { return state >= 0 && state <= 4; },
        {0,1},
        [](int currentState, int charcterInAlphabet) -> std::set<int> {
            if (currentState == 0 && charcterInAlphabet == 0) return {0};
                else if (currentState == 0 && charcterInAlphabet == 1) return {0,1};
                else if (currentState == 1) return {2};
                else if (currentState == 2) return {3};
                else return {};
            },
            [](int currentState) -> std::set<int> {
                if (currentState == 4) return {0};
                else return {};
            },
            4,
            [](int state){return state == 3;}
    );
    
    
    DFA<int> DFASample2(
            [](int state) { return state >= 0 && state <= 2; },
            {0,1},
            [](int currentState, int charcterInAlphabet) {
                if (currentState == 2 || charcterInAlphabet == 0) return 2;
                else return 1;
            },
            0,
            [](int state){return state == 1;}
    );

    NFA<int> NFASample2(DFASample2);
    
    NFA<int> NFASample3(
            [](int state) { return state >= 0 && state <= 2; },
            {0,1},
            [](int currentState, int charcterInAlphabet) -> std::set<int> {
                if (currentState == 0 && charcterInAlphabet == 0) return {1};
                if (currentState == 1 && charcterInAlphabet == 0) return {1};
                if (currentState == 1 && charcterInAlphabet == 1) return {1,2};
                else return {};
            },
            [](int currentState) -> std::set<int> {
                return {};
            },
            0,
            [](int state){return state == 2;}
    );
    
    DFA<int> DFASample4(
            [](int state) { return state >= 0 && state <= 3; },
            {0,1},
            [](int currentState, int charcterInAlphabet) {
                if (currentState == 0 && charcterInAlphabet == 1) return 1;
                else if (currentState == 1 && charcterInAlphabet == 1) return 2;
                else if (currentState == 2 && charcterInAlphabet == 0) return 2;
                else return 3;
            },
            0,
            [](int state){return state == 2;}
    );
    NFA<int> NFASample4(DFASample4);
    

    
    std::vector<bool> reallyLongTests{
        isAEqualityOfB(NFAtoDFA(NFASample1), NFAtoDFA(REToNFAComplier(outputRE1()))),
        isAEqualityOfB(NFAtoDFA(outputNFA1()), NFAtoDFA(REToNFAComplier(outputRE1()))),
        isAEqualityOfB(NFAtoDFA(REToNFAComplier(outputRE1Copy())), NFAtoDFA(REToNFAComplier(outputRE1()))),
        isAEqualityOfB(NFAtoDFA(NFASample2), NFAtoDFA(REToNFAComplier(outputRE6()))),
        isAEqualityOfB(NFAtoDFA(NFA<int>(outputDFA16())), NFAtoDFA(REToNFAComplier(outputRE6()))),
        isAEqualityOfB(NFAtoDFA(REToNFAComplier(outputRE6())), NFAtoDFA(REToNFAComplier(outputRE6()))),
        isAEqualityOfB(NFAtoDFA(NFASample3), NFAtoDFA(REToNFAComplier(outputRE2()))),
        isAEqualityOfB(NFAtoDFA(outputNFA13()), NFAtoDFA(REToNFAComplier(outputRE2()))),
        isAEqualityOfB(NFAtoDFA(REToNFAComplier(outputRE2())), NFAtoDFA(REToNFAComplier(outputRE2()))),
        isAEqualityOfB(NFAtoDFA(NFASample4), NFAtoDFA(REToNFAComplier(outputRE9()))),
        isAEqualityOfB(NFAtoDFA(NFA<int>(outputDFA17())), NFAtoDFA(REToNFAComplier(outputRE9()))),
        isAEqualityOfB(NFAtoDFA(REToNFAComplier(outputRE9())), NFAtoDFA(REToNFAComplier(outputRE9())))
    };
    
    boolCounter(reallyLongTests);

    
    //********************************************************************************************************
    // Testing grounds for RE Equality (task 48-49)
    //***********************************************************************************
    std::vector<bool> task49Pass{
        isREEquality(outputRE4(), outputRE4()),
        isREEquality(outputRE2(), outputRE2()),
        isREEquality(outputRE7(), outputRE7()),
        isREEquality(outputRE8(), outputRE8()),
        isREEquality(outputRE6(), outputRE6()),
        isREEquality(outputRE11(), outputRE11()),
        isREEquality(outputRE1(), outputRE1Copy()),
        isREEquality(outputRE5(), outputRE5Copy()),
        isREEquality(outputRE3(), outputRE3Copy()),
        isREEquality(outputRE9(), outputRE9Copy()),
        isREEquality(outputRE10(), outputRE10Copy()),
        isREEquality(outputRE12(), outputRE12Copy())
    };
    
    boolCounter(task49Pass);


    
    //********************************************************************************************************
    // Testing grounds for RE optimizer (task 50)
    //***********************************************************************************
    RE REOpt1Bef('U',
        new RE('U',
            new RE('N'),
            new RE('O')
        ),
        new RE('C',
            new RE('Z'),
            new RE('E')
        )
    );
    
    RE REOpt2Bef('U',
        new RE('K',
            new RE('N')
        ),
        new RE('C',
            new RE('N'),
            new RE('Z')
        )
    );
    
    RE REOpt3Bef('U',
        new RE('K',
            new RE('E')
        ),
        new RE('U',
            new RE('O'),
            new RE('E')
        )
    );
    
    REOpt1Bef.printOutEquation();
    RE* REOpt1Aft = REOpt1Bef.optimizer();
    REOpt1Aft->printOutEquation();
    std::cout << std::endl;
    REOpt2Bef.printOutEquation();
    RE* REOpt2Aft = REOpt2Bef.optimizer();
    REOpt2Aft->printOutEquation();
    std::cout << std::endl;
    REOpt3Bef.printOutEquation();
    RE* REOpt3Aft = REOpt3Bef.optimizer();
    REOpt3Aft->printOutEquation();

    return 0;
}

