#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linkedList.h>

// Function to print the linked list
void displayList(List head) {
    List current = head;
    while (current != NULL) {
        printf("%s -> ", current->word);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to add elements to the list
void addElementToList(List* head, char* data) {
    // Allocate the new element
    List newElement = (List)malloc(sizeof(ElementList));
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

// Bubble sort function for linked list in ascending order
void bubbleSortList(List head, int* numComparisons, int* numPermutations) {
    if (head == NULL) {
        printf("Error: The list is empty\n");
        return;
    }

    List endPointer = NULL;
    List current;
    char temp[100];
    int swapped;

    *numComparisons = 0;
    *numPermutations = 0;

    do {
        swapped = 0;
        current = head;

        while (current->next != endPointer) {
            (*numComparisons)++;
            if (strcmp(current->word, current->next->word) > 0) {
                strcpy(temp, current->word);
                strcpy(current->word, current->next->word);
                strcpy(current->next->word, temp);
                (*numPermutations)++;
                swapped = 1;
            }
            current = current->next;
        }
        displayList(head);
        endPointer = current;
    } while (swapped);
}

// Insertion sort function for linked list in ascending order
void insertionSortList(List* head, int* numComparisons, int* numPermutations) {
    // Test if the list is empty
    if (*head == NULL) {
        printf("Error: The list is empty\n");
        return;
    }

    // Initialize counters
    *numComparisons = 0;
    *numPermutations = 0;

    // Create a new head
    List newHead = (List)malloc(sizeof(ElementList));
    newHead->next = *head;
    strcpy(newHead->word, "");

    List current = (*head)->next;  // Start from the second element
    List prev = *head;

    while (current != NULL) {
        if (strcmp(current->word, prev->word) >= 0) {
            // If the current element is greater than or equal to the previous, continue
            prev = current;
            current = current->next;
            (*numComparisons)++;
        } else {
            // Find the position to insert the current element in the sorted part
            List temp = newHead;
            prev->next = current->next;
            if (strcmp(current->word, temp->next->word) <= 0) {
                current->next = temp->next;
                temp->next = current;
                (*numComparisons)++;
            } else {
                while (temp->next != NULL && strcmp(current->word, temp->next->word) > 0) {
                    temp = temp->next;
                    (*numComparisons)++;
                }
                current->next = temp->next;
                temp->next = current;
                
            }
            (*numPermutations)++;
            current = prev->next;
        }
        displayList(newHead->next); // Display the list after each iteration
        printf("\n");
    }

    *head = newHead->next;
    free(newHead);
}
