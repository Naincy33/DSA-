#include <stdio.h>
#include <stdlib.h>

// ------------------- NODE STRUCTURE ---------------------
struct Node {
    int data;
    struct Node* next;
};

// Create new node
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

// Print list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}





// ========================================================
//  1. ITERATIVE METHOD (3 POINTER) --> MOST IMPORTANT
// ========================================================

struct Node* reverseIterative(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;      // store next
        curr->next = prev;      // reverse link
        prev = curr;            // move prev
        curr = next;            // move current
    }
    return prev; // new head
}



// ========================================================
//  2. RECURSIVE REVERSE
// ========================================================

struct Node* reverseRecursive(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct Node* newHead = reverseRecursive(head->next);

    head->next->next = head; // reverse link
    head->next = NULL;       // last node becomes NULL

    return newHead;
}



// ========================================================
//  3. STACK-BASED REVERSE
// ========================================================

struct Node* reverseUsingStack(struct Node* head) {
    if (head == NULL) return NULL;

    // Step 1: Count nodes
    int size = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        size++;
        temp = temp->next;
    }

    // Step 2: Create stack
    struct Node** stack = (struct Node**)malloc(size * sizeof(struct Node*));

    // Step 3: Push nodes
    temp = head;
    int i = 0;
    while (temp != NULL) {
        stack[i++] = temp;
        temp = temp->next;
    }

    // Step 4: Pop and rebuild
    struct Node* newHead = stack[size - 1];
    temp = newHead;

    for (i = size - 2; i >= 0; i--) {
        temp->next = stack[i];
        temp = temp->next;
    }

    temp->next = NULL; // last node points to NULL
    free(stack);

    return newHead;
}



// ========================================================
//  4. ARRAY-BASED REVERSE (Extra space)
// ========================================================

struct Node* reverseUsingArray(struct Node* head) {
    if (head == NULL) return NULL;

    // Step 1: Count nodes
    int size = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        size++;
        temp = temp->next;
    }

    // Step 2: Copy data to array
    int* arr = (int*)malloc(size * sizeof(int));
    temp = head;

    for (int i = 0; i < size; i++) {
        arr[i] = temp->data;
        temp = temp->next;
    }

    // Step 3: Rewrite in reverse order
    temp = head;
    for (int i = size - 1; i >= 0; i--) {
        temp->data = arr[i];
        temp = temp->next;
    }

    free(arr);
    return head;
}




// ======================= MAIN ===========================

int main() {
    struct Node* head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);
    insertEnd(&head, 50);

    printf("Original List:\n");
    printList(head);



    // 1. Iterative Reverse
    head = reverseIterative(head);
    printf("\nAfter Iterative Reverse:\n");
    printList(head);


    // 2. Recursive Reverse
    head = reverseRecursive(head);
    printf("\nAfter Recursive Reverse:\n");
    printList(head);


    // 3. Stack Reverse
    head = reverseUsingStack(head);
    printf("\nAfter Stack Reverse:\n");
    printList(head);


    // 4. Array Reverse
    head = reverseUsingArray(head);
    printf("\nAfter Array Reverse:\n");
    printList(head);

    return 0;
}
