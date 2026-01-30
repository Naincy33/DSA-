#include <stdio.h>
#include <stdlib.h>

/* BST node structure */
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

/* Create a new node */
struct node* createNode(int value)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

/* Insert a value into BST */
struct node* insert(struct node* root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    /* if value == root->data → duplicate ignored */

    return root;
}

/* Inorder traversal (for checking) */
void inorder(struct node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/* Main function */
int main()
{
    struct node* root = NULL;
    int n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Inorder Traversal: ");
    inorder(root);

    return 0;
}
