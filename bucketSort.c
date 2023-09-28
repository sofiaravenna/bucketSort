//
// Created by Ciro on 19/9/2023.
//

#include "bucketSort.h"
#include <stdio.h>
#include <stdlib.h>

Nodo *newNodo(int valor) {
    Nodo * aux = NULL;
    aux = malloc(sizeof(Nodo));
    if(aux == NULL){
        printf("ERROR al asignar memoria.\n");
        exit(-1);
    }else{
        aux->num = valor;
        aux->sig = NULL;
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

void bucket_Sort(int *array_Desordenado) {
    Lista * bucket1[CANT_BUCKETS];

    for(int i=0; i < CANT_BUCKETS; i++){
        bucket1[i] = newLista();
    }

    for(int i=0; i < SIZE_ARREGLO; i++){
        enlistar_Bucket(bucket1, array_Desordenado[i]);
    }

    concatenar_Buckets(bucket1, array_Desordenado);

    imprimir_Buckets(bucket1);
}



int hashing_1(int array) {
    return array * CANT_BUCKETS / (99 + 1);
}

void enlistar_Bucket(Lista **bucket, int dato_Array) {
    int num_Bucket = hashing_1(dato_Array);
    Nodo * nodo = newNodo(dato_Array);

    if(bucket[num_Bucket]->cabecera == NULL){ // la lista esta vacia, inserto al principio
        bucket[num_Bucket]->cabecera = nodo;
        return;
    }
    Nodo * aux = bucket[num_Bucket]->cabecera;
    Nodo * ant = NULL;

    while(aux != NULL && aux->num < nodo->num){
        ant = aux;
        aux = aux->sig;
    }
    if(aux == NULL){ // inserto al final
        ant->sig = nodo;
        return;
    } // inserto al final
    if(aux == bucket[num_Bucket]->cabecera){ // inserto al principio sin perder cabeza
        nodo->sig = bucket[num_Bucket]->cabecera;
        bucket[num_Bucket]->cabecera = nodo;
        return;
    } // desplazo el primer elemento
    // y el nodo pasa a ser cabecera
    if(aux->num > nodo->num){
        nodo->sig = aux;
        ant->sig = nodo;
    } // inserto en el medio
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

void imprimir_Array(int *array) {
    for(int i=0; i<SIZE_ARREGLO; i++){
        printf("  %d ", array[i]);
    }
}

void imprimir_Buckets(Lista **bucket) {
    printf("\n\nImprimiendo buckets:");
    for(int i=0; i< CANT_BUCKETS; i++){
        printf("\nBucket %d: ", i);
        Nodo * aux = bucket[i]->cabecera;
        while(aux != NULL){
            printf(" %d   ", aux->num);
            aux = aux->sig;
        }
    }
}

// Segunda opcion. Para evitar insertar ordenado.

int hashing_2_1(int array) {
    return array%CANT_BUCKETS;
}

int hashing_2_2(int array) {
    return array/CANT_BUCKETS;
}

void enlistar_2_1(Lista **bucket, int dato_Array) {
    int num_Bucket = hashing_2_1(dato_Array);
    Nodo * nuevo = newNodo(dato_Array);

    if(bucket[num_Bucket]->cabecera == NULL){
        bucket[num_Bucket]->cabecera = nuevo;
        return;
    }
    Nodo * aux = bucket[num_Bucket]->cabecera;
    while(aux->sig != NULL){
        aux = aux->sig;
    }
    aux->sig = nuevo;
}

void enlistar_2_2(Lista **bucket, int dato_Array) {
    int num_Bucket = hashing_2_2(dato_Array);
    Nodo * nuevo = newNodo(dato_Array);

    if(bucket[num_Bucket]->cabecera == NULL){
        bucket[num_Bucket]->cabecera = nuevo;
        return;
    }
    Nodo * aux = bucket[num_Bucket]->cabecera;
    while(aux->sig != NULL){
        aux = aux->sig;
    }
    aux->sig = nuevo;
}

void bucket_Sort_2(int *arrayDesordenado) {
    Lista * bucket2_1[CANT_BUCKETS];

    for(int i=0; i<CANT_BUCKETS; i++){
        bucket2_1[i] = newLista();
    }

    for(int i=0; i<SIZE_ARREGLO; i++){
        enlistar_2_1(bucket2_1, arrayDesordenado[i]);
    }

    imprimir_Buckets(bucket2_1);

    concatenar_Buckets(bucket2_1, arrayDesordenado);

    Lista * bucket2_2[CANT_BUCKETS];

    for(int i=0; i<CANT_BUCKETS; i++){
        bucket2_2[i] = newLista();
    }

    for(int i=0; i<SIZE_ARREGLO; i++){
        enlistar_2_2(bucket2_2, arrayDesordenado[i]);
    }

    imprimir_Buckets(bucket2_2);


    concatenar_Buckets(bucket2_2, arrayDesordenado);

}


