#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char *s) {
    int i = strlen(s) - 1;
    int len = 0;

    // Step 1: Skip trailing spaces/newline
    while (i >= 0 && (s[i] == ' ' || s[i] == '\n'))
        i--;

    // Step 2: Count characters
    while (i >= 0 && s[i] != ' ') {
        len++;
        i--;
    }
    return len;
}

int main() {
    char s[200];

    printf("Enter the string: ");
    fgets(s, sizeof(s), stdin);

    int ans = lengthOfLastWord(s);
    printf("Length of last word = %d\n", ans);

    return 0;
}
