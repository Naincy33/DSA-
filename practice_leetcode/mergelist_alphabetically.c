#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[30];
    struct node *next;
};

struct node* createNode(char name[]) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    strcpy(newnode->name, name);
    newnode->next = NULL;
    return newnode;
}

void insertEnd(struct node **head, char name[]) {
    struct node *newnode = createNode(name);

    if(*head == NULL) {
        *head = newnode;
        return;
    }

    struct node *temp = *head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}

struct node* mergeLists(struct node *h1, struct node *h2) {
    struct node dummy;
    struct node *tail = &dummy;
    dummy.next = NULL;

    while(h1 != NULL && h2 != NULL) {
        if(strcmp(h1->name, h2->name) < 0) {
            tail->next = h1;
            h1 = h1->next;
        } else {
            tail->next = h2;
            h2 = h2->next;
        }
        tail = tail->next;
    }

    if(h1 != NULL) tail->next = h1;
    if(h2 != NULL) tail->next = h2;

    return dummy.next;
}

void display(struct node *head) {
    while(head != NULL) {
        printf("%s\n", head->name);
        head = head->next;
    }
}

int main() {
    int n1, n2;
    char name[30];
    struct node *head1 = NULL, *head2 = NULL, *merged = NULL;

    printf("Enter number of students in list A: ");
    scanf("%d", &n1);

    printf("Enter names in sorted order for List A:\n");
    for(int i = 0; i < n1; i++) {
        scanf("%s", name);
        insertEnd(&head1, name);
    }

    printf("Enter number of students in list B: ");
    scanf("%d", &n2);

    printf("Enter names in sorted order for List B:\n");
    for(int i = 0; i < n2; i++) {
        scanf("%s", name);
        insertEnd(&head2, name);
    }

    merged = mergeLists(head1, head2);

    printf("\nMerged Sorted List:\n");
    display(merged);

    return 0;
}
