//
//  noteLetter.cpp
//  PolyphonicSynthesis
//
//  Copyright © 2018 UH. All rights reserved.
//

#include "noteLetter.hpp"
using namespace std;

noteLetter::noteLetter() {
    
}

string* noteLetter::assignLetter(float n){
    
    string notes[12] {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};             // String containing the english names of notes
    
    int remainder = (int) n % 12;                               // Calculation of the remainder to associate MIDI note to its english name notation
    
    if (remainder == 0) {                                                                       // Verification: the remainder obtained has value 0
        
        note = notes[0];
    
    } else if (remainder == 1) {                                                                // Verification: the remainder obtained has value 1
    
        note = notes[1];
    
    } else if (remainder == 2) {                                                                // Verification: the remainder obtained has value 2
    
        note = notes[2];
    
    } else if (remainder == 3) {                                                                // Verification: the remainder obtained has value 3
       
        note = notes[3];
    
    } else if (remainder == 4) {                                                                // Verification: the remainder obtained has value 4
        
        note = notes[4];
            
    } else if (remainder == 5) {                                                                // Verification: the remainder obtained has value 5
       
        note = notes[5];
                
    } else if (remainder == 6) {                                                                // Verification: the remainder obtained has value 6
       
        note = notes[6];
                    
    } else if (remainder == 7) {                                                                // Verification: the remainder obtained has value 7
        
        note = notes[7];
                        
    } else if (remainder == 8) {                                                                // Verification: the remainder obtained has value 8
        
        note = notes[8];
                            
    } else if (remainder == 9) {                                                                // Verification: the remainder obtained has value 9
        
        note = notes[9];
                                
    } else if (remainder == 10) {                                                              // Verification: the remainder obtained has value 10
       
        note = notes[10] ;
    
    } else if (remainder == 11) {                                                              // Verification: the remainder obtained has value 11
       
        note = notes[11] ;
                                        
    }
    
    return &note;                                                                   // Return the value contained in specific position of the array
}

noteLetter::~noteLetter(){
    
}

