//
//  permutations.hpp
//  foundationsProject
//
//  Created by Calvin Yee on 9/12/21.
//

#ifndef permutations_hpp
#define permutations_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>

void hello(void);

void permutation(int temp[], int finalArray[], int& finalArraySize, int arraySize, int pos, std::vector<int> alpha, int& permutationNumber, int n);

std::list<int> getNthPermutation(std::vector<int> alphabet, int n);

#endif /* permutations_hpp */
