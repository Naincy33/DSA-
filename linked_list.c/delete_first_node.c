#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *deleteFirst(struct Node *head )
{
    struct Node *ptr = head;
    head= head->next;
    free(ptr);
    return head;
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 66;
    second->next = third;

    third->data = 11;
    third->next = NULL;

    printf("before\n");
    linkedListTraversal(head);
    head = deleteFirst(head );
    linkedListTraversal(head);
    return 0;
}