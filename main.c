#include <stdio.h>
#include <time.h>
#include "vectorSort.h"
#include "linkedListSort.h"
#include "matriceSort.h"
#include "menu.h"
#include "utils.h"

int main() {
  int size = 10000 ;
    int vector[size] ;
    
    fillVectorWithRandomIntegers(vector,size);
    
  //  fillLinkedListWithRandomStrings(&head, 50);

    // Measure CPU time taken by Bubble Sort
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    //bubbleSortList(head);
    selectionSortVector(vector,size);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    // Display the time taken for sorting
    printf("Time taken by Bubble Sort: %f seconds\n", cpu_time_used);

    return 0;
}
