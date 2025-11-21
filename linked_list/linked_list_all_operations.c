#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Function declarations
void beginsert();
void lastinsert();
void randominsert();
void begin_delete();
void last_delete();
void random_delete();
void search();
void display();

int main()
{
    int choice = 0;

    while(choice != 9)
    {
        printf("\n\n********** Main Menu **********\n");
        printf("\nChoose one option from the following list...\n");
        printf("==============================================\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at last\n");
        printf("3. Insert at any random location\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from last\n");
        printf("6. Delete node after specified location\n");
        printf("7. Search for an element\n");
        printf("8. Show\n");
        printf("9. Exit\n");
        printf("\nEnter your choice: ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1: beginsert(); break;
            case 2: lastinsert(); break;
            case 3: randominsert(); break;
            case 4: begin_delete(); break;
            case 5: last_delete(); break;
            case 6: random_delete(); break;
            case 7: search(); break;
            case 8: display(); break;
            case 9: printf("\nExiting...\n"); break;
            default: printf("Invalid Choice!\n");
        }
    }
    return 0;
}

void beginsert()
{
    struct node *ptr;
    int item;

    ptr = (struct node*) malloc(sizeof(struct node));

    if(ptr == NULL)
        printf("\nOVERFLOW");
    else
    {
        printf("\nEnter value: ");
        scanf("%d", &item);
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        printf("\nNode inserted at beginning.");
    }
}

void lastinsert()
{
    struct node *ptr, *temp;
    int item;

    ptr = (struct node*) malloc(sizeof(struct node));

    if(ptr == NULL)
        printf("\nOVERFLOW");
    else
    {
        printf("\nEnter value: ");
        scanf("%d", &item);
        ptr->data = item;
        ptr->next = NULL;

        if(head == NULL)
        {
            head = ptr;
            printf("\nNode inserted at last.");
        }
        else
        {
            temp = head;
            while(temp->next != NULL)
                temp = temp->next;

            temp->next = ptr;
            printf("\nNode inserted at last.");
        }
    }
}

void randominsert()
{
    int loc, item, i;
    struct node *ptr, *temp;

    ptr = (struct node*) malloc(sizeof(struct node));
    if(ptr == NULL)
        printf("\nOVERFLOW");
    else
    {
        printf("\nEnter value: ");
        scanf("%d", &item);
        ptr->data = item;

        printf("Enter the location after which you want to insert: ");
        scanf("%d", &loc);

        temp = head;

        for(i = 0; i < loc; i++)
        {
            temp = temp->next;
            if(temp == NULL)
            {
                printf("\nCan't insert\n");
                return;
            }
        }

        ptr->next = temp->next;
        temp->next = ptr;
        printf("\nNode inserted.");
    }
}

void begin_delete()
{
    struct node *ptr;

    if(head == NULL)
        printf("\nList is empty\n");
    else
    {
        ptr = head;
        head = ptr->next;
        free(ptr);
        printf("\nNode deleted from beginning.");
    }
}

void last_delete()
{
    struct node *ptr, *prev;

    if(head == NULL)
        printf("\nList is empty");
    else if(head->next == NULL)
    {
        free(head);
        head = NULL;
        printf("\nOnly node deleted.");
    }
    else
    {
        ptr = head;

        while(ptr->next != NULL)
        {
            prev = ptr;
            ptr = ptr->next;
        }

        prev->next = NULL;
        free(ptr);
        printf("\nNode deleted from last.");
    }
}

void random_delete()
{
    struct node *ptr, *prev;
    int loc, i;

    printf("\nEnter the location after which you want to delete: ");
    scanf("%d", &loc);

    ptr = head;

    for(i = 0; i < loc; i++)
    {
        prev = ptr;
        ptr = ptr->next;

        if(ptr == NULL)
        {
            printf("\nCan't delete\n");
            return;
        }
    }

    prev->next = ptr->next;
    free(ptr);
    printf("\nDeleted node at position %d.", loc + 1);
}

void search()
{
    struct node *ptr;
    int item, i = 0, flag = 1;

    ptr = head;

    if(ptr == NULL)
        printf("\nEmpty List\n");
    else
    {
        printf("\nEnter item to search: ");
        scanf("%d", &item);

        while(ptr != NULL)
        {
            if(ptr->data == item)
            {
                printf("Item found at location %d\n", i + 1);
                flag = 0;
                break;
            }

            ptr = ptr->next;
            i++;
        }

        if(flag == 1)
            printf("Item not found\n");
    }
}

void display()
{
    struct node *ptr;
    ptr = head;

    if(ptr == NULL)
        printf("\nNothing to print");
    else
    {
        printf("\nLinked list elements:\n");

        while(ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}
