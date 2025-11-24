#include <stdio.h>
#include <stdlib.h>

// Linked list node
struct ListNode {
    int val;
    struct ListNode* next;
};

// Create new node
struct ListNode* newNode(int x) {
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->val = x;
    temp->next = NULL;
    return temp;
}

// Rotate Right function
struct ListNode* rotateRight(struct ListNode* head, int k) {

    if (!head || !head->next || k == 0)
        return head;

    // Step 1: Find length of list
    struct ListNode* temp = head;
    int length = 1;
    while (temp->next) {
        temp = temp->next;
        length++;
    }

    // Step 2: Connect tail to head (circular list)
    temp->next = head;

    // Step 3: Effective rotation
    k = k % length;
    int stepsToNewTail = length - k - 1;

    // Step 4: Move to new tail
    struct ListNode* newTail = head;
    for (int i = 0; i < stepsToNewTail; i++)
        newTail = newTail->next;

    // Step 5: New head is next of new tail
    struct ListNode* newHead = newTail->next;

    // Step 6: Break the circle
    newTail->next = NULL;

    return newHead;
}

// Print list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// Driver code to test
int main() {

    // Example: 1->2->3->4->5
    struct ListNode* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    int k = 2;

    printf("Original: ");
    printList(head);

    head = rotateRight(head, k);

    printf("Rotated: ");
    printList(head);

    return 0;
}
