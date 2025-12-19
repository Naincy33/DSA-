#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

// Linked list node
struct Node {
    int data;
    struct Node* next;
};

// Hash table (array of pointers)
struct Node* table[SIZE];

// Hash function
int hashFunc(int key) {
    return key % SIZE;
}

// Insert using chaining
void insert(int key) {
    int index = hashFunc(key);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = table[index];   // insert at head
    table[index] = newNode;
}

// Search in chaining
int search(int key) {
    int index = hashFunc(key);
    struct Node* temp = table[index];

    while (temp != NULL) {
        if (temp->data == key)
            return 1;
        temp = temp->next;
    }
    return 0;
}

// Display hash table
void display() {
    for (int i = 0; i < SIZE; i++) {
        printf("%d: ", i);
        struct Node* temp = table[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    insert(10);
    insert(17);
    insert(24);   // all collide at same index

    display();

    printf("%d\n", search(10));  // 1
    printf("%d\n", search(17));  // 1
    printf("%d\n", search(24));  // 1

    return 0;
}
