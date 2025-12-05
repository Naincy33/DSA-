#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[30];
    long long mobile;
    struct node *next;
};

struct node *start = NULL;

struct node* createNode(char name[], long long mobile) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    strcpy(newnode->name, name);
    newnode->mobile = mobile;
    newnode->next = NULL;
    return newnode;
}

void insertEnd(char name[], long long mobile) {
    struct node *newnode = createNode(name, mobile);
    if(start == NULL) {
        start = newnode;
        return;
    }
    struct node *temp = start;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
}

void removeDuplicates() {
    struct node *ptr1 = start;
    struct node *ptr2, *dup;

    while(ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
        while(ptr2->next != NULL) {
            if(ptr1->mobile == ptr2->next->mobile) {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            } else {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
}

void display() {
    struct node *temp = start;
    if(temp == NULL) {
        printf("\nList is empty\n");
        return;
    }
    printf("\nFinal List (No Duplicates):\n");
    while(temp != NULL) {
        printf("%s\t%lld\n", temp->name, temp->mobile);
        temp = temp->next;
    }
}

int main() {
    int n;
    char name[30];
    long long mobile;

    printf("Enter number of registrations: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter Name and Mobile: ");
        scanf("%s %lld", name, &mobile);
        insertEnd(name, mobile);
    }

    removeDuplicates();
    display();

    return 0;
}
