/*	SENG1120: Assignment 2, Nathan Gervasoni: c3339961
    // DiscString.cpp
    // Implementation for class DiscInt.
    // Illustrates how class DiscInt.cpp works.
*/

// Includes relevant library.
#include "DiscInt.h"

/* Constructor and Destructor. */
DiscInt::DiscInt(int sizeOfDisc)
    {
        switch (sizeOfDisc)                // sizeOfDisc // Sets the value of variable 'data' to value of string disc.
        {                                  // Sets the value of variable 'discValue' to value of int size.
            case 1:
                discValue = 1;
                break;
            case 2:
                discValue = 2;
                break;
            case 3:
                discValue = 3;
                break;
            case 4:
                discValue = 4;
                break;
            case 5:
                discValue = 5;
                break;
            default:
                discValue = 0;
        }
    }

    DiscInt::~DiscInt()
    {
        // Default destructor.
    }

    // Unused function.
    void DiscInt::setData(const int sizeOfDisc)
    {
        discValue = sizeOfDisc; // Set discValue to the int passed in.
    }

    int DiscInt::getData() const
    {
        return discValue; // Returns discValue.
    }

    std::ostream& operator << (std::ostream& output, const DiscInt* disc)
    {
        output << disc->getData(); // Overloaded operator. Prints discValue from disc.
        return output;             // Returns output to be printed.
    }

    std::ostream& operator << (std::ostream& output, const DiscInt disc)
    {
        output << disc.getData(); // Overloaded operator. Prints discValue from disc.
        return output;            // Returns output to be printed.
    }

    bool operator < (const DiscInt& discOne, const DiscInt& discTwo)
    {
        return (discOne.getData() < discTwo.getData());    // Overloaded < operator.
    }

    bool operator == (const DiscInt& discOne, const DiscInt& discTwo)
    {
        return (discOne.getData() == discTwo.getData());    // Overloaded bool operator.
    }