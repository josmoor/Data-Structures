#ifndef TREE_H
#define TREE_H

class Tree {
    private:
        Tree *left = nullptr;
        Tree *right = nullptr;
        Tree *parent = nullptr;
        int value;

    public:
        Tree() { }
        Tree(int value, Tree *parent) {
            this->value = value;
            this->parent = parent;
        }

        void setParent(Tree *parent) {
            this->parent = parent;
        }

        void setLeftChild(Tree *left) {
            this->left = left;
        }

        void setRightChild(Tree *right) {
            this->right = right;
        }

        int getValue() { return value; }

        Tree *getParent() { return parent; }
        Tree *getLeftChild() { return left; }
        Tree *getRightChild() { return right; }
};

#endif