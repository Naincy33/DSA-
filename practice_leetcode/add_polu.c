#include <stdio.h>
#include <stdlib.h>

struct node {
    int coef;        // Coefficient
    int exp;         // Exponent
    struct node *next;
};

// Create new node
struct node *newNode(int c, int e) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->coef = c;
    temp->exp = e;
    temp->next = NULL;
    return temp;
}

// Insert at end
void insertEnd(struct node **head, int c, int e) {
    struct node *temp = newNode(c, e);

    if (*head == NULL) {
        *head = temp;
        return;
    }

    struct node *t = *head;
    while (t->next != NULL)
        t = t->next;

    t->next = temp;
}

// Print polynomial
void printPoly(struct node *head) {
    struct node *t = head;
    while (t != NULL) {
        if (t->coef >= 0 && t != head)
            printf("+");

        printf("%dx^%d ", t->coef, t->exp);
        t = t->next;
    }
    printf("\n");
}

// Add two polynomials
struct node *addPolynomial(struct node *p1, struct node *p2) {
    struct node *result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp == p2->exp) {
            insertEnd(&result, p1->coef + p2->coef, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp > p2->exp) {
            insertEnd(&result, p1->coef, p1->exp);
            p1 = p1->next;
        }
        else {
            insertEnd(&result, p2->coef, p2->exp);
            p2 = p2->next;
        }
    }

    // Add remaining terms
    while (p1 != NULL) {
        insertEnd(&result, p1->coef, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        insertEnd(&result, p2->coef, p2->exp);
        p2 = p2->next;
    }

    return result;
}

int main() {
    struct node *poly1 = NULL, *poly2 = NULL, *sum = NULL;

    insertEnd(&poly1, 3, 8);
    insertEnd(&poly1, 5, 7);
    insertEnd(&poly1, -2, 6);
    insertEnd(&poly1, 8, 4);

    insertEnd(&poly2, 4, 7);
    insertEnd(&poly2, 5, 6);
    insertEnd(&poly2, -1, 3);
    insertEnd(&poly2, 7, 2);
    insertEnd(&poly2, -3, 0);

    printf("Polynomial 1: ");
    printPoly(poly1);

    printf("Polynomial 2: ");
    printPoly(poly2);

    sum = addPolynomial(poly1, poly2);

    printf("\nSum = ");
    printPoly(sum);

    return 0;
}
