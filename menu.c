#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "menu.h"
#include "utils.h"

void flush_stdin()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int chooseTypeOfSorting()
{

    char choice;

    printf("\n=== Sorting Menu ===\n");
    printf("0. Sort a Vector, Press 'V' or 'v'\n");
    printf("1. Sort a Matrix, Press 'M' or 'm'\n");
    printf("2. Sort a Linked List, Press 'L' or 'l'\n");
    printf("Enter your choice: ");
    do
    {
        choice = getchar();
        flush_stdin();
        switch (choice)
        {
        case 'v':
        case 'V':
            printf("You choose Vector Sort\n");
            printf("\n");
            return VECTOR_SORT;
            break;
        case 'm':
        case 'M':
            printf("You choose Matrix Sort\n");
            printf("\n");
            return MATRIX_SORT;
            break;
        case 'l':
        case 'L':
            printf("You choose Linked List Sort\n");
            printf("\n");
            return LINKED_LIST_SORT;
            break;
        default:
            printf("Invalid choice. Enter again: ");
        }
    } while (choice != 'v' && choice != 'V' && choice != 'm' &&
             choice != 'M' && choice != 'l' && choice != 'L');

    return '\0';
}

int chooseSortingAlgorithm(int structureToSort) {
    char choice;
    printf("Select the sorting algorithm\n");

    if (structureToSort == VECTOR_SORT) {
        printf("0. Selection Sort, Press 'S' or 's'\n");
        printf("1. Bubble Sort, Press 'B' or 'b'\n");
        printf("2. Insertion Sort, Press 'I' or 'i'\n");
        printf("3. Merge Sort, Press 'M' or 'm'\n");
        printf("4. Quick Sort, Press 'Q' or 'q'\n");
        printf("5. Comp Sort, Press 'C' or 'c'\n");
    } else {
        if(structureToSort == MATRIX_SORT){
            printf("1. Insertion Sort, Press 'I' or 'i'\n");
            printf("2. Quick Sort, Press 'Q' or 'q'\n");
        }else{
            printf("1. Insertion Sort, Press 'I' or 'i'\n");
            printf("2. Bubble Sort, Press 'B' or 'b'\n");
        }
    }

    printf("Enter your choice: ");

    do {
        choice = getchar();
        flush_stdin();
        switch (choice) {
            case 's':
            case 'S':
                if (structureToSort == VECTOR_SORT) {
                    printf("You chose Selection Sort\n");
                    return SELECTION_SORT;
                }
                break;
            case 'b':
            case 'B':
                printf("You chose Bubble Sort\n");
                return BUBBLE_SORT;
            case 'i':
            case 'I':
                printf("You chose Insertion Sort\n");
                return INSERTION_SORT;
            case 'm':
            case 'M':
                if (structureToSort == VECTOR_SORT) {
                    printf("You chose Merge Sort\n");
                    return MERGE_SORT;
                }
                break;
            case 'q':
            case 'Q':
                printf("You chose Quick Sort\n");
                return QUICK_SORT;
            case 'c':
            case 'C':
                if (structureToSort == VECTOR_SORT) {
                    printf("You chose Comp Sort\n");
                    return COMB_SORT;
                }
                break;
            default:
                printf("Invalid choice. Enter again: ");
        }
    } while (choice != 's' && choice != 'S' && choice != 'M' &&
             choice != 'm' && choice != 'C' && choice != 'c' &&
             choice != 'Q' && choice != 'q' && choice != 'i' &&
             choice != 'I' && choice != 'B' && choice != 'b');

    return '\0';
}
