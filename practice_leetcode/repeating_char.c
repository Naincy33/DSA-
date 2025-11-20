/* Design a C program using suitable data structure to find first non-repeating character each time a character is inserted into the string. If character is repeated, output -1 else print the non-repeating character.
Sample Input: a a b c
Output: a -1 b c*/

#include <stdio.h>
#include <string.h>

#define MAX 256

typedef struct {
    char data[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

void enqueue(Queue *q, char ch) {
    q->data[q->rear++] = ch;
}

char front(Queue *q) {
    if (isEmpty(q)) return '\0';
    return q->data[q->front];
}

char dequeue(Queue *q) {
    if (isEmpty(q)) return '\0';
    return q->data[q->front++];
}

int main() {
    char str[100];
    printf("Enter characters separated by spaces: ");
    fgets(str, sizeof(str), stdin);

    int freq[MAX] = {0};
    Queue q;
    initQueue(&q);

    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ' || str[i] == '\n') continue;

        char ch = str[i];
        freq[ch]++;
        enqueue(&q, ch);

        // Remove repeated characters from front
        while (!isEmpty(&q) && freq[front(&q)] > 1) {
            dequeue(&q);
        }

        // Output
        if (!isEmpty(&q))
            printf("%c ", front(&q));
        else
            printf("-1 ");
    }

    return 0;
}
