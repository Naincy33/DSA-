#include <stdio.h>
#include <string.h>

#define SIZE 7
#define MAX_LEN 20

char table[SIZE][MAX_LEN];   // hash table for strings
int occupied[SIZE];          // 0 = empty, 1 = filled

/* -------- String Hash Function (ASCII sum) -------- */
int hashFunc(char *s) {
    int sum = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        sum += s[i];
    }
    return sum % SIZE;
}

/* -------- Insert using Linear Probing -------- */
void insert(char *s) {
    int index = hashFunc(s);

    while (occupied[index]) {
        index = (index + 1) % SIZE;   // linear probing
    }

    strcpy(table[index], s);
    occupied[index] = 1;
}

/* -------- Search -------- */
int search(char *s) {
    int index = hashFunc(s);
    int start = index;

    while (occupied[index]) {
        if (strcmp(table[index], s) == 0)
            return 1;

        index = (index + 1) % SIZE;
        if (index == start)
            break;
    }
    return 0;
}

/* -------- Display -------- */
void display() {
    for (int i = 0; i < SIZE; i++) {
        if (occupied[i])
            printf("%d: %s\n", i, table[i]);
        else
            printf("%d: EMPTY\n", i);
    }
}

/* -------- Main -------- */
int main() {

    insert("choti");
    insert("itohc");   // collision with "choti"
    insert("hello");

    display();

    printf("\nSearch choti: %d\n", search("choti"));
    printf("Search itohc: %d\n", search("itohc"));
    printf("Search hello: %d\n", search("hello"));

    return 0;
}
