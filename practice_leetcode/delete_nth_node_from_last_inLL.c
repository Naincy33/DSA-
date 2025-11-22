#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// ---------------- REMOVE Nth NODE FROM END (your logic) ----------------

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // Dummy node (edge cases)
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;

    // Step 1: Length find karo
    int size = 0;
    struct ListNode* temp = head;

    while (temp != NULL) {
        size++;
        temp = temp->next;
    }

    // Step 2: pos from front = size - n
    int pos = size - n;

    // Step 3: pos se just pehle tak jaao
    temp = dummy;
    for (int i = 0; i < pos; i++) {
        temp = temp->next;
    }

    // Step 4: Delete
    struct ListNode* del = temp->next;
    temp->next = temp->next->next;
    free(del);

    struct ListNode* newHead = dummy->next;
    free(dummy);
    return newHead;
}

// -------------------- Helper Functions --------------------

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* insertEnd(struct ListNode* head, int val) {
    struct ListNode* newNode = createNode(val);
    if (head == NULL) return newNode;

    struct ListNode* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    return head;
}

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// ------------------------ MAIN FUNCTION ------------------------

int main() {
    struct ListNode* head = NULL;
    int n, value, size;

    printf("Enter number of nodes: ");
    scanf("%d", &size);

    printf("Enter %d values:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printf("Enter n (remove nth from end): ");
    scanf("%d", &n);

    printf("Original List: ");
    printList(head);

    head = removeNthFromEnd(head, n);

    printf("After removing %dth node from end: ", n);
    printList(head);

    return 0;
}
