/*
Write a program to perform following operations in binary search tree. 1)Insert a node in the BST.
2)Delete a node in the BST. 3)Traversal of BST –Inorder, Preorder, Postorder
*/
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the Binary Search Tree
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to insert a node in the Binary Search Tree
struct TreeNode *insert(struct TreeNode *root, int data)
{
    if (root == NULL)
    {
        struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to find the minimum value node in a BST
struct TreeNode *findMin(struct TreeNode *node)
{
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

// Function to delete a node from the Binary Search Tree
struct TreeNode *deleteNode(struct TreeNode *root, int data)
{
    if (root == NULL)
    {
        return root;
    }

    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        // Node with only one child or no child
        if (root->left == NULL)
        {
            struct TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct TreeNode *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct TreeNode *temp = findMin(root->right);

        // Copy the inorder successor's data to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to perform Inorder traversal of the BST
void inorder(struct TreeNode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to perform Preorder traversal of the BST
void preorder(struct TreeNode *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to perform Postorder traversal of the BST
void postorder(struct TreeNode *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    struct TreeNode *root = NULL; // Initialize an empty Binary Search Tree

    int choice;
    int data;
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // INSERT NODE operation
           
            printf("Enter data to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;

        case 2:
            // DELETE NODE operation
       
            printf("Enter data to delete: ");
            scanf("%d", &data);
            root = deleteNode(root, data);
            break;

        case 3:
            // INORDER TRAVERSAL operation
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 4:
            // PREORDER TRAVERSAL operation
            printf("Preorder Traversal: ");
            preorder(root);
            printf("\n");
            break;

        case 5:
            // POSTORDER TRAVERSAL operation
            printf("Postorder Traversal: ");
            postorder(root);
            printf("\n");
            break;

        case 6:
            // Exit the program
            printf("Exiting the program.\n");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
