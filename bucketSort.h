//
// Created by Ciro on 19/9/2023.
//

#ifndef BUCKETSORT_BUCKETSORT_H
#define BUCKETSORT_BUCKETSORT_H
typedef struct nodo{
    int num;
    struct nodo* sig;
}Nodo;

typedef struct lista{
    Nodo * cabecera;
}Lista;

Nodo* newNodo(int valor);
Lista * newLista();
void imprimir(Lista *lista);
void insertar(Lista *lista, Nodo *nodo);
void hash(Lista *lista);
int cardinal(Lista * lista);

#endif //BUCKETSORT_BUCKETSORT_H
