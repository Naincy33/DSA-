#include <stdio.h>
#include <stdlib.h>

/* BST node */
struct Node {
    int data;
    struct Node *left, *right;
};

/* Create new node */
struct Node* createNode(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

/* Insert into BST */
struct Node* insert(struct Node* root, int x) {
    if (root == NULL)
        return createNode(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

/* Find minimum value in BST */
int findMin(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return -1;
    }

    while (root->left != NULL)
        root = root->left;

    return root->data;
}

/* Inorder traversal (to show BST) */
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    /* Construct BST */
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder Traversal (BST): ");
    inorder(root);

    int min = findMin(root);
    printf("\nMinimum value in BST: %d", min);

    return 0;
}
