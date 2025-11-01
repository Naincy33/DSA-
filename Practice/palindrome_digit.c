#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val)
{
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = val;
}

int pop()
{
    if (top == -1)
        printf("Stack Underflow\n");
    else
        return stack[top--];
    return -1;
}

bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    int arr[MAX];
    int n = 0;
    int temp = x;

    // for last digit
    while (temp > 0)
    {
        arr[n++] = temp % 10;
        temp /= 10;
    }

    for (int i = 0; i < n; i++)
    {
        push(arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int popped = pop();
        if (arr[i] != popped)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPalindrome(num))
        printf("%d is a palindrome\n", num);
    else
        printf("%d is not a palindrome\n", num);

    return 0;
}
