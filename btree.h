#ifndef BTREE_H
#define BTREE_H
#include "btreenode.h"

using namespace std;

class BTree {
    BTreeNode *root;
    int t;
public:
    BTree(int _t);
    void traverse();
    BTreeNode* search(int k);
    void insert(int k);
    void pruebaEstres(BTree* Raiz);
};

#endif // BTREE_H
