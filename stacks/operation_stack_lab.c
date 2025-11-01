#include <stdio.h>
int stack[100], choice, n, top, x, i;
void push(void);
void pop(void);
void display(void);
void empty(void);
int main()
{
    top = -1;
    printf("\n Enter the size of STACK[MAX=100]:");
    scanf("%d", &n);
    printf("\n\t STACK OPERATION USING ARRAYS");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EMPTY OR NOT");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            empty();
            break;
        }
        default:
        {
            printf("\n\t Please Enter a Valid Choice(1/2/3/4)");
        }
        }
    } while (choice != 4);
    return 0;
}
void push()
{
    if (top >= n - 1)
    {
        printf("\n\tSTACK is overflow");
    }
    else
    {
        printf(" Enter a value to be pushed:");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}
void pop()
{
    if (top <= -1)
    {
        printf("\n\t STACK is underflow");
    }
    else
    {
        printf("\n The popped elements is %d", stack[top]);
        top--;
    }
}
void display()
{
    if (top >= 0)
    {
        printf("\n The elements in STACK \n");
        for (i = top; i >= 0; i--)
            printf("\n%d", stack[i]);
        printf("\n Press Next Choice");
    }
    else
    {
        printf("\n The STACK is empty");
    }
}
void empty()
{
    if (top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("Stack is not empty");
    }
}