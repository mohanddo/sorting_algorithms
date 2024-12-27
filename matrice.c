#include <stdio.h>
#include <stdbool.h>

// Function to perform insertion sort on a matrix of strings
void insertionSortMatrice(char matrice[][100], int n, int* numComparisons, int* numPermutations) {
    *numComparisons = 0;
    *numPermutations = 0;

    for (int i = 1; i < n; i++) {
        char temp[100];
        strcpy(temp, matrice[i]);
        int j = i - 1;

        while (j >= 0 && strcmp(matrice[j], temp) > 0) {
            (*numComparisons)++;
            strcpy(matrice[j + 1], matrice[j]);
            j--;
            (*numPermutations)++;
        }
        strcpy(matrice[j + 1], temp);
        (*numPermutations)++;
        displayMatrice(matrice, n); // Display matrix after each iteration for visualization
        printf("\n");
    }
}

// Function to display the matrix
void displayMatrice(char matrice[][100], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\n", matrice[i]);
    }
}

// Function to swap two strings
void swap(char* word1, char* word2) {
    char temp[100];
    strcpy(temp, word1);
    strcpy(word1, word2);
    strcpy(word2, temp);
}

// Function to perform partitioning for quick sort
int partition(char matrice[][100], int low, int high, int* numComparisons, int* numPermutations) {
    char pivot[100];
    strcpy(pivot, matrice[high]); // Choose the last element as pivot
    int i = (low - 1); // Index of smaller element

    // Traverse through all elements and compare each with the pivot
    for (int j = low; j <= high - 1; j++) {
        (*numComparisons)++; // Increment comparison count
        if (strcmp(matrice[j], pivot) < 0) {
            i++; // Increment index of smaller element
            swap(matrice[i], matrice[j]); // Swap if element is smaller than pivot
            (*numPermutations)++; // Increment permutation count
        }
    }
    // Swap the pivot element with the element at i+1 position
    swap(matrice[i + 1], matrice[high]);
    (*numPermutations)++; // Increment permutation count
    return (i + 1); // Return the pivot index
}

// Function to perform quick sort on a matrix of strings
void quickSortMatrice(char matrice[][100], int low, int high, int* numComparisons, int* numPermutations) {
     if (low < high) { 
        // Partition the array and get the pivot index 
        int pi = partition(matrice, low, high, numComparisons, numPermutations);
         // Recursively sort the elements before and after partition 
        quickSortMatrice(matrice, low, pi - 1, numComparisons, numPermutations);
          // Display the matrix after sorting the left part
        printf("\nMatrix after sorting the left part:\n"); 
        displayMatrice(matrice, high + 1); 
        quickSortMatrice(matrice, pi + 1, high, numComparisons, numPermutations); 
        // Display the matrix after sorting the right part 
        printf("\nMatrix after sorting the right part:\n"); 
        displayMatrice(matrice, high + 1);
         }
}