//
//  NFA_examples.hpp
//  foundationsProject
//
//  Traces are represented as int lists (std::list<int>)
//  Traces 1-6 are accepting while traces 7-12 aren't accepting

#ifndef NFA_examples_hpp
#define NFA_examples_hpp

#include "NFA.hpp"
#include "DFA_Examples.hpp"
#include "trace_tree.hpp"


#include <stdio.h>

// Accepts all strings with the third element from the right being "1"
NFA<int> outputNFA1(void);
extern std::list<int> NFA1trace1;
extern std::list<int> NFA1trace2;
extern std::list<int> NFA1trace3;
extern std::list<int> NFA1trace4;
extern std::list<int> NFA1trace5;
extern std::list<int> NFA1trace6;
extern std::list<int> NFA1trace7;
extern std::list<int> NFA1trace8;
extern std::list<int> NFA1trace9;
extern std::list<int> NFA1trace10;
extern std::list<int> NFA1trace11;
extern std::list<int> NFA1trace12;
extern std::list<traceTreeBranch<int>> NFA1traceTree1;
extern std::list<traceTreeBranch<int>> NFA1traceTree2;
extern std::list<traceTreeBranch<int>> NFA1traceTree3;
extern std::list<traceTreeBranch<int>> NFA1traceTree4;
extern std::list<traceTreeBranch<int>> NFA1traceTree5;
extern std::list<traceTreeBranch<int>> NFA1traceTree6;



// Accepts all strings ending with "01"
NFA<int> outputNFA2(void);
extern std::list<int> NFA2trace1;
extern std::list<int> NFA2trace2;
extern std::list<int> NFA2trace3;
extern std::list<int> NFA2trace4;
extern std::list<int> NFA2trace5;
extern std::list<int> NFA2trace6;
extern std::list<int> NFA2trace7;
extern std::list<int> NFA2trace8;
extern std::list<int> NFA2trace9;
extern std::list<int> NFA2trace10;
extern std::list<int> NFA2trace11;
extern std::list<int> NFA2trace12;
extern std::list<traceTreeBranch<int>> NFA2traceTree1;
extern std::list<traceTreeBranch<int>> NFA2traceTree2;
extern std::list<traceTreeBranch<int>> NFA2traceTree3;
extern std::list<traceTreeBranch<int>> NFA2traceTree4;
extern std::list<traceTreeBranch<int>> NFA2traceTree5;
extern std::list<traceTreeBranch<int>> NFA2traceTree6;



// Accepts all strings with a double "0" (00) followed by a double "1" (11)
NFA<int> outputNFA3(void);
extern std::list<int> NFA3trace1;
extern std::list<int> NFA3trace2;
extern std::list<int> NFA3trace3;
extern std::list<int> NFA3trace4;
extern std::list<int> NFA3trace5;
extern std::list<int> NFA3trace6;
extern std::list<int> NFA3trace7;
extern std::list<int> NFA3trace8;
extern std::list<int> NFA3trace9;
extern std::list<int> NFA3trace10;
extern std::list<int> NFA3trace11;
extern std::list<int> NFA3trace12;
extern std::list<traceTreeBranch<int>> NFA3traceTree1;
extern std::list<traceTreeBranch<int>> NFA3traceTree2;
extern std::list<traceTreeBranch<int>> NFA3traceTree3;
extern std::list<traceTreeBranch<int>> NFA3traceTree4;
extern std::list<traceTreeBranch<int>> NFA3traceTree5;
extern std::list<traceTreeBranch<int>> NFA3traceTree6;



// Accepts all strings with the third element from the right being "0"
NFA<int> outputNFA4(void);
extern std::list<int> NFA4trace1;
extern std::list<int> NFA4trace2;
extern std::list<int> NFA4trace3;
extern std::list<int> NFA4trace4;
extern std::list<int> NFA4trace5;
extern std::list<int> NFA4trace6;
extern std::list<int> NFA4trace7;
extern std::list<int> NFA4trace8;
extern std::list<int> NFA4trace9;
extern std::list<int> NFA4trace10;
extern std::list<int> NFA4trace11;
extern std::list<int> NFA4trace12;
extern std::list<traceTreeBranch<int>> NFA4traceTree1;
extern std::list<traceTreeBranch<int>> NFA4traceTree2;
extern std::list<traceTreeBranch<int>> NFA4traceTree3;
extern std::list<traceTreeBranch<int>> NFA4traceTree4;
extern std::list<traceTreeBranch<int>> NFA4traceTree5;
extern std::list<traceTreeBranch<int>> NFA4traceTree6;



