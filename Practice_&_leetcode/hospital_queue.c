#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100 // maximum number of patients

// Structure to store patient info
struct Patient
{
    int id;
    char name[50];
    int age;
};

// Queue structure
struct Queue
{
    int front, rear;
    struct Patient patients[MAX];
} q;

// Function prototypes
void AddPatient();
void RemovePatient();
void displayPatients();

int main()
{
    int choice;
    q.front = q.rear = -1; // initialize queue

    printf("\n=== Hospital Patient Queue Management System ===\n");

    while (1)
    {
        printf("\n1. Add Patient");
        printf("\n2. Remove (Examine) Patient");
        printf("\n3. Display Queue");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            AddPatient();
            break;
        case 2:
            RemovePatient();
            break;
        case 3:
            displayPatients();
            break;
        case 4:
            printf("\nExiting... Have a healthy day!\n");
            exit(0);
        default:
            printf("\nInvalid choice. Try again.\n");
        }
    }
    return 0;
}

// Function to check if queue is full
int isFull()
{
    return q.rear == MAX - 1;
}

// Function to check if queue is empty
int isEmpty()
{
    return q.front == -1 || q.front > q.rear;
}

// Function to add patient
void AddPatient()
{
    if (isFull())
    {
        printf("\nQueue is full! Cannot add more patients.\n");
        return;
    }

    struct Patient p;
    printf("\nEnter Patient ID: ");
    scanf("%d", &p.id);
    printf("Enter Patient Name: ");
    scanf("%s", p.name);
    printf("Enter Patient Age: ");
    scanf("%d", &p.age);

    if (q.front == -1)
        q.front = 0;
    q.patients[++q.rear] = p;

    printf("\nPatient added successfully!\n");
}

// Function to remove patient (after examination)
void RemovePatient()
{
    if (isEmpty())
    {
        printf("\nNo patients in queue.\n");
        return;
    }

    struct Patient p = q.patients[q.front++];
    printf("\nPatient examined and removed:\n");
    printf("ID: %d, Name: %s, Age: %d\n", p.id, p.name, p.age);

    // Reset queue when all patients are processed
    if (q.front > q.rear)
        q.front = q.rear = -1;
}

// Function to display current patients
void displayPatients()
{
    if (isEmpty())
    {
        printf("\nNo patients currently waiting.\n");
        return;
    }

    printf("\nCurrent Patient Queue:\n");
    printf("----------------------------\n");
    for (int i = q.front; i <= q.rear; i++)
    {
        printf("ID: %d | Name: %s | Age: %d\n",
               q.patients[i].id, q.patients[i].name, q.patients[i].age);
    }
    printf("----------------------------\n");
}
