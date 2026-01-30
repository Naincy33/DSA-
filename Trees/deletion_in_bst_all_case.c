#include <stdio.h>
#include <stdlib.h>

/* BST node structure */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

/* Create a new node */
struct Node* createNode(int value)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

/* Insert into BST */
struct Node* insert(struct Node* root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

/* Find minimum value node (used in deletion) */
struct Node* FindMin(struct Node* root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

/* Delete a node from BST */
struct Node* Delete(struct Node* root, int data)
{
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = Delete(root->left, data);
    else if (data > root->data)
        root->right = Delete(root->right, data);
    else
    {
        /* Case 1: No child */
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        /* Case 2: One child */
        else if (root->left == NULL)
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        /* Case 3: Two children */
        else
        {
            struct Node* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

/* Inorder Traversal */
void inorder(struct Node* root)
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
    struct Node* root = NULL;
    int n, value, delKey;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nInorder traversal before deletion: ");
    inorder(root);

    printf("\nEnter value to delete: ");
    scanf("%d", &delKey);

    root = Delete(root, delKey);

    printf("Inorder traversal after deletion: ");
    inorder(root);

    return 0;
}
