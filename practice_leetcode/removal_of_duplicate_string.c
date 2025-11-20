#include <stdio.h>
#include <string.h>

char* removeDuplicates(char* s) {
    int n = strlen(s);
    char *stack = (char*)malloc((n + 1) * sizeof(char));  // stack array
    int top = -1;  // stack top index

    for (int i = 0; i < n; i++) {
        if (top >= 0 && stack[top] == s[i]) {
            top--;  // duplicate found, remove (pop)
        } else {
            stack[++top] = s[i];  // push current character
        }
    }

    stack[++top] = '\0';  // null terminate final string
    return stack;
}

int main() {
    char s[] = "abbaca";
    char *result = removeDuplicates(s);
    printf("Result: %s\n", result);
    //free(result);  // free allocated memory
    return 0;
}
