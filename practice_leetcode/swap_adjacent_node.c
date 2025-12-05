#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* swapPairs(struct ListNode* head) {

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;

    struct ListNode* prev = dummy;
    struct ListNode* curr = head;

    while (curr != NULL && curr->next != NULL) {

        struct ListNode* first  = curr;
        struct ListNode* second = curr->next;

        // swap
        prev->next = second;
        first->next = second->next;
        second->next = first;

        // move pointers forward
        prev = first;
        curr = first->next;
    }

    return dummy->next;
};

// helper function
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {

    // create linked list: 1->2->3->4
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    printf("Before swapping: ");
    printList(head);

    head = swapPairs(head);

    printf("After swapping:  ");
    printList(head);

    return 0;
}
