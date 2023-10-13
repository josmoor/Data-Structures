#ifndef BIGTREE_H
#define BIGRREE_H

struct node {
    int data;
    int sibCount = 0;
    node* parent = nullptr;
    node* prev = nullptr;
    node* next = nullptr;
    node* children[5];
};

class BigTree {

    private:
        node * root = nullptr;

        void setSibCount(node* where, int value) {
            while(where->prev != nullptr)
                where = where->prev;

            do {
                where->sibCount = value;
                where = where->next;
            } while(where->next != nullptr);
        }

    public:
        BigTree() { }
        ~BigTree() {
            node* tmp = root;
            while(tmp->next != nullptr)
                tmp = tmp->next;

            node* tmpNext = tmp;

            while(root->children[0] != nullptr) {
                if(getChildrenNum() == 0 && tmp->prev == nullptr) {
                    tmpNext = tmp->parent;
                    delete[] tmp->children;
                    delete tmp;
                    tmp = tmpNext;
                } else {
                    int childrenNum = getChildrenNum();
                    if(childrenNum < 1) {
                        tmpNext = tmp->prev;
                        delete tmp;
                    } else {
                        tmpNext = tmp->children[childrenNum - 1];
                        while(tmpNext->next != nullptr)
                            tmpNext = tmpNext->next;
                        tmp = tmpNext;
                    }
                }
            }

            delete tmp;
            delete tmpNext;
            delete root;
        }

        bool hasChildren() {
            node* child = root->children[0];

            if(child == nullptr) return false;
            else return true;
        }

        bool hasChildren(node* look) {
            return look->children[0] != nullptr;
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

        void insert(int value) {
            node* n = new node;
            n->data = value;

            node* tmp = root;
            node* tmpNext = tmp;

            bool isPlacable = false;

            while(!isPlacable) {
                if(!anySiblingHasChildren(tmpNext)) {
                    tmp = tmpNext;

                    do {
                        if(value > tmpNext->data) {
                            tmp = tmpNext;
                            tmpNext = tmpNext->next;
                        } else {
                            isPlacable = true;

                            if(tmpNext->prev == nullptr) {
                                tmpNext->prev = n;
                                n->next = tmpNext;
                            } else {
                                tmpNext->prev->next = n;
                                n->prev = tmpNext->prev;
                                n->next = tmpNext;
                                tmpNext->prev = n;
                            }

                            break;
                        }
                    } while (tmpNext != nullptr);

                    if(!isPlacable) { // Catcher for if the value is the greatest value
                        tmp->next = n;
                        n->prev = tmp;
                        isPlacable = true;
                    }

                    setSibCount(tmpNext, tmpNext->sibCount + 1);
                } else { // At Least one sibling has children
                    //TODO: Compare value with each node until end is found.
                }
            }
        }

};

#endif