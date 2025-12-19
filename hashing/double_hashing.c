#include <stdio.h>
#define SIZE 7

int table[SIZE];

int h1(int key) {
    return key % SIZE;
}

int h2(int key) {
    return 1 + (key % (SIZE - 1));
}

void insert(int key) {
    int index = h1(key);
    int step = h2(key);

    while (table[index] != 0) {
        index = (index + step) % SIZE;
    }
    table[index] = key;
}

int search(int key) {
    int index = h1(key);
    int step = h2(key);

    while (table[index] != 0) {
        if (table[index] == key)
            return 1;
        index = (index + step) % SIZE;
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