// Accepts all strings with either odd 1s or even 0s
NFA<int> outputNFA5(void);
extern std::list<int> NFA5trace1;
extern std::list<int> NFA5trace2;
extern std::list<int> NFA5trace3;
extern std::list<int> NFA5trace4;
extern std::list<int> NFA5trace5;
extern std::list<int> NFA5trace6;
extern std::list<int> NFA5trace7;
extern std::list<int> NFA5trace8;
extern std::list<int> NFA5trace9;
extern std::list<int> NFA5trace10;
extern std::list<int> NFA5trace11;
extern std::list<int> NFA5trace12;
extern std::list<traceTreeBranch<int>> NFA5traceTree1;
extern std::list<traceTreeBranch<int>> NFA5traceTree2;
extern std::list<traceTreeBranch<int>> NFA5traceTree3;
extern std::list<traceTreeBranch<int>> NFA5traceTree4;
extern std::list<traceTreeBranch<int>> NFA5traceTree5;
extern std::list<traceTreeBranch<int>> NFA5traceTree6;



// Accepts all strings ending in only "11" or "00"
NFA<int> outputNFA6(void);
extern std::list<int> NFA6trace1;
extern std::list<int> NFA6trace2;
extern std::list<int> NFA6trace3;
extern std::list<int> NFA6trace4;
extern std::list<int> NFA6trace5;
extern std::list<int> NFA6trace6;
extern std::list<int> NFA6trace7;
extern std::list<int> NFA6trace8;
extern std::list<int> NFA6trace9;
extern std::list<int> NFA6trace10;
extern std::list<int> NFA6trace11;
extern std::list<int> NFA6trace12;
extern std::list<traceTreeBranch<int>> NFA6traceTree1;
extern std::list<traceTreeBranch<int>> NFA6traceTree2;
extern std::list<traceTreeBranch<int>> NFA6traceTree3;
extern std::list<traceTreeBranch<int>> NFA6traceTree4;
extern std::list<traceTreeBranch<int>> NFA6traceTree5;
extern std::list<traceTreeBranch<int>> NFA6traceTree6;



// Accepts a string of length 2 or 4
NFA<int> outputNFA7(void);
extern std::list<int> NFA7trace1;
extern std::list<int> NFA7trace2;
extern std::list<int> NFA7trace3;
extern std::list<int> NFA7trace4;
extern std::list<int> NFA7trace5;
extern std::list<int> NFA7trace6;
extern std::list<int> NFA7trace7;
extern std::list<int> NFA7trace8;
extern std::list<int> NFA7trace9;
extern std::list<int> NFA7trace10;
extern std::list<int> NFA7trace11;
extern std::list<int> NFA7trace12;
extern std::list<traceTreeBranch<int>> NFA7traceTree1;
extern std::list<traceTreeBranch<int>> NFA7traceTree2;
extern std::list<traceTreeBranch<int>> NFA7traceTree3;
extern std::list<traceTreeBranch<int>> NFA7traceTree4;
extern std::list<traceTreeBranch<int>> NFA7traceTree5;
extern std::list<traceTreeBranch<int>> NFA7traceTree6;



// Accepts all strings either ending in "0" or has all "1"s
NFA<int> outputNFA8(void);
extern std::list<int> NFA8trace1;
extern std::list<int> NFA8trace2;
extern std::list<int> NFA8trace3;
extern std::list<int> NFA8trace4;
extern std::list<int> NFA8trace5;
extern std::list<int> NFA8trace6;
extern std::list<int> NFA8trace7;
extern std::list<int> NFA8trace8;
extern std::list<int> NFA8trace9;
extern std::list<int> NFA8trace10;
extern std::list<int> NFA8trace11;
extern std::list<int> NFA8trace12;
extern std::list<traceTreeBranch<int>> NFA8traceTree1;
extern std::list<traceTreeBranch<int>> NFA8traceTree2;
extern std::list<traceTreeBranch<int>> NFA8traceTree3;
extern std::list<traceTreeBranch<int>> NFA8traceTree4;
extern std::list<traceTreeBranch<int>> NFA8traceTree5;
extern std::list<traceTreeBranch<int>> NFA8traceTree6;



