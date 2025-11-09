/*nums = [2, 0, 2, 1, 1, 0]
[0, 0, 1, 1, 2, 2]*/

#include <stdio.h>

void sortColors(int *nums, int n) {
    int low = 0, mid = 0, high = n - 1;
    int temp;

    while (mid <= high) {
        if (nums[mid] == 0) {
            // Swap nums[low] and nums[mid]
            temp = nums[low];
            nums[low] = nums[mid];
            nums[mid] = temp;
            low++;
            mid++;
        }
        else if (nums[mid] == 1) {
            mid++;
        }
        else { // nums[mid] == 2
            // Swap nums[mid] and nums[high]
            temp = nums[mid];
            nums[mid] = nums[high];
            nums[high] = temp;
            high--;
        }
    }
}

void printArray(int *nums, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main() {
    int nums[] = {2, 0, 2, 1, 1, 0};
    int n = sizeof(nums) / sizeof(nums[0]);

    printf("Before sorting: ");
    printArray(nums, n);

    sortColors(nums, n);

    printf("After sorting:  ");
    printArray(nums, n);

    return 0;
}
