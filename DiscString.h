/*	SENG1120: Assignment 2, Nathan Gervasoni: c3339961
    // DiscString.h
    // Header file and class definition of DiscString.
    // Will be used to represent the discs as strings and have a string as its member variable.
*/

// Macro guard.
#ifndef DISCSTRING_H
#define DISCSTRING_H

// Includes relevant libraries.
#include <iostream>
#include <cstdlib>

class DiscString
{
    public:
     /* Constructor and Destructor. */
        DiscString(int sizeOfDisc = 0);
            // Constructor with int value for sizeOfDisc.
            // Uses a switch statement to allocate required "X" value for DiscString class.
        ~DiscString();
            // Destructor.
     /* Public member functions. */
        void setData(const std::string disc);
            // Set value of data in DiscString.
            // Pre-condition: DiscString has been created.
            // Post-condition: Sets the data variable of DiscString.
        std::string getData() const;
            // Returns the value of DiscString.
            // Pre-condition: DiscString has been created, and has been allocated a value.
            // Post-condition: DiscString value is returned.
    /* Private members. */

    private:
        std::string discValue;
            // String data is stored. Values such as "X", or "XXX".
};
    std::ostream& operator << (std::ostream& output, const DiscString* disc);
    std::ostream& operator << (std::ostream& output, const DiscString disc);
        // Overloads the print operator.
    bool operator < (const DiscString& disc1, const DiscString& disc2);
        // Overloaded the less than operator.
        // Compares two DiscString objects for size.
    bool operator == (const DiscString& discOne, const DiscString& discTwo);
#endif

