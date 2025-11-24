#include<stdio.h>
#include<stdlib.h>

typedef struct DListNode {
    int data;
    struct DListNode* prev;
    struct DListNode* next;
} DListNode;

DListNode* createNode(int data) {
    DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void insert_at_beg(DListNode** head, int data) {
    DListNode* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

void insert_at_end(DListNode** head, int data) {
    DListNode* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    DListNode* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insert_at_pos(DListNode** head, int data, int pos) {
    if (pos == 0) {
        insert_at_beg(head, data);
        return;
    }
    DListNode* newNode = createNode(data);
    DListNode* temp = *head;
    for (int i = 0; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void display(DListNode* head) {
    DListNode* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void delete_at_beg(DListNode** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    DListNode* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

void delete_at_end(DListNode** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    DListNode* temp = *head;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

void delete_at_pos(DListNode** head, int pos) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    DListNode* temp = *head;
    if (pos == 0) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }
    for (int i = 0; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp);
}

int main() {
    DListNode* head = NULL;

    insert_at_end(&head, 10);
    insert_at_end(&head, 20);
    insert_at_beg(&head, 5);
    insert_at_pos(&head, 15, 2);

    printf("Doubly Linked List: ");
    display(head);

    delete_at_pos(&head, 2);
    printf("After deleting at position 2: ");
    display(head);

    delete_at_beg(&head);
    printf("After deleting at beginning: ");
    display(head);

    delete_at_end(&head);
    printf("After deleting at end: ");
    display(head);

    return 0;
}