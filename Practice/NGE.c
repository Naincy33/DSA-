/*Design a C Program using suitable data structure to print the Next Greater Element for every element in a given array. The Next Greater Element for an element x is the first greater element on the right side of x in the array. Elements for which no greater element exist, consider next greater element as -1.
Sample input: {11, 13, 21, 3}
Output: {13, 21, -1, -1}*/

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
