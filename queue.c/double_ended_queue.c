#include <stdio.h>
#include <stdlib.h>

struct Deque {
    int size;
    int f;
    int r;
    int* arr;
};

// Check if Deque is empty
int isEmpty(struct Deque* dq) {
    return (dq->f == dq->r);
}

// Check if Deque is full
int isFull(struct Deque* dq) {
    return ((dq->r + 1) % dq->size == dq->f);
}

// Insert at rear
void insertRear(struct Deque* dq, int val) {
    if(isFull(dq)) {
        printf("Deque is full\n");
    } else {
        dq->r = (dq->r + 1) % dq->size;
        dq->arr[dq->r] = val;
        printf("Inserted at rear: %d\n", val);
    }
}

// Insert at front
void insertFront(struct Deque* dq, int val) {
    if(isFull(dq)) {
        printf("Deque is full\n");
    } else {
        dq->f = (dq->f - 1 + dq->size) % dq->size;
        dq->arr[dq->f] = val;
        printf("Inserted at front: %d\n", val);
    }
}

// Delete from front
int deleteFront(struct Deque* dq) {
    if(isEmpty(dq)) {
        printf("Deque is empty\n");
        return -1;
    } else {
        dq->f = (dq->f + 1) % dq->size;
        return dq->arr[dq->f];
    }
}

// Delete from rear
int deleteRear(struct Deque* dq) {
    if(isEmpty(dq)) {
        printf("Deque is empty\n");
        return -1;
    } else {
        int val = dq->arr[dq->r];
        dq->r = (dq->r - 1 + dq->size) % dq->size;
        return val;
    }
}

// Display Deque
void display(struct Deque* dq) {
    if(isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements: ");
    int i = (dq->f + 1) % dq->size;
    while(i != (dq->r + 1) % dq->size) {
        printf("%d ", dq->arr[i]);
        i = (i + 1) % dq->size;
    }
    printf("\n");
}

int main() {
    struct Deque dq;
    dq.size = 5; // actual usable size will be size-1
    dq.f = dq.r = 0;
    dq.arr = (int*) malloc(dq.size * sizeof(int));

    insertRear(&dq, 10);
    insertRear(&dq, 20);
    insertFront(&dq, 5);
    display(&dq);

    printf("Deleted from front: %d\n", deleteFront(&dq));
    printf("Deleted from rear: %d\n", deleteRear(&dq));
    display(&dq);

    insertFront(&dq, 1);
    insertRear(&dq, 30);
    display(&dq);

    free(dq.arr);
    return 0;
}
