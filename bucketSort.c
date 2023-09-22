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
    aux = malloc(sizeof(Lista));
    if(aux == NULL){
        printf("ERROR al asignar memoria.\n");
        exit(-1);
    }else{
        aux->cabecera = NULL;
    }
    return aux;
}

void bucket_Sort(int *array) {
    Lista * bucket1[CANT_BUCKETS];
    inicializar_Buckets(bucket1);

    for(int i=0; i < SIZE_ARREGLO; i++){
        insertar_Bucket(bucket1, array[i]);
    }



    Lista * bucket2[CANT_BUCKETS];
    inicializar_Buckets(bucket2);





}

void inicializar_Buckets(Lista **bucket) {
    for(int i=0; i<CANT_BUCKETS; i++){
        bucket[i] = newLista();
    }
}


int hashing_1(int * array) {
    return array%CANT_BUCKETS;
}

void insertar_Bucket(Lista **bucket, int array) {
    int num_Bucket = hashing_1();
    Nodo * new = newNodo(array);
    if(bucket[num_Bucket]->cabecera == NULL){
        bucket[num_Bucket]->cabecera = new;
        return;
    }
    new->sig = bucket[num_Bucket]->cabecera;
    bucket[num_Bucket]->cabecera = new;
}

void imprimir(Lista *lista) {
    if(lista->cabecera == NULL) {
        printf("La lista esta vacia.\n");
        return;
    }
        Nodo * aux = lista->cabecera;
        while(aux != NULL){
            printf("%d\t",aux->num);
            aux = aux->sig;
        }
}
void insertar(Lista *lista, Nodo *nodo) {
    if(lista->cabecera == NULL){ //la lista esta vacia
        lista->cabecera= nodo;
        nodo->sig=NULL;
        return;
    }
    Nodo * aux = lista->cabecera;
    while(aux->sig != NULL){
        aux = aux->sig;
    }
    aux->sig = nodo;
    nodo->sig = NULL;


}
void imprimirTablaHash(Nodo **hashTable) {
    for (int i = 0; hashTable[i]<SIZE_ARREGLO; ++i) {
        Nodo * auxN = hashTable[i];
        while (auxN != NULL){
            printf("%s\t",auxN->key);
            auxN = auxN->next;
        }
    }
}