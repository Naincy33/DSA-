#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Insert node at the end
struct Node* insert(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Display forward
void displayForward(struct Node* head) {
    printf("Forward: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Display backward
void displayBackward(struct Node* tail) {
    printf("Backward: ");
    while (tail != NULL) {
        printf("%d ", tail->data);
        tail = tail->prev;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);

    displayForward(head);

    // Go to last node
    struct Node* tail = head;
    while (tail->next != NULL)
        tail = tail->next;

    displayBackward(tail);

    return 0;
}
