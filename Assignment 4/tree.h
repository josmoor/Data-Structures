#ifndef TREE_H
#define TREE_H

class Tree {
    public:
        Tree *leftNode;
        Tree *rightNode;
        Tree *parentRoot;
        int value;

        Tree() { }
        Tree(int value) {
            this->value = value;
        }

        int getValue() { return value; }
};

#endif