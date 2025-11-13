#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void CircularLinkedListTraversal(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *ptr = head;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}

struct Node *deleteFirst(struct Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    struct Node *p = head;
    if (head->next = head)
    {
        free(head);
        return NULL;
    }
    while (p->next != head)
    {
        p = p->next;
    }

    struct Node *temp = head;
    p->next = head->next;
    head = head->next;
    free(temp);
    return head;
}

struct Node *deleteEnd(struct Node *head)
{

    if (head == NULL)
        return NULL;

    if (head->next == head)
    {
        free(head);
        return NULL;
    }
    struct Node *p = head;
    struct Node *q = head->next;

    while (q->next != head)
    {
        p = p->next;
        q = q->next;
    }
    p->next = head;
    free(q);

    return head;
}

struct Node *deleteAtPosition(struct Node *head, int pos)
{
    if (head == NULL)
        return NULL;

    if (pos == 1)
    {
        return deleteFirst(head);
    }
    struct Node *p = head;
    struct Node *q = head->next;
    int i = 1;

    while (i < pos - 1 && q->next != head)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    if (q == head)
    {
        printf("Invalid position!\n");
        return head;
    }

    p->next = q->next;
    free(q);

    return head;
}

int main()
{
    struct Node *head = NULL;

    // Creating list manually
    struct Node *n1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n3 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n4 = (struct Node *)malloc(sizeof(struct Node));

    n1->data = 10;
    n1->next = n2;
    n2->data = 20;
    n2->next = n3;
    n3->data = 30;
    n3->next = n4;
    n4->data = 40;
    n4->next = n1; // circular
    head = n1;

    printf("Original List:\n");
    CircularLinkedListTraversal(head);

    head = deleteFirst(head);
    printf("\nAfter deleting FIRST:\n");
    CircularLinkedListTraversal(head);

    head = deleteEnd(head);
    printf("\nAfter deleting LAST:\n");
    CircularLinkedListTraversal(head);

    head = deleteAtPosition(head, 2);
    printf("\nAfter deleting at POSITION 2:\n");
    CircularLinkedListTraversal(head);

    return 0;
}