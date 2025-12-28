#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct Node {
    int data;
    struct Node* next;
};

/* Create new node */
struct Node* newNode(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->next = NULL;
    return n;
}

/* Insert at end */
void insertEnd(struct Node** head, int x) {
    struct Node* n = newNode(x);
    if (*head == NULL) {
        *head = n;
        return;
    }
    struct Node* t = *head;
    while (t->next != NULL)
        t = t->next;
    t->next = n;
}

/* Display list */
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

/* Split the list into two halves */
void split(struct Node* head, struct Node** a, struct Node** b) {
    struct Node *slow = head, *fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    *a = head;
    *b = slow->next;
    slow->next = NULL;
}

/* Merge two sorted lists */
struct Node* merge(struct Node* a, struct Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    if (a->data <= b->data) {
        a->next = merge(a->next, b);
        return a;
    } else {
        b->next = merge(a, b->next);
        return b;
    }
}

/* Merge Sort */
void mergeSort(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL)
        return;

    struct Node *a, *b;
    split(*head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *head = merge(a, b);
}

/* Remove duplicates from sorted list */
void removeDuplicates(struct Node* head) {
    struct Node* curr = head;

    while (curr != NULL && curr->next != NULL) {
        if (curr->data == curr->next->data) {
            struct Node* temp = curr->next;
            curr->next = temp->next;
            free(temp);
        } else {
            curr = curr->next;
        }
    }
}

int main() {
    struct Node* head = NULL;

    /* Example input */
    insertEnd(&head, 4);
    insertEnd(&head, 2);
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);

    printf("Original List:\n");
    display(head);

    mergeSort(&head);

    printf("Sorted List:\n");
    display(head);

    removeDuplicates(head);

    printf("After Removing Duplicates:\n");
    display(head);

    return 0;
}
