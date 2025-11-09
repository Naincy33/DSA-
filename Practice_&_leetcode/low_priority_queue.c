#include <stdio.h>
#include <string.h>

#define MAX 50

struct Task {
    char name[30];
    int priority;
};

struct Task queue[MAX];
int size = 0;

// Add task to queue
void enqueue(char name[], int priority) {
    strcpy(queue[size].name, name);
    queue[size].priority = priority;
    size++;
    printf("Task added successfully!\n");
}

// Find position of lowest priority task
int findLowestPriority() {
    int min = queue[0].priority;
    int pos = 0;
    for (int i = 1; i < size; i++) {
        if (queue[i].priority < min) {
            min = queue[i].priority;
            pos = i;
        }
    }
    return pos;
}

// Process (remove) task with lowest priority number
void dequeue() {
    if (size == 0) {
        printf("\nNo task to process!\n");
        return;
    }

    int pos = findLowestPriority();
    printf("\nProcessing task: %s (Priority: %d)\n", queue[pos].name, queue[pos].priority);

    // Shift tasks
    for (int i = pos; i < size - 1; i++) {
        queue[i] = queue[i + 1];
    }
    size--;
}

// Display all tasks
void display() {
    if (size == 0) {
        printf("\nNo tasks in queue!\n");
        return;
    }

    printf("\nTasks in Queue:\n");
    printf("---------------------------\n");
    printf("Name\tPriority\n");
    for (int i = 0; i < size; i++) {
        printf("%s\t%d\n", queue[i].name, queue[i].priority);
    }
}

int main() {
    int ch;
    char name[30];
    int priority;

    do {
        printf("\n--- Task Priority Queue ---\n");
        printf("1. Add Task\n");
        printf("2. Process Task\n");
        printf("3. Display Tasks\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("Enter task name: ");
            scanf("%s", name);
            printf("Enter priority (smaller number = higher priority): ");
            scanf("%d", &priority);
            enqueue(name, priority);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (ch != 4);

    return 0;
}
