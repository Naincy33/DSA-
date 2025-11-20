#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// push function with overflow check
void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push '%c'\n", ch);
    } else {
        stack[++top] = ch;
    }
}

// pop function with underflow check
char pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return '\0';
    } else {
        return stack[top--];
    }
}

int main() {
    char str[MAX];
    int i, len, flag = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    // Push all characters to stack
    for (i = 0; i < len; i++) {
        push(str[i]);
    }

    // Compare popped characters with original string
    for (i = 0; i < len; i++) {
        char ch = pop();
        if (ch == '\0' || str[i] != ch) {
            flag = 0;
            break;
        }
    }

    if (flag == 1)
        printf("✅ Palindrome\n");
    else
        printf("❌ Not Palindrome\n");

    return 0;
}
