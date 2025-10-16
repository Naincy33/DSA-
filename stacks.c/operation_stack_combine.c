#include <stdio.h>
#include <stdlib.h>

// Stack structure
struct stack {
    int size;
    int top;
    int *arr;
};

// Function declarations
int isEmpty(struct stack *s);
int isFull(struct stack *s);
void push(struct stack *s, int val);
int pop(struct stack *s);
void display(struct stack *s);
void checkEmpty(struct stack *s);

// Function definitions
int isEmpty(struct stack *s) {
    return s->top == -1;
}

int isFull(struct stack *s) {
    return s->top == s->size - 1;
}

void push(struct stack *s, int val) {
    if (isFull(s)) {
        printf("\nStack Overflow! Cannot push %d\n", val);
    } else {
        s->top++;
        s->arr[s->top] = val;
        printf("\n%d pushed into the stack.\n", val);
    }
}

int pop(struct stack *s) {
    if (isEmpty(s)) {
        printf("\nStack Underflow! Nothing to pop.\n");
        return -1;
    } else {
        int val = s->arr[s->top];
        s->top--;
        printf("\nPopped element: %d\n", val);
        return val;
    }
}

void display(struct stack *s) {
    if (isEmpty(s)) {
        printf("\nStack is empty.\n");
    } else {
        printf("\nStack elements (Top to Bottom):\n");
        for (int i = s->top; i >= 0; i--) {
            printf("%d\n", s->arr[i]);
        }
    }
}

void checkEmpty(struct stack *s) {
    if (isEmpty(s))
        printf("\nStack is empty.\n");
    else
        printf("\nStack is not empty.\n");
}

int main() {
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));

    printf("Enter the size of the stack: ");
    scanf("%d", &sp->size);
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    int choice, val;
    printf("\n--- STACK OPERATIONS (Dynamic + Menu Driven) ---\n");
    printf("1. Push\n2. Pop\n3. Display\n4. Check Empty\n5. Exit\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(sp, val);
                break;
            case 2:
                pop(sp);
                break;
            case 3:
                display(sp);
                break;
            case 4:
                checkEmpty(sp);
                break;
            case 5:
                printf("\nExiting... Thank you!\n");
                break;
            default:
                printf("\nInvalid choice! Please enter 1-5.\n");
        }
    } while (choice != 5);

    free(sp->arr);
    free(sp);
    return 0;
}
