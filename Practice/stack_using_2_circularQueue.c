#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAPACITY 100

typedef struct {
    int arr[CAPACITY];
    int front, rear, size;
} Queue;

void queueInit(Queue* q) {
    q->front = q->rear = -1;
    q->size = 0;
}
bool queueEmpty(Queue* q) {
    return q->size == 0;
}
void enqueue(Queue* q, int val) {
    if (q->size == CAPACITY) return;
    if (q->front == -1) q->front = 0;
    q->rear = (q->rear + 1) % CAPACITY;
    q->arr[q->rear] = val;
    q->size++;
}
int dequeue(Queue* q) {
    if (queueEmpty(q)) return -1;
    int val = q->arr[q->front];
    q->front = (q->front + 1) % CAPACITY;
    q->size--;
    if (q->size == 0) q->front = q->rear = -1;
    return val;
}
int queueFront(Queue* q) {
    if (queueEmpty(q)) return -1;
    return q->arr[q->front];
}

typedef struct {
    Queue q1, q2;
} MyStack;



/*typedef struct {
    
} MyStack;*/


MyStack* myStackCreate() {
    MyStack *s= (MyStack*)malloc(sizeof(MyStack));
    queueInit (&s->q1);
    queueInit (&s->q2);
    return s;    
}

void myStackPush(MyStack* obj, int x) {
    enqueue(&obj->q2, x);
    while (!queueEmpty(&obj->q1)) {
        enqueue(&obj->q2, dequeue(&obj->q1));
    }
    Queue temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;   
}

int myStackPop(MyStack* obj) {
    return dequeue(&obj->q1);
 
}

int myStackTop(MyStack* obj) {
    return queueFront(&obj->q1); 
}

bool myStackEmpty(MyStack* obj) {
    return queueEmpty(&obj->q1);
}

void myStackFree(MyStack* obj) {
    if (obj) {
        free(obj);
    }
    
}