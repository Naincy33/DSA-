#include <stdio.h>
#define MAX 20

struct Queue {
    int a[MAX];
    int front, rear;
};

/* queue functions */
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

/* check evenly divisible from 1 to 10 */
int evenlyDivisible(int x) {
    for (int i = 1; i <= 10; i++) {
        if (x % i != 0)
            return 0;
    }
    return 1;
}

int main() {
    struct Queue q1, q2;
    init(&q1);
    init(&q2);

    /* Input Queue */
    enqueue(&q1, 13983);
    enqueue(&q1, 10080);
    enqueue(&q1, 7113);
    enqueue(&q1, 2520);
    enqueue(&q1, 2500);

    /* Process queue */
    while (!isEmpty(&q1)) {
        int x = dequeue(&q1);
        if (evenlyDivisible(x)) {
            enqueue(&q2, x);
        }
    }

    /* Output Queue */
    printf("Output Queue: ");
    while (!isEmpty(&q2)) {
        printf("%d ", dequeue(&q2));
    }

    return 0;
}
