//
//  foundationsProject
//
//  A alphabet - vector of ints
//  A string - list of ints

#include <iostream>
#include <vector>
#include <list>

void permutation(int temp[], int finalArray[], int& finalArraySize, int arraySize, int pos, std::vector<int> alpha, int& permutationNumber, int n);

std::list<int> getNthPermutation(std::vector<int> alphabet, int n);


 

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
    
    
    /*
    int z = 0;
    int finalArraySize = 0;
    std::list<int> stuff;

    
    
    for (int i = 1; i < alphabet.size() + 1; i++) {
        permutation(temp, array, finalArraySize, i, 0, alphabet, z, n);
    }
    
    std::cout << "Whats currently in array: ";
    for (int i = 0; i < finalArraySize; i++) {
        std::cout << array[i];
    }
    std::cout << std::endl;
    std::cout << finalArraySize << std::endl;

    for (int i = 0; i < finalArraySize; i++) {
        stuff.push_back(array[i]);
    }
    
    for (auto x = stuff.begin(); x != stuff.end(); ++x) {
        std::cout << *x << " ";
    }
    */
        
    return 0;
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
    
    //
    for (int j = 0; j < finalArraySize; j++) {
        stuff.push_back(array[j]);
    }

    return stuff;
}
