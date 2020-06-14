/* SENG1120: Assignment 2, Nathan Gervasoni: c3339961
    // DiscInt.h
    // Header file and class definition of class DiscInt.
    // Will be used to represent the discs as integers, and will have an int as its member variable.
*/

// Macro guard.
#ifndef DISCINT_H
#define DISCINT_H

// Includes relevant libraries.
#include <iostream>
#include <cstdlib>

class DiscInt
{
    public:
    /* Constructor and Destructor. */
        DiscInt(int sizeOfDisc = 0);
            // Constructor, with int value for sizeOfDisc.
        ~DiscInt();
            // Destructor.
    /* Public member functions. */
        void setData(int disc);
            // Set value of data in DiscInt.
            // Pre-condition: DiscInt has been created.
            // Post-condition: Sets the data variable of DiscInt.
        int getData() const;
            // Returns the value of DiscInt.
            // Pre-condition: DiscInt has been created, and has been allocated a value.
            // Post-condition: DiscInt value is returned.

    /* Private members. */
    private:
        int discValue;
            //  discValue is stored using integers.
};
    std::ostream& operator << (std::ostream& output, const DiscInt* disc);
    std::ostream& operator << (std::ostream& output, const DiscInt disc);
        // Overloads the print operator.
    bool operator < (const DiscInt& disc1, const DiscInt& disc2);
        // Overloaded the less than operator.
        // Compares two DiscInt objects for size.
    bool operator == (const DiscInt& discOne, const DiscInt& discTwo);
#endif


