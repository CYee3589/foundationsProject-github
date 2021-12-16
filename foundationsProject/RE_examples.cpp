//
//  RE_examples.cpp
//  foundationsProject
//
//  Created by Calvin Yee on 12/5/21.
//

#include "RE_examples.hpp"

// RE 1: accepts a string with the third letter 1
// (0 ∪ 1)* ° (1 ° ((0 ∪ 1) ° (0 ∪ 1)))
RE outputRE1(void){
    RE temp('C',
        new RE('K',
           new RE('U',
              new RE('Z'),
              new RE('O')
              )
           ),
        new RE('C',
           new RE('O'),
           new RE('C',
               new RE('U',
                  new RE('Z'),
                  new RE('O')
                  ),
                  new RE('U',
                     new RE('Z'),
                     new RE('O')
                  )
              )
           )
    );
    return temp;
}

RE outputRE1Copy(void){
    RE temp('C',
        new RE('K',
           new RE('U',
              new RE('O'),
              new RE('Z')
              )
           ),
        new RE('C',
           new RE('O'),
           new RE('C',
               new RE('U',
                  new RE('O'),
                  new RE('Z')
                  ),
                  new RE('U',
                     new RE('O'),
                     new RE('Z')
                  )
              )
           )
    );
    return temp;
}

std::list<int> RE1pass1 = {1,1,0,0};
std::list<int> RE1pass2 = {1,1,1};
std::list<int> RE1pass3 = {1,0,1,0,1};
std::list<int> RE1fail1 = {1,1};
std::list<int> RE1fail2 = {0,1,0,0,0};
std::list<int> RE1fail3 = {1,1,0,1,1};



// RE 2: 1s followed by 0s
//(1 o 1*) o (0 o 0*)
RE outputRE2(void){
    RE temp('C',
        new RE('C',
           new RE('O'),
           new RE('K',
              new RE('O')
           )
        ),
        new RE('C',
            new RE('Z'),
            new RE('K',
                new RE('Z')
            )
        )
    );
    return temp;
}

std::list<int> RE2pass1 = {1,0,0};
std::list<int> RE2pass2 = {1,1,1,0};
std::list<int> RE2pass3 = {1,0};
std::list<int> RE2fail1 = {1,1};
std::list<int> RE2fail2 = {0};
std::list<int> RE2fail3 = {1,1,0,0,1};



// RE 3: accepting a string of 0s and 1s, plus the null string
// (0 u 1)*
RE outputRE3(void){
    RE temp('K',
        new RE('U',
           new RE('Z'),
           new RE('O')
        )
    );
    return temp;
}

RE outputRE3Copy(void){
    RE temp('K',
        new RE('U',
           new RE('O'),
           new RE('Z')
        )
    );
    return temp;
}

std::list<int> RE3pass1 = {0};
std::list<int> RE3pass2 = {1};
std::list<int> RE3pass3 = {1,1};
std::list<int> RE3fail1 = {1,1};
std::list<int> RE3fail2 = {0,1,0,0,0};
std::list<int> RE3fail3 = {1,1,0,1,1};



// RE 4: accepts string of even number of 1s, plus the null string
// (1 o 1)*
RE outputRE4(void){
    RE temp('K',
        new RE('C',
           new RE('O'),
           new RE('O')
        )
    );
    return temp;
}

std::list<int> RE4pass1 = {};
std::list<int> RE4pass2 = {1,1};
std::list<int> RE4pass3 = {1,1,1,1};
std::list<int> RE4fail1 = {1};
std::list<int> RE4fail2 = {0,0};
std::list<int> RE4fail3 = {1,1,0};



// RE 5: accepts strings that are {E},{0},{1},{0,1}
// (0 u E) o (1 u E)
RE outputRE5(void){
    RE temp('C',
        new RE('U',
           new RE('Z'),
           new RE('E')
        ),
        new RE('U',
            new RE('O'),
            new RE('E')
        )
    );
    return temp;
}

RE outputRE5Copy(void){
    RE temp('C',
        new RE('U',
           new RE('E'),
           new RE('Z')
        ),
        new RE('U',
            new RE('E'),
            new RE('O')
        )
    );
    return temp;
}

std::list<int> RE5pass1 = {};
std::list<int> RE5pass2 = {1};
std::list<int> RE5pass3 = {0,1};
std::list<int> RE5fail1 = {1,1};
std::list<int> RE5fail2 = {0,1,0};
std::list<int> RE5fail3 = {0,0};



// RE 6: accepts strings of all 1s
// (1)*
RE outputRE6(void){
    RE temp('K',
        new RE('O')
    );
    return temp;
}

std::list<int> RE6pass1 = {1};
std::list<int> RE6pass2 = {1,1,1};
std::list<int> RE6pass3 = {1,1,1,1};
std::list<int> RE6fail1 = {0};
std::list<int> RE6fail2 = {1,1,0,1};
std::list<int> RE6fail3 = {1,0,1,0};



// RE 7: accepts string that end with "010"
// (0 ∪ 1)* ° (0 ° (1 ° 0))
RE outputRE7(void){
    RE temp('C',
        new RE('K',
           new RE('U',
               new RE('Z'),
               new RE('O')
           )
        ),
        new RE('C',
            new RE('O'),
            new RE('C',
                new RE('O'),
                   new RE('Z')
            )
        )
    );
    return temp;
}

std::list<int> RE7pass1 = {0,1,0};
std::list<int> RE7pass2 = {1,1,1,0,1,0};
std::list<int> RE7pass3 = {0,0,0,1,0};
std::list<int> RE7fail1 = {1,1,0};
std::list<int> RE7fail2 = {0,1};
std::list<int> RE7fail3 = {0,1,1,0};



