/*	SENG1120: Assignment 2, Nathan Gervasoni: c3339961
    // LinkedList.hpp
    // Implementation for class template LinkedList.
    // Illustrates how class LinkedList.hpp works
//*/


template<typename valueType>
LinkedList<valueType>::LinkedList()
{
    headNode = NULL;    // headNode set NULL.
    tailNode = NULL;    // tailNode set NULL.
    currentNode = NULL; // currentNode set NULL.
    listSize = 0;       // listSize set to 0.
}

template<typename valueType>
LinkedList<valueType>::~LinkedList()
{
    while(headNode != NULL)
    {
        Node<valueType>* deleteNode = headNode;
        if(headNode == tailNode)
        {
            headNode = NULL;   // Setting head to NULL.
            tailNode = NULL;   // Setting tail to NULL.
            delete deleteNode; // delete the last Node.
        }
        else
        {
            headNode = headNode->getNext(); // Head node is moved to the next node in list.
            headNode->setPrevious(NULL);	// previous pointer is set to NULL.
            deleteNode->setNext(NULL);		// sets next pointer to NULL.
            delete deleteNode;				// deletes node.

        }
    }
    currentNode = NULL;				        // currentNode = NULL;
    listSize = 0;
}

template<typename valueType>
void LinkedList<valueType>::addToHead(const valueType disc)
{
    if(headNode == NULL)                      // If headNode is NULL or list is empty.
    {
        headNode = new Node<valueType>(disc); // Sets headNode to a new Node.
        tailNode = headNode;                  // Points tailNode to headNode.
        currentNode = headNode;               // Points currentNode to headNode.
        listSize = 1;                         // listSize is set to 1.
    }
    else
    {
        Node<valueType>* tempNode = new Node<valueType>(disc); // Creates new tempNode.
        headNode->setPrevious(tempNode);                       // headNode previous points to new tempNode.
        tempNode->setNext(headNode);                           // tempNode next points to headNode.
        headNode = tempNode;                                   // headNode holds value of tempNode.
        listSize++;                                            // listSize is incremented.
        tempNode = NULL;                                       // tempNode is made NULL.
    }
}

template<typename valueType>
void LinkedList<valueType>::removeFromHead()
{

    if(listSize == 1)
    {
        Node<valueType> *tempNode = headNode; // Sets a new node to headNode.
        headNode = NULL;                      // head, tail, and currentNode set to NULL.
        tailNode = NULL;
        currentNode = NULL;
        listSize--;                           // Reduce listSize.
        delete tempNode;                      // Removes tempNode.
    }
    else
    {
        Node<valueType> *tempNode = headNode;
        headNode = tempNode->getNext();
        delete tempNode;
        listSize--;
    }
}

template<typename valueType>
void LinkedList<valueType>::moveCurrentToHead()
{
    currentNode = headNode; // Moves currentNode to head.
}

template<typename valueType>
void LinkedList<valueType>::moveCurrentForward()
{
    currentNode = currentNode->getNext(); // Moves currentNode to the the next node it's pointing to.
}

template<typename valueType>
valueType LinkedList<valueType>::getDisc() const
{
    return currentNode->getDisc(); // Returns the data value that currentNode is pointing to.

}template<typename valueType>
valueType LinkedList<valueType>::getHeadDisc() const
{
    return headNode->getDisc(); // Returns the headNode data value.
}

template<typename valueType>
int LinkedList<valueType>::sizeOfList() const
{
    return listSize; // Returns the total size of the list.
}

template<typename valueType>
std::ostream& operator << (std::ostream& output, LinkedList<valueType>& inputList)
{
    inputList.moveCurrentToHead();            // Moves currentNode to the position of the headNode.

    while(inputList.getCurrentNode() != NULL) // While the currentNode is not NULL.
    {
        output << inputList.getDisc();        // Output the inputLists disc value.
        inputList.moveCurrentForward();       // Moves the currentNode forward.
    }
    return output;                            // Returns output.
}