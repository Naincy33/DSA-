#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    struct Student *prev, *next;
};

/* Create new node */
struct Student* createNode(int roll, char name[]) {
    struct Student* n = (struct Student*)malloc(sizeof(struct Student));
    n->roll = roll;
    strcpy(n->name, name);
    n->prev = n->next = NULL;
    return n;
}

/* Insert at end */
void insertEnd(struct Student **head, int roll, char name[]) {
    struct Student* n = createNode(roll, name);

    if (*head == NULL) {
        *head = n;
        return;
    }

    struct Student* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
    n->prev = temp;
}

/* Display list */
void display(struct Student* head) {
    struct Student* temp = head;
    while (temp != NULL) {
        printf("[%d, %s]", temp->roll, temp->name);
        if (temp->next)
            printf(" <-> ");
        temp = temp->next;
    }
    printf("\n");
}

/* Remove all nodes with given roll number */
void removeByRoll(struct Student **head, int targetRoll) {
    struct Student* curr = *head;

    while (curr != NULL) {
        if (curr->roll == targetRoll) {
            struct Student* del = curr;
            curr = curr->next;

            // deleting head node
            if (del->prev == NULL) {
                *head = del->next;
                if (*head != NULL)
                    (*head)->prev = NULL;
            }
            // deleting middle or last node
            else {
                del->prev->next = del->next;
                if (del->next != NULL)
                    del->next->prev = del->prev;
            }
            free(del);
        } else {
            curr = curr->next;
        }
    }
}

int main() {
    struct Student* head = NULL;
    int targetRoll;

    /* Sample data */
    insertEnd(&head, 101, "Aman");
    insertEnd(&head, 102, "Riya");
    insertEnd(&head, 101, "Karan");
    insertEnd(&head, 103, "Neha");
    insertEnd(&head, 101, "Pooja");

    printf("Original List:\n");
    display(head);

    printf("\nEnter roll number to delete: ");
    scanf("%d", &targetRoll);

    removeByRoll(&head, targetRoll);

    printf("\nUpdated List:\n");
    display(head);

    return 0;
}
