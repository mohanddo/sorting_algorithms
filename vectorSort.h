#ifndef VECTORSORT_H
#define VECTORSORT_H

void bubbleSortVector(int *vector, int vectorSize);
void insertionSortVector(int *vector, int vectorSize);
void mergeVector(int *arr, int start, int end, int originalVectorSize);
void mergeSortVector(int *vector, int start, int end, int originalVectorSize);
int partitionVector(int *vector, int start, int end, int originalVectorSize);
void quickSortVector(int *vector, int start, int end, int originalVectorSize);
void combSortVector(int *vector, int vectorSize, int gap);

#endif