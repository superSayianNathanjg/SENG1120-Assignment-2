/*	SENG1120: Assignment 2, Nathan Gervasoni: c3339961
    // DiscString.cpp
    // Implementation for class DiscString.
    // Illustrates how class DiscString.cpp works.
*/

// Includes relevant library.
#include "DiscString.h"

// (total_length - length_of_current_disc) / 2
        /* Constructor and Destructor. */
        DiscString::DiscString(int sizeOfDisc) // Constructor with int passed to set the value of DiscString.
        {                                      // Each case represents a value, "X, "XX", "XXX", "XXXX", "XXXXX"
            switch (sizeOfDisc)                // sizeOfDisc // Sets the value of variable 'data' to value of string disc.
            {                                  // Sets the value of variable 'discValue' to value of int size.
                case 1:
                    discValue = "    X    ";
                    break;
                case 2:
                    discValue = "   XXX   ";
                    break;
                case 3:
                    discValue = "  XXXXX  ";
                    break;
                case 4:
                    discValue = " XXXXXXX ";
                    break;
                case 5:
                    discValue = "XXXXXXXXX";

                    break;
                default:
                    discValue = "         ";
            }
        }

        DiscString::~DiscString()
        {
            // Default destructor.
        }

        // Unused function.
        void DiscString::setData(const std::string disc)
        {
            discValue = disc; // Set discValue to value passed in from string disc.
        }

        std::string DiscString::getData() const
        {
            return discValue; // Returns discValue.
        }

        std::ostream& operator << (std::ostream& output, const DiscString* disc)
        {
            output << disc->getData(); // Overloaded operator. Prints discValue from disc.
            return output;             // Returns output to be printed.
        }
        std::ostream& operator << (std::ostream& output, const DiscString disc)
        {
            output << disc.getData(); // Overloaded operator. Prints discValue from disc.
            return output;            // Returns output to be printed.
        }

        bool operator < (const DiscString& discOne, const DiscString& discTwo)
        {
            return (discOne.getData() < discTwo.getData());    // Overloaded bool operator.
        }

        bool operator == (const DiscString& discOne, const DiscString& discTwo)
        {
            return (discOne.getData() == discTwo.getData());    // Overloaded bool operator.
        }