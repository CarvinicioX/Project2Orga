#ifndef AVLTREE_H
#define AVLTREE_H
#include <iostream>
#include <qgraphicsview>
#include <qtextstream>
#include <qprocess>
#include <vector>

using namespace std;

struct node {
    int llave;
    struct node *nodoIzquierdo;
    struct node *nodoDerecho;
    int altura;
};

class AVLTree{
	public:
	    AVLTree();
	    void init(QGraphicsScene* scene, QGraphicsView* view);
	    node* insertar(struct node* nodo, int llave);
	    node* borrar(struct node* raiz, int llave);
	    node* buscar(struct node* nodo, int posicion);
	    void show();
	private:
		void preOrden(struct node *raiz);
		void pruebaEstres(struct node *raiz);
		void cargar(vector<int>& lista);
		int altura(struct node *nodo);
		int maximo(int num1, int num2);
		node *nuevoNodo(int llave);
		node *cambioDerecha(struct node *nodoACambiar);
		node *cambioIzquierda(struct node *nodoACambiar);
		int balance(struct node *nodo);
		node *minimo(struct node* nodo);
		QByteArray _prepareGraph();
        void _graphWalk(Node* p,  QTextStream* stream);
        QGraphicsScene* _scene;
        QGraphicsView* _view;
};

#endif // AVLTREE_H
