#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct {
    char name[50];
} Order;

Order dineIn[MAX], takeOut[MAX];
int front1 = 0, rear1 = 0, front2 = 0, rear2 = 0;

void addOrder() {
    int type;
    char temp[50];
    printf("Enter 1 for Dine-In, 2 for Take-Out: ");
    scanf("%d", &type);
    getchar(); // clear newline
    printf("Enter order name: ");
    gets(temp);

    if (type == 1 && rear1 < MAX)
        strcpy(dineIn[rear1++].name, temp);
    else if (type == 2 && rear2 < MAX)
        strcpy(takeOut[rear2++].name, temp);
    else
        printf("Queue full!\n");
}

void processOrders() {
    int i = 0;
    printf("\nProcessing orders alternately...\n");
    while (front1 < rear1 || front2 < rear2) {
        if (i % 2 == 0 && front1 < rear1)
            printf("Served Dine-In: %s\n", dineIn[front1++].name);
        else if (i % 2 == 1 && front2 < rear2)
            printf("Served Take-Out: %s\n", takeOut[front2++].name);
        i++;
    }
    printf("All orders done!\n");
}

int main() {
    int ch;
    while (1) {
        printf("\n1. Add Order\n2. Process Orders\n3. Exit\nChoice: ");
        scanf("%d", &ch);
        getchar();
        if (ch == 1) addOrder();
        else if (ch == 2) processOrders();
        else break;
    }
    return 0;
}
