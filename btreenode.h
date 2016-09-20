#ifndef BTREENODE_H
#define BTREENODE_H
#include <iostream>

using namespace std;

class BTreeNode {
    int *keys;//Arreglo de Keys
    int t;//Degree minimo
    BTreeNode **C;//Hijos
    int n;//Número de Keys
    bool leaf;//Plain af
public:
    BTreeNode(int _t, bool _leaf);
    void insertNonFull(int k);
    void splitChild(int i, BTreeNode *y);
    void traverse();
    BTreeNode* search(int k);
    friend class BTree;
};

#endif // BTREENODE_H
