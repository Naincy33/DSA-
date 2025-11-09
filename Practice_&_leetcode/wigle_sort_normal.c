/*Before: 3 5 2 1 6 4 
After:  3 5 1 6 2 4*/

#include <stdio.h>

// Function to reorder array in wiggle (zig-zag) pattern
void wiggleSort(int nums[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (i % 2 == 0) {
            // even index → nums[i] < nums[i+1] chahiye
            if (nums[i] > nums[i + 1]) {
                int temp = nums[i];
                nums[i] = nums[i + 1];
                nums[i + 1] = temp;
            }
        } else {
            // odd index → nums[i] > nums[i+1] chahiye
            if (nums[i] < nums[i + 1]) {
                int temp = nums[i];
                nums[i] = nums[i + 1];
                nums[i + 1] = temp;
            }
        }
    }
}

void printArray(int nums[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main() {
    int nums[] = {3, 5, 2, 1, 6, 4};
    int n = sizeof(nums) / sizeof(nums[0]);

    printf("Before: ");
    printArray(nums, n);

    wiggleSort(nums, n);

    printf("After:  ");
    printArray(nums, n);

    return 0;
}
