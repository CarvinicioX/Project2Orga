#ifndef AVLTREE_H
#define AVLTREE_H
#include <iostream>
#include <qgraphicsview>
#include <qtextstream>
#include <qprocess>

using namespace std;

struct node {
    int llave;
    struct node *nodoIzquierdo;
    struct node *nodoDerecho;
    int altura;
};

class AVLTree
{
public:
    AVLTree();
};

#endif // AVLTREE_H
