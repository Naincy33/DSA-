#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    char name[50];
    int cost;
    struct Item *next;
};

struct Item *top = NULL;

/* Push item into stack */
void push(char name[], int cost) {
    struct Item *n = (struct Item*)malloc(sizeof(struct Item));
    strcpy(n->name, name);
    n->cost = cost;
    n->next = top;
    top = n;
    printf("Added: %s - Rs.%d\n", name, cost);
}

/* Pop item (bill last item) */
void pop() {
    if (top == NULL) {
        printf("No items to bill\n");
        return;
    }

    struct Item *temp = top;
    printf("Billed Item: %s - Rs.%d\n", temp->name, temp->cost);
    top = top->next;
    free(temp);
}

/* Display remaining items */
void display() {
    if (top == NULL) {
        printf("No items in cart\n");
        return;
    }

    printf("Items in cart (top = last added):\n");
    struct Item *t = top;
    while (t != NULL) {
        printf("%s - Rs.%d\n", t->name, t->cost);
        t = t->next;
    }
}

/* Main function */
int main() {
    push("Shirt", 1200);
    push("Shoes", 2500);
    push("Watch", 4500);

    display();

    pop();
    pop();

    display();

    return 0;
}
