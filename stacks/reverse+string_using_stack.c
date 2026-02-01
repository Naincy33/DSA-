#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *s) {
    return s->top == -1;
}

int isFull(struct stack *s) {
    return s->top == s->size - 1;
}

void push(struct stack *s, char ch) {
    if (!isFull(s)) {
        s->arr[++s->top] = ch;
    }
}

char pop(struct stack *s) {
    if (!isEmpty(s)) {
        return s->arr[s->top--];
    }
    return '\0';
}

int main() {
    char str[100];
    int i, len;

    printf("Enter a string: ");
    fgets(str, 100, stdin);

    len = strlen(str) - 1;   // remove '\n'

    struct stack s;
    s.size = len;
    s.top = -1;
    s.arr = (char *)malloc(s.size * sizeof(char));

    // Push characters into stack
    for (i = 0; i < len; i++) {
        push(&s, str[i]);
    }

    // Pop characters back to string
    for (i = 0; i < len; i++) {
        str[i] = pop(&s);
    }
    printf("Reversed string: %s\n", str);
    free(s.arr);
    return 0;
}
