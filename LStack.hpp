/*	SENG1120: Assignment 2, Nathan Gervasoni: c3339961
    // LStack.hpp
    // Implementation for class template LStack.h.
    // Illustrates how class LinkedList.hpp works.
//*/

template<typename valueType>
LStack<valueType>::LStack()
{
    linkedList = new LinkedList<valueType>(); // Dynamic LinkedList created.
}

template<typename valueType>
LStack<valueType>::~LStack()
{
     delete linkedList; // Deletes LinkedList.
}

template<typename valueType>
void LStack<valueType>::pushOnStack(const valueType& disc)
{
    linkedList->addToHead(disc); // Adds a disc to the top of the LStack.
}

template<typename valueType>
valueType LStack<valueType>::popOffStack() const
{
    valueType dataCollection = linkedList->getHeadDisc(); // valueType object collects the headNode disc value.
    linkedList->removeFromHead();                         // Removes the headNode from the LStack.
    return dataCollection;                                // Returns the valueType object.
}

template<typename valueType>
valueType LStack<valueType>::peekStack() const
{
    if(!emptyStackCheck())                // If LStack is not empty.
    {
        return linkedList->getHeadDisc(); // Returns the headNode disc value.
    } else
    {
        return valueType();              // Otherwise returns an empty disc.
    }
}

template<typename valueType>
int LStack<valueType>::sizeOfStack() const
{
    return linkedList->sizeOfList(); // Returns the size of LStack.
}

template<typename valueType>
bool LStack<valueType>::emptyStackCheck() const
{
    return linkedList->sizeOfList() == 0; // Determines if the Lstack is empty. Returns true if it is.
}

template<typename valueType>
std::ostream& operator << (std::ostream& output, LStack<valueType> inputStack)
{
    LStack<valueType>* copyStack = new LStack<valueType>;  // Creates dynamic LStack object.
    while(!inputStack->emptyStackCheck())                  // Whilst the inputStack is not empty.
    {
        copyStack->pushOnStack(inputStack->popOffStack()); // Pushes head disc of inputList onto the copyList.
        output << inputStack->peekStack();                 // Returns value of head disc on inputList.
    }
    while(!copyStack->emptyStackCheck())                   // Whilst the copyStack is not empty.
    {
        inputStack->pushOnStack(copyStack->popOffStack()); // Pushes head disc of copyList onto the inputList.
    }
    delete copyStack;                                      // Deletes the copyStack.
    return output;                                         // Returns output.
}
