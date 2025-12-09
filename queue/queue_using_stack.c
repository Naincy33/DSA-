#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10000

typedef struct {
    int *stack1;
    int *stack2;
    int top1;
    int top2;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
    q->stack1 = (int*)malloc(sizeof(int) * MAX);
    q->stack2 = (int*)malloc(sizeof(int) * MAX);
    q->top1 = -1;
    q->top2 = -1;
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->stack1[++obj->top1] = x;
}

int myQueuePop(MyQueue* obj) {
    if(obj->top2 == -1){
        while(obj->top1 != -1){
            obj->stack2[++obj->top2] = obj->stack1[obj->top1--];
        }
    }
    return obj->stack2[obj->top2--];
}

int myQueuePeek(MyQueue* obj) {
    if(obj->top2 == -1){
        while(obj->top1 != -1){
            obj->stack2[++obj->top2] = obj->stack1[obj->top1--];
        }
    }
    return obj->stack2[obj->top2];
}

bool myQueueEmpty(MyQueue* obj) {
    return (obj->top1 == -1 && obj->top2 == -1);
}

void myQueueFree(MyQueue* obj) {
    free(obj->stack1);
    free(obj->stack2);
    free(obj);
}

int main() {
    MyQueue* queue = myQueueCreate();
    
    myQueuePush(queue, 1);
    myQueuePush(queue, 2);
    
    printf("Peek: %d\n", myQueuePeek(queue)); // returns 1
    printf("Pop: %d\n", myQueuePop(queue));   // returns 1
    printf("Empty: %d\n", myQueueEmpty(queue)); // returns 0 (false)
    
    myQueueFree(queue);
    return 0;
}