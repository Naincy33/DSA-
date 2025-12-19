#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

typedef struct Node {
    char key[50];
    char value[50];
    struct Node* next;
} Node;

Node* hashTable[SIZE];

int hashFunction(char* key) {
    int hash = 0;
    for(int i = 0; key[i] != '\0'; i++) {
        hash += key[i];
    }
    return hash % SIZE;
}

void insert(char* key, char* value) {
    int index = hashFunction(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->key, key);
    strcpy(newNode->value, value);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

char* search(char* key) {
    int index = hashFunction(key);
    Node* temp = hashTable[index];

    while(temp != NULL) {
        if(strcmp(temp->key, key) == 0)
            return temp->value;
        temp = temp->next;
    }
    return NULL;
}

void delete(char* key) {
    int index = hashFunction(key);
    Node* temp = hashTable[index];
    Node* prev = NULL;

    while(temp != NULL) {
        if(strcmp(temp->key, key) == 0) {
            if(prev == NULL)
                hashTable[index] = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void display() {
    for(int i = 0; i < SIZE; i++) {
        printf("%d --> ", i);
        Node* temp = hashTable[i];
        while(temp != NULL) {
            printf("[%s : %s] -> ", temp->key, temp->value);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    insert("name", "Choti");
    insert("city", "Bengaluru");
    insert("lang", "C");

    printf("Search city: %s\n", search("city"));

    delete("name");
    display();
    return 0;
}
