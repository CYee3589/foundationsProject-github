//
//  foundationsProject
//
//  A alphabet - vector of ints
//  A string - list of ints

#include "permutations.hpp"

#include <iostream>
#include <vector>
#include <list>

int main(int argc, const char * argv[]) {
    
    std::vector<int> alphabet;
    alphabet.push_back(3);
    alphabet.push_back(5);
    alphabet.push_back(7);

    int n = 14;
    
    std::list<int> answer = getNthPermutation(alphabet, n);
    
    for (auto x = answer.begin(); x != answer.end(); ++x) {
        std::cout << *x << " ";
    }
    
    std::cout << std::endl;
    
    hello();
 
    return 0;
}
