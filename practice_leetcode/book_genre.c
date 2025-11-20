#include <stdio.h>
#include <string.h>

#define MAX 100

// Define a Book structure
typedef struct {
    char title[50];
    int genre; // 1 for genre1, 2 for genre2
} Book;

// Stack structure
typedef struct {
    Book items[MAX];
    int top;
} Stack;

// Initialize stack
void initStack(Stack *s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Check if stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Push a book into stack
void push(Stack *s, Book b) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        return;
    }
    s->items[++(s->top)] = b;
}

// Pop a book from stack
Book pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        Book empty;
        strcpy(empty.title, "");
        empty.genre = 0;
        return empty;
    }
    return s->items[(s->top)--];
}

// Display stack contents
void displayStack(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack contents (top to bottom):\n");
    for (int i = s->top; i >= 0; i--) {
        printf("Title: %s, Genre: %d\n", s->items[i].title, s->items[i].genre);
    }
    printf("\n");
}

// Separate books into two stacks based on genre
void separateStacks(Stack *original, Stack *genre1Stack, Stack *genre2Stack) {
    Stack temp;
    initStack(&temp);

    // Reverse original stack to maintain order
    while (!isEmpty(original)) {
        push(&temp, pop(original));
    }

    while (!isEmpty(&temp)) {
        Book b = pop(&temp);
        if (b.genre == 1) {
            push(genre1Stack, b);
        } else if (b.genre == 2) {
            push(genre2Stack, b);
        }
    }
}

int main() {
    Stack original, genre1Stack, genre2Stack;
    initStack(&original);
    initStack(&genre1Stack);
    initStack(&genre2Stack);

    int n;
    printf("Enter number of books: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        Book b;
        printf("Enter title of book %d: ", i + 1);
        scanf(" %[^\n]s", b.title); // Read string with spaces
        printf("Enter genre of book %d (1 or 2): ", i + 1);
        scanf("%d", &b.genre);
        push(&original, b);
    }

    printf("\nOriginal Stack:\n");
    displayStack(&original);

    // Separate books into genre stacks
    separateStacks(&original, &genre1Stack, &genre2Stack);

    printf("Genre 1 Stack:\n");
    displayStack(&genre1Stack);

    printf("Genre 2 Stack:\n");
    displayStack(&genre2Stack);

    return 0;
}
