#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int numComponents(struct ListNode* head, int* nums, int numsSize) {
    bool present[10001] = {false};

    for (int i = 0; i < numsSize; i++) {
        present[nums[i]] = true;
    }

    int count = 0;
    struct ListNode* curr = head;

    while (curr != NULL) {
        if (present[curr->val]) {
            if (curr->next == NULL || !present[curr->next->val]) {
                count++;
            }
        }
        curr = curr->next;
    }

    return count;
}

int main() {
    struct ListNode* head = createNode(0);
    head->next = createNode(1);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);

    int nums[] = {0, 1, 3};
    int numsSize = 3;

    int result = numComponents(head, nums, numsSize);
    printf("%d\n", result);

    return 0;
}
