/*  SENG1120: Assignment 2, Nathan Gervasoni: c3339961
     // LStack.h
     // Header file and class definition of template class LStack.h
     //
*/

#ifndef LSTACK_H
#define LSTACK_H

#include <iostream>
#include <cstdlib>
#include "LinkedList.h"

template<typename valueType>
class LStack
{
    public:
        LStack();
            // Default constructor.
        ~LStack();
            // Destructor.
        void pushOnStack(const valueType& disc);
            // Pre-condition: LStack must be existing and the input is a valid valueType disc.
            // Post-condition: A disc is pushed onto the LStack.
        valueType popOffStack()const;
            // Pre-condition: LStack and disc must be existing.
            // Post-condition: Removes a disc from the stack.
        valueType peekStack()const;
            // View top of the LStack.
            // Pre-condition: LStack exists and holds one or more discs.
            // Post-condition: Returns the disc stored at the head of the LStack.
        int sizeOfStack()const;
            // Find out the size of the LStack.
            // Pre-condition: LStack exists.
            // Post-condition: Returns an int with the value representing the size of the LStack.
        bool emptyStackCheck() const;
            // Determine if a Lstack is empty.
            // Pre-condition: LStack must be existing.
            // Post-condition: Returns true if the LStack is empty.

    private:
        LinkedList<valueType>* linkedList;
};

template<typename valueType>
std::ostream& operator << (std::ostream& output, LStack<valueType> inputStack);

#include "LStack.hpp" // Includes LStack.hpp implementation file.
#endif
