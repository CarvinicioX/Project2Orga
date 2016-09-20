#include "allhailsatan.h"
#include "avltree.h"
#include "btreenode.h"
#include "btree.h"
#include <QApplication>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <vector>
#include <qgraphicsview>
#include <qtextstream>
#include <qprocess>

using namespace std;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    /*QGraphicsScene scene;
    QGraphicsView view(&scene);
    view.setRenderHints(QPainter::SmoothPixmapTransform);*/
    AVLTree* Raiz = new AVLTree();
    //vector<int> lista;
    //Raiz->cargar(lista);
    //Raiz->init(&scene, &view);
    struct node* nodo = NULL;
    /*nodo = Raiz->insertar(nodo, 10);
    nodo = Raiz->insertar(nodo, 20);
    nodo = Raiz->insertar(nodo, 30);
    nodo = Raiz->insertar(nodo, 40);
    nodo = Raiz->insertar(nodo, 50);
    nodo = Raiz->insertar(nodo, 25);
    nodo = Raiz->insertar(nodo, 45);
    nodo = Raiz->insertar(nodo, 70);
    nodo = Raiz->insertar(nodo, 8);*/
    Raiz->pruebaEstres(nodo, Raiz);

    printf("Pre orden construido: \n");
    Raiz->preOrden(nodo);
    printf("\n");

    //Raiz->borrar(nodo, 30);

    /*printf("Pre orden luego de borrar: \n");
    Raiz->preOrden(nodo);
    printf("\n");*/
    BTree t(3); // A B-Tree with minium degree 3
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);
    cout << "Traversal of the constucted tree is ";
    t.traverse();
    //AllHailSatan w;
    //w.show();
    //Raiz->show();
    return a.exec();
}
