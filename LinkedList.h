/*  SENG1120: Assignment 2, Nathan Gervasoni: c3339961
     // LinkedList.h
     // Header file and class definition of template class LinkedList.h
     //
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <cstdlib>
#include "Node.h"

template<typename valueType>
class LinkedList
{
    public:
            //Constructors.
        LinkedList();
            // Destructor.
        ~LinkedList();
            //Destructor for LinkedList class.
            //Public member functions
        void addToHead(const valueType disc);
            // Adds a node to the head of the Linked List.
            // Pre-condition: LinkedList is initialised and has Nodes stored within.
            // Post-condition: Nodes will be added to the head, each node will add a new disc.
        void removeFromHead();
            // Removes a node from the head of the LinkedList.
            // Pre-condition: LinkedList and head node must exist.
            // Post-condition: Removes head node from the list.
        void moveCurrentToHead();
            // Moves the currentNode to the head of the LinkedList.
            // Pre-condition: LinkedList must exist.
            // Post-condition: CurrentNode is placed at top of the LinkedList.
        void moveCurrentForward();
            // Moves the currentNode forward.
            // Pre-condition: LinkedList exists and the currentNode is not NULL.
            // Post-condition: Iterates through list until set to stop.
        valueType getDisc() const;
            // Returns the value that the disc is storing.
            // Pre-condition: LinkedList exists and has nodes stored.
            // Post-condition: Returns currentNode.
        valueType getHeadDisc() const;
            // Pre-condition: LinkedList exists and headNode is not NULL.
            // Post-condition: Returns the headNodes disc value.
        int sizeOfList() const;
            // Function to check size of the chosen linkedList.
            // Pre-condition: LinkedList must exist and have nodes stored within.
            // Post-condition: Returns an int with the size of the LinkedList.
        private:
            Node<valueType>* currentNode;
            Node<valueType>* headNode;
            Node<valueType>* tailNode;
            int listSize;
};

template<typename valueType>
std::ostream& operator << (std::ostream& output, LinkedList<valueType>& inputList);
// Overrides print operator.

#include "LinkedList.hpp" // Includes LinkedList.hpp implementation file.
#endif
