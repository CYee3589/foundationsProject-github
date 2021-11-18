//
//  NFA_examples.cpp
//  foundationsProject
//
//  Created by Calvin Yee on 11/9/21.
//

#include "NFA_examples.hpp"

std::vector<int> DAlphabet0_1 {0,1};

// Accepts all strings with the third element from the right being "1"
NFA<int> outputNFA1(void){
    NFA<int> temp(
            [](int state) { return state >= 0 && state <= 3; },
            DAlphabet0_1,
            [](int currentState, int charcterInAlphabet) -> std::set<int> {
                if (currentState == 0 && charcterInAlphabet == 0) return {0};
                else if (currentState == 0 && charcterInAlphabet == 1) return {0,1};
                else if (currentState == 1) return {2};
                else if (currentState == 2) return {3};
                else return {};
            },
            [](int currentState) -> std::set<int> {
                return {};
            },
            0,
            [](int state){return state == 3;}
    );

    return temp;
};

std::list<int> NFA1trace1 = {0,1,2,3};
std::list<int> NFA1trace2 = {0,0,1,2,3};
std::list<int> NFA1trace3 = {0,0,0,1,2,3};
std::list<int> NFA1trace4 = {0,0,0,0,1,2,3};
std::list<int> NFA1trace5 = {0,0,0,0,0,1,2,3};
std::list<int> NFA1trace6 = {0,0,0,0,0,0,1,2,3};
std::list<int> NFA1trace7 = {0,1,2};
std::list<int> NFA1trace8 = {0,0,1,2};
std::list<int> NFA1trace9 = {0,1};
std::list<int> NFA1trace10 = {0,0,0};
std::list<int> NFA1trace11 = {0,0,0,1,2};
std::list<int> NFA1trace12 = {0,0,0,1};

std::list<traceTreeBranch<int>> NFA1traceTree1 =
    {   traceTreeBranch<int>(0,{1,0,0},0,0,false),
        traceTreeBranch<int>(1,{0,0},0,0,false),
        traceTreeBranch<int>(1,{0,0},0,1,false),
        traceTreeBranch<int>(2,{0},0,0,false),
        traceTreeBranch<int>(2,{0},1,2,false),
        traceTreeBranch<int>(3,{},0,0,false),
        traceTreeBranch<int>(3,{},2,3,true)
    };

std::list<traceTreeBranch<int>> NFA1traceTree2 =
    {   traceTreeBranch<int>(0,{1,0},0,0,false),
        traceTreeBranch<int>(1,{0},0,0,false),
        traceTreeBranch<int>(1,{0},0,1,false),
        traceTreeBranch<int>(2,{},0,0,false),
        traceTreeBranch<int>(2,{},1,2,false),
    };

std::list<traceTreeBranch<int>> NFA1traceTree3 =
    {   traceTreeBranch<int>(0,{0,1,0,0},0,0,false),
        traceTreeBranch<int>(1,{1,0,0},0,0,false),
        traceTreeBranch<int>(2,{0,0},0,0,false),
        traceTreeBranch<int>(2,{0,0},0,1,false),
        traceTreeBranch<int>(3,{0},0,0,false),
        traceTreeBranch<int>(3,{0},1,2,false),
        traceTreeBranch<int>(4,{},0,0,false),
        traceTreeBranch<int>(4,{},2,3,true),
    };

std::list<traceTreeBranch<int>> NFA1traceTree4 =
    {   traceTreeBranch<int>(0,{0,0,1},0,0,false),
        traceTreeBranch<int>(1,{0,1},0,0,false),
        traceTreeBranch<int>(2,{1},0,0,false),
        traceTreeBranch<int>(3,{},0,0,false),
        traceTreeBranch<int>(3,{},0,1,false),
    };

std::list<traceTreeBranch<int>> NFA1traceTree5 =
    {   traceTreeBranch<int>(0,{1,1,0,0},0,0,false),
        traceTreeBranch<int>(1,{1,0,0},0,0,false),
        traceTreeBranch<int>(1,{1,0,0},0,1,false),
        traceTreeBranch<int>(2,{0,0},0,0,false),
        traceTreeBranch<int>(2,{0,0},0,1,false),
        traceTreeBranch<int>(2,{0,0},1,2,false),
        traceTreeBranch<int>(3,{0},0,0,false),
        traceTreeBranch<int>(3,{0},1,2,false),
        traceTreeBranch<int>(3,{0},2,3,true),
        traceTreeBranch<int>(4,{},0,0,false),
        traceTreeBranch<int>(4,{},2,3,true),
    };

std::list<traceTreeBranch<int>> NFA1traceTree6 =
    {   traceTreeBranch<int>(0,{1,1},0,0,false),
        traceTreeBranch<int>(1,{1},0,0,false),
        traceTreeBranch<int>(1,{1},0,1,false),
        traceTreeBranch<int>(2,{},0,0,false),
        traceTreeBranch<int>(2,{},0,1,false),
        traceTreeBranch<int>(2,{},1,2,false),
    };



// Accepts all strings ending with "01"
NFA<int> outputNFA2(void){
    NFA<int> temp(
            [](int state) { return state >= 0 && state <= 2; },
            DAlphabet0_1,
            [](int currentState, int charcterInAlphabet) -> std::set<int> {
                if (currentState == 0 && charcterInAlphabet == 0) return {0,1};
                else if (currentState == 0 && charcterInAlphabet == 1) return {0};
                else if (currentState == 1 && charcterInAlphabet == 1) return {2};
                else return {};
            },
            [](int currentState) -> std::set<int> {
                return {};
            },
            0,
            [](int state){return state == 2;}
    );

    return temp;
};

std::list<int> NFA2trace1 = {0,1,2};
std::list<int> NFA2trace2 = {0,0,1,2};
std::list<int> NFA2trace3 = {0,0,0,1,2};
std::list<int> NFA2trace4 = {0,0,0,0,1,2};
std::list<int> NFA2trace5 = {0,0,0,0,0,1,2};
std::list<int> NFA2trace6 = {0,0,0,0,0,0,1,2};
std::list<int> NFA2trace7 = {0,1,0};
std::list<int> NFA2trace8 = {0,1,3};
std::list<int> NFA2trace9 = {1,0,0};
std::list<int> NFA2trace10 = {1,2,3};
std::list<int> NFA2trace11 = {1,1,3};
std::list<int> NFA2trace12 = {0,4,2};

std::list<traceTreeBranch<int>> NFA2traceTree1 =
    {   traceTreeBranch<int>(0,{1,0,1},0,0,false),
        traceTreeBranch<int>(1,{0,1},0,0,false),
        traceTreeBranch<int>(2,{1},0,0,false),
        traceTreeBranch<int>(2,{1},0,1,false),
        traceTreeBranch<int>(3,{},0,0,false),
        traceTreeBranch<int>(3,{},1,2,true),
    };

