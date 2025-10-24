#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void bubbleSortAdaptive(int *A, int n)
{
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n - 1; i++)
    {
        printf("Working on pass number: %d \n", i + 1);
        isSorted = 1;
        for (int j = 0; j < (n - i - 1); j++)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}

int main()
{
    int A[] = {12, 54, 77, 93, 111, 199, 210};
    int n = 7;
    printf("Before Sorting: \n");
    printArray(A, n);
    bubbleSortAdaptive(A, n);
    printf("After Sorting: \n");
    printArray(A, n);
}