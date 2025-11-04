#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure for Deque
struct Deque {
    int arr[MAX];
    int front;
    int rear;
};

// Initialize deque
void initDeque(struct Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
}

// Check if deque is empty
int isEmpty(struct Deque *dq) {
    return (dq->front == -1);
}

// Check if deque is full
int isFull(struct Deque *dq) {
    return ((dq->front == 0 && dq->rear == MAX - 1) ||
            (dq->front == dq->rear + 1));
}

// Insert at front (Push operation)
void insertFront(struct Deque *dq, int x) {
    if (isFull(dq)) {
        printf("Stack Overflow\n");
        return;
    }
    if (dq->front == -1) { // Empty
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = MAX - 1;
    } else {
        dq->front--;
    }
    dq->arr[dq->front] = x;
    printf("Pushed %d\n", x);
}

// Delete from front (Pop operation)
int deleteFront(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Stack Underflow\n");
        return -1;
    }
    int val = dq->arr[dq->front];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1; // Only one element
    } else if (dq->front == MAX - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }
    printf("Popped %d\n", val);
    return val;
}

// Peek top element (front)
int getTop(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Stack is Empty\n");
        return -1;
    }
    return dq->arr[dq->front];
}

int main() {
    struct Deque dq;
    initDeque(&dq);

    insertFront(&dq, 10);
    insertFront(&dq, 20);
    insertFront(&dq, 30);

    printf("Top element: %d\n", getTop(&dq));

    deleteFront(&dq);
    deleteFront(&dq);
    deleteFront(&dq);
    deleteFront(&dq);  // Underflow check

    return 0;
}
