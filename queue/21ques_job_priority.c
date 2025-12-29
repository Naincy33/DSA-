#include <stdio.h>

struct Queue
{
    int job[10];
    int pri[10];
    int front, rear;
};

void init(struct Queue *q)
{
    q->front = 0;
    q->rear = -1;
}

void enqueue(struct Queue *q, int jobNo, int priority)
{
    q->rear++;
    q->job[q->rear] = jobNo;
    q->pri[q->rear] = priority;
}

void dequeue(struct Queue *q)
{
    int max = q->pri[q->front];
    int pos = q->front;

    for (int i = q->front + 1; i <= q->rear; i++)
    {
        if (q->pri[i] > max)
        {
            max = q->pri[i];
            pos = i;
        }
    }

    printf("Job %d with Priority %d is executed first\n",
           q->job[pos], q->pri[pos]);

    for (int i = pos; i < q->rear; i++)
    {
        q->job[i] = q->job[i + 1];
        q->pri[i] = q->pri[i + 1];
    }
    q->rear--;
}

int main()
{
    struct Queue q;
    init(&q);

    enqueue(&q, 1, 27);
    enqueue(&q, 2, 4);
    enqueue(&q, 3, 80);
    enqueue(&q, 4, 45);
    enqueue(&q, 5, 95);

    dequeue(&q);

    return 0;
}
