//
//  main.cpp
//  PolyphonicSynthesis
//
//  Copyright © 2017 UH. All rights reserved.
//

#include <iostream>
#include <math.h>                                                                                          // Needed to use mathematical functions
#include <fstream>                                                                                               // Needed to write and read files
#include <string.h>                                                                                                       // Needed to use Strings
#include "errorCheck.hpp"                                                                                        // Needed to use class errorCheck
#include "noteLetter.hpp"                                                                                        // Needed to use class noteLetter

using namespace std;                                                                          // Needed to avoid declaring every class as standard


int main() {
    
    errorCheck error;                                                                                                  // Declaration of variables
    noteLetter letter;
    float t;
    float n;
    string Chord;
    string MajorChord = "major";
    string MinorChord = "minor";
    float sampleRate;
    float bitDepth;
    

    cout << "- Welcome! -" << endl;                                                                                           // Welcoming message
    cout << "With this program you will be able to generate a chord composed of complex tones." << endl;
    
    cout << "What MIDI note (0-127) would you like to use as your basic tone?" << endl;                                            // Question n.1
    do {
        error.checkForError();                                                                                            // Check for input error
        cin >> n;                                                                                                // User input of MIDI note number
        if (n >= 0) {                                                                // Verification: the note input has a value between 0 and 127
            if (n < 128) {
                if (cin.fail()){
                } else {
                break;                                                                       // Break the loop if input value is between 0 and 127
                }
            }
        }
        cout << "The value entered was not recognised. Please try again:" << endl;                                         // Output error message
    } while ((cin.fail()) | (n < 0) | (n >= 128));                                                                           // Conditions of loop
    cout << "Thank you." << endl;

    
    cout << "Declare if you need a 'major' or a 'minor' chord (please, DO NOT use capital letters):" << endl;                      // Question n.2
    do {
        if (cin.fail()) {                                                                                                 // Check for input error
            cin.clear();
            cin.ignore();
        }
        cin >> Chord;                                                                                                      // User choice of chord
        if (Chord == MajorChord) {                                                                      // Verification: the user has input "major"
            break;                                                                                      // Break the loop if user has input "major"
        } else if (Chord == MinorChord) {                                                               // Verification: the user has input "minor"
                    break;                                                                              // Break the loop if user has input "minor"
                }
       cout << "The value entered was not recognised. Please try again:" << endl;                                          // Output error message
    } while ((cin.fail()) | (Chord != MajorChord) | (Chord != MinorChord));                                                  // Conditions of loop
    cout << "Thank you." << endl;

    
    cout << "How many seconds (expressed in numbers) would you like your audio file to be?" << endl;                               // Question n.3
    do {
        error.checkForError();                                                                                            // Check for input error
        cin >> t;                                                                                                     // User input of time length
        if (t > 0) {                                                                    // Verification: the time input has a value greater than 0
            break;                                                                              // Break the loop if input value is greater than 0
        }
        cout << "The value entered was not recognised. Please try again:" << endl;                                         // Output error message
    } while ((cin.fail()) | (t <= 0));                                                                                       // Conditions of loop
    cout << "Thank you." << endl;
    
    
    cout << "What sample rate (Hz) would you like to use: 44100, 48000, 96000?" << endl;                                           // Question n.4
    do {
        error.checkForError();                                                                                            // Check for input error
        cin >> sampleRate;                                                                                           // User choice of sample rate
        if (sampleRate == 44100) {                                           // Verification: the sample rate input has one of the values declared
            break;                                                                              // Break the loop if input value is equal to 44100
        } else if (sampleRate == 48000) {
            break;                                                                              // Break the loop if input value is equal to 48000
        } else if (sampleRate == 96000) {
            break;                                                                              // Break the loop if input value is equal to 96000
        }
        cout << "The value entered was not recognised. Please try again:" << endl;                                         // Output error message
    } while ((cin.fail()) | (sampleRate != 44100) | (sampleRate != 48000) | (sampleRate != 96000));                          // Conditions of loop
    cout << "Thank you." << endl;
    
    
    cout << "What bit depth (bits) would you like to use: 8, 16, 32?" << endl;                                                     // Question n.5
    do {
        error.checkForError();                                                                                            // Check for input error
        cin >> bitDepth;                                                                                               // User choice of bit depth
        if (bitDepth == 8) {                                                   // Verification: the bit depth input has one of the values declared
            break;                                                                                  // Break the loop if input value is equal to 8
        } else if (bitDepth == 16) {
            break;                                                                                 // Break the loop if input value is equal to 16
        } else if (bitDepth == 32) {
            break;                                                                                 // Break the loop if input value is equal to 32
        }
        cout << "The value entered was not recognised. Please try again:" << endl;                                         // Output error message
    } while ((cin.fail()) | (bitDepth != 8) | (bitDepth != 16) | (bitDepth != 32));                                          // Conditions of loop
    cout << "Thank you." << endl;

                                                    ///// End of interaction with user /////
    
                                                       ///// Start of calculations /////
    
    string *note = letter.assignLetter(n);
    
    int f = 440 * pow(2 , (n-69) / 12);                                          // Expression to find fundamental frequency from MIDI note number
    int f0 = 0;
    int f1 = 0;
    int f2 = 0;
    
    if (Chord == MajorChord) {                                          // If this condition is met, code execute equation to create a major chord
        
        f0 = f;
        f1 = f * 5 / 4;
        f2 = f * 6 / 4;
        
    } else if (Chord == MinorChord) {                                   // If this condition is met, code execute equation to create a minor chord
        
        f0 = f;
        f1 = f * 12 / 10;
        f2 = f * 15 / 10;
        
    }
    
    int freq [3] = {f0, f1, f2};                                                          // Creation of array containing the values for the chord
    
    ofstream textFile;                                                                                // Creates the stream to write the text file
    textFile.open ("User's Choice.txt");                                                                          // Gives a name to the text file

    if (!textFile) {                                                                                    // Check if the text file has been created
        cout << "Text file not found." << endl;                                                                                   // Error message
        return 1;                                                                                                                  // Return error
    }
    
    textFile << "You have selected " << n << " as the number of your MIDI note, which correspond to the note " << *note << ". " << f << "Hz is therefore the root frequency used to create a " << Chord << " chord." << endl;                                                                       // Writes in the text file
    
    textFile.close();                                                                                                         // Closes the stream
    
    ofstream audioFile("Audio File.RAW", ios::binary);                                               // Creates the stream to write the audio file
    
    if (!audioFile) {                                                                                  // Check if the audio file has been created
        cout << "Audio file not found." << endl;                                                                                  // Error message
        return 1;                                                                                                                  // Return error
    }
    
    int sample = sampleRate * t;                                                                              // Calculating the number of samples
    
    for (int x = 0; x < (sample * 2/3); x++){                                                                // For loop to cycle through x values
                                                                                                    // sample*(2/3) needed to output a stereo file
        float currentTime = (float)x / sampleRate;                                                   // Calculation of current time of each sample
        float y = 0;
        
        for (int c = 0; c <= 2; c++){                                                                        // For loop to cycle through c values
            
            float chordFreq = 1;
            chordFreq = freq [c];                                  // Variable assigned to the value contained in a specific position of the array
        
            for (int k = 1; k <= 3; k++){                                                                // For loop to cycle through the k values
                
                y += ((sin(2 * M_PI * chordFreq * currentTime * (2 * k - 1))) / (2 * k - 1));                              // Square wave equation
            
            }
            
            int byte = bitDepth / 8;                                                                      // Calculation of size of the audio file
            int maxValue = (pow (2, bitDepth)) / 2 - 1;                           // Calculation of maximum value available according to bit depth
            int output = (y * maxValue * (4 / M_PI)) / 4;                           // (/4) is needed to contain the amplitude of the audio signal
            
            audioFile.write((char*)&output, byte);                                                                     // Writes in the audio file
            
        }
    }
    
    audioFile.close();                                                                                                        // Closes the stream
    cout << "--- The .RAW stereo file ("<< bitDepth << "bits, " << sampleRate << "Hz) containing the chord made with your selected characteristics has been created. ---" <<endl;
    cout << "--- You can also find your inputs saved in a text file on your computer. ---" <<endl;                               // Ending message

    return 0;
    
}



