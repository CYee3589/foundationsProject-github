//
//  RE_examples.hpp
//  foundationsProject
//
//  Created by Calvin Yee on 12/5/21.
//

#ifndef RE_examples_hpp
#define RE_examples_hpp

#include "RE.hpp"

#include <stdio.h>

// RE 1: accepts a string with the third letter being 1
// (0 ∪ 1)* ° (1 ° ((0 ∪ 1) ° (0 ∪ 1)))
RE outputRE1(void);
RE outputRE1Copy(void);
extern std::list<int> RE1pass1;
extern std::list<int> RE1pass2;
extern std::list<int> RE1pass3;
extern std::list<int> RE1fail1;
extern std::list<int> RE1fail2;
extern std::list<int> RE1fail3;

// RE 2: 1s followed by 0s
//(1 o 1*) o (0 o 0*)
RE outputRE2(void);
extern std::list<int> RE2pass1;
extern std::list<int> RE2pass2;
extern std::list<int> RE2pass3;
extern std::list<int> RE2fail1;
extern std::list<int> RE2fail2;
extern std::list<int> RE2fail3;

// RE 3: accepting a string of 0s and 1s, plus the null string
// (0 u 1)*
RE outputRE3(void);
RE outputRE3Copy(void);
extern std::list<int> RE3pass1;
extern std::list<int> RE3pass2;
extern std::list<int> RE3pass3;
extern std::list<int> RE3fail1;
extern std::list<int> RE3fail2;
extern std::list<int> RE3fail3;

// RE 4: accepts string of only an even number of 1s, plus the null string
// (1 o 1)*
RE outputRE4(void);
extern std::list<int> RE4pass1;
extern std::list<int> RE4pass2;
extern std::list<int> RE4pass3;
extern std::list<int> RE4fail1;
extern std::list<int> RE4fail2;
extern std::list<int> RE4fail3;

// RE 5: accepts strings that are {E},{0},{1},{0,1}
// (0 u E) o (1 u E)
RE outputRE5(void);
RE outputRE5Copy(void);
extern std::list<int> RE5pass1;
extern std::list<int> RE5pass2;
extern std::list<int> RE5pass3;
extern std::list<int> RE5fail1;
extern std::list<int> RE5fail2;
extern std::list<int> RE5fail3;

// RE 6: accepts strings of all 1s
// (1)*
RE outputRE6(void);
extern std::list<int> RE6pass1;
extern std::list<int> RE6pass2;
extern std::list<int> RE6pass3;
extern std::list<int> RE6fail1;
extern std::list<int> RE6fail2;
extern std::list<int> RE6fail3;

// RE 7: accepts string that end with "010"
// (0 ∪ 1)* ° (0 ° (1 ° 0))
RE outputRE7(void);
extern std::list<int> RE7pass1;
extern std::list<int> RE7pass2;
extern std::list<int> RE7pass3;
extern std::list<int> RE7fail1;
extern std::list<int> RE7fail2;
extern std::list<int> RE7fail3;

// RE 8: accepts string with an even number of 0s followed by a odd number of 1s
// (0 o 0)* o ((1 o 1)* o 1)
RE outputRE8(void);
extern std::list<int> RE8pass1;
extern std::list<int> RE8pass2;
extern std::list<int> RE8pass3;
extern std::list<int> RE8fail1;
extern std::list<int> RE8fail2;
extern std::list<int> RE8fail3;

// RE 9: accepts strings that have "110" in it
// (0 ∪ (1 ∪ N))* ° ((1 ° (1 ° 0)) ° (0 ∪ (1 u N))* )
RE outputRE9(void);
RE outputRE9Copy(void);
extern std::list<int> RE9pass1;
extern std::list<int> RE9pass2;
extern std::list<int> RE9pass3;
extern std::list<int> RE9fail1;
extern std::list<int> RE9fail2;
extern std::list<int> RE9fail3;

// RE 10: accepts strings that end in 0
// (0 ∪ (1 ∪ N))* ° 0
RE outputRE10(void);
RE outputRE10Copy(void);
extern std::list<int> RE10pass1;
extern std::list<int> RE10pass2;
extern std::list<int> RE10pass3;
extern std::list<int> RE10fail1;
extern std::list<int> RE10fail2;
extern std::list<int> RE10fail3;

// RE 11: accepts strings of all 0s and ends in with "1"
// (0)* ° 1
RE outputRE11(void);
extern std::list<int> RE11pass1;
extern std::list<int> RE11pass2;
extern std::list<int> RE11pass3;
extern std::list<int> RE11fail1;
extern std::list<int> RE11fail2;
extern std::list<int> RE11fail3;

// RE 12: accepts strings with the length less than or equal to 3
// (0 ∪ (1 ∪ N)) ° ((0 ∪ (1 ∪ N)) ° (0 ∪ (1 ∪ N)))
RE outputRE12(void);
RE outputRE12Copy(void);
extern std::list<int> RE12pass1;
extern std::list<int> RE12pass2;
extern std::list<int> RE12pass3;
extern std::list<int> RE12fail1;
extern std::list<int> RE12fail2;
extern std::list<int> RE12fail3;

#endif /* RE_examples_hpp */
