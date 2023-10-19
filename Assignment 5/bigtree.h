#ifndef BIGTREE_H
#define BIGRREE_H

#include<iostream>
#include<fstream>
#include<string>
#include<map>

struct node {
    int* data;
    int* childCount[2];
    node* parent = nullptr;
    node* prev = nullptr;
    node* next = nullptr;
    node* children[2];
};

class BigTree {

    private:
        node * root = nullptr;

        int setParentToFirst(node* tmpNextLoc) {
            while(tmpNextLoc->prev != nullptr) {
                tmpNextLoc = tmpNextLoc->prev;
            }

            if(tmpNextLoc->data >= tmpNextLoc->parent->data) {
                tmpNextLoc->parent->children[1] = tmpNextLoc;
                tmpNextLoc->parent->childCount[1] += 1;
                return 0;
            } else {
                tmpNextLoc->parent->children[0] = tmpNextLoc;
                tmpNextLoc->parent->childCount[0] += 1;
                return 1;
            }
        }

        std::string getLine(node* loc) {
            std::string ret = "";


        }

    public:
        BigTree() { }
        ~BigTree() {
            node* tmp = root;
            while(tmp->next != nullptr)
                tmp = tmp->next;

            node* tmpNext = tmp;

            while(root->children[0] != nullptr) {
                if(hasChildren(tmpNext)) {
                    tmpNext = tmpNext->children[1] != nullptr ? tmpNext->children[1] : tmpNext->children[0];

                    while(tmpNext->next != nullptr)
                        tmpNext = tmpNext->next;

                    tmp = tmpNext;
                } else {
                    if(tmp->prev != nullptr) {
                        tmp = tmp->prev;
                    } else {
                        tmp = tmp->parent;

                        if(*tmp->data >= *tmp->parent->data)
                            tmp->children[1] = nullptr;
                        else
                            tmp->children[0] = nullptr;
                    }

                    tmpNext->data = nullptr;
                    tmpNext->childCount[0] = nullptr;
                    tmpNext->childCount[1] = nullptr;
                    tmpNext->parent = nullptr;
                    tmpNext->prev = nullptr;
                    tmpNext->next = nullptr;

                    delete[] tmpNext->children;
                    delete[] tmpNext->childCount;
                    delete tmpNext->parent;
                    delete tmpNext->next;
                    delete tmpNext->prev;
                    delete tmpNext->data;
                    delete tmpNext;

                    tmpNext = tmp;
                }
            }

            delete[] tmpNext->children;
            delete[] tmpNext->childCount;
            delete tmpNext->parent;
            delete tmpNext->next;
            delete tmpNext->prev;
            delete tmpNext->data;

            delete tmpNext;
            delete tmp;
            delete root;
        }

        bool hasChildren() {
            node* child = root->children[0];

            if(child == nullptr) return false;
            else return true;
        }

        bool hasChildren(node* look) {
            return look->children[0] != nullptr || look->children[1] != nullptr;
        }

        bool anySiblingHasChildren(node* look) {
            while(look->prev != nullptr)
                look = look->prev;

            while(look->next != nullptr) {
                if(hasChildren(look))
                    return true;
                look = look->next;
            }

            return false;
        }

        int getChildrenNum(node* look) {
            if(!hasChildren(look))
                return 0;
            else {
                int ret = 1;
                for(int i = 1; i < 4; i++)
                    ret += look->children[i] != nullptr ? 1 : 0;

                return ret;
            }
        }

        void insert(node* newNode, node* tmpRoot) {
            node* tmpNext = tmpRoot;
            bool isPlaced = false;

            if(root == nullptr) {
                root = newNode;
                return;
            }

            if(!anySiblingHasChildren(tmpNext)) {
                while(tmpNext->next != nullptr) {
                    if(tmpNext->data > newNode->data)
                        break;
                    else
                        tmpNext = tmpNext->next;
                }

                if(tmpNext->data > newNode->data) {
                    if(tmpNext->prev == nullptr) {
                        tmpNext->prev = newNode;
                        newNode->next = tmpNext;
                    } else {
                        tmpNext->prev->next = newNode;
                        newNode->prev = tmpNext->prev;
                        newNode->next = tmpNext;
                        tmpNext->prev = newNode;
                    }
                } else {
                    if(tmpNext->next == nullptr) {
                        tmpNext->next = newNode;
                        newNode->prev = tmpNext;
                    }  else {
                        tmpNext->next->prev = newNode;
                        newNode->next = tmpNext->next;
                        newNode->prev = tmpNext;
                        tmpNext->next = newNode;
                    }
                }

                newNode->parent = tmpNext->parent;

                int which = setParentToFirst(tmpNext);
                reconstruct(tmpNext, which);
            } else { // Has Children
                bool hasBeenFound = false;

                while(tmpNext->next != nullptr) {
                    if(tmpNext->data > newNode->data) {
                        tmpRoot = tmpNext->children[0];
                        insert(newNode, tmpNext);
                        hasBeenFound = true;
                        break;
                    } else
                        tmpNext = tmpNext->next;
                }

                if(!hasBeenFound) { // Compare last node
                    if(tmpNext->data < newNode->data) {
                        tmpRoot = tmpNext->children[0];
                        insert(newNode, tmpRoot);
                    } else {
                        tmpRoot = tmpNext->children[1];
                        insert(newNode, tmpRoot);
                    }
                }
            }
        }

