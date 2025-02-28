#include <stdio.h>
#include <time.h>
#include "vectorSort.h"
#include "linkedListSort.h"
#include "matriceSort.h"
#include "menu.h"
#include "utils.h"

void sort(int sortingAlgorithme, int structureToSort)
{
    if (structureToSort == VECTOR_SORT)
    {

        int size = 15 ;
        int vector[size];
        fillVectorWithRandomIntegers(vector, size);

        switch (sortingAlgorithme)
        {
        case SELECTION_SORT:
            selectionSortVector(vector, size);
            break;

        case BUBBLE_SORT:
            bubbleSortVector(vector, size);
            break;

        case INSERTION_SORT:
            insertionSortVector(vector, size);
            break;

        case COMB_SORT:
            combSortVector(vector, size, size);
            break;

        case MERGE_SORT:
            mergeSortVector(vector, 0, size, size);
            break;

        case QUICK_SORT:
            quickSortVector(vector, 0, size, size);
            break;

        default:
            break;
        }
    }
    else if (structureToSort == MATRIX_SORT)
    {

        char matrix[10][20];
        fillMatrixWithRandomStrings(matrix, 10);

        switch (sortingAlgorithme)
        {

        case INSERTION_SORT:
            insertionSortMatrice(matrix, 10);
            break;

        case QUICK_SORT:
            quickSortMatrice(matrix, 0, 9, 10);
            break;

        default:
            break;
        }
    }
    else if (structureToSort == LINKED_LIST_SORT)
    {
        List head = NULL;
        fillLinkedListWithRandomStrings(&head, 15);

        switch (sortingAlgorithme)
        {

        case INSERTION_SORT:
            insertionSortList(&head);
            break;

        case BUBBLE_SORT:
            bubbleSortList(head);
            break;

        default:
            break;
        }
    }
}

int main()
{
    srand(time(NULL));

    // Measure CPU time taken by Bubble Sort
    clock_t start, end;
    double cpu_time_used;

    int structureToSort = chooseTypeOfSorting();
    int sortingAlgorithem = chooseSortingAlgorithm(structureToSort);

    start = clock();
    sort(sortingAlgorithem, structureToSort);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken : %f seconds\n", cpu_time_used);

    return 0;
}
