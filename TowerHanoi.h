/* SENG1120: Assignment 2, Nathan Gervasoni: c3339961
    // TowerHanoi.h.
    // Header file and class definition of template class TowerHanoi.h.
    // Illustrates game logic of Tower of Hanoi.
*/

// Macro guard.
#ifndef TOWERHANOI_H
#define TOWERHANOI_H

// Includes relevant libraries.
#include <iostream>
#include <cstdlib>
#include <sstream>
#include "LStack.h"

// Defining template class TowerHanoi.
template<typename valueType>
class TowerHanoi
{
    public:
    /* Constructor and Destructor. */
        TowerHanoi(int numberOfDiscs);
            // Default constructor with int disc setting size.
        ~TowerHanoi();
            // Destructor for TowerHanoi class
        void move(int rodFrom,int rodTo);
            // Move discs between different rods. Must be moved onto a larger disc.
            // Pre-condition: TowerHanoi rods and disc are existing and valid to be moved between.
            // Post-condition: ValueType disc moved to a valid rod. Otherwise error printed.
        const bool checkWin();
            // Checks if user has required position to win.
            // Pre-condition: TowerHanoi rods and disc are existing.
            // Post-condition: If the third Tower rod has all discs, then return true.
            //                 Otherwise return false.
        const int getDiscSize();
            // Returns size of TowerHanoi discs on rod.
            // Pre-condition: Rod must be existing.
            // Post-condition: Returns an int with number of discs.
        const void printTowers();
            // Prints current status of TowerHanoi game. Uses mirror Towers to print.
            // Stores size of existing towers and then prints.
            // Pre-condition: Tower rods are existing.
            // Post-condition: Towers and discs are displayed either in "X" or in numeral form.
    /* Private members. */
    private:
        LStack<valueType>* towerRods[3];
            // Array of three valueTypes are created for the towerRods.
        int sizeOfDisc;
            // Used to track number of discs on individual ropd.
            // checkWin() uses sizeOfRod to enable end of game.
};

// Overriding print function.
template<typename valueType>
std::ostream& operator << (std::ostream& output, TowerHanoi<valueType>& printRods);

#include "TowerHanoi.hpp" // Includes TowerHanoi.hpp implementation file.
#endif
