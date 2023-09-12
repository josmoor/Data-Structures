#include <iostream>
#include <stdio.h>
#include <fstream>
#include <rectObj.h>
#include <circleObj.h>

using namespace std;

// Functions
void generateCircles(int);

// Variables
int numRect;
Rectangle rects[];
Circle circles[];

int main() {
    cout << "Enter number of rectangles: ";
    cin >> numRect;

    circles = new Circle[numRect];
    rects = new Rectangle[numRect];

    generateCircles(numRect);

    for(int i = 0; i < numRect; i++) {
        rects[i] = circles[i].getRect();
    }

    writeData();
    return 0;
}

/*
* Takes all the information of the Rectangles and final Obscurity angle and outputs
* the data into two files. The file containing the Rectangle data is then used into
* another format to display the visible representation of the rectangles.
*/
void writeData() {
    ofstream outputFile;

    outputFile.open("rectData.txt");

    for (int i = 0; i < numRect; i++) {
        outputFile << rects[i].getX() + ","
            << rects[i].getY() + ","
            << rects[i].getPointX() + ","
            << rects[i].getPointY() + ","
            << rects[i].getLength() + ","
            << rects[i].getWidth() + ","
            << rects[i].getAngle() + ","
            << rects[i].getMaxAngleObscure()
            << endl;
    }

    outputFile.flush();
    outputFile.close();

    outputFile.open("angleObscureTotal.txt");
    outputFile << /*Angle Amount*/;
    outputFile.flush();
    outputFile.close();
}

/**
* @parm amount - INT: Number of Rectangles to create. User Defined.
* 
* Generates the number of circles that the user defined. Goes through and ensures none of
* the circles overlap each other in terms of coordinates, distance and radius.
*/
void generateCircles(int amount) {
    for(int i = 0; i < amount; i++) {
        bool isOverlap = true;

        while(isOverlap) {
            //TODO: If overlapping a circle, redefine distance.
        }
    }
}