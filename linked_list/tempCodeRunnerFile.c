#include <stdio.h>
#include <stdlib.h>

// Node structure
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

// Display list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// SORTING FUNCTION (Bubble Sort on Linked List)
void sortList(struct Node* head) {
    if (head == NULL)
        return;

    struct Node *ptr1, *ptr2;
    int temp;

    for (ptr1 = head; ptr1->next != NULL; ptr1 = ptr1->next) {
        for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next) {

            if (ptr1->data > ptr2->data) {
                // Swap data
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
        }
    }
}

// MAIN function
int main() {
    struct Node* head = NULL;

    insertEnd(&head, 5);
    insertEnd(&head, 1);
    insertEnd(&head, 4);
    insertEnd(&head, 2);
    insertEnd(&head, 8);

    printf("Original List: ");
    display(head);

    sortList(head);

    printf("Sorted List: ");
    display(head);

    return 0;
}
