#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
    char data;
    struct node *left, *right;
};

struct node* stack[20];
int top = -1;

struct node* newNode(char x) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

void push(struct node* n) {
    stack[++top] = n;
}

struct node* pop() {
    return stack[top--];
}

struct node* buildTree(char postfix[]) {
    int i = 0;
    while (postfix[i]) {
        char ch = postfix[i];

        if (isalnum(ch)) {
            push(newNode(ch));
        } else {
            struct node* n = newNode(ch);
            n->right = pop();
            n->left = pop();
            push(n);
        }
        i++;
    }
    return pop();
}

void preorder(struct node* root) {
    if (root) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node* root) {
    if (root) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

void postorder(struct node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

int main() {
    char postfix[] = "ab+c*";

    struct node* root = buildTree(postfix);

    printf("Prefix : ");
    preorder(root);
    printf("\n");

    printf("Infix  : ");
    inorder(root);
    printf("\n");

    printf("Postfix: ");
    postorder(root);

    return 0;
}
