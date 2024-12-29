#include <stdio.h>
#include <stdbool.h>
#include "vectorSort.h"
#include <stdlib.h>
#include "utils.h"

void selectionSortVector(int *vector, int vectorSize) {
    // Track comparisons, swaps, and iterations
    int nbComp = 0, nbPerm = 0, nbIter = 0;

    for (int i = 0; i < vectorSize - 1; i++) {
        nbIter++; // Increment the iteration count
        printf("Iteration number: %d\n", nbIter);

        int minIndex = i; // Assume the first unsorted element is the smallest
        for (int j = i + 1; j < vectorSize; j++) {
            // Update minIndex if a smaller element is found
            nbComp++; // Count the comparison
            if (vector[j] < vector[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the smallest found element with the current position
        swap(vector + i, vector + minIndex);
        nbPerm++;                        // Count the swap
       printVector(vector, vectorSize); // Print the vector after each iteration
    }

    // Print the total number of comparisons, swaps, and iterations
    printnbCompAndnbPerm(nbComp, nbPerm);
    printf("Total iterations: %d\n", nbIter);
    printf("\n");
}



void bubbleSortVector(int *vector, int vectorSize) {
    // Track number of comparisons, swaps, and iterations
    int nbComp = 0, nbPerm = 0, nbIter = 0;

    for (int i = 0; i < vectorSize; i++) {
        nbIter++; // Increment the iteration count
        printf("Iteration number: %d\n", nbIter);

        bool sorted = true; // Check if the array is already sorted
        for (int j = 0; j < vectorSize - i - 1; j++) {
            // Swap if elements are in the wrong order
            if (vector[j] > vector[j + 1]) {
                swap(&vector[j], &vector[j + 1]);
                nbPerm++;       // Count the swap
                sorted = false; // Array is not sorted yet
            }
            nbComp++; // Count the comparison
        }
         printVector(vector, vectorSize); // Print after each iteration
        if (sorted) { // Stop early if the array is sorted
            break;
        }
    }
    // Print total number of comparisons, swaps, and iterations
    printf("Total comparisons: %d\n", nbComp);
    printf("Total permutations: %d\n", nbPerm);
    printf("Total iterations: %d\n", nbIter);
}


void insertionSortVector(int *vector, int vectorSize) {
    // Track comparisons, swaps, and iterations
    int nbComp = 0, nbPerm = 0, nbIter = 0;

    for (int i = 1; i < vectorSize; i++) {
        nbIter++; // Increment the iteration count
        printf("Iteration number: %d\n", nbIter);

        int pos = i;
        int temp = vector[i]; // Store the current element temporarily
        for (int j = i - 1; j >= 0; j--) {
            nbComp++; // Count comparisons
            if (vector[j] > temp) {
                vector[j + 1] = vector[j];
                nbPerm++; // Count swaps
                pos = j;
            } else {
                break;
            }
        }

        vector[pos] = temp; // Place the element in the correct position
        printVector(vector, vectorSize); // Print the vector after each iteration
    }

    // Print total number of comparisons, swaps, and iterations
    printf("Total comparisons: %d\n", nbComp);
    printf("Total permutations: %d\n", nbPerm);
    printf("Total iterations: %d\n", nbIter);
}


void mergeVector(int *arr, int start, int end, int originalVectorSize)
{
    int mid = (start + end) / 2; // Find the middle point

    // Create left and right subarrays
    int leftvectorlenght = mid - start + 1;
    int *leftvector = (int *)malloc(sizeof(int) * leftvectorlenght);
    for (size_t i = 0; i < leftvectorlenght; i++)
    {
        leftvector[i] = arr[start + i];
    }

    int rightvectorlenght = end - mid;
    int *rightvector = (int *)malloc(sizeof(int) * rightvectorlenght);
    for (size_t i = 0; i < rightvectorlenght; i++)
    {
        rightvector[i] = arr[mid + i + 1];
    }

    // Merge the two sorted halves
    int i, j, k;
    i = j = 0;
    k = start;

    while (i < leftvectorlenght && j < rightvectorlenght)
    {
        if (leftvector[i] <= rightvector[j])
        {
            arr[k] = leftvector[i];
            i++;
        }
        else
        {
            arr[k] = rightvector[j];
            j++;
        }
        k++;
    }

    // Add remaining elements from left and right arrays
    while (j < rightvectorlenght)
    {
        arr[k] = rightvector[j];
        k++;
        j++;
    }

    while (i < leftvectorlenght)
    {
        arr[k] = leftvector[i];
        k++;
        i++;
    }

    free(leftvector);
    free(rightvector);

    printVector(arr, originalVectorSize); // Print after merging
}

void mergeSortVector(int *vector, int start, int end, int originalVectorSize)
{
    if (start < end)
    {
        int mid = (start + end) / 2;

        // Recursively sort left and right halves
        mergeSortVector(vector, start, mid, originalVectorSize);
        mergeSortVector(vector, mid + 1, end, originalVectorSize);

        // Merge the sorted halves
        mergeVector(vector, start, end, originalVectorSize);
    }
}

int partitionVector(int *vector, int start, int end, int originalVectorSize)
{
    int pivot = vector[end - 1]; // Choose the last element as the pivot
    int pIndex = start;

    for (int i = start; i < end - 1; i++)
    {
        // Place elements smaller than pivot to the left
        if (vector[i] <= pivot)
        {
            swap(vector + i, vector + pIndex);
            pIndex++;
        }
    }
    // Place the pivot in its correct position
    swap(vector + pIndex, vector + end - 1);
    printVector(vector, originalVectorSize);
    return pIndex;
}

void quickSortVector(int *vector, int start, int end, int originalVectorSize)
{
    if (start < end)
    {
        // Partition the array and get the pivot index
        int pIndex = partitionVector(vector, start, end, originalVectorSize);
        quickSortVector(vector, start, pIndex, originalVectorSize);   // Sort left half
        quickSortVector(vector, pIndex + 1, end, originalVectorSize); // Sort right half
    }
}

void combSortVector(int *vector, int vectorSize, int gap)
{
    while (gap >= vectorSize)
    {
        gap--;
    }

    int nbComp, nbPerm, iterationNumber;
    nbComp = nbPerm = iterationNumber = 0;

    do
    {
        printf("Iteration number: %d | ", iterationNumber + 1);
        for (int i = 0; i + gap < vectorSize; i++)
        {
            // Swap elements if they are in the wrong order
            if (vector[i] > vector[i + gap])
            {
                swap(vector + i, vector + i + gap);
                nbPerm++;
            }
            nbComp++;
        }
        gap--; // Decrease the gap
        iterationNumber++;
        printVector(vector, vectorSize);
    } while (gap > 0);

    printnbCompAndnbPerm(nbComp, nbPerm);
    printf("iteration number : %d",iterationNumber);
    printf("\n");
}
