#include <stdio.h>
#include <stdlib.h>

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

// Print linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


// -------------------------------
// CONCATENATE (Your Method)
// -------------------------------
void concatenate(struct Node* head1, struct Node* head2) {

    if (head1 == NULL) { 
        // If first list empty, second becomes whole result
        head1 = head2;
        return;
    }

    struct Node* temp = head1;

    // Go to last node of first list
    while (temp->next != NULL)
        temp = temp->next;

    // Link last node of list1 to head2
    temp->next = head2;
}



// -------------------------------
// MAIN FUNCTION
// -------------------------------
int main() {

    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    // First list
    insertEnd(&head1, 10);
    insertEnd(&head1, 20);
    insertEnd(&head1, 30);

    // Second list
    insertEnd(&head2, 40);
    insertEnd(&head2, 50);
    insertEnd(&head2, 60);

    printf("First List:\n");
    printList(head1);

    printf("Second List:\n");
    printList(head2);

    // Concatenate
    concatenate(head1, head2);

    printf("\nAfter Concatenation:\n");
    printList(head1);

    return 0;
}
