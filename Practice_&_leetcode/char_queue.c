#include <stdio.h>
#include <string.h>
#define MAX 256   // ASCII characters

int main() {
    char input[100];
    printf("Enter characters (space separated): ");
    fgets(input, sizeof(input), stdin);

    int count[MAX] = {0};  // har character ka frequency count
    char queue[100];       // queue to store order of chars
    int front = 0, rear = 0;

    // loop through input
    for (int i = 0; i < strlen(input); i++) {
        char ch = input[i];

        // skip spaces and newlines
        if (ch == ' ' || ch == '\n')
            continue;

        count[ch]++;          // frequency badhao
        queue[rear++] = ch;   // queue me daal do

        // check queue front
        while (front < rear && count[queue[front]] > 1) {
            front++; // remove repeated chars from front
        }

        // print result
        if (front == rear) {
            printf("-1 ");
        } else {
            printf("%c ", queue[front]);
        }
    }

    return 0;
}
