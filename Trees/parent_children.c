#include <stdio.h>
#include <stdlib.h>

/* Tree node */
struct Node {
    char data;
    struct Node *left, *right;
};

/* Create node */
struct Node* createNode(char x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

/* Print ancestors (top-down) */
int printAncestors(struct Node* root, char key) {
    if (root == NULL)
        return 0;

    if (root->data == key)
        return 1;

    if (printAncestors(root->left, key) ||
        printAncestors(root->right, key)) {
        printf("%c ", root->data);
        return 1;
    }
    return 0;
}

/* Print children (left-to-right) */
void preorder(struct Node* root) {
    if (root) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

/* Level order traversal */
void levelOrder(struct Node* root) {
    if (!root) return;

    struct Node* q[20];
    int front = 0, rear = 0;

    q[rear++] = root;

    while (front < rear) {
        struct Node* temp = q[front++];
        printf("%c ", temp->data);

        if (temp->left)
            q[rear++] = temp->left;
        if (temp->right)
            q[rear++] = temp->right;
    }
}

int main() {
    /* Construct tree */
    struct Node* root = createNode('A');
    root->left = createNode('B');
    root->right = createNode('C');
    root->left->left = createNode('D');
    root->left->right = createNode('E');
    root->right->right = createNode('F');

    printf("Ancestors of node E (top-down): ");
    printAncestors(root, 'E');

    printf("\nChildren (left-to-right): ");
    preorder(root);

    printf("\nAll nodes level by level: ");
    levelOrder(root);

    return 0;
}
