#include <stdio.h>
#include <time.h>
#include "vectorSort.h"
#include "linkedListSort.h"
#include "matriceSort.h"
#include "menu.h"
#include "utils.h"

int main() {
    int vector[10] ;
    List head = NULL;
    fillVectorWithRandomIntegers(vector,200);
    
  //  fillLinkedListWithRandomStrings(&head, 50);

    // Measure CPU time taken by Bubble Sort
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    //bubbleSortList(head);
    bubbleSortVector(vector,10);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    // Display the time taken for sorting
    printf("Time taken by Bubble Sort: %f seconds\n", cpu_time_used);

    return 0;
}
