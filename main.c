#include "bucketSort.h"
#include <stdio.h>

int main() {
    int array_Desordenado[SIZE_ARREGLO] = {23, 4, 91, 12, 86, 34, 8, 17, 42, 97, 66, 88, 0, 44, 51, 27, 39, 77, 99, 25};

    printf("\nArray desordenado:\n");

    imprimir_Array(array_Desordenado);

    bucket_Sort(array_Desordenado);

    //bucket_Sort_2(array_Desordenado);

    printf("\nArray ordenado:\n");

    imprimir_Array(array_Desordenado);


    return 0;
}
