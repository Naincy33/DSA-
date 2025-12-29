#include <stdio.h>
#define MAX 20

struct Queue {
    int a[MAX];
    int front, rear;
};

void init(struct Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(struct Queue *q) {
    return q->front > q->rear;
}

void enqueue(struct Queue *q, int x) {
    q->a[++q->rear] = x;
}

int dequeue(struct Queue *q) {
    return q->a[q->front++];
}

int main() {
    struct Queue room1, room2;
    init(&room1);
    init(&room2);

    int cards[] = {12, 7, 9, 20, 15, 8};
    int n = 6;

    /* Allocate people to rooms */
    for (int i = 0; i < n; i++) {
        if (cards[i] % 2 == 0)
            enqueue(&room1, cards[i]);
        else
            enqueue(&room2, cards[i]);
    }

    /* People leaving after test */
    printf("Room 1 (Even card numbers): ");
    while (!isEmpty(&room1))
        printf("%d ", dequeue(&room1));

    printf("\nRoom 2 (Odd card numbers): ");
    while (!isEmpty(&room2))
        printf("%d ", dequeue(&room2));

    return 0;
}
