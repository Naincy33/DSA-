#include <stdio.h>
#include <ctype.h>   // for isdigit()
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Function to push an element to the stack
void push(int val) {
    if (top >= MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = val;
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return 0;
    }
    return stack[top--];
}

// Function to check if a character is an operator
int is_operator(char symbol) {
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
}

// Function to evaluate postfix expression
int evaluate(char *expression) {
    int i = 0;
    char symbol;
    int operand1, operand2, result;

    symbol = expression[i];
    while (symbol != '\0') {
        if (isdigit(symbol)) {  // if symbol is a digit
            int num = symbol - '0';  // convert '3' → 3
            push(num);
        } 
        else if (is_operator(symbol)) {
            operand1 = pop(); // first popped value
            operand2 = pop(); // second popped value
            switch (symbol) {
                case '+': result = operand2 + operand1; break;
                case '-': result = operand2 - operand1; break;
                case '*': result = operand2 * operand1; break;
                case '/': result = operand2 / operand1; break;
            }
            push(result);
        }
        // move to next symbol
        i++;
        symbol = expression[i];
    }
    result = pop();
    return result;
}

// Main function
int main() {
    char expression[100];

    printf("Enter a postfix expression (e.g., 23*54*+): ");
    scanf("%s", expression);

    int result = evaluate(expression);
    printf("Result = %d\n", result);

    return 0;
}
