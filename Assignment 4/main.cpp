#include "tree.h"
#include <iostream>
#include <vector>

// Functions
void getInput();
void place();
void display();

// Variables
Tree *first;
std::vector<int> values;

int main() {

    getInput();
    place();
    display();

    return 0;
}

void getInput() {
    int input;
    int counter;
    
    std::cout << "Enter number of values: ";
    std::cin >> counter;

    while(counter > 0) {
        std::cout << "Enter value: ";
        std::cin >> input;
        counter--;

        values.push_back(input);
    }

    for(int i = 0; i < values.size(); i++) {
        for(int j = i + 1; j < values.size(); j++) {
            if(values.at(i) < values.at(j)) {
                int tmp = values.at(i);
                values.at(i) = values.at(j);
                values.at(j) = tmp;
            }
        }
    }
}

void place() {
    
}

void display() {

}