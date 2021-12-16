//
//  DFA_testing.cpp
//  foundationsProject
//
//  Created by Calvin Yee on 9/27/21.
//

#include "DFA_testing.hpp"

void boolCounter(std::vector<bool> examples){
    int counter = 0;
    int numberOfTrue = 0;
    for (bool const &c: examples) {
        if (c == true) {
            numberOfTrue++;
        }
        counter++;
    }
    
    std::cout << "Results for BoolCounter: " << numberOfTrue << "/" << counter << std::endl;
    
    
}