std::list<traceTreeBranch<int>> NFA2traceTree2 =
    {   traceTreeBranch<int>(0,{0,1},0,0,false),
        traceTreeBranch<int>(1,{1},0,0,false),
        traceTreeBranch<int>(1,{1},0,1,false),
        traceTreeBranch<int>(2,{},0,0,false),
        traceTreeBranch<int>(2,{},1,2,true),
    };

std::list<traceTreeBranch<int>> NFA2traceTree3 =
    {   traceTreeBranch<int>(0,{1,1,1,1},0,0,false),
        traceTreeBranch<int>(1,{1,1,1},0,0,false),
        traceTreeBranch<int>(2,{1,1},0,0,false),
        traceTreeBranch<int>(3,{1},0,0,false),
        traceTreeBranch<int>(4,{},0,0,false),
    };

std::list<traceTreeBranch<int>> NFA2traceTree4 =
    {   traceTreeBranch<int>(0,{1,0,0,1},0,0,false),
        traceTreeBranch<int>(1,{0,0,1},0,0,false),
        traceTreeBranch<int>(2,{0,1},0,0,false),
        traceTreeBranch<int>(2,{0,1},0,1,false),
        traceTreeBranch<int>(3,{1},0,0,false),
        traceTreeBranch<int>(3,{1},0,1,false),
        traceTreeBranch<int>(4,{},0,0,false),
        traceTreeBranch<int>(4,{},1,2,true),
    };

std::list<traceTreeBranch<int>> NFA2traceTree5 =
    {   traceTreeBranch<int>(0,{0,0},0,0,false),
        traceTreeBranch<int>(1,{0},0,0,false),
        traceTreeBranch<int>(1,{0},0,1,false),
        traceTreeBranch<int>(2,{},0,0,false),
        traceTreeBranch<int>(2,{},0,1,false),
    };

std::list<traceTreeBranch<int>> NFA2traceTree6 =
    {   traceTreeBranch<int>(0,{1,1,1},0,0,false),
        traceTreeBranch<int>(1,{1,1},0,0,false),
        traceTreeBranch<int>(2,{1},0,0,false),
        traceTreeBranch<int>(3,{},0,0,false),
    };



// Accepts strings with a double "1" followed by a double "0" (1100) in it
NFA<int> outputNFA3(void){
    NFA<int> temp(
            [](int state) { return state >= 0 && state <= 4; },
            DAlphabet0_1,
            [](int currentState, int charcterInAlphabet) -> std::set<int> {
                if (currentState == 0 && charcterInAlphabet == 0) return {0};
                else if (currentState == 0 && charcterInAlphabet == 1) return {0,1};
                else if (currentState == 1 && charcterInAlphabet == 1) return {2};
                else if (currentState == 2 && charcterInAlphabet == 0) return {3};
                else if (currentState == 3 && charcterInAlphabet == 0) return {4};
                else if (currentState == 4) return {4};
                else return {};
            },
            [](int currentState) -> std::set<int> {
                return {};
            },
            0,
            [](int state){return state == 4;}
    );

    return temp;
};

std::list<int> NFA3trace1 = {0,1,2,3,4};
std::list<int> NFA3trace2 = {0,0,1,2,3,4};
std::list<int> NFA3trace3 = {0,1,2,3,4,4};
std::list<int> NFA3trace4 = {0,0,0,1,2,3,4};
std::list<int> NFA3trace5 = {0,1,2,3,4,4,4};
std::list<int> NFA3trace6 = {0,0,1,2,3,4,4};
std::list<int> NFA3trace7 = {0,1,2,3};
std::list<int> NFA3trace8 = {0,4,2,1};
std::list<int> NFA3trace9 = {1,0,1,2,3};
std::list<int> NFA3trace10 = {0,1,2,3,5};
std::list<int> NFA3trace11 = {0,1,2,3,4,5,6};
std::list<int> NFA3trace12 = {0,1,2,2,3};

std::list<traceTreeBranch<int>> NFA3traceTree1 =
    {   traceTreeBranch<int>(0,{1,1,0,0},0,0,false),
        traceTreeBranch<int>(1,{1,0,0},0,0,false),
        traceTreeBranch<int>(1,{1,0,0},0,1,false),
        traceTreeBranch<int>(2,{0,0},0,0,false),
        traceTreeBranch<int>(2,{0,0},0,1,false),
        traceTreeBranch<int>(2,{0,0},1,2,false),
        traceTreeBranch<int>(3,{0},0,0,false),
        traceTreeBranch<int>(3,{0},2,3,false),
        traceTreeBranch<int>(4,{},0,0,false),
        traceTreeBranch<int>(4,{},3,4,true),
    };

std::list<traceTreeBranch<int>> NFA3traceTree2 =
    {   traceTreeBranch<int>(0,{1,1,0},0,0,false),
        traceTreeBranch<int>(1,{1,0},0,0,false),
        traceTreeBranch<int>(1,{1,0},0,1,false),
        traceTreeBranch<int>(2,{0},0,0,false),
        traceTreeBranch<int>(2,{0},0,1,false),
        traceTreeBranch<int>(2,{0},1,2,false),
        traceTreeBranch<int>(3,{},0,0,false),
        traceTreeBranch<int>(3,{},2,3,false),
    };

std::list<traceTreeBranch<int>> NFA3traceTree3 =
    {   traceTreeBranch<int>(0,{0,0},0,0,false),
        traceTreeBranch<int>(1,{0},0,0,false),
        traceTreeBranch<int>(2,{},0,0,false),
    };

std::list<traceTreeBranch<int>> NFA3traceTree4 =
    {   traceTreeBranch<int>(0,{1,1,1,0,0},0,0,false),
        traceTreeBranch<int>(1,{1,1,0,0},0,0,false),
        traceTreeBranch<int>(1,{1,1,0,0},0,1,false),
        traceTreeBranch<int>(2,{1,0,0},0,0,false),
        traceTreeBranch<int>(2,{1,0,0},0,1,false),
        traceTreeBranch<int>(2,{1,0,0},1,2,false),
        traceTreeBranch<int>(3,{0,0},0,0,false),
        traceTreeBranch<int>(3,{0,0},0,1,false),
        traceTreeBranch<int>(3,{0,0},1,2,false),
        traceTreeBranch<int>(4,{0},0,0,false),
        traceTreeBranch<int>(4,{0},2,3,false),
        traceTreeBranch<int>(5,{},0,0,false),
        traceTreeBranch<int>(5,{},3,4,true),
    };

