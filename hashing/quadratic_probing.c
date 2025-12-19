#include <stdio.h>
#define SIZE 7

int table[SIZE];

int hashFunc(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunc(key);
    int i = 1;

    while (table[index] != 0) {
        index = (key + i * i) % SIZE;
        i++;
    }
    table[index] = key;
}

int search(int key) {
    int index = hashFunc(key);
    int i = 1;

    while (table[index] != 0) {
        if (table[index] == key)
            return 1;
        index = (key + i * i) % SIZE;
        i++;
    }
    return 0;
}

void display() {
    for (int i = 0; i < SIZE; i++)
        printf("%d ", table[i]);
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
