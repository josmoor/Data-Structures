#include "queen.h"
#include <iostream>
#include <fstream>
#include <stack>
#include <vector>

// Functions
void placeQueens(bool);
void getQueens();
void output();
void removePos();
void storePosition();
void addToStack();
void removeFromStack();
bool tryPlace();
bool getOverlap();

// Variables
std::vector<Queen> full; // Contains all the non-placed queens
std::vector<int> posR; // Contains Position (Row) of placed queens
std::vector<int> posC; // Contains Position (Column) of placed queens.
std::stack<Queen> empty; // Contains the placed / placing-at-the-moment queens
int end = 0; // Queen Counter

// Global size variable
namespace Vars {
    int size; // Size of the board
}

// Main
int main() {
    getQueens();
    placeQueens(false);
    output();
}
 /**
 Type: Function
 Name: output
 Return: Void
 Desciption:
    Creates a file named "outputData.txt" if the file does not exist. Once the file exists, then the program
    will open the file to be written to. The format of the file is a CSV-style ("","","",...) having two
    values in each line; Row and Column. One each iteration of the loop, the top Queen object is popped and
    removed until empty. Once empty, the loop exits and the file is flushed/closed of data.
 */
void output() {
    std::ofstream outFile;
    std::ofstream displayFile;
    std::string graphic;

    outFile.open("outputData.txt");
    displayFile.open("graphicalDisplay.txt");
    outFile << Vars::size << "," << Vars::size << std::endl; // Outputs the size of the board at first line.

    while(empty.size() != 0) {
        graphic = "";
        for(int i = 0; i < Vars::size; i++)
            graphic.append((i + 1 == empty.top().getColumn() ? "Q" : "-"));

        outFile << empty.top().getRow() << "," << empty.top().getColumn() << std::endl;
        displayFile << graphic << std::endl;
        empty.pop();
    }

    outFile.flush();
    outFile.close();
    displayFile.flush();
    displayFile.close();
}

/**
Type: Function
Name: placeQueens
Return: void
Parameters: Boolean - moveQueen
Description:
    Using recursion, runs through each queen's location and places it on the board. If the queen cannot be placed,
    then the queen is pushed back to the vector and the previous queen is than set to move until a spot is found. This
    repeats until the lowest queen can move to a spot no occupied by another queen. Once the queen is capable of being
    placed, the loop is exited and the 'end' value (stack size count) is increased by 1. The function is called until
    all queens have been placed ('end' value is equal to the size of the board).
*/
void placeQueens(bool moveQueen) {
    if(end < Vars::size) { // If there is still a queen that can be moved (ie. 1 or 100 queen(s) left to move)
        bool retry = false; // Determines if the recursion requires the stack to POP (remove) the current queen.

        // recalled, no conflict
        if(!moveQueen) { // If Queen does NOT need to be popped, add another queen
            addToStack(); // Adds queen
            retry = tryPlace(); // Checks queen conflict on board

            // If no conflict, store the position for queen checking, recall function.
            // If Conflict, remove from stack, recall function.
            if(!retry) {
                storePosition();
                placeQueens(retry);
            } else {
                removeFromStack();
                placeQueens(retry);
            }

        // (Recalled) if conflicted
        } else {
            // Move current queen
            empty.top().increaseCol();

            // If pass board edge, remove from stack, recall function
            if(empty.top().getColumn() > Vars::size) {
                removeFromStack();
                placeQueens(true);

            // If not at edge, re-check all board queen conflict
            } else {
                retry = tryPlace();

                // If no conflict, store position, recall
                if(!retry) {
                    storePosition();
                    placeQueens(retry);
                } else { // Conflict, remove from stack, recall.
                    removeFromStack();
                    placeQueens(retry);
                }
            }
        }

    } else return; // All queens have been placed.
}

/**
 * Type: Function
 * Name: addToStack
 * Return: Void
 * Description: Adds the next queen to the stack for moving. Increases the counter for the queens. 
*/
void addToStack() {
    empty.push(full.back());
    full.pop_back();
    end++;
}

/**
 * Type: Function
 * Name: removeFromStack
 * Return: removeFromStack
 * Description: Resets the queen to the first column and pushes it back into the vector containing all un-placed queens (used like a stack).
 * Removes the queen from the current stack, removes it's stored position and decreases queen counter.
*/
void removeFromStack() {
    empty.top().setColumn(1);
    full.push_back(empty.top());
    empty.pop();
    removePos();
    end--;
}

/**
 * Type: Function
 * Name: tryPlace
 * Return: Boolean
 * Description: Attempts to place the queen in the current location. If the queen has some conflict with a single queen
 * then this will return true (conflict), other false (no conflict). If the queen goes beyond the board, then a conflict
 * is incurred.
*/
bool tryPlace() {
    for(int i = 0; i < Vars::size + 1; i++) {
        if(getOverlap())
            empty.top().increaseCol();

        if(empty.top().getColumn() > Vars::size) {
            return true;
        }
    }

    return false;
}

/**
 * Type: Function
 * Name: getOverlap
 * Return: Boolean
 * Description: Runs through all placed queens and calculates the Row, Column and Diagonals. If any of the said
 * items match to the current queen, then a conflict is found and returned true.
*/
bool getOverlap() {

    if(posC.size() == 0 || posR.size() == 0)
        return false;

    for(int i = 0; i < posR.size(); i++) {
        if(empty.top().overlap(posR.at(i), posC.at(i))) // i = row, i+1 = column | Checking previous queens to CURRENT queen
            return true;
    }

    return false;
}

/**
 * Type: Function
 * Name: removePos
 * Return: Void
 * Description: Removes the position of the current Queen from the stored postions.
*/
void removePos() {
    posR.pop_back();
    posC.pop_back();
}

/**
 * Type: Function
 * Name: storePosition
 * Return: Void
 * Description: Stores the current Queen's location for checking with future queens.
*/
void storePosition() {
    posR.push_back(empty.top().getRow());
    posC.push_back(empty.top().getColumn());
}

/**
Type: Function
Name: getQueens
Return: void
Description:
    Asks the user to input the number of queens to place. This also sets
    the size of the board (ie. 16 queens = 16x16 board). If the number is
    below 4, then the user is asked again to input a new numerical value.
*/
void getQueens() {
    int amount = 0;

    while(amount < 3) {
        std::cout << "Enter number of Queens (Greater than 3): ";
        std::cin >> amount;

        if(amount < 3)
            std::cout << "Value is not greater than 3...\n";
    }

    Vars::size = amount;

    for(int i = 0; i < amount; i++)
        full.push_back(*new Queen(amount - i));

    empty = *new std::stack<Queen>();
    posR = *new std::vector<int>();
    posC = *new std::vector<int>();
}