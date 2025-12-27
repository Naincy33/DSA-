#include <stdio.h>
#include <limits.h>

#define MAX 100

struct Stack {
    int arr[MAX];
    int top;
};

void init(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, int x) {
    s->arr[++s->top] = x;
}

int pop(struct Stack *s) {
    return s->arr[s->top--];
}

void display(struct Stack *s) {
    printf("Stack (top -> bottom): ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Stack S, T;
    init(&S);
    init(&T);

    // Input stack: top -> bottom = 5 66 5 8 7
    push(&S, 7);
    push(&S, 8);
    push(&S, 5);
    push(&S, 66);
    push(&S, 5);

    printf("Original ");
    display(&S);

    int minVal = INT_MAX, minCount = 0;

    // Step 1: find min + move to T
    while (!isEmpty(&S)) {
        int x = pop(&S);
        if (x < minVal) {
            minVal = x;
            minCount = 1;
        } else if (x == minVal) {
            minCount++;
        }
        push(&T, x);
    }

    // Step 2: rebuild S
    // 2a) push all mins first (go to bottom)
    while (minCount--)
        push(&S, minVal);

    // 2b) restore non-min elements
    while (!isEmpty(&T)) {
        int x = pop(&T);
        if (x != minVal)
            push(&S, x);
    }

    printf("Updated  ");
    display(&S);

    return 0;
}
