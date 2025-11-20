/* Clumsy factorial is calculated by performing operations *, /, +, - in a repeating sequence on the integers from n down to 1, following normal operator precedence (multiplication and division before addition and subtraction), and integer division (floor division).
clumsy(10) = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1*/

#include <stdio.h>

int clumsy(int n) {
    int stack[1000];
    int top = 0;
    stack[top] = n;
    n--;
    int index = 0;

    while (n > 0) {
        if (index % 4 == 0) {           // multiply
            stack[top] *= n;
        } else if (index % 4 == 1) {    // divide
            stack[top] /= n;
        } else if (index % 4 == 2) {    // add
            stack[++top] = n;
        } else {                        // subtract
            stack[++top] = -n;
        }
        index++;
        n--;
    }

    int result = 0;
    for (int i = 0; i <= top; i++) {
        result += stack[i];
    }

    return result;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int ans = clumsy(n);
    printf("Clumsy factorial of %d is: %d\n", n, ans);

    return 0;
}
