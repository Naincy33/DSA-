#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// -------------------- Traversal (Forward) --------------------
void traversal(struct Node *head) {
    struct Node *ptr = head;
    printf("List: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// -------------------- Insert at FIRST --------------------
struct Node* insertAtFirst(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = head;

    if (head != NULL)
        head->prev = ptr;

    return ptr;   // new head
}

// -------------------- Insert at END --------------------
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;

    if (head == NULL) {
        ptr->prev = NULL;
        return ptr;
    }

    struct Node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }

    p->next = ptr;
    ptr->prev = p;

    return head;
}

// -------------------- Insert at POSITION --------------------
struct Node* insertAtPosition(struct Node* head, int data, int pos) {
    if (pos == 1)
        return insertAtFirst(head, data);

    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node* p = head;
    int i = 1;

    while (i < pos - 1 && p != NULL) {
        p = p->next;
        i++;
    }

    if (p == NULL) {
        printf("Invalid position!\n");
        free(ptr);
        return head;
    }

    ptr->next = p->next;
    ptr->prev = p;

    if (p->next != NULL)
        p->next->prev = ptr;

    p->next = ptr;

    return head;
}

// -------------------- Delete FIRST --------------------
struct Node* deleteFirst(struct Node* head) {
    if (head == NULL) return NULL;

    struct Node* temp = head;

    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);

    return head;
}

// -------------------- Delete END --------------------
struct Node* deleteEnd(struct Node* head) {
    if (head == NULL) return NULL;

    struct Node* p = head;

    if (head->next == NULL) {  // Only one node
        free(head);
        return NULL;
    }

    while (p->next != NULL)
        p = p->next;

    p->prev->next = NULL;
    free(p);

    return head;
}

// -------------------- Delete at POSITION --------------------
struct Node* deleteAtPosition(struct Node* head, int pos) {
    if (head == NULL) return NULL;

    if (pos == 1)
        return deleteFirst(head);

    struct Node *p = head;
    int i = 1;

    while (i < pos && p != NULL) {
        p = p->next;
        i++;
    }

    if (p == NULL) {
        printf("Invalid position!\n");
        return head;
    }

    p->prev->next = p->next;

    if (p->next != NULL)
        p->next->prev = p->prev;

    free(p);
    return head;
}

// -------------------------- MAIN --------------------------
int main() {
    struct Node *head = NULL;

    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

    printf("Original: ");
    traversal(head);

    head = insertAtFirst(head, 5);
    printf("\nAfter insert FIRST: ");
    traversal(head);

    head = insertAtEnd(head, 50);
    printf("After insert END: ");
    traversal(head);

    head = insertAtPosition(head, 99, 3);
    printf("After insert POS 3: ");
    traversal(head);

    head = deleteFirst(head);
    printf("\nAfter delete FIRST: ");
    traversal(head);

    head = deleteEnd(head);
    printf("After delete END: ");
    traversal(head);

    head = deleteAtPosition(head, 3);
    printf("After delete POS 3: ");
    traversal(head);

    return 0;
}
