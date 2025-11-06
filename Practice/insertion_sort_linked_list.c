/*Sort a singly linked list using insertion sort
Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list’s head*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to perform insertion sort on a linked list
struct ListNode* insertionSortList(struct ListNode* head) {
    // If list is empty or has one node, it's already sorted
    if (head == NULL || head->next == NULL)
        return head;

    // Dummy node to act as the new sorted list's head
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = -1;       // dummy value
    dummy->next = NULL;    // start with empty sorted list

    // Current pointer to traverse the original list
    struct ListNode* curr = head;

    // Traverse the original list
    while (curr != NULL) {
        // Save the next node before changing pointers
        struct ListNode* nextNode = curr->next;

        // Find the correct place in the sorted list
        struct ListNode* prev = dummy;
        while (prev->next != NULL && prev->next->val < curr->val) {
            prev = prev->next;
        }

        // Insert current node at the correct position
        curr->next = prev->next;
        prev->next = curr;

        // Move to the next node from the original list
        curr = nextNode;
    }

    // The sorted list starts from dummy->next
    struct ListNode* sortedHead = dummy->next;
    free(dummy); // free dummy node memory
    return sortedHead;
}

// 🔹 Helper function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// 🔹 Helper function to print the linked list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// 🔹 Driver code (main function)
int main() {
    // Creating linked list: 4 → 2 → 1 → 3
    struct ListNode* head = createNode(4);
    head->next = createNode(2);
    head->next->next = createNode(1);
    head->next->next->next = createNode(3);

    printf("Original List: ");
    printList(head);

    // Sorting the list
    head = insertionSortList(head);

    printf("Sorted List:   ");
    printList(head);

    return 0;
}
