/* SENG1120: Assignment 2, Nathan Gervasoni: c3339961
    // TowerHanoi.hpp
    // Implementaion for class TowerHanoi.hpp.
*/

#include <iostream>
#include <vector>

template<typename valueType>
TowerHanoi<valueType>::TowerHanoi(int numberOfDiscs)
{
    sizeOfDisc = numberOfDiscs;                 // Assigns sizeOfDisc an int value.
   towerRods[0] = new LStack<valueType>();      // Creates three dynamic LStack towers.
   towerRods[1] = new LStack<valueType>();
   towerRods[2] = new LStack<valueType>();
    for(int i = numberOfDiscs; i > 0; i--)
    {
        towerRods[0]->pushOnStack(valueType(i)); // For each int size passed it allocates the first tower discs.
    }
}

template<typename valueType>
TowerHanoi<valueType>::~TowerHanoi()
{
   // delete towerRods[3];
   // Empty constructor. Gives a segmentation core dump if uncommented.
}

template<typename valueType>
void TowerHanoi<valueType>::move(int rodFrom, int rodTo)
{

    if (rodFrom < 1 || rodFrom > 3 || rodTo < 1 || rodTo > 3)                 // Ensures the user inputs the correct values.
    {
        std::cout << "\nInvalid rod selection!\n"
                     "Select from tower rods 1-3. Try again.\n" << std::endl;
    }
    else if (rodFrom == rodTo)                                                // Gives error if they're equal.
    {
        std::cout << "\nInvalid rod selection!\n"
                  << "Cannot place disc on same rod. Try again.\n" << std::endl;
    }
        // Error checks. Returns invalid move message.
    else if(towerRods[rodFrom - 1]->emptyStackCheck())
    {
        std::cout << "\nInvalid move!\nRod contains no discs. Try again.\n" << std::endl;
    }
    else if(towerRods[rodTo-1]->emptyStackCheck())
    {
        towerRods[rodTo-1]->pushOnStack(towerRods[rodFrom-1]->popOffStack());
        std::cout << "\n";
        // return;
    }
    else
    {
        if(towerRods[rodFrom-1]->peekStack() < towerRods[rodTo-1]->peekStack())
        {
            towerRods[rodTo-1]->pushOnStack(towerRods[rodFrom-1]->popOffStack());
            std::cout << "\n";
        } else
        {
            std::cout << "\nError!\nCan't place disc onto smaller disc.\n" << std::endl;
        }
    }
}

// Checks pre-requisites for winning the game.
template<typename valueType>
const bool TowerHanoi<valueType>::checkWin()
{
    sizeOfDisc = getDiscSize();
    return(towerRods[2]->sizeOfStack() == sizeOfDisc);
}

// Prints all the towers in current game state.
// Wasn't able to get the blankDiscs implemented correctly.
// Wasn't able to get DiscInt spacing implemented.
template<typename valueType>
const void TowerHanoi<valueType>::printTowers() {


    LStack<valueType> *mirrorRod1 = new LStack<valueType>();  // Dynamic mirror rods.
    LStack<valueType> *mirrorRod2 = new LStack<valueType>();
    LStack<valueType> *mirrorRod3 = new LStack<valueType>();

    for(int i = sizeOfDisc; i > 0; i--)
    {
        std::string discSpace = std::string("         ");
        std::string space = std::string("     ");

        if(towerRods[0]->sizeOfStack() == 0)
        {
            std::cout << discSpace;
        }
        else
        {
            std::cout << towerRods[0]->peekStack();
            mirrorRod1->pushOnStack(towerRods[0]->popOffStack());
        }
        std::cout << space;
        if(towerRods[1]->sizeOfStack() == 0)
        {
            std::cout << discSpace;
        }
        else
        {
            std::cout << towerRods[1]->peekStack();
            mirrorRod2->pushOnStack(towerRods[1]->popOffStack());
        }
        std::cout << space;
        if(towerRods[2]->sizeOfStack() == 0)
        {
            std::cout << discSpace;
        }
        else
        {
            std::cout << towerRods[2]->peekStack();
            mirrorRod3->pushOnStack(towerRods[2]->popOffStack());
        }
        std::cout << space;
        std::cout << "\n";
    }
    std::cout <<("-----------------------------------------------------") << std::endl;
    std::cout << "    1             2             3" << std::endl;

    while(!mirrorRod1->emptyStackCheck())
    {
        towerRods[0]->pushOnStack(mirrorRod1->peekStack());
        mirrorRod1->popOffStack();
    }

    while(!mirrorRod2->emptyStackCheck())
    {
        towerRods[1]->pushOnStack(mirrorRod2->peekStack());
        mirrorRod2->popOffStack();
    }

    while(!mirrorRod3->emptyStackCheck())
    {
        towerRods[2]->pushOnStack(mirrorRod3->peekStack());
        mirrorRod3->popOffStack();
    }

    delete mirrorRod1;
    delete mirrorRod2;
    delete mirrorRod3;
}

template<typename valueType>
const int TowerHanoi<valueType>::getDiscSize()
{
    return sizeOfDisc;
}

template<typename valueType>
std::ostream& operator << (std::ostream& output, TowerHanoi<valueType>& printRods)
{
    printRods.printTowers();
    return output;
}