std::list<traceTreeBranch<int>> NFA3traceTree5 =
    {   traceTreeBranch<int>(0,{0,1,0},0,0,false),
        traceTreeBranch<int>(1,{1,0},0,0,false),
        traceTreeBranch<int>(2,{0},0,0,false),
        traceTreeBranch<int>(2,{0},0,1,false),
        traceTreeBranch<int>(3,{},0,0,false),
    };

std::list<traceTreeBranch<int>> NFA3traceTree6 =
    {   traceTreeBranch<int>(0,{1,0,1,0},0,0,false),
        traceTreeBranch<int>(1,{0,1,0},0,0,false),
        traceTreeBranch<int>(1,{0,1,0},0,1,false),
        traceTreeBranch<int>(2,{1,0},0,0,false),
        traceTreeBranch<int>(3,{0},0,0,false),
        traceTreeBranch<int>(3,{0},0,1,false),
        traceTreeBranch<int>(4,{},0,0,false),
    };



// Accepts strings with the third element from the right being "0"
NFA<int> outputNFA4(void){
    NFA<int> temp(
            [](int state) { return state >= 0 && state <= 3; },
            DAlphabet0_1,
            [](int currentState, int charcterInAlphabet) -> std::set<int> {
                if (currentState == 0 && charcterInAlphabet == 0) return {0,1};
                else if (currentState == 0 && charcterInAlphabet == 1) return {0};
                else if (currentState == 1) return {2};
                else if (currentState == 2) return {3};
                else return {};
            },
            [](int currentState) -> std::set<int> {
                return {};
            },
            0,
            [](int state){return state == 3;}
    );

    return temp;
};

std::list<int> NFA4trace1 = {0,1,2,3,4};
std::list<int> NFA4trace2 = {0,0,1,2,3,4};
std::list<int> NFA4trace3 = {0,1,2,3,4,4};
std::list<int> NFA4trace4 = {0,0,0,1,2,3,4};
std::list<int> NFA4trace5 = {0,1,2,3,4,4,4};
std::list<int> NFA4trace6 = {0,0,1,2,3,4,4};
std::list<int> NFA4trace7 = {0,1,2,3};
std::list<int> NFA4trace8 = {0,4,2,1};
std::list<int> NFA4trace9 = {1,0,1,2,3};
std::list<int> NFA4trace10 = {0,1,2,3,5};
std::list<int> NFA4trace11 = {0,1,2,3,4,5,6};
std::list<int> NFA4trace12 = {0,1,2,2,3};

std::list<traceTreeBranch<int>> NFA4traceTree1 =
    {   traceTreeBranch<int>(0,{0,1,0},0,0,false),
        traceTreeBranch<int>(1,{1,0},0,0,false),
        traceTreeBranch<int>(1,{1,0},0,1,false),
        traceTreeBranch<int>(2,{0},0,0,false),
        traceTreeBranch<int>(2,{0},1,2,false),
        traceTreeBranch<int>(3,{},0,0,false),
        traceTreeBranch<int>(3,{},0,1,false),
        traceTreeBranch<int>(3,{},2,3,true),
    };

std::list<traceTreeBranch<int>> NFA4traceTree2 =
    {   traceTreeBranch<int>(0,{0,0,0},0,0,false),
        traceTreeBranch<int>(1,{0,0},0,0,false),
        traceTreeBranch<int>(1,{0,0},0,1,false),
        traceTreeBranch<int>(2,{0},0,0,false),
        traceTreeBranch<int>(2,{0},0,1,false),
        traceTreeBranch<int>(2,{0},1,2,false),
        traceTreeBranch<int>(3,{},0,0,false),
        traceTreeBranch<int>(3,{},0,1,false),
        traceTreeBranch<int>(3,{},1,2,false),
        traceTreeBranch<int>(3,{},2,3,true),
    };

std::list<traceTreeBranch<int>> NFA4traceTree3 =
    {   traceTreeBranch<int>(0,{1,1,1},0,0,false),
        traceTreeBranch<int>(1,{1,1},0,0,false),
        traceTreeBranch<int>(2,{1},0,0,false),
        traceTreeBranch<int>(3,{},0,0,false),
    };

std::list<traceTreeBranch<int>> NFA4traceTree4 =
    {   traceTreeBranch<int>(0,{1,1,0,1},0,0,false),
        traceTreeBranch<int>(1,{1,0,1},0,0,false),
        traceTreeBranch<int>(2,{0,1},0,0,false),
        traceTreeBranch<int>(3,{1},0,0,false),
        traceTreeBranch<int>(3,{1},0,1,false),
        traceTreeBranch<int>(4,{},0,0,false),
        traceTreeBranch<int>(4,{},1,2,false),
    };

std::list<traceTreeBranch<int>> NFA4traceTree5 =
    {   traceTreeBranch<int>(0,{0,0},0,0,false),
        traceTreeBranch<int>(1,{0},0,0,false),
        traceTreeBranch<int>(1,{0},0,1,false),
        traceTreeBranch<int>(2,{},0,0,false),
        traceTreeBranch<int>(2,{},0,1,false),
        traceTreeBranch<int>(2,{},1,2,false),
    };

std::list<traceTreeBranch<int>> NFA4traceTree6 =
    {   traceTreeBranch<int>(0,{0,1,1},0,0,false),
        traceTreeBranch<int>(1,{1,1},0,0,false),
        traceTreeBranch<int>(1,{1,1},0,1,false),
        traceTreeBranch<int>(2,{1},0,0,false),
        traceTreeBranch<int>(2,{1},1,2,false),
        traceTreeBranch<int>(3,{},0,0,false),
        traceTreeBranch<int>(3,{},2,3,true),
    };



// Accepts strings either with odd 1s or even 0s
NFA<int> outputNFA5(void){
    NFA<int> temp(
            [](int state) { return state >= 0 && state <= 4; },
            DAlphabet0_1,
            [](int currentState, int charcterInAlphabet) -> std::set<int> {
                if (charcterInAlphabet == 0)
                    if (currentState == 1) return {1};
                    if (currentState == 2) return {2};
                    if (currentState == 3) return {4};
                    if (currentState == 4) return {3};
                else if (charcterInAlphabet ==  1)
                    if (currentState == 1) return {2};
                    if (currentState == 2) return {1};
                    if (currentState == 3) return {3};
                    if (currentState == 4) return {4};
                else return {};
            },
            [](int currentState) -> std::set<int> {
                if (currentState == 0) return {1,3};
                else return {};
            },
            0,
            [](int state){return (state == 3) || (state == 2);}
    );

    return temp;
};

