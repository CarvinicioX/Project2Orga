#include "allhailsatan.h"
#include "avltree.h"
#include "btreenode.h"
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

/*struct node{
    int llave;
    struct node *nodoIzquierdo;
    struct node *nodoDerecho;
    int altura;
};

int maximo(int num1, int num2);

int altura(struct node *nodo){
    if (nodo == NULL)
        return 0;
    return nodo->altura;
}

int maximo(int num1, int num2){
    return (num1 > num2)? num1 : num2;
}

struct node* nuevoNodo(int llave){
    struct node* nodo = (struct node*)
    malloc(sizeof(struct node));
    nodo->llave = llave;
    nodo->nodoIzquierdo = NULL;
    nodo->nodoDerecho = NULL;
    nodo->altura = 1;
    return(nodo);
}

struct node *cambioDerecha(struct node *nodoACambiar){
    struct node *nodoCambiado = nodoACambiar->nodoIzquierdo;
    struct node *temp = nodoCambiado->nodoDerecho;
    nodoCambiado->nodoDerecho = nodoACambiar;
    nodoACambiar->nodoIzquierdo = temp;
    nodoACambiar->altura = maximo(altura(nodoACambiar->nodoIzquierdo), altura(nodoACambiar->nodoDerecho))+1;
    nodoCambiado->altura = maximo(altura(nodoCambiado->nodoIzquierdo), altura(nodoCambiado->nodoDerecho))+1;
    return nodoCambiado;
}

struct node *cambioIzquierda(struct node *nodoACambiar){
    struct node *nodoCambiado = nodoACambiar->nodoDerecho;
    struct node *temp = nodoCambiado->nodoIzquierdo;
    nodoCambiado->nodoIzquierdo = nodoACambiar;
    nodoACambiar->nodoDerecho = temp;
    nodoACambiar->altura = maximo(altura(nodoACambiar->nodoIzquierdo), altura(nodoACambiar->nodoDerecho))+1;
    nodoCambiado->altura = maximo(altura(nodoCambiado->nodoIzquierdo), altura(nodoCambiado->nodoDerecho))+1;
    return nodoCambiado;
}

int balance(struct node *nodo){
    if (nodo == NULL)
        return 0;
    return altura(nodo->nodoIzquierdo) - altura(nodo->nodoDerecho);
}
 
struct node* insertar(struct node* nodo, int llave){
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

struct node * minimo(struct node* nodo){
    struct node* minimo = nodo;
    while (minimo->nodoIzquierdo != NULL)
        minimo = minimo->nodoIzquierdo;
 
    return minimo;
}
 
struct node* borrar(struct node* raiz, int llave){
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
            struct node* temp = minimo(raiz->nodoDerecho);
            raiz->llave = temp->llave;
            raiz->nodoDerecho = borrar(raiz->nodoDerecho, temp->llave);
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

void preOrden(struct node *raiz){
    if(raiz != NULL){
        printf("%d ", raiz->llave);
        preOrden(raiz->nodoIzquierdo);
        preOrden(raiz->nodoDerecho);
    }
}*/

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    QGraphicsScene scene;
    QGraphicsView view(&scene);
    view.setRenderHints(QPainter::SmoothPixmapTransform);
    AVLTree* Raiz = new AVLTree();
    vector<int> lista;
    Raiz->init(&scene, &view);
    Raiz->cargar(lista);
    Raiz = Raiz->insertar(Raiz, 10);
    Raiz = Raiz->insertar(Raiz, 20);
    Raiz = Raiz->insertar(Raiz, 30);
    Raiz = Raiz->insertar(Raiz, 40);
    Raiz = Raiz->insertar(Raiz, 50);
    Raiz = Raiz->insertar(Raiz, 25);
    Raiz = Raiz->insertar(Raiz, 45);
    Raiz = Raiz->insertar(Raiz, 70);
    Raiz = Raiz->insertar(Raiz, 8);

    printf("Pre orden construido: \n");
    Raiz->preOrden(Raiz);
    printf("\n");

    Raiz = Raiz->borrar(Raiz, 30);

    printf("Pre orden luego de borrar: \n");
    Raiz->preOrden(Raiz);
    printf("\n");
    AllHailSatan w;
    w.show();

    return a.exec();
}

/*int main(){
 
    return 0;
}*/
