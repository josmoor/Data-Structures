#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

// Functions
void generateRect(int);

// Variables
int numRect;

int main() {
    cout << "Enter number of rectangles: ";
    cin >> numRect;

    generateRect(numRect);

    ofstream outFile;
    outFile.open("rectData.txt");
    outFile << numRect;
    outFile.flush();
    outFile.close();

    return 0;
}

void generateRect(int amount) {
    for(int i = 0; i < amount; i++) {
        bool isOverlap = true;
    }
}