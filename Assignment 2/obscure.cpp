#include <iostream>
#include <stdio.h>
#include <fstream>
#include <rectObj.h>
using namespace std;

// Functions
void generateRect(int);

// Variables
int numRect;
Rectangle rects[];

int main() {
    cout << "Enter number of rectangles: ";
    cin >> numRect;

    generateRect(numRect);
    writeData();

    return 0;
}

void writeData() {
    ofstream outputFile;

    outputFile.open("rectData.txt");

    //TODO Loop

    outputFile.flush();
    outputFile.close();
}

void generateRect(int amount) {
    for(int i = 0; i < amount; i++) {
        bool isOverlap = true;

        while(isOverlap) {
            
        }
    }
}