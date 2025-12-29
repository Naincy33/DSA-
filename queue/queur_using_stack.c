#include <stdio.h>
#define MAX 50

struct Stack {
    int a[MAX];
    int top;
};

struct Stack s1, s2;

/* stack functions */
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

/* enqueue operation */
void enqueue(int x) {
    push(&s1, x);
}

/* dequeue operation */
int dequeue() {
    if (isEmpty(&s2)) {
        while (!isEmpty(&s1)) {
            push(&s2, pop(&s1));
        }
    }
    if (isEmpty(&s2)) {
        printf("Queue is empty\n");
        return -1;
    }
    return pop(&s2);
}

int main() {
    init(&s1);
    init(&s2);

    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("%d ", dequeue());
    printf("%d ", dequeue());
    printf("%d ", dequeue());

    return 0;
}
