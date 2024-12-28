#include <stdio.h>
#include <time.h>
#include "vectorSort.h"
#include "linkedListSort.h"
#include "matriceSort.h"
#include "menu.h"
#include "utils.h"

int main()
{
    srand(time(NULL));

    // int arr[] = {3, 6, 2, 100, 5, 340, 0, 50, 55, 55, 1, 24, 14, 14, 47, 55, 444, 77};
    // printVector(arr, 8);

    // Measure time taken by Quick Sort
    clock_t start, end;
    double cpu_time_used;
    // bubbleSortVector(arr, 8);
    // selectionSortVector(arr, 8);
    // insertionSortVector(arr, 8);
    // mergeSortVector(arr, 0, 8, 8);
    // quickSortVector(arr, 0, 8, 8);
    // combSortVector(arr, 8, 10);

    // char matrix[10][20];
    // fillMatrixWithRandomStrings(matrix, 10);
    // insertionSortMatrice(matrix, 10);

    // quickSortMatrice(matrix, 0, 9, 10);

    start = clock();

    List head;
    fillLinkedListWithRandomStrings(&head, 1000);
    // bubbleSortList(head);
    insertionSortList(&head);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by Insertion Sort: %f seconds\n", cpu_time_used);

    return 0;
}