        void reconstruct(node* tmpRoot, int childID) {
            if(*tmpRoot->parent->childCount[childID] != 5)
                return;
            else {
                while(tmpRoot->prev != nullptr)
                    tmpRoot = tmpRoot->prev;

                tmpRoot = tmpRoot->next->next; // Gets middle (medium) value of all siblings

                tmpRoot->prev->prev->parent = tmpRoot;
                tmpRoot->prev->parent = tmpRoot;        // Set previous two values to children of current node

                if(hasChildren(tmpRoot)) {
                    tmpRoot->prev->children[1] = tmpRoot->children[0];
                    node* tmpNext = tmpRoot->children[1];

                    while(tmpNext != nullptr)
                        tmpNext->parent = tmpRoot->prev;
                }

                if(tmpRoot->data < tmpRoot->parent->data) {
                    tmpRoot->parent->children[0] = tmpRoot->next; // Set parent child to next node
                    tmpRoot->childCount[0] = new int(2);
                    tmpRoot->parent->childCount[0] = new int(2);
                    tmpRoot->prev->next = nullptr;
                    tmpRoot->next->prev = nullptr;

                    if(tmpRoot->parent->prev != nullptr) { // Parent has LEFT sib
                        tmpRoot->parent->prev->next = tmpRoot;
                        tmpRoot->prev = tmpRoot->parent->prev;
                        tmpRoot->next = tmpRoot->parent;
                        tmpRoot->parent->prev = tmpRoot;
                        tmpRoot->parent = tmpRoot->next->parent;
                    } else { // Parent has NO LEFT sib
                        tmpRoot->prev = nullptr;
                        tmpRoot->parent->prev = tmpRoot;
                        tmpRoot->next = tmpRoot->parent;
                        tmpRoot->parent = tmpRoot->next->parent;
                    }
                } else { // >=
                    tmpRoot->parent->children[1] = nullptr;
                    tmpRoot->parent->childCount[1] = 0;
                    tmpRoot->childCount[0] = new int(2);
                    tmpRoot->childCount[1] = new int(2);
                    tmpRoot->children[0] = tmpRoot->prev->prev;
                    tmpRoot->children[1] = tmpRoot->next->next;
                    tmpRoot->prev->next = nullptr;
                    tmpRoot->next->prev = nullptr;
                    tmpRoot->next->next->parent = tmpRoot;
                    tmpRoot->next->parent = tmpRoot;
                    tmpRoot->parent->next = tmpRoot;
                    tmpRoot->next = nullptr;
                    tmpRoot->prev = tmpRoot->parent;
                    tmpRoot->parent = tmpRoot->prev->parent;
                }

                int which = setParentToFirst(tmpRoot);
                reconstruct(tmpRoot, which);
            }
        }

        void displayTree(std::map<int, std::string> tree, node* tmpRoot, int depth) {
            //node* tmpRoot = root;
            node* tmpNext = tmpRoot;

            while(tmpNext->next != nullptr)
                tmpNext = tmpNext->next;

            while(hasChildren(tmpNext)) {
                tmpNext = tmpNext->children[1];
                tmpRoot = tmpNext;
                depth++;

                while(tmpNext->next != nullptr)
                    tmpNext = tmpNext->next;
            }

            std::string add = "";

            while(tmpNext != nullptr) {
                add = "(" + std::to_string(*tmpNext->parent->data) + ")" + std::to_string(*tmpNext->data) + " " + add;
            }

            if(tree.count(depth) == 1) {
                std::string current = tree.at(depth);
                current = add + " | " + current;
                tree.at(depth) = current;
            } else
                tree.at(depth) = add;

            if(depth != 0) {
                tmpNext = tmpRoot;
                tmpRoot = tmpRoot->parent;
                depth--;
                bool stop = false;

                while(!stop) {
                    //TODO: If children[1] is complete, move to children[0]
                    //TODO: If children[0] is complete, move to previous
                    //TODO: If previous is null, move to parent.
                    //TODO: Repeat previous steps.
                }
            }

            if(tmpRoot != nullptr)
                displayTree(tree, tmpRoot, depth);
            else
                return;
        }

        void displayKeys() {

        }

};

#endif