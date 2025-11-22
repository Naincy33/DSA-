#include <stdio.h>
#include <stdlib.h>

/*
    QUESTION:
    Given the heads of two singly linked lists, return the node 
    at which they intersect (same memory address).
    If no intersection, return NULL.
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

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    struct ListNode *p1 = headA, *p2 = headB;
    while (p1 != p2) {
        p1 = (p1 == NULL) ? headB : p1->next;
        p2 = (p2 == NULL) ? headA : p2->next;
    }
    return p1;
}

int main() {
    // Create intersection part
    struct ListNode* c1 = createNode(8);
    c1->next = createNode(10);

    // List A: 3 → 7 → 8 → 10
    struct ListNode* A = createNode(3);
    A->next = createNode(7);
    A->next->next = c1;

    // List B: 99 → 1 → 8 → 10
    struct ListNode* B = createNode(99);
    B->next = createNode(1);
    B->next->next = c1;

    struct ListNode* ans = getIntersectionNode(A, B);

    if (ans)
        printf("Intersection at node value: %d\n", ans->val);
    else
        printf("No intersection.\n");

    return 0;
}
