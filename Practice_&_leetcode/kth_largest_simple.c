/*Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Explanation: The 2nd largest element is 5.
*/

#include <stdio.h>

// 🔹 Function to find kth largest element
int findKthLargest(int* nums, int numsSize, int k) {
    // Step 1: Sort the array (ascending) using Bubble Sort
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = 0; j < numsSize - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                // 🔸 Swap directly inside sorting loop
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }

    // Step 2: kth largest = element at index (numsSize - k)
    return nums[numsSize - k];
}

// 🔹 Driver function to test
int main() {
    int nums[] = {10, 5, 20, 8, 15};
    int n = sizeof(nums) / sizeof(nums[0]);
    int k = 2;

    int result = findKthLargest(nums, n, k);

    printf("The %dth largest element is: %d\n", k, result);

    return 0;
}
