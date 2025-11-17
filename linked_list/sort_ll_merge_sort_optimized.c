#include <stdio.h>
#include <stdlib.h>

// Node structure
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

// Display linked list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// ----------- MERGE TWO SORTED LISTS -----------
struct Node* merge(struct Node* a, struct Node* b) {
    if (!a) return b;
    if (!b) return a;

    struct Node* result = NULL;

    if (a->data < b->data) {
        result = a;
        result->next = merge(a->next, b);
    } else {
        result = b;
        result->next = merge(a, b->next);
    }
    return result;
}

// ----------- FIND MIDDLE NODE ----------
struct Node* findMid(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;   // slow = middle node
}

// ----------- MERGE SORT FUNCTION ----------
struct Node* mergeSort(struct Node* head) {
    // Base case: 0 or 1 node → already sorted
    if (!head || !head->next)
        return head;

    // Step 1: Find middle
    struct Node* mid = findMid(head);

    // Step 2: Split list into two halves
    struct Node* right = mid->next;
    mid->next = NULL;

    // Step 3: Sort both halves
    struct Node* leftSorted = mergeSort(head);
    struct Node* rightSorted = mergeSort(right);

    // Step 4: Merge both sorted halves
    return merge(leftSorted, rightSorted);
}

// ----------- MAIN FUNCTION ----------
int main() {
    struct Node* head = NULL;

    insertEnd(&head, 5);
    insertEnd(&head, 1);
    insertEnd(&head, 8);
    insertEnd(&head, 3);
    insertEnd(&head, 2);

    printf("Original List: ");
    display(head);

    head = mergeSort(head);

    printf("Sorted List: ");
    display(head);

    return 0;
}
