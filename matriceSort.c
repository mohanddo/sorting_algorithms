#include <stdio.h>
#include <stdbool.h>
#include "utils.h"
#include "matriceSort.h"

// Function to perform insertion sort on a matrix of strings
void insertionSortMatrice(char matrice[][20], int n) {
    int nbComp, nbPerm, iterationNumber; // Variables to count comparisons, permutations, and iterations
    nbComp = nbPerm = iterationNumber = 0;

    for (int i = 1; i < n; i++) {
        iterationNumber++; // Increment the iteration count
        printf("Iteration number: %d\n", iterationNumber);

        char temp[20];
        strcpy(temp, matrice[i]); // Copy the current string to temp
        int j = i - 1; // Set j to the previous element's index

        while (j >= 0 && strcmp(matrice[j], temp) > 0) { // Compare temp with each element to find its correct position
            nbComp++; // Count comparison
            strcpy(matrice[j + 1], matrice[j]); // Shift elements to the right
            j--; // Move to the previous element
            nbPerm++; // Count permutation
        }
        strcpy(matrice[j + 1], temp); // Insert the temp string in the correct position
        nbPerm++; // Count the final placement as a permutation
        displayMatrice(matrice, n); // Display matrix after each iteration for visualization
    }
    printnbCompAndnbPerm(nbComp, nbPerm); // Print total comparisons and permutations
    
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