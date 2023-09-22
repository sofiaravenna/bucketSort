//
// Created by Ciro on 19/9/2023.
//

#include "bucketSort.h"
#include <stdio.h>
#include <stdlib.h>

Nodo *newNodo(int valor) {
    Nodo * aux = NULL;
    aux= malloc(sizeof(Nodo));
    if(aux==NULL){
        printf("ERROR al asignar memoria.\n");
        exit(-1);
    }else{
        aux->num=valor;
        aux->sig=NULL;
    }
    return aux;
}

Lista *newLista() {
        Lista * aux = NULL;
    aux= malloc(sizeof(Lista));
    if(aux==NULL){
        printf("ERROR al asignar memoria.\n");
        exit(-1);
    }else{
        aux->cabecera=NULL;
    }
    return aux;
}
void imprimir(Lista *lista) {
    if(lista->cabecera ==NULL){
        printf("La lista esta vacia.\n");
    }else{
        Nodo * aux =lista->cabecera;
        while(aux != NULL){
            printf("%d\t",aux->num);
            aux=aux->sig;
        }
    }
}
void insertar(Lista *lista, Nodo *nodo) {
    if(lista->cabecera == NULL){ //la lista esta vacia
        lista->cabecera= nodo;
        nodo->sig=NULL;
    }else{
        Nodo * aux = lista->cabecera;
        while(aux->sig != NULL){
            aux=aux->sig;
        }
        aux->sig=nodo;
        nodo->sig=NULL;
    }
}
void imprimirTablaHash(Nodo **hashTable) {
    for (int i = 0; hashTable[i]<SIZE; ++i) {
        Nodo * auxN = hashTable[i];
        while (auxN != NULL){
            printf("%s\t",auxN->key);
            auxN=auxN->next;
        }
    }
}