std::list<int> NFA5trace1 = {0,1,2};
std::list<int> NFA5trace2 = {0,3};
std::list<int> NFA5trace3 = {0,1,2,1,2};
std::list<int> NFA5trace4 = {0,3,4,3};
std::list<int> NFA5trace5 = {0,3,4,3,4,3};
std::list<int> NFA5trace6 = {0,1,2,1,2,1,2};
std::list<int> NFA5trace7 = {0,1,3};
std::list<int> NFA5trace8 = {0,2,3,4};
std::list<int> NFA5trace9 = {1,2,3};
std::list<int> NFA5trace10 = {0,3,4};
std::list<int> NFA5trace11 = {0,1};
std::list<int> NFA5trace12 = {0,4};

std::list<traceTreeBranch<int>> NFA5traceTree1 =
    {   traceTreeBranch<int>(0,{1,0,1},0,0,false),
        traceTreeBranch<int>(1,{1,0,1},0,1,false),
        traceTreeBranch<int>(1,{1,0,1},0,3,true),
        traceTreeBranch<int>(2,{0,1},1,2,true),
        traceTreeBranch<int>(2,{0,1},3,4,false),
        traceTreeBranch<int>(3,{1},2,2,true),
        traceTreeBranch<int>(3,{1},4,3,true),
        traceTreeBranch<int>(4,{},2,2,true),
        traceTreeBranch<int>(4,{},3,4,false),
    };

std::list<traceTreeBranch<int>> NFA5traceTree2 =
    {   traceTreeBranch<int>(0,{0,0},0,0,false),
        traceTreeBranch<int>(1,{0,0},0,1,false),
        traceTreeBranch<int>(1,{0,0},0,3,true),
        traceTreeBranch<int>(2,{0},1,1,false),
        traceTreeBranch<int>(2,{0},3,4,false),
        traceTreeBranch<int>(3,{},1,1,false),
        traceTreeBranch<int>(3,{},4,3,true),
    };

std::list<traceTreeBranch<int>> NFA5traceTree3 =
    {   traceTreeBranch<int>(0,{1},0,0,false),
        traceTreeBranch<int>(1,{1},0,1,false),
        traceTreeBranch<int>(1,{1},0,3,true),
    };

std::list<traceTreeBranch<int>> NFA5traceTree4 =
    {   traceTreeBranch<int>(0,{1,1},0,0,false),
        traceTreeBranch<int>(1,{1,1},0,1,false),
        traceTreeBranch<int>(1,{1,1},0,3,true),
        traceTreeBranch<int>(2,{1},1,2,true),
        traceTreeBranch<int>(2,{1},3,4,false),
        traceTreeBranch<int>(3,{},2,2,true),
        traceTreeBranch<int>(3,{},4,3,true),
    };

std::list<traceTreeBranch<int>> NFA5traceTree5 =
    {   traceTreeBranch<int>(0,{1,0,0},0,0,false),
        traceTreeBranch<int>(1,{1,0,0},0,1,false),
        traceTreeBranch<int>(1,{1,0,0},0,3,true),
        traceTreeBranch<int>(2,{0,0},1,2,true),
        traceTreeBranch<int>(2,{0,0},3,4,false),
        traceTreeBranch<int>(3,{0},2,2,true),
        traceTreeBranch<int>(3,{0},4,3,true),
        traceTreeBranch<int>(4,{},2,2,true),
        traceTreeBranch<int>(4,{},3,4,false),
    };

std::list<traceTreeBranch<int>> NFA5traceTree6 =
    {   traceTreeBranch<int>(0,{1,1,0},0,0,false),
        traceTreeBranch<int>(1,{1,1,0},0,1,false),
        traceTreeBranch<int>(1,{1,1,0},0,3,true),
        traceTreeBranch<int>(2,{1,0},1,2,true),
        traceTreeBranch<int>(2,{1,0},3,4,false),
        traceTreeBranch<int>(3,{0},2,2,true),
        traceTreeBranch<int>(3,{0},4,3,true),
        traceTreeBranch<int>(4,{},2,2,true),
        traceTreeBranch<int>(4,{},3,4,false),
    };



// Accepts strings only ending with "11" or "00"
NFA<int> outputNFA6(void){
    NFA<int> temp(
            [](int state) { return state >= 0 && state <= 3; },
            DAlphabet0_1,
            [](int currentState, int charcterInAlphabet) -> std::set<int> {
                if (charcterInAlphabet == 0)
                    if (currentState == 0) return {0,2};
                    if (currentState == 2) return {3};
                else if (charcterInAlphabet ==  1)
                    if (currentState == 0) return {0,1};
                    if (currentState == 1) return {3};
                else return {};
            },
            [](int currentState) -> std::set<int> {
                return {};
            },
            0,
            [](int state){return state == 3;}
    );

    return temp;
};

std::list<int> NFA6trace1 = {0,1,3};
std::list<int> NFA6trace2 = {0,2,3};
std::list<int> NFA6trace3 = {0,0,1,3};
std::list<int> NFA6trace4 = {0,0,2,3};
std::list<int> NFA6trace5 = {0,0,0,1,3};
std::list<int> NFA6trace6 = {0,0,0,2,3};
std::list<int> NFA6trace7 = {0,1};
std::list<int> NFA6trace8 = {0,2};
std::list<int> NFA6trace9 = {0};
std::list<int> NFA6trace10 = {0,0,1};
std::list<int> NFA6trace11 = {0,0,2};
std::list<int> NFA6trace12 = {0,0,0,2};

std::list<traceTreeBranch<int>> NFA6traceTree1 =
    {   traceTreeBranch<int>(0,{1,1},0,0,false),
        traceTreeBranch<int>(1,{1},0,0,false),
        traceTreeBranch<int>(1,{1},0,1,false),
        traceTreeBranch<int>(2,{},0,0,false),
        traceTreeBranch<int>(2,{},0,1,false),
        traceTreeBranch<int>(2,{},1,3,true),

    };

std::list<traceTreeBranch<int>> NFA6traceTree2 =
    {   traceTreeBranch<int>(0,{0,0},0,0,false),
        traceTreeBranch<int>(1,{0},0,0,false),
        traceTreeBranch<int>(1,{0},0,2,false),
        traceTreeBranch<int>(2,{},0,0,false),
        traceTreeBranch<int>(2,{},0,2,false),
        traceTreeBranch<int>(2,{},2,3,true),
    };

std::list<traceTreeBranch<int>> NFA6traceTree3 =
    {   traceTreeBranch<int>(0,{1,0,0},0,0,false),
        traceTreeBranch<int>(1,{0,0},0,0,false),
        traceTreeBranch<int>(1,{0,0},0,1,false),
        traceTreeBranch<int>(2,{0},0,0,false),
        traceTreeBranch<int>(2,{0},0,2,false),
        traceTreeBranch<int>(2,{0},1,3,true),
        traceTreeBranch<int>(3,{},0,0,false),
        traceTreeBranch<int>(3,{},0,2,false),
        traceTreeBranch<int>(3,{},2,3,true),
    };

