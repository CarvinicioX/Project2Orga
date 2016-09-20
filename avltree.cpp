#include "avltree.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <sstring>
#include <fstream>
#include <vector>

using namespace std;

AVLTree::AVLTree(){

}
int AVLTree::altura(struct node *nodo){
    if (nodo == NULL)
        return 0;
    return nodo->altura;
}

int AVLTree::maximo(int num1, int num2){
    return (num1 > num2)? num1 : num2;
}

node* AVLTree::nuevoNodo(int llave){
    struct node* nodo = (struct node*)
    malloc(sizeof(struct node));
    nodo->llave = llave;
    nodo->nodoIzquierdo = NULL;
    nodo->nodoDerecho = NULL;
    nodo->altura = 1;
    return(nodo);
}

node* AVLTree::cambioDerecha(struct node *nodoACambiar){
    struct node *nodoCambiado = nodoACambiar->nodoIzquierdo;
    struct node *temp = nodoCambiado->nodoDerecho;
    nodoCambiado->nodoDerecho = nodoACambiar;
    nodoACambiar->nodoIzquierdo = temp;
    nodoACambiar->altura = maximo(altura(nodoACambiar->nodoIzquierdo), altura(nodoACambiar->nodoDerecho))+1;
    nodoCambiado->altura = maximo(altura(nodoCambiado->nodoIzquierdo), altura(nodoCambiado->nodoDerecho))+1;
    return nodoCambiado;
}

node* AVLTree::cambioIzquierda(struct node *nodoACambiar){
    struct node *nodoCambiado = nodoACambiar->nodoDerecho;
    struct node *temp = nodoCambiado->nodoIzquierdo;
    nodoCambiado->nodoIzquierdo = nodoACambiar;
    nodoACambiar->nodoDerecho = temp;
    nodoACambiar->altura = maximo(altura(nodoACambiar->nodoIzquierdo), altura(nodoACambiar->nodoDerecho))+1;
    nodoCambiado->altura = maximo(altura(nodoCambiado->nodoIzquierdo), altura(nodoCambiado->nodoDerecho))+1;
    return nodoCambiado;
}

int AVLTree::balance(struct node *nodo){
    if (nodo == NULL)
        return 0;
    return altura(nodo->nodoIzquierdo) - altura(nodo->nodoDerecho);
}
 
node* AVLTree::insertar(struct node* nodo, int llave){
    if (nodo == NULL){
        return(nuevoNodo(llave));
    }
    if (llave < nodo->llave){
        nodo->nodoIzquierdo  = insertar(nodo->nodoIzquierdo, llave);
    }
    else{
        nodo->nodoDerecho = insertar(nodo->nodoDerecho, llave);
    }
    nodo->altura = maximo(altura(nodo->nodoIzquierdo), altura(nodo->nodoDerecho)) + 1;
    int hacerBalance = balance(nodo);
    if (hacerBalance > 1 && llave < nodo->nodoIzquierdo->llave){
        return cambioDerecha(nodo);
    }

    if (hacerBalance < -1 && llave > nodo->nodoDerecho->llave){
        return cambioIzquierda(nodo);
    }

    if (hacerBalance > 1 && llave > nodo->nodoIzquierdo->llave){
        nodo->nodoIzquierdo =  cambioIzquierda(nodo->nodoIzquierdo);
        return cambioDerecha(nodo);
    }

    if (hacerBalance < -1 && llave < nodo->nodoDerecho->llave){
        nodo->nodoDerecho = cambioDerecha(nodo->nodoDerecho);
        return cambioIzquierda(nodo);
    }

    return nodo;
}

node* AVLTree::minimo(struct node* nodo){
    struct node* minimo = nodo;
    while (minimo->nodoDerecho != NULL)
        minimo = minimo->nodoDerecho;
 
    return minimo;
}
 
node* AVLTree::borrar(struct node* raiz, int llave){
    if (raiz == NULL){
        return raiz;
    }
    if (llave < raiz->llave){
        raiz->nodoIzquierdo = borrar(raiz->nodoIzquierdo, llave);
    }
    else if(llave > raiz->llave){
        raiz->nodoDerecho = borrar(raiz->nodoDerecho, llave);
    }
    else{
        if((raiz->nodoIzquierdo == NULL) || (raiz->nodoDerecho == NULL)){
            struct node *temp = raiz->nodoIzquierdo ? raiz->nodoIzquierdo : raiz->nodoDerecho;
            if(temp == NULL){
                temp = raiz;
                raiz = NULL;
            }
            else{
             *raiz = *temp;
            }
            free(temp);
        }
        else{
            struct node* temp = minimo(raiz->nodoIzquierdo);
            raiz->llave = temp->llave;
            raiz->nodoIzquierdo = borrar(raiz->nodoIzquierdo, temp->llave);
        }
    }
    if (raiz == NULL){
      return raiz;
    }
    raiz->altura = maximo(altura(raiz->nodoIzquierdo), altura(raiz->nodoDerecho)) + 1;
    int hacerBalance = balance(raiz);

    if (hacerBalance > 1 && balance(raiz->nodoIzquierdo) >= 0){
        return cambioDerecha(raiz);
    }

    if (hacerBalance > 1 && balance(raiz->nodoIzquierdo) < 0){
        raiz->nodoIzquierdo =  cambioIzquierda(raiz->nodoIzquierdo);
        return cambioDerecha(raiz);
    }

    if (hacerBalance < -1 && balance(raiz->nodoDerecho) <= 0){
        return cambioIzquierda(raiz);
    }

    if (hacerBalance < -1 && balance(raiz->nodoDerecho) > 0){
        raiz->nodoDerecho = cambioDerecha(raiz->nodoDerecho);
        return cambioIzquierda(raiz);
    }
    return raiz;
}

