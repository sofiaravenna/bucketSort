#include "bucketSort.h"
#include <stdio.h>

int main() {
    int array_Desordenado[SIZE_ARREGLO] = {23, 4, 56, 12, 86, 34, 8, 17, 42, 97};

    int array_Ordenado[SIZE_ARREGLO] = {};

    printf("\nArray desordenado:\n");

    imprimir_Array(array_Desordenado);

    bucket_Sort(array_Desordenado, array_Ordenado);

    printf("\nArray ordenado:\n");

    imprimir_Array(array_Ordenado);

    return 0;
}
