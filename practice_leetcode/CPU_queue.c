#include <stdio.h>
#define N 5
#define TIME 10

int main() {
    int burst[N] = {50, 40, 30, 20, 10};
    int front = 0, rear = N - 1;
    int queue[N] = {0, 1, 2, 3, 4};
    int time = 0, done = 0;

    printf("Round Robin (Circular Queue):\n");

    while (done < N) {
        int task = queue[front];
        if (burst[task] > 0) {
            if (burst[task] > TIME) {
                printf("T%d runs 10s (left %ds)\n", task + 1, burst[task] - TIME);
                burst[task] -= TIME;
                time += TIME;
                rear = (rear + 1) % N;
                queue[rear] = task;  // put back at end
            } else {
                printf("T%d runs %ds and finishes\n", task + 1, burst[task]);
                time += burst[task];
                burst[task] = 0;
                done++;
            }
        }
        front = (front + 1) % N;
    }

    printf("\nAll tasks done in %d sec.\n", time);
    return 0;
}
