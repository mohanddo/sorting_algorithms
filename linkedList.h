// Define the structure for linked list elements
typedef struct ElementList {
    char word[100];
    struct ElementList* next;
} ElementList;

// Define a typedef for the pointer to ElementList
typedef ElementList* List;

void displayList(List head);
void addElementToList(List* head, char* data);
void bubbleSortList(List head, int* numComparisons, int* numPermutations);
void insertionSortList(List* head, int* numComparisons, int* numPermutations);