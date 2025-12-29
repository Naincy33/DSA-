#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 7

// Node for chaining
struct Node {
    char name[20];
    struct Node* next;
};

struct Node* table[SIZE];

// Simple string hash (ASCII sum)
int hashFunc(char* s) {
    int sum = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        sum += s[i];
    }
    return sum % SIZE;
}

// Insert string
void insert(char* s) {
    int index = hashFunc(s);

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    strcpy(node->name, s);
    node->next = table[index];
    table[index] = node;
}

// Search string
int search(char* s) {
    int index = hashFunc(s);
    struct Node* temp = table[index];

    while (temp != NULL) {
        if (strcmp(temp->name, s) == 0)
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
            printf("%s -> ", temp->name);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {

    insert("choti");
    insert("itohc");   // same characters, different order

    display();

    printf("\nSearch choti: %d\n", search("choti"));
    printf("Search itohc: %d\n", search("itohc"));

    return 0;
}
