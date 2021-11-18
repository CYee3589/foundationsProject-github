//
//  foundationsProject
//
//  Task #1: A alphabet -> vector of ints (std::vector<int> alphabet)
//  Task #2: A string -> list of ints (std::list<int> string)

#include "permutations.hpp"
#include "DFA.hpp"
#include "DFA_Examples.hpp"
#include "DFA_testing.hpp"
#include "NFA.hpp"
#include "NFA_examples.hpp"
#include "NFA_testing.hpp"

#include <iostream>
#include <vector>
#include <list>

int main(int argc, const char * argv[]) {
    
        // All NFAs Used
        //************************************************************
        // NFA Sample 1 - Accepts all strings with the third element from the right being "1"
        //************************************************************
        NFA nfa1 = outputNFA1();

    
        // NFA Sample 2 - Accepts all strings ending with "01"
        //************************************************************
        NFA nfa2 = outputNFA2();
    
    
        // NFA Sample 3 - Accepts strings with a double "1" followed by a double "0" (1100) in it
        //************************************************************
        NFA nfa3 = outputNFA3();


        // DFA Sample 4 - Accepts strings with the third element from the right being "0"
        //************************************************************
        NFA nfa4 = outputNFA4();


        // DFA Sample 5 - Accepts strings either with odd 1s or even 0s
        //************************************************************
        NFA nfa5 = outputNFA5();

    
        // DFA Sample 6 - Accepts strings only ending with "11" or "00"
        //************************************************************
        NFA nfa6 = outputNFA6();
    
    
        // DFA Sample 7 - Accepts strings with a length of 2 or 4
        //************************************************************
        NFA nfa7 = outputNFA7();


        // DFA Sample 8 - Accepts strings either ending in 0 or has all "1"s
        //************************************************************
        NFA nfa8 = outputNFA8();

    
        // DFA Sample 9 - Accepts strings that start with 1 and either ends in 0 or has a length of 4
        //************************************************************
        NFA nfa9 = outputNFA9();

    
        // DFA Sample 10 - NFA = DFA Sample 4: accepts only strings with "01" in it
        //************************************************************
        NFA nfa10 = outputNFA10();


        // DFA Sample 11 - NFA = DFA Sample 10: accepting strings starting with ‘11’
        //************************************************************
        NFA nfa11 = outputNFA11();


        // DFA Sample 12 - NFA = DFA Sample 14: accepts only strings beginning and ending with "1"
        //************************************************************
        NFA nfa12 = outputNFA12();
    
   
    //********************************************************************************************************
    // Initializing NFA and "Oracle" (task 23-27)
    //***********************************************************************************
    
    std::vector<bool> task27Pass{
        Oracle(nfa1, {0,1,1,1}, NFA1trace2, true),
        Oracle(nfa2, {0,0,1}, NFA2trace3, true),
        Oracle(nfa3, {0,1,0,1,1,0,0}, NFA3trace4, true),
        Oracle(nfa4, {0,0,1}, NFA4trace1, true),
        Oracle(nfa5, {1,1,1}, NFA5trace1, true),
        Oracle(nfa6, {1,1,0,0}, NFA6trace3, true),
        Oracle(nfa7, {0,1,1,1}, NFA7trace10, true),
        Oracle(nfa8, {0,0,0,0}, NFA8trace1, true),
        Oracle(nfa9, {1,0,1,1}, NFA9trace2, true),
        Oracle(nfa10, {1,0,0,1}, NFA10trace3, true),
        Oracle(nfa11, {1,0,1}, NFA11trace1, true),
        Oracle(nfa12, {1,1}, NFA12trace1, true),
    };

    std::vector<bool> task27Fail{
        Oracle(nfa1, {0,1,1,3}, NFA1trace4, false),
        Oracle(nfa2, {0,0,1}, NFA2trace3, false),
        Oracle(nfa3, {0,1,0,1,1,0,0}, NFA3trace4, false),
        Oracle(nfa4, {0,0,1}, NFA4trace1, false),
        Oracle(nfa5, {1,1,1}, NFA5trace1, false),
        Oracle(nfa6, {1,1,0,3}, NFA6trace3, false),
        Oracle(nfa7, {0,1,1,1}, NFA7trace10, false),
        Oracle(nfa8, {0,3,0,0}, NFA8trace1, false),
        Oracle(nfa9, {1,0,1,1}, NFA9trace2, false),
        Oracle(nfa10, {0,0,0,1}, NFA10trace3, false),
        Oracle(nfa11, {1,0,1}, NFA11trace1, false),
        Oracle(nfa12, {1,1}, NFA12trace1, false),
    };


    boolCounter(task27Pass);
    boolCounter(task27Fail);

     
    
    //********************************************************************************************************
    // Initializing Trace trees and "Forking" (task 28-31)
    //***********************************************************************************
    
    std::list<traceTreeBranch<int>> answer = Forking(nfa1, {0,1,1,0,0});
    printTraceTree(answer);
    
    
    std::vector<bool> task31Pass{
        // NFA1 forks
        doTraceTreesEqual(Forking(nfa1, {1,0,0}), NFA1traceTree1),
        doTraceTreesEqual(Forking(nfa1, {1,0}), NFA1traceTree2),
        doTraceTreesEqual(Forking(nfa1, {0,1,0,0}), NFA1traceTree3),
        doTraceTreesEqual(Forking(nfa1, {0,0,1}), NFA1traceTree4),
        doTraceTreesEqual(Forking(nfa1, {1,1,0,0}), NFA1traceTree5),
        doTraceTreesEqual(Forking(nfa1, {1,1}), NFA1traceTree6),
        doTraceTreesEqual(Forking(nfa1, {1,0}), Forking(nfa1, {1,0})),
        doTraceTreesEqual(Forking(nfa1, {1,0,0}), Forking(nfa1, {1,0,0})),
        doTraceTreesEqual(Forking(nfa1, {0,1}), Forking(nfa1, {0,1})),
        doTraceTreesEqual(Forking(nfa1, {1,0,0}), Forking(nfa1, {1,0,0})),
        doTraceTreesEqual(Forking(nfa1, {1,1,1,1}), Forking(nfa1, {1,1,1,1})),
        doTraceTreesEqual(Forking(nfa1, {1,1,1}), Forking(nfa1, {1,1,1})),

        // NFA2 forks
        doTraceTreesEqual(Forking(nfa2, {1,0,1}), NFA2traceTree1),
        doTraceTreesEqual(Forking(nfa2, {0,1}), NFA2traceTree2),
        doTraceTreesEqual(Forking(nfa2, {1,1,1,1}), NFA2traceTree3),
        doTraceTreesEqual(Forking(nfa2, {1,0,0,1}), NFA2traceTree4),
        doTraceTreesEqual(Forking(nfa2, {0,0}), NFA2traceTree5),
        doTraceTreesEqual(Forking(nfa2, {1,1,1}), NFA2traceTree6),
        doTraceTreesEqual(Forking(nfa2, {1,0}), Forking(nfa2, {1,0})),
        doTraceTreesEqual(Forking(nfa2, {0,1,1}), Forking(nfa2, {0,1,1})),
        doTraceTreesEqual(Forking(nfa2, {1,0}), Forking(nfa2, {1,0})),
        doTraceTreesEqual(Forking(nfa2, {0,0,1}), Forking(nfa2, {0,0,1})),
        doTraceTreesEqual(Forking(nfa2, {1,1,1}), Forking(nfa2, {1,1,1})),
        doTraceTreesEqual(Forking(nfa2, {0,1}), Forking(nfa2, {0,1})),

        // NFA3 forks
        doTraceTreesEqual(Forking(nfa3, {1,1,0,0}), NFA3traceTree1),
        doTraceTreesEqual(Forking(nfa3, {1,1,0}), NFA3traceTree2),
        doTraceTreesEqual(Forking(nfa3, {0,0}), NFA3traceTree3),
        doTraceTreesEqual(Forking(nfa3, {1,1,1,0,0}), NFA3traceTree4),
        doTraceTreesEqual(Forking(nfa3, {0,1,0}), NFA3traceTree5),
        doTraceTreesEqual(Forking(nfa3, {1,0,1,0}), NFA3traceTree6),
        doTraceTreesEqual(Forking(nfa3, {0,0,1}), Forking(nfa3, {0,0,1})),
        doTraceTreesEqual(Forking(nfa3, {1,0,1,1}), Forking(nfa3, {1,0,1,1})),
        doTraceTreesEqual(Forking(nfa3, {1,1,1}), Forking(nfa3, {1,1,1})),
        doTraceTreesEqual(Forking(nfa3, {1,0,1,0}), Forking(nfa3, {1,0,1,0})),
        doTraceTreesEqual(Forking(nfa3, {1,0}), Forking(nfa3, {1,0})),
        doTraceTreesEqual(Forking(nfa3, {1,0,1,0}), Forking(nfa3, {1,0,1,0})),

        // NFA4 forks
        doTraceTreesEqual(Forking(nfa4, {0,1,0}), NFA4traceTree1),
        doTraceTreesEqual(Forking(nfa4, {0,0,0}), NFA4traceTree2),
        doTraceTreesEqual(Forking(nfa4, {1,1,1}), NFA4traceTree3),
        doTraceTreesEqual(Forking(nfa4, {1,1,0,1}), NFA4traceTree4),
        doTraceTreesEqual(Forking(nfa4, {0,0}), NFA4traceTree5),
        doTraceTreesEqual(Forking(nfa4, {0,1,1}), NFA4traceTree6),
        doTraceTreesEqual(Forking(nfa4, {1,0,1}), Forking(nfa4, {1,0,1})),
        doTraceTreesEqual(Forking(nfa4, {0,1,1,1,1}), Forking(nfa4, {0,1,1,1,1})),
        doTraceTreesEqual(Forking(nfa4, {0,1,0,1}), Forking(nfa4, {0,1,0,1})),
        doTraceTreesEqual(Forking(nfa4, {0,0,0,1}), Forking(nfa4, {0,0,0,1})),
        doTraceTreesEqual(Forking(nfa4, {0,1,0,1,1}), Forking(nfa4, {0,1,0,1,1})),
        doTraceTreesEqual(Forking(nfa4, {1,1,0,1,1}), Forking(nfa4, {1,1,0,1,1})),

        // NFA5 forks
        doTraceTreesEqual(Forking(nfa5, {1,0,1}), NFA5traceTree1),
        doTraceTreesEqual(Forking(nfa5, {0,0}), NFA5traceTree2),
        doTraceTreesEqual(Forking(nfa5, {1}), NFA5traceTree3),
        doTraceTreesEqual(Forking(nfa5, {1,1}), NFA5traceTree4),
        doTraceTreesEqual(Forking(nfa5, {1,0,0}), NFA5traceTree5),
        doTraceTreesEqual(Forking(nfa5, {1,1,0}), NFA5traceTree6),
        doTraceTreesEqual(Forking(nfa5, {1,0,1,0}), Forking(nfa5, {1,0,1,0})),
        doTraceTreesEqual(Forking(nfa5, {0,1,1,0}), Forking(nfa5, {0,1,1,0})),
        doTraceTreesEqual(Forking(nfa5, {1,0}), Forking(nfa5, {1,0})),
        doTraceTreesEqual(Forking(nfa5, {1,1,0,1}), Forking(nfa5, {1,1,0,1})),
        doTraceTreesEqual(Forking(nfa5, {1,1,1,0}), Forking(nfa5, {1,1,1,0})),
        doTraceTreesEqual(Forking(nfa5, {1,1,1}), Forking(nfa5, {1,1,1})),

        // NFA6 forks
        doTraceTreesEqual(Forking(nfa6, {1,1}), NFA6traceTree1),
        doTraceTreesEqual(Forking(nfa6, {0,0}), NFA6traceTree2),
        doTraceTreesEqual(Forking(nfa6, {1,0,0}), NFA6traceTree3),
        doTraceTreesEqual(Forking(nfa6, {0,1,1}), NFA6traceTree4),
        doTraceTreesEqual(Forking(nfa6, {0,1}), NFA6traceTree5),
        doTraceTreesEqual(Forking(nfa6, {1,0}), NFA6traceTree6),
        doTraceTreesEqual(Forking(nfa6, {1,0,0,1}), Forking(nfa6, {1,0,0,1})),
        doTraceTreesEqual(Forking(nfa6, {1,1,0,1}), Forking(nfa6, {1,1,0,1})),
        doTraceTreesEqual(Forking(nfa6, {0,0,1}), Forking(nfa6, {0,0,1})),
        doTraceTreesEqual(Forking(nfa6, {0}), Forking(nfa6, {0})),
        doTraceTreesEqual(Forking(nfa6, {1}), Forking(nfa6, {1})),
        doTraceTreesEqual(Forking(nfa6, {1,1,0}), Forking(nfa6, {1,1,0})),
        
        // NFA7 forks
        doTraceTreesEqual(Forking(nfa7, {1,0}), NFA7traceTree1),
        doTraceTreesEqual(Forking(nfa7, {0,0}), NFA7traceTree2),
        doTraceTreesEqual(Forking(nfa7, {1,1,1,0}), NFA7traceTree3),
        doTraceTreesEqual(Forking(nfa7, {0,1,0,0}), NFA7traceTree4),
        doTraceTreesEqual(Forking(nfa7, {1,1,0}), NFA7traceTree5),
        doTraceTreesEqual(Forking(nfa7, {1}), NFA7traceTree6),
        doTraceTreesEqual(Forking(nfa7, {0,1,1,0}), Forking(nfa7, {0,1,1,0})),
        doTraceTreesEqual(Forking(nfa7, {1,0,1}), Forking(nfa7, {1,0,1})),
        doTraceTreesEqual(Forking(nfa7, {1,0,1,1}), Forking(nfa7, {1,0,1,1})),
        doTraceTreesEqual(Forking(nfa7, {0,0}), Forking(nfa7, {0,0})),
        doTraceTreesEqual(Forking(nfa7, {1,1,1}), Forking(nfa7, {1,1,1})),
        doTraceTreesEqual(Forking(nfa7, {0,1,0,0}), Forking(nfa7, {0,1,0,0})),

        // NFA8 forks
        doTraceTreesEqual(Forking(nfa8, {1,1}), NFA8traceTree1),
        doTraceTreesEqual(Forking(nfa8, {1,1,0}), NFA8traceTree2),
        doTraceTreesEqual(Forking(nfa8, {1,1,1,1}), NFA8traceTree3),
        doTraceTreesEqual(Forking(nfa8, {0}), NFA8traceTree4),
        doTraceTreesEqual(Forking(nfa8, {1,0}), NFA8traceTree5),
        doTraceTreesEqual(Forking(nfa8, {1,0,1}), NFA8traceTree6),
        doTraceTreesEqual(Forking(nfa8, {1,0,0}), Forking(nfa8, {1,0,0})),
        doTraceTreesEqual(Forking(nfa8, {1,1,1,1}), Forking(nfa8, {1,1,1,1})),
        doTraceTreesEqual(Forking(nfa8, {1,0,0,1}), Forking(nfa8, {1,0,0,1})),
        doTraceTreesEqual(Forking(nfa8, {0,0,0}), Forking(nfa8, {0,0,0})),
        doTraceTreesEqual(Forking(nfa8, {1,1,0}), Forking(nfa8, {1,1,0})),
        doTraceTreesEqual(Forking(nfa8, {0,1,1}), Forking(nfa8, {0,1,1})),

        // NFA9 forks
        doTraceTreesEqual(Forking(nfa9, {1,0,1}), NFA9traceTree1),
        doTraceTreesEqual(Forking(nfa9, {0}), NFA9traceTree2),
        doTraceTreesEqual(Forking(nfa9, {1,1,1}), NFA9traceTree3),
        doTraceTreesEqual(Forking(nfa9, {1,1,1,1}), NFA9traceTree4),
        doTraceTreesEqual(Forking(nfa9, {1,0,0}), NFA9traceTree5),
        doTraceTreesEqual(Forking(nfa9, {1,1,0,0}), NFA9traceTree6),
        doTraceTreesEqual(Forking(nfa9, {1,0}), Forking(nfa9, {1,0})),
        doTraceTreesEqual(Forking(nfa9, {1,1,0}), Forking(nfa9, {1,1,0})),
        doTraceTreesEqual(Forking(nfa9, {1,1}), Forking(nfa9, {1,1})),
        doTraceTreesEqual(Forking(nfa9, {1,0,1,1}), Forking(nfa9, {1,0,1,1})),
        doTraceTreesEqual(Forking(nfa9, {1,0,0,0}), Forking(nfa9, {1,0,0,0})),
        doTraceTreesEqual(Forking(nfa9, {1,0,1,1,1}), Forking(nfa9, {1,0,1,1,1})),

        // NFA10 forks
        doTraceTreesEqual(Forking(nfa10, {0,1,0}), NFA10traceTree1),
        doTraceTreesEqual(Forking(nfa10, {0,0,1,0}), NFA10traceTree2),
        doTraceTreesEqual(Forking(nfa10, {1,0}), NFA10traceTree3),
        doTraceTreesEqual(Forking(nfa10, {1,1,0,0}), NFA10traceTree4),
        doTraceTreesEqual(Forking(nfa10, {1,0,0,1}), NFA10traceTree5),
        doTraceTreesEqual(Forking(nfa10, {1,1,1}), NFA10traceTree6),
        doTraceTreesEqual(Forking(nfa10, {0,0}), Forking(nfa10, {0,0})),
        doTraceTreesEqual(Forking(nfa10, {0,0,1}), Forking(nfa10, {0,0,1})),
        doTraceTreesEqual(Forking(nfa10, {1,1,1,0}), Forking(nfa10, {1,1,1,0})),
        doTraceTreesEqual(Forking(nfa10, {0,1,0,1,0}), Forking(nfa10, {0,1,0,1,0})),
        doTraceTreesEqual(Forking(nfa10, {1,1,1,0,0}), Forking(nfa10, {1,1,1,0,0})),
        doTraceTreesEqual(Forking(nfa10, {1,1,0}), Forking(nfa10, {1,1,0})),

        // NFA11 forks
        doTraceTreesEqual(Forking(nfa11, {1,1,0}), NFA11traceTree1),
        doTraceTreesEqual(Forking(nfa11, {0,1,1,0}), NFA11traceTree2),
        doTraceTreesEqual(Forking(nfa11, {1,0,1,1}), NFA11traceTree3),
        doTraceTreesEqual(Forking(nfa11, {1,1,1}), NFA11traceTree4),
        doTraceTreesEqual(Forking(nfa11, {1,1,0,1,1}), NFA11traceTree5),
        doTraceTreesEqual(Forking(nfa11, {1,1}), NFA11traceTree6),
        doTraceTreesEqual(Forking(nfa11, {1,0,0}), Forking(nfa11, {1,0,0})),
        doTraceTreesEqual(Forking(nfa11, {1,1,0,1}), Forking(nfa11, {1,1,0,1})),
        doTraceTreesEqual(Forking(nfa11, {0,1,1,1,0}), Forking(nfa11, {0,1,1,1,0})),
        doTraceTreesEqual(Forking(nfa11, {0,0}), Forking(nfa11, {0,0})),
        doTraceTreesEqual(Forking(nfa11, {0,1,1}), Forking(nfa11, {0,1,1})),
        doTraceTreesEqual(Forking(nfa11, {1,0,0,1}), Forking(nfa11, {1,0,0,1})),
 
        // NFA12 forks
        doTraceTreesEqual(Forking(nfa12, {0,1}), NFA12traceTree1 ),
        doTraceTreesEqual(Forking(nfa12, {1,1,1,1}), NFA12traceTree2 ),
        doTraceTreesEqual(Forking(nfa12, {1,0,0,0,1}), NFA12traceTree3 ),
        doTraceTreesEqual(Forking(nfa12, {1,1,1,0}), NFA12traceTree4 ),
        doTraceTreesEqual(Forking(nfa12, {1,0,1,0,1}), NFA12traceTree5 ),
        doTraceTreesEqual(Forking(nfa12, {0,0,1}), NFA12traceTree6 ),
        doTraceTreesEqual(Forking(nfa12, {1,0}), Forking(nfa12, {1,0}) ),
        doTraceTreesEqual(Forking(nfa12, {0,1,1,0}), Forking(nfa12, {0,1,1,0}) ),
        doTraceTreesEqual(Forking(nfa12, {0,1,1}), Forking(nfa12, {0,1,1}) ),
        doTraceTreesEqual(Forking(nfa12, {1,1}), Forking(nfa12, {1,1}) ),
        doTraceTreesEqual(Forking(nfa12, {0}), Forking(nfa12, {0}) ),
        doTraceTreesEqual(Forking(nfa12, {0,1,0}), Forking(nfa12, {0,1,0}) ),

    };
        

    boolCounter(task31Pass);
    
    
    //********************************************************************************************************
    // Testing grounds for function "Backtracking" (task 32)
    //***********************************************************************************
    
    std::vector<bool> task33Pass{
        Backtrack(nfa1, {0,0,1,1,0}),
        Backtrack(nfa2, {0,1,0,1}),
        Backtrack(nfa3, {1,1,0,0,0}),
        Backtrack(nfa4, {0,0,1}),
        Backtrack(nfa5, {0,0,1,0}),
        Backtrack(nfa6, {0,0,1,1}),
        Backtrack(nfa7, {0,0,0}),
        Backtrack(nfa8, {1,1,1,1}),
        Backtrack(nfa9, {1,0,0,0}),
        Backtrack(nfa10, {1,1,1,0,1}),
        Backtrack(nfa11, {1,1}),
        Backtrack(nfa12, {1,0,1,0,1}),
        
    };
    
    boolCounter(task33Pass);


    return 0;
}

