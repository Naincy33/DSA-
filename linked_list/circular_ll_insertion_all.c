#include <stdio.h>
#include <Stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void CircularLinkedListTraversal(struct Node *head)
{
    if (head == NULL)
    {
        printf("empty\n");
        return;
    }

    struct Node *ptr = head;
    do
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    if (head == NULL)
    {
        ptr->next = ptr;
        return ptr;
    }

    struct Node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    return ptr;
}
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    if (head == NULL)
    {
        ptr->next = ptr;
        return ptr;
    }

    struct Node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = head;
    return head;
}

struct Node *insertAtPosition(struct Node *head, int data, int pos)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    if (pos == 1)
    {
        return insertAtFirst(head, data);
    }
    struct Node *p = head;
    int i = 1;

    while (i < pos - 1 && p->next != head)
    {
        p = p->next;
        i++;
    }

    ptr->next = p->next;
    p->next = ptr;

    return head;
}
int main()
{
    struct Node *head = NULL;

    // Making initial circular list manually:
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 6);
    head = insertAtEnd(head, 1);

    printf("Original List:\n");
    CircularLinkedListTraversal(head);

    head = insertAtFirst(head, 56);
    printf("\nAfter inserting at FIRST:\n");
    CircularLinkedListTraversal(head);

    head = insertAtEnd(head, 99);
    printf("\nAfter inserting at END:\n");
    CircularLinkedListTraversal(head);

    head = insertAtPosition(head, 777, 3);
    printf("\nAfter inserting at POSITION 3:\n");
    CircularLinkedListTraversal(head);

    return 0;
}