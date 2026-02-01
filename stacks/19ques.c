// The first element in stack1 should be merged with last element in stack2, second element
// in stack1 should be merged with second last element in stack2 and so on. If an element in
// stack1/stack2 is None, then the corresponding element in the other stack should be kept as it is in
// the merged stack

#include <stdio.h>
#define MAX 20

struct Stack {
    int a[MAX];
    int top;
};

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

int main() {
    struct Stack s1, s2, temp, s3;
    init(&s1);
    init(&s2);
    init(&temp);
    init(&s3);

    /* Stack1 (top → bottom): 1 2 3 */
    push(&s1, 3);
    push(&s1, 2);
    push(&s1, 1);

    /* Stack2 (top → bottom): 4 5 6 */
    push(&s2, 6);
    push(&s2, 5);
    // push(&s2, 4);

    /* Reverse stack2 */
    while (!isEmpty(&s2))
        push(&temp, pop(&s2));

    /* Merge */
    while (!isEmpty(&s1) && !isEmpty(&temp)) {
        push(&s3, pop(&s1));
        push(&s3, pop(&temp));
    }

    /* Remaining elements */
    while (!isEmpty(&s1))
        push(&s3, pop(&s1));

    while (!isEmpty(&temp))
        push(&s3, pop(&temp));

    /* Display merged stack */
    printf("Merged Stack (top-bottom): ");
    while (!isEmpty(&s3))
        printf("%d ", pop(&s3));

    return 0;
}
