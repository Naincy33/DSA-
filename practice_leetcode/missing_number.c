/*
🔹 Question:
Given an array `nums` containing `n` distinct numbers in the range [0, n],
return the only number in the range that is missing from the array.

Example:
Input: nums = [3, 0, 1]
Output: 2
Explanation:
Numbers in range [0, 3] are 0, 1, 2, 3
Given array has 0, 1, 3 → Missing number is 2
*/

#include <stdio.h>

int missingNumber(int* nums, int numsSize) {
    // Expected sum of all numbers from 0 to n
    int total = numsSize * (numsSize + 1) / 2;

    // Actual sum of numbers present in array
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    // Missing number = Expected - Actual
    return total - sum;
}

int main() {
    int nums[] = {3, 0, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    int result = missingNumber(nums, n);
    printf("Missing number is: %d\n", result);

    return 0;
}
