//
//  RE.cpp
//  foundationsProject
//
//  Created by Calvin Yee on 12/5/21.
//

#include "RE.hpp"

std::stack<int> elements;
std::stack<int> specialtyCounter;
std::stack<int> finalProduct;


void RE::printer(void){
    switch (type) {
        case 'E':
            std::cout << "Ε";
            break;
            
        case 'N':
            std::cout << "∅";
            break;
            
        case 'Z':
            std::cout << "0";
            break;
            
        case 'O':
            std::cout << "1";
            break;
            
        case 'U':
            std::cout << "(";
            leftOperand->printer();
            std::cout << " ∪ ";
            rightOperand->printer();
            std::cout << ")";
            break;
            
        case 'K':
            std::cout << "(";
            leftOperand->printer();
            std::cout << ")*";

            break;
            
        case 'C':
            std::cout << "(";
            leftOperand->printer();
            std::cout << " ° ";
            rightOperand->printer();
            std::cout << ")";
            break;
            
        default:
            std::cout << "something went wrong in printer switch";
            exit(1);
            break;
    }
};

void RE::printOutEquation(void){
    printer();
    std::cout << std::endl;
};

// If false, list = {-9999}
std::list<int> RE::generate(void){
    switch (type) {
        case 'E':
            return {};
            break;
            
        case 'N':
            return {-9999};
            break;
            
        case 'Z':
            return {0};
            break;
            
        case 'O':
            return {1};
            break;
            
        case 'U':
            if (rand() % 2) {
                return leftOperand->generate();
            } else {
                return rightOperand->generate();
            }
            break;
            
        case 'K':
//            RE temp('U',
            
            return RE('U',
                new RE('E'),
                new RE('C',
                    new RE(*leftOperand),
                    new RE('K', leftOperand)
                )
            ).generate();

//            return temp.generate();

            break;
            
        case 'C':
        {
            std::list<int> tempL = leftOperand->generate();
            std::list<int> tempR = rightOperand->generate();
            std::list<int> fail = {-9999};
            
//            A.insert(A.end(), B.begin(), B.end());
            if ((tempL != fail) && (tempR != fail)) {
                tempL.insert(tempL.end(), tempR.begin(), tempR.end());
                return tempL;
            } else {
                return fail;
            }
            
            break;
        }
            
        default:
            std::cout << "something went wrong in generate switch";
            exit(1);
            break;
    }
}

RE* RE::optimizer(){
    switch (type) {
        case 'E':
            return this;
            
        case 'N':
            return this;
            
        case 'Z':
            return this;

        case 'O':
            return this;

        case 'U':
        {
            RE* tempL = leftOperand->optimizer();
            RE* tempR = rightOperand->optimizer();

            if (tempL->type == 'N') {
                return tempR;
            } else if (tempR->type == 'N') {
                return tempL;
            }
            
            leftOperand = tempL;
            rightOperand = tempR;
            return this;
            
            break;
        }
            
        case 'K':
        {
            RE* tempL = leftOperand->optimizer();
            if ((tempL->type == 'N') || (tempL->type == 'E')) {
                return new RE('E');
            }
            leftOperand = tempL;
            return this;

            break;
        }
            
        case 'C':
        {
            RE* tempL = leftOperand->optimizer();
            RE* tempR = rightOperand->optimizer();
            
            if (tempL->type == 'N') {
                return tempL;
            } else if (tempR->type == 'N') {
                return tempR;
            }
            
            if (tempL->type == 'E') {
                return tempR;
            } else if (tempR->type == 'E') {
                return tempL;
            }
            
            leftOperand = tempL;
            rightOperand = tempR;
            return this;
            
            break;
        }
            
        default:
            std::cout << "something went wrong in optimizer switch";
            exit(1);
            break;
    }
}


void castEverythingToInt(RE re){
    switch (re.getType()) {
        case 'E':
            break;
            
        case 'N':
            elements.push(-9999);
            while(!elements.empty()){
                auto temp = elements.top();
                elements.pop();
                finalProduct.push(temp);
            }
            break;

        case 'Z':
            elements.push(0);
            while(!elements.empty()){
                auto temp = elements.top();
                elements.pop();
                finalProduct.push(temp);
            }
            break;

        case 'O':
            elements.push(1);
            while(!elements.empty()){
                auto temp = elements.top();
                elements.pop();
                finalProduct.push(temp);
            }
            break;

        case 'U':
            specialtyCounter.push(0);
            while(!elements.empty()){
                auto temp = elements.top();
                elements.pop();
                finalProduct.push(temp);
                finalProduct.push(temp);
            }
            break;
            
        case 'K':
            specialtyCounter.push(1);
            while(!elements.empty()){
                auto temp = elements.top();
                elements.pop();
                finalProduct.push(temp);
                finalProduct.push(temp);
            }
            break;

        case 'C':
            specialtyCounter.push(2);
            while(!elements.empty()){
                auto temp = elements.top();
                elements.pop();
                finalProduct.push(temp);
                finalProduct.push(temp);
            }
            break;

        default:
            break;
    }
}
