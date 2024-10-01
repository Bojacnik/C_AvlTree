#include "avltree.h"

#include <stdio.h>
#include <stdlib.h>

AvlNode* avl_create_node(const int data)
{
    AvlNode* node = malloc(sizeof(AvlNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

int height(const AvlNode* root)
{
    if (root == NULL)
    {
        return 0;
    }

    return root->height;
}

int max(const int a, const int b)
{
    return a > b ? a : b;
}

int get_balance(const AvlNode* root)
{
    if (root == NULL)
    {
        return 0;
    }

    return height(root->left) - height(root->right);
}

AvlNode* right_rotate(AvlNode* y)
{
    AvlNode* x = y->left;
    AvlNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

AvlNode* left_rotate(AvlNode* x)
{
    AvlNode* y = x->right;
    AvlNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

AvlNode* avl_insert_avltree(AvlNode* root, const int data)
{
    if (root == NULL)
    {
        return avl_create_node(data);
    }

    if (data < root->data)
    {
        root->left = avl_insert_avltree(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = avl_insert_avltree(root->right, data);
    }
    else
    {
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));

    const int balance = get_balance(root);

    if (balance > 1 && data < root->left->data)
    {
        return right_rotate(root);
    }

    if (balance < -1 && data > root->right->data)
    {
        return left_rotate(root);
    }

    if (balance > 1 && data > root->left->data)
    {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    if (balance < -1 && data < root->right->data)
    {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

AvlNode* avl_find_avltree(const AvlNode* root, const int data)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (data < root->data)
    {
        return avl_find_avltree(root->left, data);
    }
    if (data > root->data)
    {
        return avl_find_avltree(root->right, data);
    }

    return (AvlNode*)root;
}

void avl_print_inorder(const AvlNode* root)
{
    if (root == NULL)
    {
        return;
    }

    avl_print_inorder(root->left);
    printf("%d ", root->data);
    avl_print_inorder(root->right);
}

void avl_print_postorder(const AvlNode* root)
{
    if (root == NULL)
    {
        return;
    }

    avl_print_postorder(root->right);
    printf("%d ", root->data);
    avl_print_postorder(root->left);
}

void avl_print_preorder(const AvlNode* root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->data);
    avl_print_preorder(root->left);
    avl_print_preorder(root->right);
}
