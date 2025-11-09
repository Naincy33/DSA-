#include <stdio.h>
#include <string.h>

#define MAX 100

// Stack structure
typedef struct {
    char data[MAX];
    int top;
} Stack;

// Initialize stack
void init(Stack *s) {
    s->top = -1;
}

// Push character onto stack
void push(Stack *s, char c) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->data[++(s->top)] = c;
}

// Pop character from stack
char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return s->data[(s->top)--];
}

// Check if word is palindrome using stack
int isPalindrome(char str[]) {
    Stack s;
    init(&s);
    int len = strlen(str);

    // Push all characters to stack
    for (int i = 0; i < len; i++) {
        push(&s, str[i]);
    }

    // Pop characters and compare with original
    for (int i = 0; i < len; i++) {
        if (str[i] != pop(&s)) {
            return 0; // Not palindrome
        }
    }
    return 1; // Palindrome
}

int main() {
    char word[MAX];
    
    printf("Enter a word: ");
    scanf("%s", word);

    if (isPalindrome(word)) {
        printf("Yes! The word '%s' reads the same left-to-right and right-to-left.\n", word);
    } else {
        printf("No! The word '%s' does not read the same backward.\n", word);
    }

    return 0;
}
