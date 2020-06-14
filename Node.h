/* SENG1120: Assignment 2, Nathan Gervasoni: c3339961
    // Node.h
    // Header file and class definition of template class Node.h
    // This class will store instances of DiscInt && DiscString.
    // Node class is then used to construct the LinkedList class.
*/

// Macro guard.
#ifndef NODE_H
#define NODE_H

// Includes relevant library.
#include <cstdlib>

// Defining template class Node.
template<typename valueType>
class Node
{
    public:
    /* Constructor and destructor. */
        Node(const valueType& disc = valueType());
            // Default Constructor allowing for template valueType.
        ~Node();
            // Destructor for Node class.
     /* Public member functions. */
        void setDisc(const valueType& disc);
            // Pre-condition: ValueType is int or string type.
            // Post-condition: ValueType input is stored in 'tempDisc' then copied to valueType variable 'disc'.
            // Variable 'disc' is then updated.
        void setNext(Node<valueType>* nextNode);
            // Pre-condition: Pointer 'next' must be existing, and either NULL, or pointing to another Node.
            // Post-condition: Pointer 'next' is set to desired Node.
        void setPrevious(Node<valueType>* previousNode);
            // Pre-condition: Pointer 'previous' must be existing, and either NULL, or pointing to another Node.
            // Post-condition: Pointer 'previous' is set to desired Node.
        valueType getDisc() const;
            // Pre-condition: Node has been created, and has been allocated a data type with value.
            // Post-condition: Data of valueType stored within the node is retrieved.
         Node<valueType>* getNext() const;
            // Pre-condition: Pointer 'nextNode' must be existing, and either NULL, or pointing to another Node.
            // Post-condition: The value of 'nextNode' is returned.

        // Unused function.
         Node<valueType>* getPrevious() const;
            // Pre-condition: Pointer 'previousNode' must be existing, and either Null, or pointing to another Node.
            // Post-condition: The value of 'previousNode is returned.

    /* Private members. */
    private:
        valueType data;
            // ValueType: String or Int from DiscInt/DiscString classes.
        Node<valueType> *next;
            // Private pointer variable 'next'.
        Node<valueType> *previous;
            // Private pointer variable 'previous'.
};

#include "Node.hpp" // Includes Node.hpp implementation file.
#endif