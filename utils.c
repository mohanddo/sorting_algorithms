#include <stdio.h>
#include "utils.h"

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

void fillMatrixWithRandomStrings(char matrix[][20], int matrixSize)
{
    for (size_t i = 0; i < matrixSize; i++)
    {
        strcpy(matrix[i], strings[rand() % 100]);
    }
}

void fillLinkedListWithRandomStrings(List *head, int linkedListLength) {
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
