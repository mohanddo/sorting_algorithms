#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedListSort.h"

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
    printf("Iteration number: %d | ", iterationNumber );
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
    printf("Iteration number: %d | ", iterationNumber);
    printf("\n");
}
