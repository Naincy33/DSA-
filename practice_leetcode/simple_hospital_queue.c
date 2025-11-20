#include <stdio.h>
#define MAX 50

int front = -1, rear = -1;
char patientQueue[MAX][50];

void AddPatient() {
    if (rear == MAX - 1) {
        printf("\nQueue is full!\n");
        return;
    }
    char name[50];
    printf("\nEnter patient name: ");
    scanf("%s", name);
    if (front == -1)
        front = 0;
    rear++;
    strcpy(patientQueue[rear], name);
    printf("Patient added successfully!\n");
}

void RemovePatient() {
    if (front == -1 || front > rear) {
        printf("\nNo patients in queue!\n");
        return;
    }
    printf("\nPatient examined and removed: %s\n", patientQueue[front]);
    front++;
    if (front > rear)
        front = rear = -1;
}

void displayPatients() {
    if (front == -1 || front > rear) {
        printf("\nNo patients waiting.\n");
        return;
    }
    printf("\nCurrent Patient Queue:\n");
    for (int i = front; i <= rear; i++) {
        printf("%d. %s\n", i - front + 1, patientQueue[i]);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Hospital Queue Menu ---\n");
        printf("1. Add Patient\n");
        printf("2. Remove Patient\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: AddPatient(); break;
            case 2: RemovePatient(); break;
            case 3: displayPatients(); break;
            case 4: return 0;
            default: printf("\nInvalid choice!\n");
        }
    }
}
