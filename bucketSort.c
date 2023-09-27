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

void bucket_Sort(int *array_Desordenado, int * array_Ordenado) {
    Lista * bucket1[CANT_BUCKETS];

    for(int i=0; i < CANT_BUCKETS; i++){
        bucket1[i] = newLista();
    }

    for(int i=0; i < SIZE_ARREGLO; i++){
        enlistar_Bucket(bucket1, array_Desordenado[i]);
    }

 concatenar_Buckets(bucket1, array_Ordenado);
}



int hashing_1(int array) {
    return array/CANT_BUCKETS;
}

void enlistar_Bucket(Lista **bucket, int dato_Array) {
    int num_Bucket = hashing_1(dato_Array);

    Nodo * nodo = newNodo(dato_Array);

    if(bucket[num_Bucket]->cabecera == NULL){
        bucket[num_Bucket]->cabecera = nodo;
        return;
    }
    Nodo * aux = bucket[num_Bucket]->cabecera;
    Nodo * ant = NULL;

    while(aux != NULL && aux->num < nodo->num){
        ant = aux;
        aux = aux->sig;
    }
    if(aux == NULL){
        ant->sig = nodo;
        return;
    }
    if(aux == bucket[num_Bucket]->cabecera){
        nodo->sig = bucket[num_Bucket]->cabecera;
        bucket[num_Bucket]->cabecera = nodo;
        return;
    }
    if(aux->num > nodo->num){
        nodo->sig = aux;
        ant->sig = nodo;
    }
}

void concatenar_Buckets(Lista **bucket, int *array) {
    int pos=0;
    for(int i=0; i<CANT_BUCKETS; i++){
        if(bucket[i]->cabecera != NULL){
            Nodo * aux = bucket[i]->cabecera;
            while(aux != NULL){
                array[pos] = aux->num;
                pos++;
                aux = aux->sig;
            }
        }
    }
}
    /*
    for(int i=0; i<SIZE_ARREGLO; i++){
        for(int j=0; j<CANT_BUCKETS; j++){
            if(bucket[j]->cabecera != NULL){
                Nodo * aux = bucket[j]->cabecera;
                while(aux != NULL){
                    array[i] = aux->num;
                    aux = aux->sig;
                }
            }
        }
    }
}
     */

void imprimir_Array(int *array) {
    for(int i=0; i<SIZE_ARREGLO; i++){
        printf("  %d ", array[i]);
    }
}