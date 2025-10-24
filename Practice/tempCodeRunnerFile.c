#include <stdio.h>

#define MAX 100

int main()
{
    int arr[MAX], nge[MAX], stack[MAX];
    int n, top = -1; // 'top' for stack

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        nge[i] = -1; // initialize all NGE as -1
    }

    // Process each element
    for (int i = 0; i < n; i++)
    {
        // While stack is not empty and current element is greater than element at stack top
        while (top != -1 && arr[i] > arr[stack[top]])
        {
            nge[stack[top]] = arr[i]; // Current element is NGE for stack top
            top--;                    // pop element from stack
        }
        stack[++top] = i; // push current index onto stack
    }

    // Print result
    printf("Next Greater Elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", nge[i]);
    }
    printf("\n");

    return 0;
}
