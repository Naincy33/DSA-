/*a C program to return an array of strings representing the numbers from 1 to n.
But for multiples of 3 print "Fizz", for 5 print "Buzz", and for both 3 & 5 print "FizzBuzz".*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** fizzBuzz(int n, int* returnSize) {
    *returnSize = n;
    char** result = (char**)malloc(n * sizeof(char*));

    for (int i = 1; i <= n; i++) {
        result[i - 1] = (char*)malloc(10 * sizeof(char));
        if (i % 3 == 0 && i % 5 == 0)
            strcpy(result[i - 1], "FizzBuzz");
        else if (i % 3 == 0)
            strcpy(result[i - 1], "Fizz");
        else if (i % 5 == 0)
            strcpy(result[i - 1], "Buzz");
        else
            sprintf(result[i - 1], "%d", i);
    }
    return result;
}

int main() {
    int n = 15, returnSize;
    char** ans = fizzBuzz(n, &returnSize);

    for (int i = 0; i < returnSize; i++)
        printf("%s\n", ans[i]);

    // free memory
    for (int i = 0; i < returnSize; i++)
        free(ans[i]);
    free(ans);

    return 0;
}
