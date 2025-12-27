#include <stdio.h>
#define MAX 50

struct Stack {
    int arr[MAX];
    int top;
};

void init(struct Stack *s) {
    s->top = -1;
}

void push(struct Stack *s, int x) {
    s->arr[++s->top] = x;
}

int pop(struct Stack *s) {
    return s->arr[s->top--];
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

int isEqual(struct Stack *s1, struct Stack *s2) {

    // size check
    if (s1->top != s2->top)
        return 0;

    // element-wise comparison
    while (!isEmpty(s1)) {
        if (pop(s1) != pop(s2))
            return 0;
    }
    return 1;
}

int main() {
    struct Stack s1, s2;
    init(&s1);
    init(&s2);

    // Example 1
    push(&s1, 10);
    push(&s1, 4);
    push(&s1, 2);

    push(&s2, 10);
    push(&s2, 4);
    push(&s2, 2);

    if (isEqual(&s1, &s2))
        printf("EQUAL\n");
    else
        printf("NOT EQUAL\n");

    return 0;
}
