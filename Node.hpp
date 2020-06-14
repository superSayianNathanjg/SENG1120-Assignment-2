/*	SENG1120: Assignment 2, Nathan Gervasoni: c3339961
    // Node.hpp
    // Implementation for class template Node.
    // Illustrates how class Node.hpp works
*/

#include "Node.h"

/* Constructor and Destructor. */
template<typename valueType>
Node<valueType>::Node(const valueType& disc)
{
    data = disc;     // Sets the data to the valueType of disc input. This can be either be from discString, or discInt.
    next = NULL;     // Sets the next pointer to location of initialNext.
    previous = NULL; // Sets the previous pointer to the location of initialPrevious.
}

template<typename valueType>
Node<valueType>::~Node()
{
    next = NULL;
    previous = NULL;
    // Value of data is deleted once out of scope as it's not dynamic.
}

/* Public member functions. */
template<typename valueType>
void Node<valueType>::setDisc(const valueType& disc)
{
    data = disc; // Sets the nodes data to the value of valueType disc.
}

template<typename valueType>
void Node<valueType>::setNext(Node<valueType>* nextNode)
{
    next = nextNode; // Sets value of next to input.
}

template<typename valueType>
void Node<valueType>::setPrevious(Node<valueType>* previousNode)
{
    previous = previousNode; // Sets value of previous to input.
}

template<typename valueType>
valueType Node<valueType>::getDisc() const
{
    return data; // Returns value stored within data.
}

// Unused function.
template<typename valueType>
Node<valueType>* Node<valueType>::getPrevious() const
{
    return previous;
}

template<typename valueType>
Node<valueType>* Node<valueType>::getNext() const
{
    return next;
}
