#include "binarytree.h"

#include <stdio.h>
#include <stdlib.h>

// Create a new node with the given data
BinaryNode* create_node(const int data) {
    BinaryNode* node = malloc(sizeof(BinaryNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert_binarytree(BinaryNode* root, const int data) {
    // If the tree is empty, create a new node
    if (root == NULL) {
        root = create_node(data);
        return;
    }

    // Otherwise if the data is less than the root, insert it into the left subtree RECURSIVELY
    if (data < root->data) {
        if (root->left == NULL) {
            root->left = create_node(data);
        } else {
            insert_binarytree(root->left, data);
        }
    }
    // Otherwise if the data is greater than the root, insert it into the right subtree RECURSIVELY
    else {
        if (root->right == NULL) {
            root->right = create_node(data);
        }
        else {
            insert_binarytree(root->right, data);
        }
    }
}

// Recursive function to print the binary tree inorder
void print_inorder(const BinaryNode* root) {
    if (root == NULL) {
        return;
    }

    print_inorder(root->left);
    printf("%d ", root->data);
    print_inorder(root->right);
}

// Recursive function to print the binary tree preorder
void print_preorder(const BinaryNode* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    print_preorder(root->left);
    print_preorder(root->right);
}

// Recursive function to print the binary tree postorder
void print_postorder(const BinaryNode* root) {
    if (root == NULL) {
        return;
    }

    print_postorder(root->right);
    printf("%d ", root->data);
    print_postorder(root->left);
}
