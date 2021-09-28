//  DFA_Examples.cpp
//
//  ISV = is state valid
//  TF = transition function
//  ISA = is state accepted

#include "DFA_Examples.hpp"

// General use alphabet set
std::vector<int> alphabet0 {0};
std::vector<int> alphabet0_1 {0,1};

// outputs a DFA that will only accept a string of only that one alphabet character
DFA generateOneCharDFA(int onlyAlphabet){
    DFA results(
            [](int state) { return state >= 0 && state <= 2; },
            alphabet0_1,
            [onlyAlphabet](int currentState, int charcterInAlphabet) {
                if (currentState == 0 && charcterInAlphabet == onlyAlphabet) return 1;
                else return 2;
            },
            0,
            [](int state){return state == 1;}
    );

    return results;

};


//************************************************************
// acceptNoString parameter functions
//************************************************************
bool acceptNoStringISV(int state){
    if(state == 0){
        return true;
    } else {
        return false;
    }
};

int acceptNoStringTF(int currentState, int alphabetCharcter){
    return 0;
};

bool acceptNoStringISA(int state){
    return false;
};

DFA outputAcceptNoString(void){
    return DFA(acceptNoStringISV, alphabet0_1, acceptNoStringTF, 0, acceptNoStringISA);;
}


//************************************************************
// acceptEmptyString parameter functions
//************************************************************
bool acceptEmptyStringISV(int state){
    if(state == 0 || state == 1){
        return true;
    } else {
        return false;
    }
};


int acceptEmptyStringTF(int currentState, int alphabetCharcter){
    return 1;
};

bool acceptEmptyStringISA(int state){
    if (state == 0) {
        return true;
    } else {
        return false;
    }
};

DFA outputAcceptEmptyString(void){
    return DFA(acceptEmptyStringISV, alphabet0_1, acceptEmptyStringTF, 0, acceptEmptyStringISA);
};

//************************************************************
// DFA Sample 1 - accepts only strings that start with "1"
//************************************************************
DFA outputDFA1(void){
    DFA temp(
            [](int state) { return state >= 0 && state <= 2; },
            alphabet0_1,
            [](int currentState, int charcterInAlphabet) {
                if (currentState == 0 && charcterInAlphabet == 1) return 1;
                else if (currentState == 1) return 1;
                else return 2;
            },
            0,
            [](int state){return state == 1;}
    );

    return temp;
};

//************************************************************
// DFA Sample 2 - accepts only strings that end with "1"
//************************************************************
DFA outputDFA2(void){
    DFA temp(
            [](int state) { return state >= 0 && state <= 1; },
            alphabet0_1,
            [](int currentState, int charcterInAlphabet) {
                if (charcterInAlphabet == 1) return 1;
                else return 0;
            },
            0,
            [](int state){return state == 1;}
    );

    return temp;
};

//************************************************************
// DFA Sample 3 - accepts only strings of all "0"
//************************************************************
DFA outputDFA3(void){
    DFA temp(
            [](int state) { return state >= 0 && state <= 2; },
            alphabet0_1,
            [](int currentState, int charcterInAlphabet) {
                if (currentState == 2 || charcterInAlphabet == 1) return 2;
                else return 1;
            },
            0,
            [](int state){return state == 1;}
    );

    return temp;
};

//************************************************************
// DFA Sample 4 - accepts only strings with "01" in it
//************************************************************
DFA outputDFA4(void){
    DFA temp(
            [](int state) { return state >= 0 && state <= 2; },
            alphabet0_1,
            [](int currentState, int charcterInAlphabet) {
                if (currentState == 0 && charcterInAlphabet == 0) return 1;
                else if (currentState == 1)
                    if (charcterInAlphabet == 1) return 2;
                    else return 1;
                else if (currentState == 2) return 2;
                else return 0;
            },
            0,
            [](int state){return state == 2;}
    );

    return temp;
};

//************************************************************
// DFA Sample 5 - accepts only strings with an odd number of 1s
//************************************************************
DFA outputDFA5(void){
    DFA temp(
            [](int state) { return state >= 0 && state <= 1; },
            alphabet0_1,
            [](int currentState, int charcterInAlphabet) {
                if (charcterInAlphabet == 0) return currentState;
                else if (currentState == 0) return 1;
                else return 0;
            },
            0,
            [](int state){return state == 1;}
    );

    return temp;
};

