#include "tree.h"

// Functions
void getInput();
void place(int);
void balance();
void display();

// Variables
Tree *first;

int main() {

    getInput();
    display();

    return 0;
}

void getInput() {
    int counter;
    int value;

    std::cout << "Enter array size: ";
    std::cint >> counter;

    while(counter > 0) {
        std::cout << "Enter value: ";
        std::cin >> value;

        place(value);
        counter--;
    }
}

void place(int value) {
    if(*first == null) {
        first = new Tree(null, value, 1, 0);
        return;
    } else {
        Tree *current = first;
        bool placing = true;
        while(placing) {
            if(current->getValue() > value) { // <
                //TODO: While loop checking each node.
            } else { // >=

            }
        }
    }
}

void balance() {
    //TODO: Loop through until depth of lowest leaf are 1 off from each other.
}

void display() {
    Tree *dis = *first;

    while(*dis.getLeftChild() != null) {
        *dis = *dis.getLeftChild();
    }

    std::cout << "Lowest Value: " << *dis.getValue() << std::endl;
}