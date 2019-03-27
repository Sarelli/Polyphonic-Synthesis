//
//  noteLetter.hpp
//  PolyphonicSynthesis
//
//  Copyright © 2018 UH. All rights reserved.
//

#ifndef noteLetter_hpp
#define noteLetter_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class noteLetter {
public:
    noteLetter();
    string* assignLetter(float);
    ~noteLetter();
protected:
    string note;
};

#endif /* noteLetter_hpp */
