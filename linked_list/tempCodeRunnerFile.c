#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev, *next;
};

struct Node *newNode(int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->prev = n->next = NULL;
    return n;
}

void append(struct Node **head, int data)
{
    struct Node *n = newNode(data);

    if (*head == NULL)
    {
        *head = n;
        return;
    }

    struct Node *temp = *head;
    while (temp->next)
        temp = temp->next;

    temp->next = n;
    n->prev = temp;
}

void removeDuplicates(struct Node *head)
{
    struct Node *cur, *temp;

    for (cur = head; cur != NULL; cur = cur->next)
    {
        temp = cur->next;

        while (temp != NULL)
        {
            if (temp->data == cur->data)
            {
                struct Node *del = temp;
                temp = temp->next;

                del->prev->next = del->next;
                if (del->next)
                    del->next->prev = del->prev;

                free(del);
            }
            else
            {
                temp = temp->next;
            }
        }
    }
}

void printList(struct Node *head)
{
    while (head)
    {
        printf("%d", head->data);
        if (head->next)
            printf(" <-> ");
        head = head->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;
    int arr[] = {8, 7, 5, 8, 7, 8, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
        append(&head, arr[i]);

    printf("Original: ");
    printList(head);

    removeDuplicates(head);

    printf("After removing duplicates: ");
    printList(head);

    return 0;
}
