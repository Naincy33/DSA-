#include <stdio.h>
#define SIZE 7

int table[SIZE];

// Hash function
int hashFunc(int key) {
    return key % SIZE;
}

// Insert (linear probing)
void insert(int key) {
    int index = hashFunc(key);

    while (table[index] != 0) {
        index = (index + 1) % SIZE;
    }
    table[index] = key;
}

// Search
int search(int key) {
    int index = hashFunc(key);
    int start = index;

    while (table[index] != 0) {
        if (table[index] == key)
            return 1;
        index = (index + 1) % SIZE;
        if (index == start)
            break;
    }
    return 0;
}

// Display
void display() {
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", table[i]);
    }
    printf("\n");
}

int main() {
    insert(10);
    insert(17);
    insert(24);

    display();

    printf("%d\n", search(10));
    printf("%d\n", search(17));
    printf("%d\n", search(24));

    return 0;
}
