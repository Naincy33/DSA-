#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Customer {
    char name[50];
    char email[50];
    struct Customer *prev, *next;
};

/* Create new node */
struct Customer* createNode(char name[], char email[]) {
    struct Customer* n = (struct Customer*)malloc(sizeof(struct Customer));
    strcpy(n->name, name);
    strcpy(n->email, email);
    n->prev = n->next = NULL;
    return n;
}

/* Insert in alphabetical order */
void insertSorted(struct Customer **head, char name[], char email[]) {
    struct Customer* newNode = createNode(name, email);

    /* Empty list */
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    /* Insert at beginning */
    if (strcmp(name, (*head)->name) < 0) {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    /* Traverse to find position */
    struct Customer* curr = *head;
    while (curr->next != NULL && strcmp(name, curr->next->name) > 0) {
        curr = curr->next;
    }

    /* Insert in middle or end */
    newNode->next = curr->next;
    if (curr->next != NULL)
        curr->next->prev = newNode;

    curr->next = newNode;
    newNode->prev = curr;
}

/* Print customer names */
void printNames(struct Customer* head) {
    struct Customer* temp = head;
    printf("Customer Names (Alphabetical Order):\n");
    while (temp != NULL) {
        printf("%s\n", temp->name);
        temp = temp->next;
    }
}

int main() {
    struct Customer* head = NULL;

    insertSorted(&head, "Riya", "riya@gmail.com");
    insertSorted(&head, "Aman", "aman@gmail.com");
    insertSorted(&head, "Neha", "neha@gmail.com");
    insertSorted(&head, "Karan", "karan@gmail.com");

    printNames(head);

    return 0;
}