std::list<traceTreeBranch<int>> NFA6traceTree4 =
    {   traceTreeBranch<int>(0,{0,1,1},0,0,false),
        traceTreeBranch<int>(1,{1,1},0,0,false),
        traceTreeBranch<int>(1,{1,1},0,2,false),
        traceTreeBranch<int>(2,{1},0,0,false),
        traceTreeBranch<int>(2,{1},0,1,false),
        traceTreeBranch<int>(2,{1},2,3,true),
        traceTreeBranch<int>(3,{},0,0,false),
        traceTreeBranch<int>(3,{},0,1,false),
        traceTreeBranch<int>(3,{},1,3,true),
    };

std::list<traceTreeBranch<int>> NFA6traceTree5 =
    {   traceTreeBranch<int>(0,{0,1},0,0,false),
        traceTreeBranch<int>(1,{1},0,0,false),
        traceTreeBranch<int>(1,{1},0,2,false),
        traceTreeBranch<int>(2,{},0,0,false),
        traceTreeBranch<int>(2,{},0,1,false),
        traceTreeBranch<int>(2,{},2,3,true),
    };

std::list<traceTreeBranch<int>> NFA6traceTree6 =
    {   traceTreeBranch<int>(0,{1,0},0,0,false),
        traceTreeBranch<int>(1,{0},0,0,false),
        traceTreeBranch<int>(1,{0},0,1,false),
        traceTreeBranch<int>(2,{},0,0,false),
        traceTreeBranch<int>(2,{},0,2,false),
        traceTreeBranch<int>(2,{},1,3,true),
    };



// Accepts strings with a length of 2 or 4
NFA<int> outputNFA7(void){
    NFA<int> temp(
            [](int state) { return state >= 0 && state <= 8; },
            DAlphabet0_1,
            [](int currentState, int charcterInAlphabet) -> std::set<int> {
                if (currentState == 1) return {2};
                if (currentState == 2) return {3};
                if (currentState == 4) return {5};
                if (currentState == 5) return {6};
                if (currentState == 6) return {7};
                if (currentState == 7) return {8};
                else return {};
            },
            [](int currentState) -> std::set<int> {
                if (currentState == 0) return {1,4};
                else return {};
            },
            0,
            [](int state){return (state == 3) || (state == 8);}
    );
    return temp;
};

std::list<int> NFA7trace1 = {0,1,2,3};
std::list<int> NFA7trace2 = {0,4,5,6,7,8};
std::list<int> NFA7trace3 = {0,1};
std::list<int> NFA7trace4 = {0,1,2};
std::list<int> NFA7trace5 = {0,1,2,3};
std::list<int> NFA7trace6 = {0,4};
std::list<int> NFA7trace7 = {0,4,5};
std::list<int> NFA7trace8 = {0,4,5,6};
std::list<int> NFA7trace9 = {0,4,5,6,7};
std::list<int> NFA7trace10 = {0,4,5,6,7,8};
std::list<int> NFA7trace11 = {0};
std::list<int> NFA7trace12 = {0,1,2,3,4};

std::list<traceTreeBranch<int>> NFA7traceTree1 =
    {   traceTreeBranch<int>(0,{1,0},0,0,false),
        traceTreeBranch<int>(1,{1,0},0,1,false),
        traceTreeBranch<int>(1,{1,0},0,4,false),
        traceTreeBranch<int>(2,{0},1,2,false),
        traceTreeBranch<int>(2,{0},4,5,false),
        traceTreeBranch<int>(3,{},2,3,true),
        traceTreeBranch<int>(3,{},5,6,false),
    };

std::list<traceTreeBranch<int>> NFA7traceTree2 =
    {   traceTreeBranch<int>(0,{0,0},0,0,false),
        traceTreeBranch<int>(1,{0,0},0,1,false),
        traceTreeBranch<int>(1,{0,0},0,4,false),
        traceTreeBranch<int>(2,{0},1,2,false),
        traceTreeBranch<int>(2,{0},4,5,false),
        traceTreeBranch<int>(3,{},2,3,true),
        traceTreeBranch<int>(3,{},5,6,false),
    };

std::list<traceTreeBranch<int>> NFA7traceTree3 =
    {   traceTreeBranch<int>(0,{1,1,1,0},0,0,false),
        traceTreeBranch<int>(1,{1,1,1,0},0,1,false),
        traceTreeBranch<int>(1,{1,1,1,0},0,4,false),
        traceTreeBranch<int>(2,{1,1,0},1,2,false),
        traceTreeBranch<int>(2,{1,1,0},4,5,false),
        traceTreeBranch<int>(3,{1,0},2,3,true),
        traceTreeBranch<int>(3,{1,0},5,6,false),
        traceTreeBranch<int>(4,{0},6,7,false),
        traceTreeBranch<int>(5,{},7,8,true),
    };

std::list<traceTreeBranch<int>> NFA7traceTree4 =
    {   traceTreeBranch<int>(0,{0,1,0,0},0,0,false),
        traceTreeBranch<int>(1,{0,1,0,0},0,1,false),
        traceTreeBranch<int>(1,{0,1,0,0},0,4,false),
        traceTreeBranch<int>(2,{1,0,0},1,2,false),
        traceTreeBranch<int>(2,{1,0,0},4,5,false),
        traceTreeBranch<int>(3,{0,0},2,3,true),
        traceTreeBranch<int>(3,{0,0},5,6,false),
        traceTreeBranch<int>(4,{0},6,7,false),
        traceTreeBranch<int>(5,{},7,8,true),
    };

std::list<traceTreeBranch<int>> NFA7traceTree5 =
    {   traceTreeBranch<int>(0,{1,1,0},0,0,false),
        traceTreeBranch<int>(1,{1,1,0},0,1,false),
        traceTreeBranch<int>(1,{1,1,0},0,4,false),
        traceTreeBranch<int>(2,{1,0},1,2,false),
        traceTreeBranch<int>(2,{1,0},4,5,false),
        traceTreeBranch<int>(3,{0},2,3,true),
        traceTreeBranch<int>(3,{0},5,6,false),
        traceTreeBranch<int>(4,{},6,7,false),
    };

std::list<traceTreeBranch<int>> NFA7traceTree6 =
    {   traceTreeBranch<int>(0,{1},0,0,false),
        traceTreeBranch<int>(1,{1},0,1,false),
        traceTreeBranch<int>(1,{1},0,4,false),
    };



