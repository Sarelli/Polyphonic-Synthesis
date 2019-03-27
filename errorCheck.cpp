//
//  errorCheck.cpp
//  PolyphonicSynthesis
//
//  Copyright © 2017 UH. All rights reserved.
//

#include "errorCheck.hpp"
using namespace std;

errorCheck::errorCheck() {
    
}

void errorCheck::checkForError() {
    
    if (cin.fail()) {                                                                                                 // Verification: input error
        
        cin.clear();                                                                                      // Clear the memory from the value input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');                                 // Codition: if input is a number, don't execute fail
        
    }
    
}

errorCheck::~errorCheck(){
    
}
