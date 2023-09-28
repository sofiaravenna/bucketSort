//
// Created by Ciro on 19/9/2023.
//

#ifndef BUCKETSORT_BUCKETSORT_H
#define BUCKETSORT_BUCKETSORT_H

#define SIZE_ARREGLO 20
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
void bucket_Sort(int * array_Desordenado);
int hashing_1(int array);
void concatenar_Buckets(Lista * bucket[], int * array_Ordenado);
void imprimir_Array(int * array);
void imprimir_Buckets(Lista * bucket[]);

// secundarias por las dudas
void bucket_Sort_2(int * arrayDesordenado);
int hashing_2_1(int array);
int hashing_2_2(int array);
void enlistar_2_1(Lista * bucket[], int dato_Array);
void enlistar_2_2(Lista * bucket[], int dato_Array);

#endif //BUCKETSORT_BUCKETSORT_H
