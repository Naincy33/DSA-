#include <stdio.h>
#include <string.h>

#define MAX 40

struct Queue {
    char names[MAX][50];  // Array to store participant names
    int front;
    int rear;
};

// Initialize queue
void initQueue(struct Queue* q) {
    q->front = 0;
    q->rear = -1;
}

// Check if full
int isFull(struct Queue* q) {
    return q->rear == MAX - 1;
}

// Check if empty
int isEmpty(struct Queue* q) {
    return q->front > q->rear;
}

// Enqueue (Register participant)
void registerParticipant(struct Queue* q, char name[]) {
    if (isFull(q)) {
        printf("Registrations Closed for the Hackathon.\n");
        return;
    }
    q->rear++;
    strcpy(q->names[q->rear], name);
    printf("Participant '%s' registered successfully! (Seat %d)\n", name, q->rear + 1);

    if (isFull(q)) {
        printf("All %d seats filled! Registrations Closed for the Hackathon.\n", MAX);
    }
}

// Dequeue (Participant leaves)
void removeParticipant(struct Queue* q) {
    if (isEmpty(q)) {
        printf("No participants to remove.\n");
        return;
    }
    printf("Participant '%s' has left the event.\n", q->names[q->front]);
    q->front++;
}

// Display all participants
void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("No participants currently registered.\n");
        return;
    }

    printf("\nCurrent Registered Participants:\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d. %s\n", i - q->front + 1, q->names[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q;
    initQueue(&q);

    int choice;
    char name[50];

    while (1) {
        printf("\n--- B.M.S. College Hackathon Registration ---\n");
        printf("1. Register Participant\n");
        printf("2. Remove Participant\n");
        printf("3. Display Participants\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter participant name: ");
                scanf("%s", name);
                registerParticipant(&q, name);
                break;
            case 2:
                removeParticipant(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exiting Registration System.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
