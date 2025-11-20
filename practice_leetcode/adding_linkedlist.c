/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itsel*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Utility to create a new node
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add two numbers
struct Node *addTwoNumbers(struct Node *l1, struct Node *l2)
{
    struct Node dummy; // dummy head
    struct Node *tail = &dummy;
    dummy.next = NULL;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        int x = (l1 != NULL) ? l1->data : 0;
        int y = (l2 != NULL) ? l2->data : 0;

        int sum = x + y + carry;
        carry = sum / 10;

        tail->next = newNode(sum % 10);
        tail = tail->next;

        if (l1 != NULL)
            l1 = l1->next;
        if (l2 != NULL)
            l2 = l2->next;
    }

    return dummy.next;
}

// Helper function to print a linked list
void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d", head->data);
        if (head->next != NULL)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

// Example usage
int main()
{
    // l1 = [2 -> 4 -> 3]
    struct Node *l1 = newNode(2);
    l1->next = newNode(4);
    l1->next->next = newNode(3);

    // l2 = [5 -> 6 -> 4]
    struct Node *l2 = newNode(5);
    l2->next = newNode(6);
    l2->next->next = newNode(4);

    struct Node *result = addTwoNumbers(l1, l2);
    printList(result); // Output: 7 -> 0 -> 8

    return 0;
}
