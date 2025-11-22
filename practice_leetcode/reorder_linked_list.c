#include <stdio.h>
#include <stdlib.h>

/*
    QUESTION: 
    Given the head of a singly linked list, reorder it as:
    L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
*/

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL, *curr = head, *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void reorderList(struct ListNode* head) {
    if (!head || !head->next) return;

    struct ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* second = reverseList(slow->next);
    slow->next = NULL;

    struct ListNode *first = head, *temp;
    while (second) {
        temp = first->next;
        first->next = second;
        second = second->next;
        first->next->next = temp;
        first = temp;
    }
}

void printList(struct ListNode* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original List: ");
    printList(head);

    reorderList(head);

    printf("Reordered List: ");
    printList(head);

    return 0;
}
