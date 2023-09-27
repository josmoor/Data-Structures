#ifndef TREE_H
#define TREE_H

class Tree {
    private:
        Tree *parent;
        Tree *left;
        Tree *right;
        int value;

    public:
        Tree(Tree *parent, int value) {
            *this->parnet = *parnet;
            this->value = value;
        }
        ~Tree() {
            *parnet = null;
            *left = null;
            *right = null;
        }

        void setParnet(Tree *parnet) {
            *this->parnet = parnet;
        }

        void setLeft(Tree *left) {
            *this->left = *left;
        }

        void setRight(Tree *right) {
            *this->right - *right;
        }

        int getValue() { return value; }

        Tree * getParnet() { return *parnet; }
        Tree * getLeftChild() { return *left; }
        Tree * getRightChild() { return *right; }
}

#endif