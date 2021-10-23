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

//bool doesStringFollowDFA(DFA dfa, std::list<int> string){
//    int currentState = dfa.startState;
//
//    for (int const &c: string) {
//        if (!(dfa.isStateValid(currentState))) {
//            return false;
//        }
//        currentState = dfa.transitionFunction(currentState, c);
//    }
//    return dfa.isAcceptedState(currentState);
//}
//
//std::list<int> generateViableString(DFA dfa){
//    std::list<int> answer;
//
//    // Check if it will accept the empty string
//    if (doesStringFollowDFA(dfa, answer)) {
//        return answer;
//    }
//
//
//    for (; <#condition#>; increment) {
//        <#statements#>
//    }
//
//
//    return answer;
//}
//
//DFA generateComplement(DFA dfa){
//    DFA temp{
//        [dfa](int state){return dfa.isStateValid(state);},
//        dfa.alphabet,
//        [dfa](int currentState, int charcterInAlphabet){return dfa.transitionFunction(currentState, charcterInAlphabet);},
//        0,
//        [dfa](int state){return !(dfa.isAcceptedState(state));}
//    };
//    return temp;
//}
//
////DFA generateUnion(DFA dfa1, DFA dfa2){
////
////
////
////    DFA temp{
////        [dfa1, dfa2](int state){return dfa1.isStateValid(state) || dfa2.isStateValid;},
////        dfa.alphabet,
////        [dfa1, dfa2](int currentState, int charcterInAlphabet){return dfa.transitionFunction(currentState, charcterInAlphabet);},
////        0,
////        [dfa](int state){return !(dfa.isAcceptedState(state));}
////    };
////    return temp;
////}
