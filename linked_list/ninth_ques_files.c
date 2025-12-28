#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 3

struct File {
    char name[50];
    struct File *prev, *next;
};

struct File *head = NULL;
int count = 0;

/* Add new file at front */
void addFile(char fname[]) {
    struct File *n = (struct File*)malloc(sizeof(struct File));
    strcpy(n->name, fname);
    n->prev = NULL;
    n->next = head;

    if (head != NULL)
        head->prev = n;

    head = n;
    count++;

    /* If size exceeds limit → remove last */
    if (count > MAX)
        removeLast();
}

/* Remove last file */
void removeLast() {
    struct File *temp = head;

    if (temp == NULL)
        return;

    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev)
        temp->prev->next = NULL;
    else
        head = NULL;

    free(temp);
    count--;
}

/* Display recent file list */
void display() {
    struct File *temp = head;
    printf("Recent Files:\n");
    while (temp != NULL) {
        printf("%s\n", temp->name);
        temp = temp->next;
    }
}

int main() {
    addFile("file1.txt");
    addFile("file2.txt");
    addFile("file3.txt");
    addFile("file4.txt");

    display();

    return 0;
}
