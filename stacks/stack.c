#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    return ptr->top == -1;
}

int isFull(struct stack *ptr)
{
    return ptr->top == ptr->size - 1;
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

void display(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements (top to bottom):\n");
    for (int i = ptr->top; i >= 0; i--)
    {
        printf("%d\n", ptr->arr[i]);
    }
}

int main()
{
    struct stack s;
    s.size = 10;
    s.top = -1;
    s.arr = (int *)malloc(s.size * sizeof(int)); // 🔥 important

    push(&s, 33);
    push(&s, 44);
    push(&s, 55);

    display(&s);

    free(s.arr);
    return 0;
}
