#ifndef TREE_H
#define TREE_H

class Tree {
    private:
        Tree left;
        Tree right;
        Tree parent;
        int value;

    public:
        Tree(int value, Tree parent) {
            this->value = value;
            this->parent = parent;
        }
};

#endif