//
// Created by Ciro on 19/9/2023.
//

#ifndef BUCKETSORT_BUCKETSORT_H
#define BUCKETSORT_BUCKETSORT_H

#define SIZE_ARREGLO 10
#define CANT_BUCKETS 10


typedef struct nodo{
    int num;
    struct nodo* sig;
}Nodo;

typedef struct lista{
    Nodo * cabecera;
}Lista;

Nodo* newNodo(int valor);
Lista * newLista();
void enlistar_Bucket(Lista * bucket[], int dato_Array);
void bucket_Sort(int * array_Desordenado, int * array_Ordenado);
int hashing_1(int array);
void concatenar_Buckets(Lista * bucket[], int * array_Ordenado);
void imprimir_Array(int * array);


#endif //BUCKETSORT_BUCKETSORT_H
