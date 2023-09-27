#include "tree.h"

// Functions
void getInput();
void place();
void display();

// Variables
Tree *first;

int main() {

    getInput();
    display();

    return 0;
}

void getInput() {
    //TODO: create a a loop asking for user input
    //TODO: Stop at user non-int value.
    //TODO: Resize during loop for balance //place();
}

void display() {
    Tree *dis = *first;

    while(*dis.getLeftChild() != null) {
        *dis = *dis.getLeftChild();
    }

    std::cout << "Lowest Value: " << *dis.getValue() << std::endl;
}