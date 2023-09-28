#include "tree.h"
#include <iostream>
#include <vector>

// Functions
void getInput();
Tree * place(Tree*, int);
void storeElements();
void display();

// Variables
Tree *first = nullptr;
std::vector<int> values;
std::vector<int> element;

int main() {

    getInput();
    
    int mid = values.size() % 2 == 0 ? values.size() / 2 + 1: values.size() / 2;
    first = new Tree(values.at(mid));

    for(int i = mid - 1; i >= 0; i--)
        place(first, values.at(i));

    for(int i = mid + 1; i < values.size(); i++)
        place(first, values.at(i));

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

    for(auto i : values) {
        std::cout << "Value: " << i << std::endl;
    }
}

Tree * place(Tree *node, int value) {
    if(node == NULL) {
        node = new Tree(value);
    } else if(node->getValue() < value) {
        node->rightNode = place(node->rightNode, value);
        node->rightNode->parentRoot = node;
    } else {
        node->leftNode = place(node->leftNode, value);
        node->leftNode->parentRoot = node;
    }

    return node;
}

void display() {
    Tree * dis = first;

    while(dis->leftNode != NULL) {
        dis = dis->leftNode;
    }

    std::cout << "Lowest Inputted value: " << dis->getValue() << std::endl;
}