#include <stdio.h>
#include <stdlib.h>

struct PriorityQueue {
    int size;
    int rear;   // rear points to last element
    int* arr;
};

// Check if empty
int isEmpty(struct PriorityQueue* pq) {
    return (pq->rear == -1);
}

// Check if full
int isFull(struct PriorityQueue* pq) {
    return (pq->rear == pq->size - 1);
}

// Enqueue element with priority
void enqueue(struct PriorityQueue* pq, int val) {
    if (isFull(pq)) {
        printf("Priority Queue is full\n");
        return;
    }

    int i;
    // Find correct position for new element (higher value = higher priority)
    for (i = pq->rear; i >= 0 && pq->arr[i] < val; i--) {
        pq->arr[i + 1] = pq->arr[i]; // shift elements to right
    }
    pq->arr[i + 1] = val;
    pq->rear++;
    printf("Inserted: %d\n", val);
}

// Dequeue highest priority element
int dequeue(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty\n");
        return -1;
    }
    int val = pq->arr[0]; // highest priority element is at front
    // shift all elements left
    for (int i = 0; i < pq->rear; i++) {
        pq->arr[i] = pq->arr[i + 1];
    }
    pq->rear--;
    return val;
}

// Display Priority Queue
void display(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty\n");
        return;
    }
    printf("Priority Queue elements: ");
    for (int i = 0; i <= pq->rear; i++) {
        printf("%d ", pq->arr[i]);
    }
    printf("\n");
}

int main() {
    struct PriorityQueue pq;
    pq.size = 5;
    pq.rear = -1;
    pq.arr = (int*) malloc(pq.size * sizeof(int));

    enqueue(&pq, 30);
    enqueue(&pq, 10);
    enqueue(&pq, 20);
    enqueue(&pq, 40);
    display(&pq);

    printf("Dequeued element: %d\n", dequeue(&pq));
    display(&pq);

    free(pq.arr);
    return 0;
}
