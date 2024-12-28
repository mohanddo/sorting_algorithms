#ifndef MATRICESORT_H
#define MATRICESORT_H

void insertionSortMatrice(char matrice[][20], int n);
int partition(char matrice[][20], int low, int high, int originalSizeMatrix);
void quickSortMatrice(char matrice[][20], int high, int low, int originalSizeMatrix);

#endif