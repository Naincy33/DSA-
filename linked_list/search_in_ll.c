#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode* next;
};

struct ListNode* head = NULL;

struct ListNode* createNode(int x){
    struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newnode->val = x;
    newnode->next = NULL;
    return newnode;
}

void printList(struct ListNode* head){
    struct ListNode* temp = head;
    while(temp != NULL){
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

void search(){
    struct ListNode* ptr;
    int item, i=0, flag = 1;
    
    ptr= head;
    if(ptr== NULL){
        printf("List is empty\n");
    }
    else{
        printf("Enter item to search: ");
        scanf("%d", &item);
        while (ptr!=NULL){
            if(ptr->val == item){
                printf("Item found at location %d\n", i+1);
                flag=0;
                break;
            }
            i++;
            ptr=ptr->next;
        }
        if(flag==1){
            printf("Item not found in the list\n");
        }
    }
}

int main(){
    head = createNode(4);
    head->next = createNode(5);
    head->next->next = createNode(1);
    head->next->next->next = createNode(9);

    printf("Linked List: ");
    printList(head);

    search();

    return 0;
}
