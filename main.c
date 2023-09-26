#include "bucketSort.h"

int main() {
    int array_Desordenado[SIZE_ARREGLO] = {23, 4, 56, 12, 89, 34, 8, 17, 42, 6};

    int array_Ordenado[SIZE_ARREGLO] = {};

    imprimir_Array(array_Desordenado);

    bucket_Sort(array_Desordenado, array_Ordenado);

    imprimir_Array(array_Ordenado);

    return 0;
}
