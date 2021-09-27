//
//  foundationsProject
//
//  A alphabet - vector of ints
//  A string - list of ints

#include "permutations.hpp"
#include "DFA.hpp"
#include "DFA_Examples.hpp"

#include <iostream>
#include <vector>
#include <list>

int main(int argc, const char * argv[]) {
//
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
    
    std::list<int> example = {1,0,1};
    std::list<int> example1;
    std::list<int> example2 = {1};
    std::list<int> example3 = {0, 1, 1, 1};


    
    DFA dfa1 = outputAcceptEmptyString();
    DFA dfa2 = generateOneCharDFA(1);
    DFA dfa3 = outputDFA1();


    std::cout << doesStringFollowDFA(dfa2, example) << std::endl;
    traceStringInDFA(dfa3, example);
    
//    for (int const &c: example) {
//        std::cout << c << std::endl;
//        i++;
//        std::cout << i << std::endl;
//    }
//
//    std::cout << i << std::endl;
//    std::cout << "hello" << std::endl;

//    int s = NULL;
//    std::string temp = std::to_string(s);
//    std::cout << temp << std::endl;
//
//    int results = (temp.empty()) ? 0 : 1;
//    std::cout << results << std::endl;
    
    return 0;
}