void AVLTree::preOrden(struct node *raiz){
    if(raiz != NULL){
        printf("%d ", raiz->llave);
        preOrden(raiz->nodoIzquierdo);
        preOrden(raiz->nodoDerecho);
    }
}

void AVLTree::pruebaEstres(struct node *raiz){
	for (int i = 0; i < 1000000; ++i){
    	raiz = insertar(raiz, i);
    	cout<<i<<endl;
    }
}

node* AVLTree::buscar(struct node* nodo, int posicion){
    if(nodo != NULL){
        if(posicion == nodo->llave) {
        	return nodo;
        }
        if(posicion < nodo->llave){
            return buscar(posicion, nodo->nodoIzquierdo);
        }else{
            return buscar(posicion, nodo->nodoDerecho);
        }
    }else{
        return NULL;
    }
}

void AVLTree::cargar(vector<int>& lista){
	ifstream lector;
	lector.open("numeros.txt");
	stringstream ss;
	string numero;
	while(!lector.fail()){
		char delim;
		lector >> delim;
		if (!lector.fail()){
			if (delim == ','){
				numero.ss.str();
				ss.str("");
				int cambio = atoi(numero.c_str());
				lista.push_back(cambio);
			}else{
				ss << delim;
			}
		}
	}
	numero = ss.str();
	int cambio = atoi(numero.c_str());
	lista.push_back(cambio);
}

void AVLTree::init(QGraphicsScene* scene, QGraphicsView* view){
    this->_scene = scene;
    this->_view = view;
}

void AVLTree::_graphWalk(Node* nodo, QTextStream *stream) {
    if (nodo != NULL){
        *stream < < "\t\t" << "n" << nodo->llave < < "[label=\"" << nodo->llave < <"\"];" << endl;
 
        if(p->nodoIzquierdo != NULL){
            *stream < < "\t\tn" << nodo->llave < < "--" << "n" << nodo->nodoIzquierdo->llave < < ";" << endl;
            this->_graphWalk(nodo->nodoIzquierdo, stream);
        }else{
            *stream < < "\t\t" << "n" << nodo->llave < < "leftNull" << "[style=\"filled\",label=\"NULL\"];" << endl;
            *stream << "\t\tn" << nodo->llave < < "--" << "n" << nodo->llave < < "leftNull" << endl;
        }
 
        if(p->nodoDerecho != NULL){
            *stream < < "\t\tn" << nodo->llave < < "--" << "n" << nodo->nodoDerecho->llave < < ";" << endl;
            this->_graphWalk(nodo->nodoDerecho, stream);
        }else{
            *stream < < "\t\t" << "n" << nodo->llave < < "rightNull" << "[style=\"filled\",label=\"NULL\"];" << endl;
            *stream << "\t\tn" << nodo->llave < < "--" << "n" << nodo->llave < < "rightNull" << endl;
        }
    }
}
 
QByteArray AVLTree::_prepareGraph(){
    QByteArray a = QByteArray();
 
    QTextStream stream(&a, QIODevice::ReadWrite);
    stream << "graph ""{" << endl;
    stream << "\tnode[fontsize=10,margin=0,width=\".4\", height=\".3\"];" << endl;
    stream << "\tsubgraph cluster17{" << endl;
 
    this->_graphWalk(this->_root, &stream);
    stream < < "\t}\n" << "}" << endl;
    stream.flush();
 
    return a;
}
 
void AVLTree::show(){
    QProcess* p = new QProcess();
    QByteArray a = this->_prepareGraph();
 
    p->setProcessChannelMode(QProcess::MergedChannels);
    p->start("dot", QStringList() < < "-Tpng");
    p->write(a);
 
    QByteArray data;
    QPixmap pixmap = QPixmap();
 
    while(p->waitForReadyRead(100)){
        data.append(p->readAll());
    }
 
    pixmap.loadFromData(data);
 
    this->_scene->addPixmap(pixmap);
    this->_view->show();
}