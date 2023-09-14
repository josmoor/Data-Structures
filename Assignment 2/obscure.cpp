#include <iostream>
#include <stdio.h>
#include <fstream>
#include "rectObj.h"
#include "circleObj.h"
#include <vector>

using namespace std;

// Functions
void generateCircles(int);

// Variables
int numRect;
vector<Circle> circles;
vector<Rectangle> rects;

int main() {
    cout << "Enter number of rectangles: ";
    cin >> numRect;

    circles.resize(numRect);
    rects.resize(numRect);

    generateCircles(numRect);

    for(int i = 0; i < numRect; i++) {
        rects.at(i) = * new Rectangle(circles[i].getX(), circles[i].getY(), circles[i].getRadius());
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
        outputFile << rects.at(i).getCenterX() << ","
            << rects.at(i).getCenterY() << ","
            << rects.at(i).getPointX(0) << ","
            << rects.at(i).getPointY(0) << ","
            << rects.at(i).getPointX(1) << ","
            << rects.at(i).getPointY(1) << ","
            << rects.at(i).getPointX(2) << ","
            << rects.at(i).getPointY(2) << ","
            << rects.at(i).getPointX(3) << ","
            << rects.at(i).getPointY(3) << ","
            << rects.at(i).getMinAngle() << ","
            << rects.at(i).getMaxAngle() << ","
            << endl;
    }

    outputFile.flush();
    outputFile.close();

    outputFile.open("angleObscureTotal.txt");
    outputFile << "VALUE" /*Angle Amount*/;
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
        float points[2] = {rand() % 10 + 1,rand() % 10 + 1};

        circles.at(i) = * new Circle(points, rand() % 15 + 1);

        while(isOverlap) {
            if(!circles.at(i).isInCircle({1.1,1.1}, 1))
                isOverlap = false;
            else {
                points[0] = rand() % 10 + 1;
                points[1] = rand() % 10 + 1;

                circles.at(i).setPosition(points);
            }
        }
    }
}