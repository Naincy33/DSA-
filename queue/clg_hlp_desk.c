#include <stdio.h>
#define SIZE 10

int queue[SIZE];
int front = -1, rear = -1;

/* Add student */
void enqueue(int roll) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue is full\n");
        return;
    }

    if (front == -1) {          // first student
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }

    queue[rear] = roll;
    printf("Student %d added\n", roll);
}

/* Display waiting students */
void display() {
    if (front == -1) {
        printf("No students waiting\n");
        return;
    }

    printf("Waiting students: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    enqueue(101);
    enqueue(102);
    enqueue(103);

    display();

    enqueue(104);
    display();

    return 0;
}