// Accepts all strings that over or equal to the length 2, and has either all "1"s or all "0"s
NFA<int> outputNFA9(void);
extern std::list<int> NFA9trace1;
extern std::list<int> NFA9trace2;
extern std::list<int> NFA9trace3;
extern std::list<int> NFA9trace4;
extern std::list<int> NFA9trace5;
extern std::list<int> NFA9trace6;
extern std::list<int> NFA9trace7;
extern std::list<int> NFA9trace8;
extern std::list<int> NFA9trace9;
extern std::list<int> NFA9trace10;
extern std::list<int> NFA9trace11;
extern std::list<int> NFA9trace12;
extern std::list<traceTreeBranch<int>> NFA9traceTree1;
extern std::list<traceTreeBranch<int>> NFA9traceTree2;
extern std::list<traceTreeBranch<int>> NFA9traceTree3;
extern std::list<traceTreeBranch<int>> NFA9traceTree4;
extern std::list<traceTreeBranch<int>> NFA9traceTree5;
extern std::list<traceTreeBranch<int>> NFA9traceTree6;



// DFA Sample 4 - accepts only strings with "01" in it
NFA<int> outputNFA10(void);
extern std::list<int> NFA10trace1;
extern std::list<int> NFA10trace2;
extern std::list<int> NFA10trace3;
extern std::list<int> NFA10trace4;
extern std::list<int> NFA10trace5;
extern std::list<int> NFA10trace6;
extern std::list<int> NFA10trace7;
extern std::list<int> NFA10trace8;
extern std::list<int> NFA10trace9;
extern std::list<int> NFA10trace10;
extern std::list<int> NFA10trace11;
extern std::list<int> NFA10trace12;
extern std::list<traceTreeBranch<int>> NFA10traceTree1;
extern std::list<traceTreeBranch<int>> NFA10traceTree2;
extern std::list<traceTreeBranch<int>> NFA10traceTree3;
extern std::list<traceTreeBranch<int>> NFA10traceTree4;
extern std::list<traceTreeBranch<int>> NFA10traceTree5;
extern std::list<traceTreeBranch<int>> NFA10traceTree6;



// DFA Sample 10 - accepting strings starting with ‘11’
NFA<int> outputNFA11(void);
extern std::list<int> NFA11trace1;
extern std::list<int> NFA11trace2;
extern std::list<int> NFA11trace3;
extern std::list<int> NFA11trace4;
extern std::list<int> NFA11trace5;
extern std::list<int> NFA11trace6;
extern std::list<int> NFA11trace7;
extern std::list<int> NFA11trace8;
extern std::list<int> NFA11trace9;
extern std::list<int> NFA11trace10;
extern std::list<int> NFA11trace11;
extern std::list<int> NFA11trace12;
extern std::list<traceTreeBranch<int>> NFA11traceTree1;
extern std::list<traceTreeBranch<int>> NFA11traceTree2;
extern std::list<traceTreeBranch<int>> NFA11traceTree3;
extern std::list<traceTreeBranch<int>> NFA11traceTree4;
extern std::list<traceTreeBranch<int>> NFA11traceTree5;
extern std::list<traceTreeBranch<int>> NFA11traceTree6;



// DFA Sample 7 - accepts only strings with an even number of 0s and 1s
NFA<int> outputNFA12(void);
extern std::list<int> NFA12trace1;
extern std::list<int> NFA12trace2;
extern std::list<int> NFA12trace3;
extern std::list<int> NFA12trace4;
extern std::list<int> NFA12trace5;
extern std::list<int> NFA12trace6;
extern std::list<int> NFA12trace7;
extern std::list<int> NFA12trace8;
extern std::list<int> NFA12trace9;
extern std::list<int> NFA12trace10;
extern std::list<int> NFA12trace11;
extern std::list<int> NFA12trace12;
extern std::list<traceTreeBranch<int>> NFA12traceTree1;
extern std::list<traceTreeBranch<int>> NFA12traceTree2;
extern std::list<traceTreeBranch<int>> NFA12traceTree3;
extern std::list<traceTreeBranch<int>> NFA12traceTree4;
extern std::list<traceTreeBranch<int>> NFA12traceTree5;
extern std::list<traceTreeBranch<int>> NFA12traceTree6;

#endif /* NFA_examples_hpp */
