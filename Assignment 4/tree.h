#ifndef TREE_H
#define TREE_H

class Tree {
    private:
        Tree *parent;
        Tree *left;
        Tree *right;
        int value;
        int height, depth;

    public:
        Tree(Tree *parent, int value, int height, int depth) {
            *this->parent = *parent;
            this->value = value;
            this->height = height;
            this->depth = depth;
        }
        ~Tree() {
            *parent = null;
            *left = null;
            *right = null;
        }

        void setParnet(Tree *parent) {
            *this->parent = *parent;
        }

        void setLeft(Tree *left) {
            *this->left = *left;
        }

        void setRight(Tree *right) {
            *this->right = *right;
        }

        void setHeight(int value) {
            height = value;
        }

        void setDepth(int value) {
            depth = value;
        }

        int getValue() { return value; }
        int getHeight() { return height; }
        int getDepth() { return depth; }

        Tree * getParnet() { return *parnet; }
        Tree * getLeftChild() { return *left; }
        Tree * getRightChild() { return *right; }
}

#endif