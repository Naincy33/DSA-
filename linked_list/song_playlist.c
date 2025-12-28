#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Song node */
struct Song {
    char name[50];
    struct Song *prev, *next;
};

/* Global pointers */
struct Song *head = NULL;
struct Song *current = NULL;

/* Create new song */
struct Song* createSong(char name[]) {
    struct Song* s = (struct Song*)malloc(sizeof(struct Song));
    strcpy(s->name, name);
    s->prev = s->next = NULL;
    return s;
}

/* Add song AFTER current */
void addAfter(char name[]) {
    struct Song* s = createSong(name);

    if (current == NULL) {   // empty playlist
        head = current = s;
        return;
    }

    s->next = current->next;
    s->prev = current;

    if (current->next != NULL)
        current->next->prev = s;

    current->next = s;
}

/* Add song BEFORE current */
void addBefore(char name[]) {
    struct Song* s = createSong(name);

    if (current == NULL) {   // empty playlist
        head = current = s;
        return;
    }

    s->next = current;
    s->prev = current->prev;

    if (current->prev != NULL)
        current->prev->next = s;
    else
        head = s;   // inserted at beginning

    current->prev = s;
}

/* Move to NEXT song */
void nextSong() {
    if (current != NULL && current->next != NULL)
        current = current->next;
    else
        printf("No next song available\n");
}

/* Move to PREVIOUS song */
void prevSong() {
    if (current != NULL && current->prev != NULL)
        current = current->prev;
    else
        printf("No previous song available\n");
}

/* Delete CURRENT song */
void deleteCurrent() {
    if (current == NULL)
        return;

    struct Song* temp = current;

    // adjust previous link
    if (current->prev != NULL)
        current->prev->next = current->next;
    else
        head = current->next;

    // adjust next link
    if (current->next != NULL)
        current->next->prev = current->prev;

    // move current
    if (current->next != NULL)
        current = current->next;
    else
        current = current->prev;

    free(temp);
}

/* Display playlist */
void display() {
    struct Song* t = head;
    printf("\nPlaylist:\n");
    while (t != NULL) {
        if (t == current)
            printf("▶ %s\n", t->name);
        else
            printf("  %s\n", t->name);
        t = t->next;
    }
}

/* Main function */
int main() {
    /* Initial playlist */
    addAfter("Song-1");
    addAfter("Song-2");
    addAfter("Song-3");

    display();

    /* Move to next and add after */
    nextSong();          // move to Song-2
    addAfter("Song-4");  // insert after Song-2
    display();

    /* Move backward */
    prevSong();          // move to Song-1
    display();

    /* Delete current song */
    deleteCurrent();     // delete Song-1
    display();

    /* Add before current */
    addBefore("Song-0");
    display();

    return 0;
}
