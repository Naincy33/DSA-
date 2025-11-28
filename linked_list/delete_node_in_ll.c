#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode* next;
};

void deleteNode(struct ListNode* node){
    struct ListNode* temp = node->next;
    node->val = temp->val;
    node->next = temp->next;
    free(temp);
}

void printList(struct ListNode* head){
    struct ListNode* temp = head;
    while(temp != NULL){
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

// helper function to create node
struct ListNode* createNode(int x){
    struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newnode->val = x;
    newnode->next = NULL;
    return newnode;
}

int main(){
    // create linked list: 4->5->1->9
    struct ListNode* head = createNode(4);
    head->next = createNode(5);
    head->next->next = createNode(1);
    head->next->next->next = createNode(9);

    printf("Before deletion: ");
    printList(head);

    // suppose we want to delete node "5"
    struct ListNode* node = head->next;

    deleteNode(node);

    printf("After deletion:  ");
    printList(head);

    return 0;
}
