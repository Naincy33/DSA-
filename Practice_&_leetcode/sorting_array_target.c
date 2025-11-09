/*🔹 LeetCode Problem:
Return a list of the target indices of nums after sorting nums in non-decreasing order.
If there are no target indices, return an empty list.
The returned list must be sorted in increasing order.
Example 1:
Input: nums = [1,2,5,2,3], target = 2
Output: [1,2]*/

#include <stdio.h>

// 🔹 Step 1: Bubble sort function
void sortArray(int nums[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}

// 🔹 Step 2: Main LeetCode function
int* targetIndices(int* nums, int numsSize, int target, int* returnSize) {
    static int result[100]; // static so it survives after function returns
    int count = 0;

    // Step 1: Sort the array manually
    sortArray(nums, numsSize);

    // Step 2: Find target indices
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            result[count++] = i;
        }
    }

    // Step 3: Update returnSize
    *returnSize = count;

    // Step 4: Return result array
    return result;
}

// 🔹 Step 3: Main function for local testing
int main() {
    int nums[] = {1, 2, 5, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 2;
    int returnSize = 0;

    // Call function
    int* indices = targetIndices(nums, numsSize, target, &returnSize);

    // Print output
    printf("Sorted Target Indices: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", indices[i]);
        if (i != returnSize - 1) printf(", ");
    }
    printf("]\n");

    return 0;
}
