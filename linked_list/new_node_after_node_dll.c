#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next, *prev;
};

struct node* insertAfter(struct node *head, int val, int newData) {
    struct node *ptr = head;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = newData;

    // Find the node with value = val
    while(ptr != NULL && ptr->data != val) {
        ptr = ptr->next;
    }

    if(ptr == NULL) {
        printf("Value not found!\n");
        free(newnode);
        return head;
    }

    // Insert newnode after ptr
    newnode->next = ptr->next;
    newnode->prev = ptr;

    if(ptr->next != NULL) {
        ptr->next->prev = newnode;
    }

    ptr->next = newnode;

    return head;
}

void display(struct node *head) {
    struct node *temp = head;
    printf("Linked List: ");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {

    // Creating sample linked list: 10 -> 20 -> 30 -> 40
    struct node *head = (struct node*)malloc(sizeof(struct node));
    struct node *n2 = (struct node*)malloc(sizeof(struct node));
    struct node *n3 = (struct node*)malloc(sizeof(struct node));
    struct node *n4 = (struct node*)malloc(sizeof(struct node));

    head->data = 10; head->prev = NULL; head->next = n2;
    n2->data = 20; n2->prev = head; n2->next = n3;
    n3->data = 30; n3->prev = n2; n3->next = n4;
    n4->data = 40; n4->prev = n3; n4->next = NULL;

    display(head);

    head = insertAfter(head, 20, 22);

    display(head);

    return 0;
}