// RE 8: accepts string with an even number of 0s followed by a odd number of 1s
// (0 o 0)* o ((1 o 1)* o 1)
RE outputRE8(void){
    RE temp('C',
        new RE('K',
           new RE('C',
               new RE('Z'),
               new RE('Z')
           )
        ),
        new RE('C',
            new RE('K',
                new RE('C',
                    new RE('O'),
                    new RE('O')
                )
            ),
            new RE('O')
        )
    );
    return temp;
}

std::list<int> RE8pass1 = {0,0,1};
std::list<int> RE8pass2 = {1,1,1};
std::list<int> RE8pass3 = {0,0,0,0,1,1,1};
std::list<int> RE8fail1 = {0,1};
std::list<int> RE8fail2 = {0,0,1,1};
std::list<int> RE8fail3 = {0,1,0};



// RE 9: accepts strings that have "110" in it
// (0 ∪ (1 ∪ E))* ° ((1 ° (1 ° 0)) ° (0 ∪ (1 u E))* )
RE outputRE9(void){
    RE temp('C',
        new RE('K',
            new RE('U',
                new RE('Z'),
                new RE('U',
                    new RE('O'),
                    new RE('E')
                )
            )
        ),
        new RE('C',
            new RE('C',
                new RE('O'),
                new RE('C',
                    new RE('O'),
                    new RE('Z')
                )
            ),
            new RE('K',
                new RE('U',
                    new RE('Z'),
                    new RE('U',
                        new RE('O'),
                        new RE('E')
                    )
                )
            )
        )
    );
    return temp;
}

RE outputRE9Copy(void){
    RE temp('C',
        new RE('K',
            new RE('U',
                new RE('Z'),
                new RE('U',
                    new RE('E'),
                    new RE('O')
                )
            )
        ),
        new RE('C',
            new RE('C',
                new RE('O'),
                new RE('C',
                    new RE('O'),
                    new RE('Z')
                )
            ),
            new RE('K',
                new RE('U',
                    new RE('Z'),
                    new RE('U',
                        new RE('E'),
                        new RE('O')
                    )
                )
            )
        )
    );
    return temp;
}

std::list<int> RE9pass1 = {1,1,0};
std::list<int> RE9pass2 = {0,0,1,1,0,1};
std::list<int> RE9pass3 = {1,1,1,1,0};
std::list<int> RE9fail1 = {1,0,0,1};
std::list<int> RE9fail2 = {0,0,1,0};
std::list<int> RE9fail3 = {1,1};



// RE 10: accepts strings that end in 0
// (0 ∪ (1 ∪ E))* ° 0
RE outputRE10(void){
    RE temp('C',
        new RE('K',
            new RE('U',
                new RE('Z'),
                new RE('U',
                    new RE('O'),
                    new RE('E')
                )
            )
        ),
        new RE('Z')
    );
    return temp;
}

RE outputRE10Copy(void){
    RE temp('C',
        new RE('K',
            new RE('U',
                new RE('U',
                    new RE('E'),
                    new RE('O')
                ),
                new RE('Z')
            )
        ),
        new RE('Z')
    );
    return temp;
}

std::list<int> RE10pass1 = {0};
std::list<int> RE10pass2 = {1,1,1,0};
std::list<int> RE10pass3 = {0,1,0,0};
std::list<int> RE10fail1 = {1};
std::list<int> RE10fail2 = {};
std::list<int> RE10fail3 = {0,1,1,0,1};



// RE 11: accepts strings of all 0s and ends in with "1"
// (0)* ° 1
RE outputRE11(void){
    RE temp('C',
        new RE('K',
            new RE('Z')
        ),
        new RE('Z')
    );
    return temp;
}

std::list<int> RE11pass1 = {0,1};
std::list<int> RE11pass2 = {0,0,0,1};
std::list<int> RE11pass3 = {0,0,0,0,1};
std::list<int> RE11fail1 = {1};
std::list<int> RE11fail2 = {0,1,0,1};
std::list<int> RE11fail3 = {0,0,0,0,1,1};



// RE 12: accepts strings with the length less than or equal to 3
// (0 ∪ (1 ∪ N)) ° ((0 ∪ (1 ∪ N)) ° (0 ∪ (1 ∪ N)))
RE outputRE12(void){
    RE temp('C',
        new RE('U',
            new RE('Z'),
            new RE('U',
                new RE('O'),
                new RE('E')
            )
        ),
        new RE('C',
            new RE('U',
                new RE('Z'),
                new RE('U',
                    new RE('O'),
                    new RE('E')
                )
            ),
            new RE('U',
                new RE('Z'),
                new RE('U',
                    new RE('O'),
                    new RE('E')
                )
            )
        )
    );
    return temp;
}

RE outputRE12Copy(void){
    RE temp('C',
        new RE('U',
            new RE('Z'),
            new RE('U',
                new RE('E'),
                new RE('O')
            )
        ),
        new RE('C',
            new RE('U',
                new RE('U',
                    new RE('E'),
                    new RE('O')
                ),
                new RE('Z')
            ),
            new RE('U',
                new RE('U',
                    new RE('O'),
                    new RE('E')
                ),
                new RE('Z')
            )
        )
    );
    return temp;
}

std::list<int> RE12pass1 = {0};
std::list<int> RE12pass2 = {1,1};
std::list<int> RE12pass3 = {1,0,1};
std::list<int> RE12fail1 = {1,1,1,1};
std::list<int> RE12fail2 = {0,1,0,1,1};
std::list<int> RE12fail3 = {0,0,0,0,1,1};