//************************************************************
// DFA Sample 6 - accepts only strings that starts with 1 and ends with 1
//************************************************************
DFA outputDFA6(void){
    DFA temp(
            [](int state) { return state >= 0 && state <= 3; },
            alphabet0_1,
            [](int currentState, int charcterInAlphabet) {
                // State 0 - if 1, proceed, else go to dead zone
                if (currentState == 0 && charcterInAlphabet == 1) return 1;
                // State 1 - If next element is 1, go to state 2. Else, stay in state 1
                else if (currentState == 1)
                    if (charcterInAlphabet == 0) return 1;
                    else return 2;
                // State 2 - If theres more, go back to state 1
                else if (currentState == 2)
                    if (charcterInAlphabet == 1) return 2;
                    else return 1;
                // State 3 - Dead zone
                else return 3;
            },
            0,
            [](int state){return state == 2;}
    );

    return temp;
};

//************************************************************
// DFA Sample 7 - accepts only strings with an even number of 0s and 1s
//************************************************************
DFA outputDFA7(void){
    //  (0) 1
    //   3  2
    DFA temp(
            [](int state) { return state >= 0 && state <= 3; },
            alphabet0_1,
            [](int currentState, int charcterInAlphabet) {
                if (charcterInAlphabet == 1)
                    if (currentState == 0) return 3;
                    else if (currentState == 1) return 2;
                    else if (currentState == 2) return 1;
                    else return 0; // currentState == 3
                else // charcterInAlphabet == 0
                    if (currentState == 0) return 1;
                    else if (currentState == 1) return 0;
                    else if (currentState == 2) return 3;
                    else return 2; // currentState == 3;
            },
            0,
            [](int state){return state == 0;}
    );

    return temp;
};

//************************************************************
// DFA Sample 8 - accepts the strings with an even number of leading 0's followed by single 1
//************************************************************
DFA outputDFA8(void){
    //   0  1
    //  (3) 2
    DFA temp(
            [](int state) { return state >= 0 && state <= 3; },
            alphabet0_1,
            [](int currentState, int charcterInAlphabet) {
                if (currentState == 0)
                    if (charcterInAlphabet == 0) return 1;
                    else return 3;
                else if (currentState == 1 && charcterInAlphabet == 0) return 0;
                else return 2;
            },
            0,
            [](int state){return state == 3;}
    );

    return temp;
};

//************************************************************
// DFA Sample 9 - accepting strings ending with ‘00’ over input alphabets
//************************************************************
DFA outputDFA9(void){
    //  (0) 1
    //   3  2
    DFA temp(
            [](int state) { return state >= 0 && state <= 2; },
            alphabet0_1,
            [](int currentState, int charcterInAlphabet) {
                if (charcterInAlphabet == 0)
                    if (currentState == 0) return 1;
                    else return 2;
                else return 0;
            },
            0,
            [](int state){return state == 2;}
    );

    return temp;
};


//************************************************************
// DFA Sample 10 - accepting strings starting with ‘11’
//************************************************************
DFA outputDFA10(void){
    DFA temp(
            [](int state) { return state >= 0 && state <= 3; },
            alphabet0_1,
            [](int currentState, int charcterInAlphabet) {
                if (charcterInAlphabet == 1)
                    if (currentState == 0) return 1;
                    else if (currentState == 3) return 3;
                    else return 2;
                else if (currentState == 2) return 2;
                else return 3;
            },
            0,
            [](int state){return state == 2;}
    );

    return temp;
};

//************************************************************
// DFA Sample 11 - accepting strings over the length of 3
//************************************************************
DFA outputDFA11(void){
    DFA temp(
            [](int state) { return state >= 0 && state <= 4; },
            alphabet0_1,
            [](int currentState, int charcterInAlphabet) {
                if (currentState < 4) return currentState + 1;
                else return 4; //currentState == 4
            },
            0,
            [](int state){return state == 4;}
    );

    return temp;
};

//************************************************************
// DFA Sample 12 - accepting strings less or equal to the length of 3
//************************************************************
DFA outputDFA12(void){
    DFA temp(
            [](int state) { return state >= 0 && state <= 4; },
            alphabet0_1,
            [](int currentState, int charcterInAlphabet) {
                if (currentState < 4) return currentState + 1;
                else return 4; //currentState == 4
            },
            0,
            [](int state){return state <= 3;}
    );

    return temp;
};