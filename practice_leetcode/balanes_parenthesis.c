/*
Input: ({{[]}})
Output: Valid

Input: ({{[}]})
Output: Invalid

Input: ({{0}})
Output: Invalid*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Stack operations
void push(char c) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        return '\0'; // Empty stack
    }
    return stack[top--];
}

int isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int isValidChar(char c) {
    return c == '(' || c == ')' ||
           c == '{' || c == '}' ||
           c == '[' || c == ']';
}

int main() {
    char expr[MAX];
    printf("Enter expression: ");
    scanf("%s", expr);

    int valid = 1; // assume valid

    for (int i = 0; i < strlen(expr); i++) {
        char c = expr[i];

        if (!isValidChar(c)) {  // Invalid character check
            valid = 0;
            break;
        }

        if (c == '(' || c == '{' || c == '[') {
            push(c);
        } else { // closing bracket
            char topChar = pop();
            if (topChar == '\0' || !isMatching(topChar, c)) {
                valid = 0;
                break;
            }
        }
    }

    if (top != -1) valid = 0; // leftover opening brackets

    if (valid)
        printf("Valid\n");
    else
        printf("Invalid\n");

    return 0;
}
