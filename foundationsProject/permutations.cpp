//
//  permutations.cpp
//  foundationsProject
//
//  Created by Calvin Yee on 9/12/21.
//

#include "permutations.hpp"

void hello(void){
    std::cout << "Hello Pootis" << std::endl;
}

void permutation(int temp[], int finalArray[], int& finalArraySize, int arraySize, int pos, std::vector<int> alpha, int& permutationNumber, int n){
    
    if (arraySize == pos) {
        
        permutationNumber += 1;
        
        //Print all elements in array
        if (n == permutationNumber) {
            finalArraySize = pos;
            std::cout << permutationNumber <<  ": ";
            for (int i = 0; i < arraySize; i++) {
                std::cout << temp[i];
                finalArray[i] = temp[i];
            }
            std::cout << std::endl;
        }
    } else {
        for (int i = 0; i < alpha.size(); i++) {
            temp[pos] = alpha.at(i);
            //permutationNumber += 1;
            permutation(temp, finalArray, finalArraySize, arraySize, pos + 1, alpha, permutationNumber, n);
        }
    }
}


std::list<int> getNthPermutation(std::vector<int> alphabet, int n){
    
    // If n = 0, return a empty list;
    if (n == 0) {
        std::list<int> empty;
        return empty;
    }
    
    // Set up pre-requiste data
    int temp[alphabet.size()];
    int array[alphabet.size()];
    int z = 0;
    int finalArraySize = 0;
    std::list<int> stuff;
    
    // Loop through a recursive functions to find permutation
    for (int i = 1; i < alphabet.size() + 1; i++) {
        permutation(temp, array, finalArraySize, i, 0, alphabet, z, n);
    }
    
    // Push back data from
    for (int j = 0; j < finalArraySize; j++) {
        stuff.push_back(array[j]);
    }

    return stuff;
}
