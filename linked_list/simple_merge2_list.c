#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->next = NULL;
    return n;
}

struct Node* mergeSimple(struct Node* list1, struct Node* list2) {
    if (list1 == NULL)
        return list2;

    struct Node* temp = list1;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = list2;
    return list1;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* list1 = newNode(10);
    list1->next = newNode(20);
    list1->next->next = newNode(30);

    struct Node* list2 = newNode(40);
    list2->next = newNode(50);

    struct Node* list3 = mergeSimple(list1, list2);

    printf("Merged Simple List:\n");
    printList(list3);

    return 0;
}
