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

    for(int i=0; i < CANT_BUCKETS; i++){
        bucket1[i] = newLista();
    }

    for(int i=0; i < SIZE_ARREGLO; i++){
        enlistar_Bucket(bucket1, array[i]);
    }

    for(int i=0; i < CANT_BUCKETS; i++){
        ordenar_Buckets(bucket1[i]);
    }




    Lista * bucket2[CANT_BUCKETS];

    for(int i=0; i<CANT_BUCKETS; i++){
        bucket2[i] = newLista();
    }




}



int hashing_1(int array) {
    return array/CANT_BUCKETS;
}

void enlistar_Bucket(Lista **bucket, int array) {
    int num_Bucket = hashing_1(array);
    Nodo * nodo = newNodo(array);
    if(bucket[num_Bucket]->cabecera == NULL){
        bucket[num_Bucket]->cabecera = nodo;
        return;
    }
    nodo->sig = bucket[num_Bucket]->cabecera;
    bucket[num_Bucket]->cabecera = nodo;
}

int hashing_2(int array) {



    return 0;
}

void ordenar_Buckets(Lista *bucket) {
    if(bucket->cabecera == NULL || bucket->cabecera->sig == NULL){
        return;
    }
    Nodo * act = bucket->cabecera;


    while(act != NULL){
        Nodo * sig = act->sig;
    }


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
/*void imprimirTablaHash(Nodo **hashTable) {
    for (int i = 0; hashTable[i]<SIZE_ARREGLO; ++i) {
        Nodo * auxN = hashTable[i];
        while (auxN != NULL){
            printf("%s\t",auxN->key);
            auxN = auxN->next;
        }
    }
}

 */