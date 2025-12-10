#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char usn[20];
    char name[30];
    int backlogs;
    struct node *next;
};

struct node *Start = NULL;

struct node *createNode(char usn[], char name[], int backlogs)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    strcpy(newnode->usn, usn);
    strcpy(newnode->name, name);
    newnode->backlogs = backlogs;
    newnode->next = NULL;
    return newnode;
}

void insertStudent(char usn[], char name[], int backlogs)
{
    struct node *newnode = createNode(usn, name, backlogs);
    if (Start == NULL)
    {
        Start = newnode;
    }
    else
    {
        struct node *temp = Start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}

void updateBacklogs(char usn[])
{
    struct node *temp = Start;
    int newBacklogs;
    while (temp != NULL)
    {
        if (strcmp(temp->usn, usn) == 0)
        {
            printf("Enter new backlog count: ");
            scanf("%d", &newBacklogs);
            temp->backlogs = newBacklogs;
            return;
        }
        temp = temp->next;
    }
    printf("USN not found!\n");
}

void deleteMoreBacklogs()
{
    struct node *temp = Start, *prev = NULL;

    while (temp != NULL)
    {
        if (temp->backlogs > 4)
        {
            if (prev == NULL)
            {
                Start = temp->next;
                free(temp);
                temp = Start;
            }
            else
            {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
}

void display()
{
    struct node *temp = Start;
    printf("\nStudent List:\n");
    while (temp != NULL)
    {
        printf("%s\t%s\t%d\n", temp->usn, temp->name, temp->backlogs);
        temp = temp->next;
    }
}

int main()
{
    int n, i, b;
    char u[20], nm[30];

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter USN, Name and Backlogs: ");
        scanf("%s %s %d", u, nm, &b);
        insertStudent(u, nm, b);
    }

    display();

    printf("\nEnter USN to update backlog: ");
    scanf("%s", u);
    updateBacklogs(u);
    display();

    deleteMoreBacklogs();
    printf("\nAfter deleting students with >4 backlogs:\n");
    display();

    return 0;
}