// Accepts strings either ending in 0 or has all "1"s
NFA<int> outputNFA8(void){
    NFA<int> temp(
            [](int state) { return state >= 0 && state <= 3; },
            DAlphabet0_1,
            [](int currentState, int charcterInAlphabet) -> std::set<int> {
                if (currentState == 1 && charcterInAlphabet == 1) return {1};
                if (currentState == 2 && charcterInAlphabet == 0) return {2,3};
                if (currentState == 2 && charcterInAlphabet == 1) return {2};
                else return {};
            },
            [](int currentState) -> std::set<int> {
                if (currentState == 0) return {1,2};
                else return {};
            },
            0,
            [](int state){return (state == 1) || (state == 3);}
    );

    return temp;
};

std::list<int> NFA8trace1 = {0,1,1,1};
std::list<int> NFA8trace2 = {0,1,1};
std::list<int> NFA8trace3 = {0,2,2,3};
std::list<int> NFA8trace4 = {0,2,3};
std::list<int> NFA8trace5 = {0,1};
std::list<int> NFA8trace6 = {0,2,2,2,3};
std::list<int> NFA8trace7 = {0,2};
std::list<int> NFA8trace8 = {0,2,2};
std::list<int> NFA8trace9 = {0,2,2,2};
std::list<int> NFA8trace10 = {0,1,1,1,1};
std::list<int> NFA8trace11 = {0,2,2,2,2,3};
std::list<int> NFA8trace12 = {0,2,2,2,3};

std::list<traceTreeBranch<int>> NFA8traceTree1 =
    {   traceTreeBranch<int>(0,{1,1},0,0,false),
        traceTreeBranch<int>(1,{1,1},0,1,true),
        traceTreeBranch<int>(1,{1,1},0,2,false),
        traceTreeBranch<int>(2,{1},1,1,true),
        traceTreeBranch<int>(2,{1},2,2,false),
        traceTreeBranch<int>(3,{},1,1,true),
        traceTreeBranch<int>(3,{},2,2,false),
    };

std::list<traceTreeBranch<int>> NFA8traceTree2 =
    {   traceTreeBranch<int>(0,{1,1,0},0,0,false),
        traceTreeBranch<int>(1,{1,1,0},0,1,true),
        traceTreeBranch<int>(1,{1,1,0},0,2,false),
        traceTreeBranch<int>(2,{1,0},1,1,true),
        traceTreeBranch<int>(2,{1,0},2,2,false),
        traceTreeBranch<int>(3,{0},1,1,true),
        traceTreeBranch<int>(3,{0},2,2,false),
        traceTreeBranch<int>(4,{},2,2,false),
        traceTreeBranch<int>(4,{},2,3,true),
    };

std::list<traceTreeBranch<int>> NFA8traceTree3 =
    {   traceTreeBranch<int>(0,{1,1,1,1},0,0,false),
        traceTreeBranch<int>(1,{1,1,1,1},0,1,true),
        traceTreeBranch<int>(1,{1,1,1,1},0,2,false),
        traceTreeBranch<int>(2,{1,1,1},1,1,true),
        traceTreeBranch<int>(2,{1,1,1},2,2,false),
        traceTreeBranch<int>(3,{1,1},1,1,true),
        traceTreeBranch<int>(3,{1,1},2,2,false),
        traceTreeBranch<int>(4,{1},1,1,true),
        traceTreeBranch<int>(4,{1},2,2,false),
        traceTreeBranch<int>(5,{},1,1,true),
        traceTreeBranch<int>(5,{},2,2,false),
    };

std::list<traceTreeBranch<int>> NFA8traceTree4 =
    {   traceTreeBranch<int>(0,{0},0,0,false),
        traceTreeBranch<int>(1,{0},0,1,true),
        traceTreeBranch<int>(1,{0},0,2,false),
    };

std::list<traceTreeBranch<int>> NFA8traceTree5 =
    {   traceTreeBranch<int>(0,{1,0},0,0,false),
        traceTreeBranch<int>(1,{1,0},0,1,true),
        traceTreeBranch<int>(1,{1,0},0,2,false),
        traceTreeBranch<int>(2,{0},1,1,true),
        traceTreeBranch<int>(2,{0},2,2,false),
        traceTreeBranch<int>(3,{},2,2,false),
        traceTreeBranch<int>(3,{},2,3,true),
    };

std::list<traceTreeBranch<int>> NFA8traceTree6 =
    {   traceTreeBranch<int>(0,{1,0,1},0,0,false),
        traceTreeBranch<int>(1,{1,0,1},0,1,true),
        traceTreeBranch<int>(1,{1,0,1},0,2,false),
        traceTreeBranch<int>(2,{0,1},1,1,true),
        traceTreeBranch<int>(2,{0,1},2,2,false),
        traceTreeBranch<int>(3,{1},2,2,false),
        traceTreeBranch<int>(3,{1},2,3,true),
        traceTreeBranch<int>(4,{},2,2,false),
    };



// Accepts strings that start with 1 and either ends in 0 or has a length of 4
NFA<int> outputNFA9(void){
    NFA<int> temp(
            [](int state) { return state >= 0 && state <= 7; },
            DAlphabet0_1,
            [](int currentState, int charcterInAlphabet) -> std::set<int> {
                if (currentState == 0 && charcterInAlphabet == 1) return {1};
                if (currentState == 2 && charcterInAlphabet == 0) return {2,3};
                if (currentState == 2 && charcterInAlphabet == 1) return {2};
                if (currentState == 4) return {5};
                if (currentState == 5) return {6};
                if (currentState == 6) return {7};
                else return {};
            },
            [](int currentState) -> std::set<int> {
                if (currentState == 1) return {2,4};
                else return {};
            },
            0,
            [](int state){return (state == 3) || (state == 7);}
    );

    return temp;
};

std::list<int> NFA9trace1 = {0,1,2,3};
std::list<int> NFA9trace2 = {0,1,4,5,6,7};
std::list<int> NFA9trace3 = {0,1,2,2,3};
std::list<int> NFA9trace4 = {0,1,2,2,2,3};
std::list<int> NFA9trace5 = {0,1};
std::list<int> NFA9trace6 = {0};
std::list<int> NFA9trace7 = {0,1};
std::list<int> NFA9trace8 = {0,1,2};
std::list<int> NFA9trace9 = {0,1,4};
std::list<int> NFA9trace10 = {0,1,2,2};
std::list<int> NFA9trace11 = {0,1,2,2,2};
std::list<int> NFA9trace12 = {0,1,2,2,2,2};

