//
//  RE.hpp
//  foundationsProject
//
//  Created by Calvin Yee on 12/5/21.
//

#ifndef RE_hpp
#define RE_hpp

#include "DFA_Examples.hpp"
#include "NFA.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <list>
#include <stack>

extern std::stack<int> elements;
extern std::stack<int> specialtyCounter;
extern std::stack<int> finalProduct;

class RE
{
public:
    // for epsilon(E), null(N), singletons(Z,O)
    RE(char initType):
    type(initType){};
    
    // for union(U), concatenation(C)
    RE(char initType, RE *initLeftOperand, RE *initRightOperand):
    type(initType), leftOperand(initLeftOperand), rightOperand(initRightOperand){};
    
    // for Kleene star(K)
    RE(char initType, RE *initOperand):
    type(initType), leftOperand(initOperand){};
    
    // For printer function
    void printer();
    void printOutEquation();
    
    // Generate function
    std::list<int> generate();
    
    // Optimize function
    RE* optimizer();
    
    
    // Getters
    char getType(void){
        return type;
    }
    
    RE getLeftRE(void){
        return *leftOperand;
    }
    
    RE getRightRE(void){
        return *rightOperand;
    }
    

private:
    char type; // can be E, N, Z(singleton 0), O(singleton 1), U, K, or C
    RE *leftOperand; // only assigned if type == union/concatentation/kleene star
    RE *rightOperand; //  only assigned if type == union/concatentation
};

void outputReallyLongNFA();
void castEverythingToInt(RE re);

// RE to NFA function
template<typename T>
NFA<T> REToNFAComplier(RE re){
    
    switch (re.getType()) {
        case 'E':
            castEverythingToInt(re.getType());
            return NFA<int>(outputAcceptEmptyString());
            break;
            
        case 'N':
            castEverythingToInt(re.getType());
            return NFA<int>(outputAcceptNoString());
            break;
            
        case 'Z':
            castEverythingToInt(re.getType());
            return NFA<int>(generateOneCharDFA(0));
            break;
            
        case 'O':
            castEverythingToInt(re.getType());
            return NFA<int>(generateOneCharDFA(1));
            break;
            
        case 'U':
            castEverythingToInt(re.getType());
            return (generateNFAUnion(REToNFAComplier<T>(re.getLeftRE()), REToNFAComplier<T>(re.getRightRE())));
            break;
            
        case 'K':
            castEverythingToInt(re.getType());
            return (generateKleeneStar(REToNFAComplier<T>(re.getLeftRE())));
            break;
            
        case 'C':
            castEverythingToInt(re.getType());
            return (generateNFAConcat(REToNFAComplier<T>(re.getLeftRE()), REToNFAComplier<T>(re.getRightRE())));
            break;
            
        default:
            std::cout << "something went wrong in RE to NFA switch";
            exit(1);
            break;
    }
    
}

#endif /* RE_hpp */
