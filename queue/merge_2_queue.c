#include <stdio.h>

#define MAX 20

/* Integer Queue */
struct IntQueue {
    int arr[MAX];
    int front, rear;
};

/* Character Queue */
struct CharQueue {
    char arr[MAX];
    int front, rear;
};

void initIntQ(struct IntQueue *q) {
    q->front = q->rear = 0;
}

void initCharQ(struct CharQueue *q) {
    q->front = q->rear = 0;
}

int isEmptyInt(struct IntQueue *q) {
    return q->front == q->rear;
}

int isEmptyChar(struct CharQueue *q) {
    return q->front == q->rear;
}

void enqueueInt(struct IntQueue *q, int x) {
    q->arr[q->rear++] = x;
}

void enqueueChar(struct CharQueue *q, char x) {
    q->arr[q->rear++] = x;
}

int dequeueInt(struct IntQueue *q) {
    return q->arr[q->front++];
}

char dequeueChar(struct CharQueue *q) {
    return q->arr[q->front++];
}

int main() {
    struct IntQueue q1;
    struct CharQueue q2;

    initIntQ(&q1);
    initCharQ(&q2);

    /* Input queues */
    enqueueInt(&q1, 3);
    enqueueInt(&q1, 6);
    enqueueInt(&q1, 8);

    enqueueChar(&q2, 'b');
    enqueueChar(&q2, 'y');
    enqueueChar(&q2, 'u');
    enqueueChar(&q2, 't');
    enqueueChar(&q2, 'r');
    enqueueChar(&q2, 'o');

    printf("Merged Queue: ");

    /* Merge using dequeue */
    while (!isEmptyInt(&q1) && !isEmptyChar(&q2)) {
        printf("%d ", dequeueInt(&q1));
        printf("%c ", dequeueChar(&q2));
    }

    /* Remaining elements */
    while (!isEmptyInt(&q1))
        printf("%d ", dequeueInt(&q1));

    while (!isEmptyChar(&q2))
        printf("%c ", dequeueChar(&q2));

    return 0;
}