std::list<traceTreeBranch<int>> NFA9traceTree1 =
    {   traceTreeBranch<int>(0,{1,0,1},0,0,false),
        traceTreeBranch<int>(1,{0,1},0,1,false),
        traceTreeBranch<int>(2,{0,1},1,2,false),
        traceTreeBranch<int>(2,{0,1},1,4,false),
        traceTreeBranch<int>(3,{1},2,2,false),
        traceTreeBranch<int>(3,{1},2,3,true),
        traceTreeBranch<int>(3,{1},4,5,false),
        traceTreeBranch<int>(4,{},2,2,false),
        traceTreeBranch<int>(4,{},5,6,false),

    };

std::list<traceTreeBranch<int>> NFA9traceTree2 =
    {   traceTreeBranch<int>(0,{0},0,0,false),
    };

std::list<traceTreeBranch<int>> NFA9traceTree3 =
    {   traceTreeBranch<int>(0,{1,1,1},0,0,false),
        traceTreeBranch<int>(1,{1,1},0,1,false),
        traceTreeBranch<int>(2,{1,1},1,2,false),
        traceTreeBranch<int>(2,{1,1},1,4,false),
        traceTreeBranch<int>(3,{1},2,2,false),
        traceTreeBranch<int>(3,{1},4,5,false),
        traceTreeBranch<int>(4,{},2,2,false),
        traceTreeBranch<int>(4,{},5,6,false),

    };

std::list<traceTreeBranch<int>> NFA9traceTree4 =
    {   traceTreeBranch<int>(0,{1,1,1,1},0,0,false),
        traceTreeBranch<int>(1,{1,1,1},0,1,false),
        traceTreeBranch<int>(2,{1,1,1},1,2,false),
        traceTreeBranch<int>(2,{1,1,1},1,4,false),
        traceTreeBranch<int>(3,{1,1},2,2,false),
        traceTreeBranch<int>(3,{1,1},4,5,false),
        traceTreeBranch<int>(4,{1},2,2,false),
        traceTreeBranch<int>(4,{1},5,6,false),
        traceTreeBranch<int>(5,{},2,2,false),
        traceTreeBranch<int>(5,{},6,7,true),
    };

std::list<traceTreeBranch<int>> NFA9traceTree5 =
    {   traceTreeBranch<int>(0,{1,0,0},0,0,false),
        traceTreeBranch<int>(1,{0,0},0,1,false),
        traceTreeBranch<int>(2,{0,0},1,2,false),
        traceTreeBranch<int>(2,{0,0},1,4,false),
        traceTreeBranch<int>(3,{0},2,2,false),
        traceTreeBranch<int>(3,{0},2,3,true),
        traceTreeBranch<int>(3,{0},4,5,false),
        traceTreeBranch<int>(4,{},2,2,false),
        traceTreeBranch<int>(4,{},2,3,true),
        traceTreeBranch<int>(4,{},5,6,false),

    };

std::list<traceTreeBranch<int>> NFA9traceTree6 =
    {   traceTreeBranch<int>(0,{1,1,0,0},0,0,false),
        traceTreeBranch<int>(1,{1,0,0},0,1,false),
        traceTreeBranch<int>(2,{1,0,0},1,2,false),
        traceTreeBranch<int>(2,{1,0,0},1,4,false),
        traceTreeBranch<int>(3,{0,0},2,2,false),
        traceTreeBranch<int>(3,{0,0},4,5,false),
        traceTreeBranch<int>(4,{0},2,2,false),
        traceTreeBranch<int>(4,{0},2,3,true),
        traceTreeBranch<int>(4,{0},5,6,false),
        traceTreeBranch<int>(5,{},2,2,false),
        traceTreeBranch<int>(5,{},2,3,true),
        traceTreeBranch<int>(5,{},6,7,true),
    };



// NFA = DFA Sample 4 - accepts only strings with "01" in it
NFA<int> outputNFA10(void){
    DFA stuff = outputDFA4();
    return NFA<int>(stuff);
//    return DFAtoNFA(outputDFA4());
}

std::list<int> NFA10trace1 = {0,1,2};
std::list<int> NFA10trace2 = {0,0,1,1,2};
std::list<int> NFA10trace3 = {0,1,1,2};
std::list<int> NFA10trace4 = {0,0,1,1,2};
std::list<int> NFA10trace5 = {0,0,1,2};
std::list<int> NFA10trace6 = {0,0,1,1,1,2};
std::list<int> NFA10trace7 = {0};
std::list<int> NFA10trace8 = {0,1,1};
std::list<int> NFA10trace9 = {0,1};
std::list<int> NFA10trace10 = {0,0,1};
std::list<int> NFA10trace11 = {0,0,1,1};
std::list<int> NFA10trace12 = {0,0,0,1};

std::list<traceTreeBranch<int>> NFA10traceTree1 =
    {   traceTreeBranch<int>(0,{0,1,0},0,0,false),
        traceTreeBranch<int>(1,{1,0},0,1,false),
        traceTreeBranch<int>(2,{0},1,2,true),
        traceTreeBranch<int>(3,{},2,2,true),
    };

std::list<traceTreeBranch<int>> NFA10traceTree2 =
    {   traceTreeBranch<int>(0,{0,0,1,0},0,0,false),
        traceTreeBranch<int>(1,{0,1,0},0,1,false),
        traceTreeBranch<int>(2,{1,0},1,1,false),
        traceTreeBranch<int>(3,{0},1,2,true),
        traceTreeBranch<int>(4,{},2,2,true),
    };

std::list<traceTreeBranch<int>> NFA10traceTree3 =
    {   traceTreeBranch<int>(0,{1,0},0,0,false),
        traceTreeBranch<int>(1,{0},0,0,false),
        traceTreeBranch<int>(2,{},0,1,false),
    };

std::list<traceTreeBranch<int>> NFA10traceTree4 =
    {   traceTreeBranch<int>(0,{1,1,0,0},0,0,false),
        traceTreeBranch<int>(1,{1,0,0},0,0,false),
        traceTreeBranch<int>(2,{0,0},0,0,false),
        traceTreeBranch<int>(3,{0},0,1,false),
        traceTreeBranch<int>(4,{},1,1,false),
    };

std::list<traceTreeBranch<int>> NFA10traceTree5 =
    {   traceTreeBranch<int>(0,{1,0,0,1},0,0,false),
        traceTreeBranch<int>(1,{0,0,1},0,0,false),
        traceTreeBranch<int>(2,{0,1},0,1,false),
        traceTreeBranch<int>(3,{1},1,1,false),
        traceTreeBranch<int>(4,{},1,2,true),
    };

std::list<traceTreeBranch<int>> NFA10traceTree6 =
    {   traceTreeBranch<int>(0,{1,1,1},0,0,false),
        traceTreeBranch<int>(1,{1,1},0,0,false),
        traceTreeBranch<int>(2,{1},0,0,false),
        traceTreeBranch<int>(3,{},0,0,false),
    };



