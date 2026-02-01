#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int *arr;
    int max;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Dynamic memory allocation
    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Reading elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Finding maximum
    max = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("Maximum value in the array is: %d\n", max);

    // Free allocated memory
    free(arr);

    return 0;
}
