#include <stdio.h>
#include <stdbool.h>
#include "vectorSort.h"

void printVector(int *vector, int vectorSize)
{
    printf("Vector: ");
    for (size_t i = 0; i < vectorSize; i++)
    {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printnbCompAndnbPerm(int nbComb, int nbPerm)
{
    printf("The number of comparisons is: %d\n", nbComb);
    printf("The number of permutations is: %d\n", nbPerm);
}

void selectionSort(int *vector, int vectorSize)
{
    // Initially the number of comparisons and permutations is 0
    int nbComp, nbPerm;
    nbComp = nbPerm = 0;

    printVector(vector, vectorSize);
    for (size_t i = 0; i < vectorSize - 1; i++)
    {
        printf("Iteration number: %ld | ", i + 1);

        int minIndex = i;
        for (size_t j = i + 1; j < vectorSize; j++)
        {
            // If the element at the currect index is smaller then the minimum, we update the minIdex
            if (vector[j] < vector[minIndex])
            {
                minIndex = j;
            }
            nbComp++;
        }
        swap(vector + i, vector + minIndex);
        nbPerm++;
        printVector(vector, vectorSize);
    }

    printnbCompAndnbPerm(nbComp, nbPerm);
}

void bubbleSort(int *vector, int vectorSize)
{

    // Initially the number of comparisons and permutations is 0
    int nbComp, nbPerm;
    nbComp = nbPerm = 0;

    printVector(vector, vectorSize);
    for (size_t i = 0; i < vectorSize; i++)
    {
        printf("Iteration number: %ld | ", i + 1);

        bool sorted = true;
        for (size_t j = 0; j < vectorSize - i - 1; j++)
        {
            if (vector[j] > vector[j + 1])
            {
                swap(vector + j + 1, vector + j);
                nbPerm++;
                sorted = false;
            }
            nbComp++;
        }
        printVector(vector, vectorSize);
        if (sorted)
        {
            break;
        }
    }
    printnbCompAndnbPerm(nbComp, nbPerm);
}

void insertionSort(int *vector, int vectorSize)
{
    // Initially the number of comparisons and permutations is 0
    int nbComp, nbPerm;
    nbComp = nbPerm = 0;

    printVector(vector, vectorSize);
    for (size_t i = 1; i < vectorSize; i++)
    {
        printf("Iteration number: %ld | ", i);

        int pos = i;
        int temp = vector[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (vector[i] < vector[j])
            {
                pos = j;
            }
            nbComp++;
        }

        for (int k = i - 1; k >= pos; k--)
        {
            vector[k + 1] = vector[k];
        }

        vector[pos] = temp;
        nbPerm++;
        printVector(vector, vectorSize);
    }
    printnbCompAndnbPerm(nbComp, nbPerm);
}

void merge(int *arr, int start, int end, int originalVectorSize)
{
    int mid = (start + end) / 2;

    int leftvectorlenght = mid - start + 1;
    int leftvector[leftvectorlenght];
    for (size_t i = 0; i < leftvectorlenght; i++)
    {
        leftvector[i] = arr[start + i];
    }

    int rightvectorlenght = end - mid;
    int rightvector[rightvectorlenght];
    for (size_t i = 0; i < rightvectorlenght; i++)
    {
        rightvector[i] = arr[mid + i + 1];
    }

    int i, j, k;
    i = j = 0;
    k = start;

    while (i < leftvectorlenght && j < rightvectorlenght)
    {
        if (leftvector[i] <= rightvector[j])
        {
            arr[k] = leftvector[i];
            i += 1;
        }
        else
        {
            arr[k] = rightvector[j];
            j += 1;
        }
        k += 1;
    }

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

    printVector(arr, 8);
}

void mergeSort(int *vector, int start, int end, int originalVectorSize)
{
    if (start < end)
    {
        int mid = (start + end) / 2;

        mergeSort(vector, start, mid, originalVectorSize);

        mergeSort(vector, mid + 1, end, originalVectorSize);

        merge(vector, start, end, originalVectorSize);
    }
}

int randomizedPartition(int *vector, int start, int end, int originalVectorSize)
{
    int pivot = vector[end - 1];
    int pIndex = start;

    for (size_t i = start; i < end - 1; i++)
    {
        if (vector[i] <= pivot)
        {
            swap(vector + i, vector + pIndex);
            pIndex++;
        }
    }
    swap(vector + pIndex, vector + end - 1);
    printVector(vector, originalVectorSize);
    return pIndex;
}

void quickSort(int *vector, int start, int end, int originalVectorSize)
{
    if (start < end)
    {
        int pIndex = randomizedPartition(vector, start, end, originalVectorSize);
        quickSort(vector, start, pIndex, originalVectorSize);
        quickSort(vector, pIndex + 1, end, originalVectorSize);
    }
}

void combSort(int *vector, int vectorSize, int gap)
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
        for (size_t i = 0; i + gap < vectorSize; i++)
        {
            if (vector[i] > vector[i + gap])
            {
                swap(vector + i, vector + i + gap);
                nbPerm++;
            }
            nbComp++;
        }
        gap--;
        iterationNumber++;
        printVector(vector, vectorSize);
    } while (gap > 0);

    printnbCompAndnbPerm(nbComp, nbPerm);
}