// NFA = DFA Sample 10 - accepting strings starting with ‘11’
NFA<int> outputNFA11(void){
    NFA<int> temp(outputDFA10());
    return temp;
}

std::list<int> NFA11trace1 = {0,1,2,2};
std::list<int> NFA11trace2 = {0,1,2,2,2};
std::list<int> NFA11trace3 = {0};
std::list<int> NFA11trace4 = {0,1};
std::list<int> NFA11trace5 = {0,1,2};
std::list<int> NFA11trace6 = {0,3};
std::list<int> NFA11trace7 = {0,3,3};
std::list<int> NFA11trace8 = {0,3,3,3};
std::list<int> NFA11trace9 = {0,1,3};
std::list<int> NFA11trace10 = {0,1,3,3};
std::list<int> NFA11trace11 = {0,1,2,2,2,2};
std::list<int> NFA11trace12 = {0,3,3,3,3,3};

std::list<traceTreeBranch<int>> NFA11traceTree1 =
    {   traceTreeBranch<int>(0,{1,1,0},0,0,false),
        traceTreeBranch<int>(1,{1,0},0,1,false),
        traceTreeBranch<int>(2,{0},1,2,true),
        traceTreeBranch<int>(3,{},2,2,true),
    };

std::list<traceTreeBranch<int>> NFA11traceTree2 =
    {   traceTreeBranch<int>(0,{0,1,1,0},0,0,false),
        traceTreeBranch<int>(1,{1,1,0},0,3,false),
        traceTreeBranch<int>(2,{1,0},3,3,false),
        traceTreeBranch<int>(3,{0},3,3,false),
        traceTreeBranch<int>(4,{},3,3,false),

    };

std::list<traceTreeBranch<int>> NFA11traceTree3 =
    {   traceTreeBranch<int>(0,{1,0,1,1},0,0,false),
        traceTreeBranch<int>(1,{0,1,1},0,1,false),
        traceTreeBranch<int>(2,{1,1},1,3,false),
        traceTreeBranch<int>(3,{1},3,3,false),
        traceTreeBranch<int>(4,{},3,3,false),
    };

std::list<traceTreeBranch<int>> NFA11traceTree4 =
    {   traceTreeBranch<int>(0,{1,1,1},0,0,false),
        traceTreeBranch<int>(1,{1,1},0,1,false),
        traceTreeBranch<int>(2,{1},1,2,true),
        traceTreeBranch<int>(3,{},2,2,true),
    };

std::list<traceTreeBranch<int>> NFA11traceTree5 =
    {   traceTreeBranch<int>(0,{1,1,0,1,1},0,0,false),
        traceTreeBranch<int>(1,{1,0,1,1},0,1,false),
        traceTreeBranch<int>(2,{0,1,1},1,2,true),
        traceTreeBranch<int>(3,{1,1},2,2,true),
        traceTreeBranch<int>(4,{1},2,2,true),
        traceTreeBranch<int>(5,{},2,2,true),
    };

std::list<traceTreeBranch<int>> NFA11traceTree6 =
    {   traceTreeBranch<int>(0,{1,1},0,0,false),
        traceTreeBranch<int>(1,{1},0,1,false),
        traceTreeBranch<int>(2,{},1,2,true),
    };



// NFA = DFA Sample 7 - accepts only strings with an even number of 0s and 1s
NFA<int> outputNFA12(void){
    NFA<int> temp(outputDFA6());
    return temp;
}

std::list<int> NFA12trace1 = {0,1,2};
std::list<int> NFA12trace2 = {0,1,1,1};
std::list<int> NFA12trace3 = {0,3,3,3};
std::list<int> NFA12trace4 = {0,1,1,2,1,2};
std::list<int> NFA12trace5 = {0,1,2,2,2};
std::list<int> NFA12trace6 = {0,1,1,1,2,1};
std::list<int> NFA12trace7 = {0,3,3,3,3};
std::list<int> NFA12trace8 = {0,3};
std::list<int> NFA12trace9 = {0,1,1,1,1,1};
std::list<int> NFA12trace10 = {0,1,1,2,2,1,1};
std::list<int> NFA12trace11 = {0,1,2,2,1};
std::list<int> NFA12trace12 = {0,1,1,2,2};

std::list<traceTreeBranch<int>> NFA12traceTree1 =
    {   traceTreeBranch<int>(0,{0,1},0,0,false),
        traceTreeBranch<int>(1,{1},0,3,false),
        traceTreeBranch<int>(2,{},3,3,false),
    };

std::list<traceTreeBranch<int>> NFA12traceTree2 =
    {   traceTreeBranch<int>(0,{1,1,1,1},0,0,false),
        traceTreeBranch<int>(1,{1,1,1},0,1,false),
        traceTreeBranch<int>(2,{1,1},1,2,true),
        traceTreeBranch<int>(3,{1},2,2,true),
        traceTreeBranch<int>(4,{},2,2,true),

    };

std::list<traceTreeBranch<int>> NFA12traceTree3 =
    {   traceTreeBranch<int>(0,{1,0,0,0,1},0,0,false),
        traceTreeBranch<int>(1,{0,0,0,1},0,1,false),
        traceTreeBranch<int>(2,{0,0,1},1,1,false),
        traceTreeBranch<int>(3,{0,1},1,1,false),
        traceTreeBranch<int>(4,{1},1,1,false),
        traceTreeBranch<int>(5,{},1,2,true),

    };

std::list<traceTreeBranch<int>> NFA12traceTree4 =
    {   traceTreeBranch<int>(0,{1,1,1,0},0,0,false),
        traceTreeBranch<int>(1,{1,1,0},0,1,false),
        traceTreeBranch<int>(2,{1,0},1,2,true),
        traceTreeBranch<int>(3,{0},2,2,true),
        traceTreeBranch<int>(4,{},2,1,false),
    };

std::list<traceTreeBranch<int>> NFA12traceTree5 =
    {   traceTreeBranch<int>(0,{1,0,1,0,1},0,0,false),
        traceTreeBranch<int>(1,{0,1,0,1},0,1,false),
        traceTreeBranch<int>(2,{1,0,1},1,1,false),
        traceTreeBranch<int>(3,{0,1},1,2,true),
        traceTreeBranch<int>(4,{1},2,1,false),
        traceTreeBranch<int>(5,{},1,2,true),

    };

std::list<traceTreeBranch<int>> NFA12traceTree6 =
    {   traceTreeBranch<int>(0,{0,0,1},0,0,false),
        traceTreeBranch<int>(1,{0,1},0,3,false),
        traceTreeBranch<int>(2,{1},3,3,false),
        traceTreeBranch<int>(3,{},3,3,false),
    };
