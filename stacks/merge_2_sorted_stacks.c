#include <stdio.h>
#define MAX 20

struct Stack {
    int a[MAX];
    int top;
};

/* stack operations */
void init(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, int x) {
    s->a[++s->top] = x;
}

int pop(struct Stack *s) {
    return s->a[s->top--];
}

/* reverse stack */
void reverse(struct Stack *s) {
    struct Stack temp;
    init(&temp);

    while (!isEmpty(s))
        push(&temp, pop(s));

    *s = temp;
}

int main() {
    struct Stack s1, s2, result;
    init(&s1);
    init(&s2);
    init(&result);

    /* Stack1 (sorted) */
    push(&s1, 9);
    push(&s1, 7);
    push(&s1, 5);
    push(&s1, 3);

    /* Stack2 (sorted) */
    push(&s2, 10);
    push(&s2, 8);
    push(&s2, 6);
    push(&s2, 4);

    /* Merge */
    while (!isEmpty(&s1) && !isEmpty(&s2)) {
        if (s1.a[s1.top] < s2.a[s2.top])
            push(&result, pop(&s1));
        else
            push(&result, pop(&s2));
    }

    /* Remaining elements */
    while (!isEmpty(&s1))
        push(&result, pop(&s1));

    while (!isEmpty(&s2))
        push(&result, pop(&s2));

    /* Reverse result for sorted order */
    reverse(&result);

    /* Display result stack */
    printf("Merged Sorted Stack (top-bottom): ");
    while (!isEmpty(&result))
        printf("%d ", pop(&result));

    return 0;
}
