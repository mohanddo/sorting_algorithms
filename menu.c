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

int chooseSortingAlgorithem()
{
    char choice;
    printf("Select the sorting algorithme\n");
    printf("0. Selection Sort, Press 'S' or 's'\n");
    printf("1. Bubble Sort, Press 'B' or 'b'\n");
    printf("2. Insertion Sort, Press 'I' or 'i'\n");
    printf("3. Merge Sort, Press 'M' or 'm'\n");
    printf("4. Quick Sort, Press 'Q' or 'q'\n");
    printf("5. Comp Sort, Press 'C' or 'c'\n");
    printf("Enter your choice: ");

    do
    {
        choice = getchar();
        flush_stdin();
        switch (choice)
        {
        case 's':
        case 'S':
            printf("You choose Selection Sort\n");
            printf("\n");
            return SELECTION_SORT;
            break;
        case 'b':
        case 'B':
            printf("You choose Bubble Sort\n");
            printf("\n");
            return BUBBLE_SORT;
            break;
        case 'i':
        case 'I':
            printf("You choose Insertion Sort\n");
            printf("\n");
            return INSERTION_SORT;
            break;
        case 'm':
        case 'M':
            printf("You choose Merge Sort\n");
            printf("\n");
            return MERGE_SORT;
            break;
        case 'q':
        case 'Q':
            printf("You choose Quick Sort\n");
            printf("\n");
            return QUICK_SORT;
            break;
        case 'c':
        case 'C':
            printf("You choose Comp Sort\n");
            printf("\n");
            return COMB_SORT;
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
