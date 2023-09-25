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

void imprimir_Lista(Lista *lista);
void enlistar_Bucket(Lista * bucket[CANT_BUCKETS], int array);
void bucket_Sort(int * array);
int hashing_1(int array);

void ordenar_Buckets(Lista * bucket);
void concatenar_Buckets(Lista * bucket[CANT_BUCKETS], int array[SIZE_ARREGLO]);




int hash(Lista *lista);
int cardinal(Lista * lista);

#endif //BUCKETSORT_BUCKETSORT_H
