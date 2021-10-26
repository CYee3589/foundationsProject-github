//
//  foundationsProject
//
//  Task #1: A alphabet -> vector of ints (std::vector<int> alphabet)
//  Task #2: A string -> list of ints (std::list<int> string)

#include "permutations.hpp"
#include "DFA.hpp"
#include "DFA_Examples.hpp"
#include "DFA_testing.hpp"

#include <iostream>
#include <vector>
#include <list>

int main(int argc, const char * argv[]) {
    
        // All DFAs Used and their pass and fail cases
        //************************************************************
        // DFA Sample 1 - accepts only strings that start with "1"
        //************************************************************
        std::vector<std::list<int>> passCases1 {
            {1}, {1,0,1}, {1,1,1,1}, {1,0,0}, {1,1,0,0}, {1,0}
        };
        std::vector<std::list<int>> failCases1 {
            {0,0,0}, {0}, {}, {0,1,1}, {0,0,1,1}, {0,1,1,1}
        };
        DFA dfa1 = outputDFA1();
    

        //************************************************************
        // DFA Sample 2 - accepts only strings that end with "1"
        //************************************************************
        std::vector<std::list<int>> passCases2 {
            {1}, {1,0,1}, {1,1,1,1}, {0,0,1}, {0,0,0,1}, {1,1,0,0,1}
        };
        std::vector<std::list<int>> failCases2 {
            {1,1,0}, {1,0,0,0}, {}, {0,1,0,0}, {0,0,0,0}, {0,0,1,0}
        };
        DFA dfa2 = outputDFA2();
    
    
        //************************************************************
        // DFA Sample 3 - accepts only strings of all "0"
        //************************************************************
        std::vector<std::list<int>> passCases3 {
            {0}, {0,0}, {0,0,0}, {0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0,0,0,0,0}
        };
        std::vector<std::list<int>> failCases3 {
            {}, {1,0,0,0}, {0,0,1}, {1,1,1,1}, {0,0,1,0,0}, {1,0,0}
        };
        DFA dfa3 = outputDFA3();
    

        //************************************************************
        // DFA Sample 4 - accepts only strings with "01" in it
        //************************************************************
        std::vector<std::list<int>> passCases4 {
            {0,1}, {0,0,0,1}, {0,1,1}, {0,1,0,1}, {0,1,1,1,0}, {1,1,1,0,1}
        };
        std::vector<std::list<int>> failCases4 {
            {}, {1,0,0,0}, {0,0,0}, {1,1,1,1}, {1,0,0,0,0}, {1,1,0}
        };
        DFA dfa4 = outputDFA4();
    

        //************************************************************
        // DFA Sample 5 - accepts only strings with an odd number of 1s
        //************************************************************
        std::vector<std::list<int>> passCases5 {
            {0,1}, {0,0,0,1}, {1,1,1}, {0,1,0,1,0,1}, {0,1,1,1,0}, {0,1,1,0,1,0}
        };
        std::vector<std::list<int>> failCases5 {
            {}, {1,0,1,0}, {0,0,0,0}, {1,1,1,1}, {1,1,0,1,1}, {1,0,0,0,1}
        };
        DFA dfa5 = outputDFA5();
    

        //************************************************************
        // DFA Sample 6 - accepts only strings that starts with 1 and end with 1
        //************************************************************
        std::vector<std::list<int>> passCases6 {
            {1,1}, {1,0,0,1}, {1,1,1,1}, {1,0,1,0,1}, {1,1,1,0,1}, {1,0,1,0,1,0,1,1}
        };
        std::vector<std::list<int>> failCases6 {
            {}, {0,0,1,1}, {0,0,0,0}, {1,1,1,0}, {0,0,1,0,1}, {1,1,0,1,0}
        };
        DFA dfa6 = outputDFA6();
    
    
        //************************************************************
        // DFA Sample 7 - accepts only strings with an even number of 0s and 1s
        //************************************************************
        std::vector<std::list<int>> passCases7 {
            {1,1}, {0,0}, {}, {1,0,1,0,1,0,0,1}, {1,1,0,0,1,0,1,0}, {0,1,0,1,0,0}
        };
        std::vector<std::list<int>> failCases7 {
            {1}, {0,0,1}, {0}, {1,1,0,0,0}, {0,0,1,1,0}, {1,1,0,1,0}
        };
        DFA dfa7 = outputDFA7();
    

        //************************************************************
        // DFA Sample 8 - accepts the strings with an even number of leading 0's followed by single 1
        //************************************************************
        std::vector<std::list<int>> passCases8 {
            {0,0,1}, {1}, {0,0,0,0,0,0,1}, {0,0,0,0,1}, {0,0,0,0,0,0,0,0,1}, {0,0,0,0,0,0,0,0,0,0,1}
        };
        std::vector<std::list<int>> failCases8 {
            {0,1}, {0,0,1,1}, {1,0,0,1}, {0,0,0,0}, {0,0,0,1}, {1,1,1,1}
        };
        DFA dfa8 = outputDFA8();
    
    
        //************************************************************
        // DFA Sample 9 - accepting strings ending with ‘00’ over input alphabets
        //************************************************************
        std::vector<std::list<int>> passCases9 {
            {0,0}, {0,0,0}, {1,1,0,0}, {0,1,1,0,0}, {1,1,1,0,0}, {1,0,0,1,0,0}
        };
        std::vector<std::list<int>> failCases9 {
            {}, {1,0}, {0,1,0}, {1,1,0,0,1}, {0,1,1}, {1,1,1,0}
        };
        DFA dfa9 = outputDFA9();
    
    
        //************************************************************
        // DFA Sample 10 - accepting strings starting with ‘11’
        //************************************************************
        std::vector<std::list<int>> passCases10 {
            {1,1}, {1,1,1}, {1,1,0,0}, {1,1,0,1,0}, {1,1,0,0,1,1}, {1,1,0,1,1,0}
        };
        std::vector<std::list<int>> failCases10 {
            {}, {0,0}, {0,1,1}, {1,0,1,1,1}, {1,0,0}, {0,1,1,0}
        };
        DFA dfa10 = outputDFA10();
    

        //************************************************************
        // DFA Sample 11 - accepting strings over the length of 3
        //************************************************************
        std::vector<std::list<int>> passCases11 {
            {0,0,0,0}, {1,1,1,1}, {1,0,1,0,1}, {0,0,0,1,1}, {1,1,1,1,0,1}, {1,1,0,1,1,0,0,0,0}
        };
        std::vector<std::list<int>> failCases11 {
            {}, {0}, {0,1,1}, {1,0}, {1,1,1}, {1,1,0}
        };
        DFA dfa11 = outputDFA11();
    

        //************************************************************
        // DFA Sample 12 - accepting strings less or equal to the length of 3
        //************************************************************
        std::vector<std::list<int>> passCases12 {
            {}, {1}, {0}, {1,0,1}, {1,1}, {0,0,0}
        };
        std::vector<std::list<int>> failCases12 {
            {1,1,1,1}, {0,0,0,0}, {1,0,0,1,1,1}, {1,0,1,0,1}, {1,0,0,0,1}, {1,0,1,0,0}
        };
        DFA dfa12 = outputDFA12();
    
    
        //************************************************************
        // DFA Sample 13 - Accepts no strings
        //************************************************************
        DFA dfaNo = outputAcceptNoString(); // DFA that accepts no strings
    
    
        //************************************************************
        // DFA Sample 14 - Accepts only {1}
        //************************************************************
        DFA dfaOnly1 = generateOneCharDFA(1); // DFA that accepts only {1}
    
    
        //************************************************************
        // DFA Sample 15 - Accepts only {0}
        //************************************************************
        DFA dfaOnly0 = generateOneCharDFA(0); // DFA that accepts only {0}
    
    
        //*****************************
        // Added DFAs for Task 20-22
        //*****************************
        DFA dfa13 = outputDFA13(); // DFA Sample 13 - only accepts string odd number of charcters
        DFA dfa14 = outputDFA14(); // DFA Sample 14 - only accepts string even number of charcters
        DFA dfa15 = outputDFA15(); // DFA Sample 15 - only accepts string with a length of 1




    
    
   
    //********************************************************************************************************
    // Testing grounds for function "generateViableString" (task 12)
    //***********************************************************************************
    
    std::vector<bool> task12Pass{
        doesStringFollowDFA(dfa1, generateViableString(dfa1)),
        doesStringFollowDFA(dfa2, generateViableString(dfa2)),
        doesStringFollowDFA(dfa3, generateViableString(dfa3)),
        doesStringFollowDFA(dfa4, generateViableString(dfa4)),
        doesStringFollowDFA(dfa5, generateViableString(dfa5)),
        doesStringFollowDFA(dfa6, generateViableString(dfa6)),
        doesStringFollowDFA(dfa7, generateViableString(dfa7)),
        doesStringFollowDFA(dfa8, generateViableString(dfa8)),
        doesStringFollowDFA(dfa9, generateViableString(dfa9)),
        doesStringFollowDFA(dfa10, generateViableString(dfa10)),
        doesStringFollowDFA(dfa11, generateViableString(dfa11)),
        doesStringFollowDFA(dfa12, generateViableString(dfa12)),
    };

    std::vector<bool> task12Fail{
        doesStringFollowDFA(dfaNo, generateViableString(dfaNo)),
    };
    
    boolCounter(task12Pass);
    boolCounter(task12Fail);
    
//********************************************************************************************************
    
    // Testing grounds for function "complement" (task 13)
    //***********************************************************************************
    testingDFA(generateComplement(dfa1), 1, failCases1, passCases1);
    testingDFA(generateComplement(dfa1), 2, passCases1, failCases1);
    
    testingDFA(generateComplement(dfa2), 3, failCases2, passCases2);
    testingDFA(generateComplement(dfa2), 4, passCases2, failCases2);
    
    testingDFA(generateComplement(dfa3), 5, failCases3, passCases3);
    testingDFA(generateComplement(dfa3), 6, passCases3, failCases3);
    
    testingDFA(generateComplement(dfa4), 7, failCases4, passCases4);
    testingDFA(generateComplement(dfa4), 8, passCases4, failCases4);
    
    testingDFA(generateComplement(dfa5), 9, failCases5, passCases5);
    testingDFA(generateComplement(dfa5), 10, passCases5, failCases5);
    
    testingDFA(generateComplement(dfa6), 11, failCases6, passCases6);
    testingDFA(generateComplement(dfa6), 12, passCases6, failCases6);
    
    
//********************************************************************************************************
        
    // Testing grounds for function "generateUnion" (task 14-15)
    //***********************************************************************************
    
    // Union 1 + 2: accepts strings that start with "1" or strings that end with "1"
    std::vector<std::list<int>> failCasesU1 {
        {}, {0}, {0,1,1,0}, {0,1,0,0}, {0,1,0,0}, {0,1,0,1,0}
    };
    testingDFA(generateUnion(dfa1, dfa2), 1, combine2Vectors(passCases1, passCases2), failCasesU1);
    
    
    // Union 7 + 8: accepts strings with an even number of 0s or 1s and strings with an even number of leading 0's followed by single 1
    std::vector<std::list<int>> failCasesU2 {
        {0,0,0,1}, {0}, {0,1,0}, {0,1,0,1,0}, {0,1,1,1,1,1}, {0,1,0,1,0}
    };
    testingDFA(generateUnion(dfa7, dfa8), 2, combine2Vectors(passCases7, passCases8), failCasesU2);
    
    
    // Union 1 + 5: accepts strings that start with "1" or strings with an odd number of 1s
    std::vector<std::list<int>> failCasesU3 {
        {0,0,0}, {}, {0,1,1}, {0,1,0,1,1,0,1}, {0,1,0,1,0}, {0,1,1,0,1,1}
    };
    testingDFA(generateUnion(dfa1, dfa5), 3, combine2Vectors(passCases1, passCases5), failCasesU3);
    
    
    // Union 10 + 11: accepts strings starting with ‘11’ or strings over the length of 3
    std::vector<std::list<int>> failCasesU4 {
        {0,1}, {}, {0,0,1}, {1,0,0}, {1}, {1,0,1}
    };
    testingDFA(generateUnion(dfa10, dfa11), 4, combine2Vectors(passCases10, passCases11), failCasesU4);
    
    
    // Union 5 + 9: accepts only strings with an odd number of 1s or strings ending with ‘00’ over input alphabets
    std::vector<std::list<int>> failCasesU5 {
        {1,0,0,1}, {}, {0,0,1,1,0}, {1,0,1}, {1,0,1,1,1,0}, {1,0,1}
    };
    testingDFA(generateUnion(dfa5, dfa9), 5, combine2Vectors(passCases5, passCases9), failCasesU5);
    
    
    // Union 3 + 4: accepts only strings of all "0" or strings with "01" in it
    std::vector<std::list<int>> failCasesU6 {
        {1,0,0}, {}, {1,0}, {1,0,0,0,0,0}, {1,1,1,1}, {1,1,1,1,0,0}
    };
    testingDFA(generateUnion(dfa3, dfa4), 6, combine2Vectors(passCases3, passCases4), failCasesU6);
    
    
    // Union 6 + 8: accepts only strings that starts with 1 and end with 1 or strings with an even number of leading 0's followed by single 1
    std::vector<std::list<int>> failCasesU7 {
        {1,0,0}, {0,0,0,1}, {1,1,0}, {0,0,0,0,0,1}, {1,1,1,0}, {0,1}
    };
    testingDFA(generateUnion(dfa6, dfa8), 7, combine2Vectors(passCases6, passCases8), failCasesU7);
    
    
    // Union 3 + 9: accepts only strings of all "0" or strings ending with ‘00’ over input alphabets
    std::vector<std::list<int>> failCasesU8 {
        {1,0}, {0,1}, {1,1,0}, {0,0,0,1}, {1,1,1,0}, {0,1,1}
    };
    testingDFA(generateUnion(dfa3, dfa9), 8, combine2Vectors(passCases3, passCases9), failCasesU8);
    
    
    // Union 2 + 6: accepts only strings that end with "1" or strings that start and end with "1"
    std::vector<std::list<int>> failCasesU9 {
        {1,0,1,0}, {1,1,1,0,1,0}, {0,0,0}, {}, {1,0,1,0}, {1,1,1,1,0}
    };
    testingDFA(generateUnion(dfa2, dfa6), 9, combine2Vectors(passCases2, passCases6), failCasesU9);
    
    
    // Union 7 + 12: accepts only strings with an even number of 0s and 1s or strings less or equal to the length of 3
    std::vector<std::list<int>> failCasesU10 {
        {1,0,1,0,1}, {1,1,0,0,1,0}, {0,0,0,0,0}, {1,1,1,1,1,0}, {1,1,0,0,0}, {1,0,1,1}
    };
    testingDFA(generateUnion(dfa7, dfa12), 10, combine2Vectors(passCases7, passCases12), failCasesU10);
    
    
    // Union 4 + 5: accepts only strings with "01" in it or strings with an odd number of 1s
    std::vector<std::list<int>> failCasesU11 {
        {1,1}, {1,1,0}, {}, {1,1,1,1,0}, {0,0,0}, {1,1,0}
    };
    testingDFA(generateUnion(dfa4, dfa5), 11, combine2Vectors(passCases4, passCases5), failCasesU11);
    
    
    // Union 8 + 10: accepts the strings with an even number of leading 0's followed by single 1 or strings starting with ‘11’
    std::vector<std::list<int>> failCasesU12 {
        {0,0,0}, {1,0}, {}, {0,0,0,1,1}, {1,0,0,1}, {0}
    };
    testingDFA(generateUnion(dfa8, dfa10), 12, combine2Vectors(passCases8, passCases10), failCasesU12);
    
    
//********************************************************************************************************
        
    // Testing grounds for function "generateIntercept" (task 16-17)
    //***********************************************************************************
    
    // Intercept 1 + 2: accepts strings that start with "1" and end with "1"
    std::vector<std::list<int>> passCasesI1 {
        {1,1}, {1,0,1}, {1,1,1}, {1,0,1,1}, {1,0,1,0,1}, {1,0,0,0,1,1}
    };
    testingDFA(generateIntercept(dfa1, dfa2), 1, passCasesI1, combine2Vectors(failCases1, failCases2));
    

    // Intercept 2 + 11: accepts only strings that ends with 1 and has over a length of 3
    std::vector<std::list<int>> passCasesI2 {
        {0,0,0,1}, {1,1,1,1}, {1,0,1,0,1}, {0,1,1,1}, {0,0,0,0,0,0,0,0,0,0,1}, {1,1,0,0,1,1}
    };
    testingDFA(generateIntercept(dfa2, dfa11), 2, passCasesI2, combine2Vectors(failCases2, failCases11));

    
    // Intercept 1 + 5: accepts strings that start with "1" and has an odd number of 1s
    std::vector<std::list<int>> passCasesI3 {
        {1}, {1,1,1}, {1,1,1,1,1}, {1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1,1,1,1}
    };
    testingDFA(generateIntercept(dfa1, dfa5), 3, passCasesI3, combine2Vectors(failCases1, failCases5));
    

    // Intercept 10 + 11: accepts strings starting with ‘11’ and over the length of 3
    std::vector<std::list<int>> passCasesI4 {
        {1,1,1,1}, {1,1,0,0}, {1,1,0,0,1}, {1,1,0,0,1,0}, {1,1,0,1,0}, {1,1,1,1,0,0}
    };
    testingDFA(generateIntercept(dfa10, dfa11), 4, passCasesI4, combine2Vectors(failCases10, failCases11));
    
    
    // Intercept 5 + 9: accepts only strings with an odd number of 1s and ends with ‘00’ over input alphabets
    std::vector<std::list<int>> passCasesI5 {
        {1,0,0}, {0,1,0,0}, {1,1,0,1,0,0}, {0,0,1,0,0}, {1,1,1,0,0}, {1,0,1,1,0,0}
    };
    testingDFA(generateIntercept(dfa5, dfa9), 5, passCasesI5, combine2Vectors(failCases5, failCases9));
    

    // Intercept 9 + 10: accepts only strings that start with "11" and end "00" over inputed alphabets
    std::vector<std::list<int>> passCasesI6 {
        {1,1,0,0}, {1,1,0,1,0,0}, {1,1,1,1,0,0}, {1,1,0,0,1,1,0,0}, {1,1,0,0,0}, {1,1,1,1,0,0}
    };
    testingDFA(generateIntercept(dfa9, dfa10), 6, passCasesI6, combine2Vectors(failCases9, failCases10));
    

    // Intercept 7 + 9 - accepts only strings with an even number of 0s and 1 while ending with ‘00’ over input alphabets
    std::vector<std::list<int>> passCasesI7 {
        {1,1,0,0}, {1,1,1,1,0,0}, {1,1,0,0}, {0,0,0,0,0,0}, {1,1,1,1,0,0}, {0,0}
    };
    testingDFA(generateIntercept(dfa7, dfa9), 7, passCasesI7, combine2Vectors(failCases7, failCases9));

    
    // Intercept 3 + 9: accepts only strings of all "0" and ends with ‘00’ over input alphabets
    std::vector<std::list<int>> passCasesI8 {
        {0,0}, {0,0,0}, {0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0,0}, {0,0,0,0,0,0,0}
    };
    testingDFA(generateIntercept(dfa3, dfa9), 8, passCasesI8, combine2Vectors(failCases3, failCases9));


    // Intercept 2 + 6: accepts only strings that start and end with "1"
    std::vector<std::list<int>> passCasesI9 {
        {1,0,1,1}, {1,1}, {1,0,1,0,1}, {1,1,1,1,1,1}, {1,0,0,1}, {1,0,1,1,0,1}
    };
    testingDFA(generateIntercept(dfa2, dfa6), 9, passCasesI9, combine2Vectors(failCases2, failCases6));

    
    // Intercept 7 + 12: accepts only strings with an even number of 0s and 1s and have a length less or equal to 3
    std::vector<std::list<int>> passCasesI10 {
        {}, {1,1}, {0,0}
    };
    testingDFA(generateIntercept(dfa7, dfa12), 10, passCasesI10, combine2Vectors(failCases7, failCases12));


    // Intercept 4 + 5: accepts only strings with "01" in it and have an odd number of 1s
    std::vector<std::list<int>> passCasesI11 {
        {0,1}, {0,1,0,1,1}, {1,1,1,1,1,1,0,1}, {0,0,0,1,1,1}, {0,1,0,1,0,1}, {1,0,1,1}
    };
    testingDFA(generateIntercept(dfa4, dfa5), 11, passCasesI11, combine2Vectors(failCases4, failCases5));

    
    // Intercept 2 + 10: accepts the strings ending with '1' and  starting with ‘11’
    std::vector<std::list<int>> passCasesI12 {
        {1,1,1}, {1,1,1,1,1}, {1,1,0,1,0,1}, {1,1,0,0,1,1}, {1,1,0,0,0,0,1}, {1,1,1,0,0,0,1,1}
    };
    testingDFA(generateIntercept(dfa2, dfa10), 12, passCasesI12, combine2Vectors(failCases2, failCases10));
    
//********************************************************************************************************
        
    // Testing grounds for function "isASubsetOfB" (task 18-19)
    //***********************************************************************************
    // DFA Sample 1 - accepts only strings that start with "1"
    // DFA Sample 2 - accepts only strings that end with "1"
    // DFA Sample 3 - accepts only strings of all "0"
    // DFA Sample 4 - accepts only strings with "01" in it
    // DFA Sample 5 - accepts only strings with an odd number of 1s
    // DFA Sample 6 - accepts only strings that starts with 1 and end with 1
    // DFA Sample 7 - accepts only strings with an even number of 0s and 1s
    // DFA Sample 8 - accepts the strings with an even number of leading 0's followed by single 1
    // DFA Sample 9 - accepting strings ending with ‘00’ over input alphabets
    // DFA Sample 10 - accepting strings starting with ‘11’
    // DFA Sample 11 - accepting strings over the length of 3
    // DFA Sample 12 - accepting strings less or equal to the length of 3
    // DFA Sample Only1 - Accepts only {1}
    // DFA Sample Only0 - Accepts only {0}
    
    std::vector<bool> task19Pass{
        isASubsetOfB(dfa10, dfa1),
        isASubsetOfB(dfa8, dfa2),
        isASubsetOfB(dfa6, dfa2),
        isASubsetOfB(dfaOnly1, dfa1),
        isASubsetOfB(dfaOnly1, dfa12),
        isASubsetOfB(dfaOnly0, dfa3)
    };
    
    std::vector<bool> task19Fail{
        isASubsetOfB(dfa1, dfa2),
        isASubsetOfB(dfa3, dfa4),
        isASubsetOfB(dfa5, dfa6),
        isASubsetOfB(dfa7, dfa8),
        isASubsetOfB(dfa9, dfa10),
        isASubsetOfB(dfa11, dfa12)
    };
    
    boolCounter(task19Pass);
    boolCounter(task19Fail);

    
//********************************************************************************************************
            
    // Testing grounds for function "isAEqualityOfB" (task 20-22)
    //***********************************************************************************
    // DFA Sample 1 - accepts only strings that start with "1"
    // DFA Sample 2 - accepts only strings that end with "1"
    // DFA Sample 3 - accepts only strings of all "0"
    // DFA Sample 4 - accepts only strings with "01" in it
    // DFA Sample 5 - accepts only strings with an odd number of 1s
    // DFA Sample 6 - accepts only strings that starts with 1 and end with 1
    // DFA Sample 7 - accepts only strings with an even number of 0s and 1s
    // DFA Sample 8 - accepts the strings with an even number of leading 0's followed by single 1
    // DFA Sample 9 - accepting strings ending with ‘00’ over input alphabets
    // DFA Sample 10 - accepting strings starting with ‘11’
    // DFA Sample 11 - accepting strings over the length of 3
    // DFA Sample 12 - accepting strings less or equal to the length of 3
    // DFA Sample 13 - only accepts string odd number of charcters
    // DFA Sample 14 - only accepts string even number of charcters
    // DFA Sample 15 - only accepts string with a length of 1
    // DFA Sample Only1 - Accepts only {1}
    // DFA Sample Only0 - Accepts only {0}
    
    
    std::vector<bool> task22Pass{
        // These two are mirror cases
        isAEqualityOfB(dfa1, dfa1),
        isAEqualityOfB(dfa8, dfa8),
        
        // These two use union
        isAEqualityOfB(generateUnion(dfaOnly0, dfaOnly1), dfa15),
        isAEqualityOfB(generateIntercept(generateUnion(dfa13, dfa14), dfa12), dfa12),
        
        // These two use complement
        isAEqualityOfB(generateComplement(dfa11), dfa12),
        isAEqualityOfB(generateComplement(dfa13), dfa14),

        // These two use intresect
        isAEqualityOfB(generateIntercept(dfa13, dfa14), dfaNo),
        isAEqualityOfB(generateIntercept(dfa15, generateComplement(dfa3)), dfaOnly1)
    };
    
    std::vector<bool> task22Fail{
        isAEqualityOfB(dfa10, dfa11),
        isAEqualityOfB(dfa1, dfa2),
        isAEqualityOfB(dfa3, dfa4),
        isAEqualityOfB(dfa5, dfa6),

    };
    
    boolCounter(task22Pass);
    boolCounter(task22Fail);
    


    return 0;
}

