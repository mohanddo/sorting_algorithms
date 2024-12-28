#include <stdio.h>
#include <stdbool.h>
#include "utils.h"
#include "matriceSort.h"

// Function to perform insertion sort on a matrix of strings
void insertionSortMatrice(char matrice[][20], int n)
{
    int nbComp, nbPerm;
    nbComp = nbPerm = 0;

    for (int i = 1; i < n; i++)
    {
        printf("Iteration number: %d | ", i);
        char temp[20];
        strcpy(temp, matrice[i]);
        int j = i - 1;

        while (j >= 0 && strcmp(matrice[j], temp) > 0)
        {
            nbComp++;
            strcpy(matrice[j + 1], matrice[j]);
            j--;
            nbPerm++;
        }
        strcpy(matrice[j + 1], temp);
        nbPerm++;
        displayMatrice(matrice, n); // Display matrix after each iteration for visualization
    }
    printnbCompAndnbPerm(nbComp, nbPerm);
    printf("\n");
}

// Function to perform partitioning for quick sort
int partition(char matrice[][20], int low, int high, int originalSizeMatrix)
{
    char pivot[20];
    strcpy(pivot, matrice[high]); // Choose the last element as pivot
    int i = (low - 1);            // Index of smaller element

    // Traverse through all elements and compare each with the pivot
    for (int j = low; j <= high - 1; j++)
    {

        if (strcmp(matrice[j], pivot) < 0)
        {
            i++;                                // Increment index of smaller element
            swapMatrix(matrice[i], matrice[j]); // Swap if element is smaller than pivot
        }
    }
    // Swap the pivot element with the element at i+1 position
    swapMatrix(matrice[i + 1], matrice[high]);
    displayMatrice(matrice, originalSizeMatrix);
    return (i + 1); // Return the pivot index
}

// Function to perform quick sort on a matrix of strings
void quickSortMatrice(char matrice[][20], int low, int high, int originalSizeMatrix)
{
    if (low < high)
    {
        // Partition the array and get the pivot index
        int pi = partition(matrice, low, high, originalSizeMatrix);
        // Recursively sort the elements before and after partition
        quickSortMatrice(matrice, low, pi - 1, originalSizeMatrix);
        quickSortMatrice(matrice, pi + 1, high, originalSizeMatrix);
    }
}