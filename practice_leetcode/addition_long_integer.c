#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node *next;
};

struct node* insert_begin(struct node* head, int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = head;
    return newnode;
}

void add(struct node* head1, struct node* head2, char result[]) {
    int sum, carry = 0, operand1, operand2, index = 0;
    struct node *temp1 = head1, *temp2 = head2;

    while (temp1 != NULL || temp2 != NULL) {
        operand1 = (temp1 != NULL) ? temp1->data : 0;
        operand2 = (temp2 != NULL) ? temp2->data : 0;
        sum = operand1 + operand2 + carry;

        if (sum >= 10) {
            carry = 1;
            sum %= 10;
        } else {
            carry = 0;
        }

        result[index++] = sum + '0';

        if (temp1 != NULL) temp1 = temp1->next;
        if (temp2 != NULL) temp2 = temp2->next;
    }

    if (carry)
        result[index++] = carry + '0';

    result[index] = '\0';
    strrev(result);
}

int main() {
    char num1[100], num2[100], result[200];
    struct node *head1 = NULL, *head2 = NULL;

    printf("Enter first number: ");
    scanf("%s", num1);
    printf("Enter second number: ");
    scanf("%s", num2);

    for (int i = 0; i < strlen(num1); i++)
        head1 = insert_begin(head1, num1[i] - '0');

    for (int i = 0; i < strlen(num2); i++)
        head2 = insert_begin(head2, num2[i] - '0');

    add(head1, head2, result);
    printf("Sum = %s\n", result);

    return 0;
}
