#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char song[50];
    struct node *next;
};

struct node *head = NULL;

struct node* createNode(char song[]) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    strcpy(newnode->song, song);
    newnode->next = NULL;
    return newnode;
}

void insertEnd(char song[]) {
    struct node *newnode = createNode(song);

    if(head == NULL) {
        head = newnode;
        newnode->next = head; // circular link
        return;
    }

    struct node *temp = head;
    while(temp->next != head)
        temp = temp->next;

    temp->next = newnode;
    newnode->next = head;
}

void displayPlaylist(int loops) {
    if(head == NULL) {
        printf("\nPlaylist is empty\n");
        return;
    }

    struct node *temp = head;
    printf("\nPlaying Songs:\n");

    for(int i = 0; i < loops; i++) {
        do {
            printf("%s\n", temp->song);
            temp = temp->next;
        } while(temp != head);
    }
}

int main() {
    int n, repeat;
    char song[50];

    printf("Enter number of songs: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter song name: ");
        scanf("%s", song);
        insertEnd(song);
    }

    printf("How many times to loop playlist? ");
    scanf("%d", &repeat);

    displayPlaylist(repeat);

    return 0;
}
