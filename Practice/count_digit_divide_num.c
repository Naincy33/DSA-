/*
🔹 Question:
Given an integer num, return the number of digits in num that divide num.

An integer val divides num if num % val == 0.

Example 1:
Input: num = 1248
Output: 4
Explanation:
All digits of num (1, 2, 4, 8) divide num.

Example 2:
Input: num = 7
Output: 1
Explanation:
7 divides itself.

Example 3:
Input: num = 120
Output: 2
Explanation:
Digits 1 and 2 divide 120.
Digit 0 does not divide anything (division by zero not allowed).
*/

#include <stdio.h>

int countDigits(int num) {
    if (num == 0) return 0;              // special case
    int temp = (num < 0) ? -num : num;   // handle negative numbers
    int count = 0;

    while (temp > 0) {
        int digit = temp % 10;           // extract last digit
        if (digit != 0 && num % digit == 0) {
            count++;                     // if digit divides num
        }
        temp = temp / 10;                // move to next digit
    }
    return count;
}

int main() {
    int num = 7;
    printf("Number of digits that divide %d = %d\n", num, countDigits(num));
    return 0;
}
