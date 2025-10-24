/*A shop manages its chocolate inventory. Each box contains a positive number of chocolates. The inventory starts empty. Over N minutes, the following operations occur:

Sell Operation: The box on top is sold.

Receive Operation: A new box is added on top.
For each Sell Operation, output the number of chocolates sold or "No chocolates available" if empty. For each Receive Operation, if inventory reaches max capacity (10 boxes), output "Inventory Full for the Day" and do not add more boxes.
Develop C code to simulate this inventory management using suitable data structure.*/

#include <stdio.h>

#define MAX 10  // Maximum boxes allowed in inventory

int main() {
    int stack[MAX];  // Stores number of chocolates in each box
    int top = -1;    // Stack is initially empty
    int N;           // Number of minutes / operations

    printf("Enter number of operations: ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char op;
        printf("Enter operation (S for Sell, R for Receive): ");
        scanf(" %c", &op);

        if (op == 'R' || op == 'r') {
            int chocolates;
            printf("Enter number of chocolates in new box: ");
            scanf("%d", &chocolates);

            if (top >= MAX - 1) {
                printf("Inventory Full for the Day\n");
            } else {
                top++;
                stack[top] = chocolates;
            }
        } else if (op == 'S' || op == 's') {
            if (top == -1) {
                printf("No chocolates available\n");
            } else {
                printf("Sold %d chocolates\n", stack[top]);
                top--;
            }
        } else {
            printf("Invalid operation!\n");
        }
    }

    return 0;
}
