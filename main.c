#include <stdio.h>
#include "vectorSort.h"

int main()
{
    int arr[] = {3, 6, 2, 100, 5, 340, 0, 50};

    // int pindex = randomizedPartition(arr, 0, 8);
    // randomizedPartition(arr, 0, pindex);
    // printf("pindex: %d\n", pindex);
    // quickSort(arr, 0, 8, 8);
    printf("\n");
    // printf("\n");
    // printVector(arr, 8);
    // mergeSort(arr, 0, 8, 8);
    // printVector(arr, 8);
    // selectionSort(arr, 8);
    combSort(arr, 8, 10);
    return 0;
}
