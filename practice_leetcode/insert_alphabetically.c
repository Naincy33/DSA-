#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[30];
    char email[50];
    struct node *prev, *next;
};

struct node *head = NULL;

struct node* createNode(char name[], char email[]) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    strcpy(newnode->name, name);
    strcpy(newnode->email, email);
    newnode->prev = newnode->next = NULL;
    return newnode;
}

void insertSorted(char name[], char email[]) {
    struct node *newnode = createNode(name, email);

    if(head == NULL || strcmp(name, head->name) < 0) {
        newnode->next = head;
        if(head != NULL)
            head->prev = newnode;
        head = newnode;
        return;
    }

    struct node *temp = head;
    while(temp->next != NULL && strcmp(temp->next->name, name) < 0)
        temp = temp->next;

    newnode->next = temp->next;
    if(temp->next != NULL)
        temp->next->prev = newnode;

    temp->next = newnode;
    newnode->prev = temp;
}

void display() {
    struct node *temp = head;
    printf("\nCustomer List in Alphabetical Order:\n");
    while(temp != NULL) {
        printf("%s\t%s\n", temp->name, temp->email);
        temp = temp->next;
    }
}

int main() {
    int n;
    char name[30], email[50];

    printf("Enter number of customers: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter Name and Email: ");
        scanf("%s %s", name, email);
        insertSorted(name, email);
    }

    display();
    return 0;
}
