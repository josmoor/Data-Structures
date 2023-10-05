#ifndef BIGTREE_H
#define BIGRREE_H

class BigTree {
    struct node {
        int data;
        int sibCount = 1;
        node* parent = nullptr;
        node* prev = nullptr;
        node* next = nullptr;
        node* children[5];
    }

    private:
        node * root = NULL;

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

            if(child == NULL) return false;
            else return true;
        }

        bool hasChildren(node* look) {
            return look->children[0] != nullptr;
        }

        bool anySiblingHasChildren(node* look) {
            while(look->prev != nullptr)
                look = look->prev;

            while(look != nullptr) {
                if(hasChildren(look))
                    return true;
            }

            return false;
        }

        int getChildrenNum() {
            if(!hasChildren())
                return 0;
            else {
                int ret = 1;
                for(int i = 1; i < 4; i++)
                    ret += root->children[i] != NULL ? 1 : 0;

                return ret;
            }
        }

        void insert(int value) {
            node* n = new node;
            n->data = value;

            node* tmp = root;
            bool notPlaced = true;

            while(notPlaced) {
                if(!hasChildren(tmp)) {
                    // TODO: no children in 'row' then place in correct spot in row.
                }
            }
        }

};

#endif