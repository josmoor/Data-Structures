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
bool getOverlap();

// Variables
std::vector<Queen> full; // Contains all the non-placed queens
std::vector<int> posR;
std::vector<int> posC;
std::stack<Queen> empty; // Contains the placed / placing-at-the-moment queens
int end = 0;

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

    outFile.open("outputData.txt");
    outFile << Vars::size << "," << Vars::size << std::endl; // Outputs the size of the board at first line.

    for(int i = 0; i < posR.size(); i+=2) {
        outFile << posR.at(i) << ","
            << posC.at(i)
            << std::endl;
        
        empty.pop(); // Removes top Queen Object.
    }

    outFile.flush();
    outFile.close();
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
        std::cout << "P:" << posC.size() << std::endl;
        if(moveQueen) { // No spot for current queen. Reset column to 1st, push queen back, move previous queen
            empty.top().setColumn(1);
            full.push_back(empty.top());
            empty.pop();
            end--;

            empty.top().increaseCol();
            removePos();
            
            // Queen at edge of wall, recall function.
            if(empty.top().getColumn() > Vars::size) {
                std::cout << "HIT!" << std::endl;
                placeQueens(true);
            }
        } else { // queen placed, start moving next queen
            if(end + 1 == Vars::size && full.empty()) {
                end++;
                return;
            }

            if(empty.size() != 0)
                storePosition();
            
            empty.push(full.back());
            end++;
            full.pop_back();
        }

<<<<<<< HEAD
        bool retry = false;
        for(int i = 0; i < Vars::size + 10; i++) {
            if(getOverlap()) {
                empty.top().increaseCol();

                if(empty.top().getColumn() > Vars::size) {
                    retry = true;
                    end--;
                    break;
                }
=======
        while(getOverlap()) { // Loop until queen is capable of being placed.
            empty.top().increaseCol(Vars::size);
            
            if(empty.top().getColumn() > Vars::size) { // Queen reached edge of board, recall function
                empty.top().setColumn(1);
                placeQueens(true);
>>>>>>> 1be0de7e0906c303ada50aaf2c61f1c8611d494b
            }
        }

        placeQueens(retry);
    } else return;
}

bool getOverlap() {

    for(int i = 0; i < posR.size(); i++) {
        if(empty.top().overlap(posR.at(i), posC.at(i))) // i = row, i+1 = column
            return true;
    }

    return false;
}

void removePos() {
    posR.pop_back();
    posC.pop_back();
}

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