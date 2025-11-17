#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Display
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Comparator for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Sort using Array Conversion
void sortList(struct Node* head) {
    if (head == NULL)
        return;

    // Step 1: Count nodes
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    // Step 2: Create array
    int* arr = (int*)malloc(count * sizeof(int));

    // Step 3: Store data in array
    temp = head;
    for (int i = 0; i < count; i++) {
        arr[i] = temp->data;
        temp = temp->next;
    }

    // Step 4: Sort array
    qsort(arr, count, sizeof(int), compare);

    // Step 5: Copy sorted data back to linked list
    temp = head;
    for (int i = 0; i < count; i++) {
        temp->data = arr[i];
        temp = temp->next;
    }

    free(arr);
}

int main() {
    struct Node* head = NULL;

    insertEnd(&head, 5);
    insertEnd(&head, 3);
    insertEnd(&head, 8);
    insertEnd(&head, 1);

    printf("Original List: ");
    display(head);

    sortList(head);

    printf("Sorted List: ");
    display(head);

    return 0;
}
