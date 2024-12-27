#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "menu.h"

char chooseTypeOfSorting()
{

    char choice;

    printf("\n=== Sorting Menu ===\n");
    printf("0. Sort a Vector, Press 'V'\n");
    printf("1. Sort a Matrix, Press 'M'\n");
    printf("2. Sort a Linked List, Press 'L'\n");
    printf("Enter your choice: ");
    do
    {
        scanf(" %c", &choice);
        printf("\n");
        switch (choice)
        {
        case 'V':
            choice = VECTOR_SORT;
            printf("You choose Vector Sort\n");
            break;
        case 'M':
            choice = MATRIX_SORT;
            printf("You choose Matrix Sort\n");
            break;
        case 'L':
            choice = LINKED_LIST_SORT;
            printf("You choose Linked List Sort\n");
            break;
        default:
            printf("Invalid choice. Enter again: \n");
        }
    } while (choice != VECTOR_SORT && choice != MATRIX_SORT && choice != LINKED_LIST_SORT);

    printf("\n");

    return choice;
}

char chooseSortingAlgorithem()
{
    char choice;
    printf("Select the sorting algorithme\n");
    printf("0. Selection Sort, Press 'S'\n");
    printf("1. Bubble Sort, Press 'B'\n");
    printf("2. Insertion Sort, Press 'I'\n");
    printf("3. Merge Sort, Press 'M'\n");
    printf("4. Quick Sort, Press 'Q'\n");
    printf("5. Comp Sort, Press 'C'\n");
    printf("Enter your choice: ");

    do
    {
        scanf(" %c", &choice);
        printf("\n");
        switch (choice)
        {
        case 'S':
            choice = SELECTION_SORT;
            printf("You choose Selection Sort\n");
            break;
        case 'B':
            choice = BUBBLE_SORT;
            printf("You choose Bubble Sort\n");
            break;
        case 'I':
            choice = INSERTION_SORT;
            printf("You choose Insertion Sort\n");
            break;
        case 'M':
            choice = MERGE_SORT;
            printf("You choose Merge Sort\n");
            break;
        case 'Q':
            choice = QUICK_SORT;
            printf("You choose Quick Sort\n");
            break;
        case 'C':
            choice = COMB_SORT;
            printf("You choose Comp Sort\n");
            break;
        default:
            printf("Invalid choice. Enter again: ");
        }
    } while (choice != SELECTION_SORT && choice != BUBBLE_SORT && choice != MERGE_SORT &&
             choice != QUICK_SORT && choice != INSERTION_SORT && choice != COMB_SORT);

    printf("\n");

    return choice;
}

void fillVectorWithRandomIntegers(int *vector, int vectorSize)
{
    for (size_t i = 0; i < vectorSize; i++)
    {
        vector[i] = rand() % 100;
    }
}

char *strings[150] = {
    "apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon",
    "mango", "nectarine", "orange", "papaya", "quince", "raspberry", "strawberry", "tomato", "ugli", "vanilla",
    "watermelon", "xigua", "yellowfruit", "zucchini", "apricot", "blueberry", "cantaloupe", "dragonfruit", "eaglefruit", "fruitcake",
    "grapefruit", "huckleberry", "imbe", "jackfruit", "kumquat", "lime", "mulberry", "nectar", "olive", "peach",
    "plum", "pomegranate", "pear", "pineapple", "papaya", "persimmon", "raspberry", "starfruit", "tangerine", "watermelon",
    "mangosteen", "blackberry", "grapefruit", "pear", "elderberry", "fig", "gooseberry", "honeydew", "apricot", "tomato",
    "coconut", "lime", "persimmon", "plum", "date", "starfruit", "apricot", "blueberry", "kiwi", "lemon",
    "banana", "fig", "cantaloupe", "guava", "pomegranate", "tamarind", "peach", "strawberry", "grape", "cherry",
    "jackfruit", "honeydew", "grapefruit", "lemon", "lime", "peach", "plum", "blueberry", "elderberry", "raspberry",
    "citrus", "mango", "quince", "kiwi", "papaya", "pear", "melon", "apple", "cantaloupe", "tomato",
    "strawberry", "pear", "blueberry", "lime", "apricot", "coconut", "cherry", "honeydew", "plum", "grapefruit"};

void fillMatrixWithRandomStrings(char matrix[10][20], int matrixSize)
{
    for (size_t i = 0; i < 10; i++)
    {
        strcpy(matrix[i], strings[rand() % 100]);
    }
}

int main()
{

    srand(time(NULL));
    chooseTypeOfSorting();

    chooseSortingAlgorithem();

    int vector[20];
    fillVectorWithRandomIntegers(vector, 20);
    for (size_t i = 0; i < 20; i++)
    {
        printf("%d ", vector[i]);
    }
    printf("\n");

    // char matrix[10][20];
    // fillMatrixWithRandomStrings(matrix, 10);

    // for (size_t i = 0; i < 10; i++)
    // {
    //     printf("%s ", matrix[i]);
    // }

    // printf("\n");
    return 0;
}