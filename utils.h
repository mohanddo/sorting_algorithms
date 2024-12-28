#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <string.h>

// Define the structure for linked list elements
typedef struct ElementList
{
    char word[20];
    struct ElementList *next;
} ElementList;

// Define a typedef for the pointer to ElementList
typedef ElementList *List;

void printVector(int *vector, int vectorSize);
void swap(int *x, int *y);
void printnbCompAndnbPerm(int nbComb, int nbPerm);
void displayMatrice(char matrice[][20], int n);
void swapMatrix(char *word1, char *word2);
void fillVectorWithRandomIntegers(int *vector, int vectorSize);
void fillMatrixWithRandomStrings(char matrix[][20], int matrixSize);
void displayList(List head);
void addElementToList(List *head, char data[20]);
void fillLinkedListWithRandomStrings(List *head, int linkedListLenght);

#endif