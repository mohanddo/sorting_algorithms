#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>

//struct 
// Define the structure for linked list elements
typedef struct ElementList
{
    char word[20];
    struct ElementList *next;
} ElementList;

// Define a typedef for the pointer to ElementList
typedef ElementList *List;

//Util 
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
// Function to display the matrix
void displayMatrice(char matrice[][20], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s ", matrice[i]);
    }
    printf("\n");
}

// Function to swap two strings
void swapMatrix(char *word1, char *word2)
{
    char temp[20];
    strcpy(temp, word1);
    strcpy(word1, word2);
    strcpy(word2, temp);
}

void fillVectorWithRandomIntegers(int *vector, int vectorSize)
{
    for (size_t i = 0; i < vectorSize; i++)
    {
        vector[i] = rand() ;
    }
}

void fillMatrixWithRandomStrings(char matrix[][20], int matrixSize)
{
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

    for (size_t i = 0; i < matrixSize; i++)
    {
        strcpy(matrix[i], strings[rand() % 100]);
    }
}

void fillLinkedListWithRandomStrings(List *head, int linkedListLength) {
    const char *strings[150] = {
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

    for (size_t i = 0; i < linkedListLength; i++) {
        addElementToList(head, strings[rand() % linkedListLength]);
    }
}

// Function to print the linked list
void displayList(List head)
{
    List current = head;
    while (current != NULL)
    {
        printf("%s ", current->word);
        current = current->next;
    }
    printf("\n");
}

void addElementToList(List *head, const char *data) {
    // Allocate the new element
    List newElement = (List)malloc(sizeof(ElementList));
    if (newElement == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    strcpy(newElement->word, data);
    newElement->next = NULL;

    if (*head == NULL) { // Check if head is NULL
        *head = newElement;
        return;
    }

    List current = *head; // Initialize current with the head of the list

    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newElement;
}



//Vector function

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


//Matrice function 

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


//Linked List function

// Bubble sort function for linked list in ascending order
void bubbleSortList(List head)
{
    if (head == NULL)
    {
        printf("Error: The list is empty\n");
        return;
    }

    List endPointer = NULL;
    List current;
    char temp[20];
    int swapped;

    int nbComp, nbPerm, iterationNumber;
    nbComp = nbPerm = iterationNumber = 0;

    do
    {
        printf("Iteration number: %d | ", iterationNumber + 1);
        iterationNumber++;
        swapped = 0;
        current = head;

        while (current->next != endPointer)
        {
            nbComp++;
            if (strcmp(current->word, current->next->word) > 0)
            {
                strcpy(temp, current->word);
                strcpy(current->word, current->next->word);
                strcpy(current->next->word, temp);
                nbPerm++;
                swapped = 1;
            }
            current = current->next;
        }
        displayList(head);
        endPointer = current;
    } while (swapped);

    printnbCompAndnbPerm(nbComp, nbPerm);
    printf("\n");
}

// Insertion sort function for linked list in ascending order
void insertionSortList(List *head)
{
    // Test if the list is empty
    if (*head == NULL)
    {
        printf("Error: The list is empty\n");
        return;
    }

    // Initialize counters
    int nbComp, nbPerm, iterationNumber;
    ;
    nbComp = nbPerm = iterationNumber = 0;

    // Create a new head
    List newHead = (List)malloc(sizeof(ElementList));
    newHead->next = *head;
    strcpy(newHead->word, "");

    List current = (*head)->next; // Start from the second element
    List prev = *head;

    while (current != NULL)
    {
        printf("Iteration number: %d | ", iterationNumber + 1);
        iterationNumber++;

        if (strcmp(current->word, prev->word) >= 0)
        {
            // If the current element is greater than or equal to the previous, continue
            prev = current;
            current = current->next;
            nbComp++;
        }
        else
        {
            // Find the position to insert the current element in the sorted part
            List temp = newHead;
            prev->next = current->next;
            if (strcmp(current->word, temp->next->word) <= 0)
            {
                current->next = temp->next;
                temp->next = current;
                nbComp++;
            }
            else
            {
                while (temp->next != NULL && strcmp(current->word, temp->next->word) > 0)
                {
                    temp = temp->next;
                    nbComp++;
                }
                current->next = temp->next;
                temp->next = current;
            }
            nbPerm++;
            current = prev->next;
        }
        displayList(newHead->next); // Display the list after each iteration
    }

    *head = newHead->next;
    free(newHead);

    printnbCompAndnbPerm(nbComp, nbPerm);
    printf("\n");
}

// Menu

#define VECTOR_SORT 0
#define MATRIX_SORT 1
#define LINKED_LIST_SORT 2

#define SELECTION_SORT 0
#define BUBBLE_SORT 1
#define INSERTION_SORT 2
#define MERGE_SORT 3
#define QUICK_SORT 4
#define COMB_SORT 5

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

int chooseSortingAlgorithm(int structureToSort) {
    char choice;
    printf("Select the sorting algorithm\n");

    if (structureToSort == VECTOR_SORT) {
        printf("0. Selection Sort, Press 'S' or 's'\n");
        printf("1. Bubble Sort, Press 'B' or 'b'\n");
        printf("2. Insertion Sort, Press 'I' or 'i'\n");
        printf("3. Merge Sort, Press 'M' or 'm'\n");
        printf("4. Quick Sort, Press 'Q' or 'q'\n");
        printf("5. Comp Sort, Press 'C' or 'c'\n");
    } else {
        if(structureToSort == MATRIX_SORT){
            printf("1. Insertion Sort, Press 'I' or 'i'\n");
            printf("2. Quick Sort, Press 'Q' or 'q'\n");
        }else{
            printf("1. Insertion Sort, Press 'I' or 'i'\n");
            printf("2. Bubble Sort, Press 'B' or 'b'\n");
        }
    }

    printf("Enter your choice: ");

    do {
        choice = getchar();
        flush_stdin();
        switch (choice) {
            case 's':
            case 'S':
                if (structureToSort == VECTOR_SORT) {
                    printf("You chose Selection Sort\n");
                    return SELECTION_SORT;
                }
                break;
            case 'b':
            case 'B':
                printf("You chose Bubble Sort\n");
                return BUBBLE_SORT;
            case 'i':
            case 'I':
                printf("You chose Insertion Sort\n");
                return INSERTION_SORT;
            case 'm':
            case 'M':
                if (structureToSort == VECTOR_SORT) {
                    printf("You chose Merge Sort\n");
                    return MERGE_SORT;
                }
                break;
            case 'q':
            case 'Q':
                printf("You chose Quick Sort\n");
                return QUICK_SORT;
            case 'c':
            case 'C':
                if (structureToSort == VECTOR_SORT) {
                    printf("You chose Comp Sort\n");
                    return COMB_SORT;
                }
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

void sort(int sortingAlgorithme, int structureToSort)
{
    if (structureToSort == VECTOR_SORT)
    {

        int size = 15 ;
        int vector[size];
        fillVectorWithRandomIntegers(vector, size);

        switch (sortingAlgorithme)
        {
        case SELECTION_SORT:
            selectionSortVector(vector, size);
            break;

        case BUBBLE_SORT:
            bubbleSortVector(vector, size);
            break;

        case INSERTION_SORT:
            insertionSortVector(vector, size);
            break;

        case COMB_SORT:
            combSortVector(vector, size, size);
            break;

        case MERGE_SORT:
            mergeSortVector(vector, 0, size, size);
            break;

        case QUICK_SORT:
            quickSortVector(vector, 0, size, size);
            break;

        default:
            break;
        }
    }
    else if (structureToSort == MATRIX_SORT)
    {

        char matrix[10][20];
        fillMatrixWithRandomStrings(matrix, 10);

        switch (sortingAlgorithme)
        {

        case INSERTION_SORT:
            insertionSortMatrice(matrix, 10);
            break;

        case QUICK_SORT:
            quickSortMatrice(matrix, 0, 9, 10);
            break;

        default:
            break;
        }
    }
    else if (structureToSort == LINKED_LIST_SORT)
    {
        List head = NULL;
        fillLinkedListWithRandomStrings(&head, 15);

        switch (sortingAlgorithme)
        {

        case INSERTION_SORT:
            insertionSortList(&head);
            break;

        case BUBBLE_SORT:
            bubbleSortList(head);
            break;

        default:
            break;
        }
    }
}


int main(){

 srand(time(NULL));

    // Measure CPU time taken by Bubble Sort
    clock_t start, end;
    double cpu_time_used;

    int structureToSort = chooseTypeOfSorting();
    int sortingAlgorithem = chooseSortingAlgorithm(structureToSort);

    start = clock();
    sort(sortingAlgorithem, structureToSort);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken : %f seconds\n", cpu_time_used);

    return 0 ;
}