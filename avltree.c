#include "avltree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Symtable_Node* avl_create_node(Symtable_Row* data)
{
    Symtable_Node* node = malloc(sizeof(Symtable_Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

int height(const Symtable_Node* root)
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

int get_balance(const Symtable_Node* root)
{
    if (root == NULL)
    {
        return 0;
    }

    return height(root->left) - height(root->right);
}

Symtable_Node* right_rotate(Symtable_Node* y)
{
    Symtable_Node* x = y->left;
    Symtable_Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

Symtable_Node* left_rotate(Symtable_Node* x)
{
    Symtable_Node* y = x->right;
    Symtable_Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

Symtable_Node* avl_insert_avltree(Symtable_Node* root, Symtable_Row* data)
{
    if (root == NULL)
    {
        return avl_create_node(data);
    }

    if (avl_compare(data, root) < 0)
    {
        root->left = avl_insert_avltree(root->left, data);
    }
    else if (avl_compare(data, root) > 0)
    {
        root->right = avl_insert_avltree(root->right, data);
    }
    else
    {
        //TODO: should throw some error or do a rename because of same name
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));

    const int balance = get_balance(root);

    if (balance > 1 && avl_compare(data, root) < 0)
    {

        return right_rotate(root);
    }

    if (balance < -1 && avl_compare(data, root->right) > 0)
    {

        return left_rotate(root);
    }

    if (balance > 1 && avl_compare(data, root->left) > 0)
    {

        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    if (balance < -1 && avl_compare(data, root->left) < 0)
    {

        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

Symtable_Node* avl_find_avltree(Symtable_Node* root, char* data)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (avl_compare_string(data, root) < 0)
    {
        return avl_find_avltree(root->left, data);
    }
    if (avl_compare_string(data, root) > 0)
    {
        return avl_find_avltree(root->right, data);
    }

    return (Symtable_Node*)root;
}

void avl_print_inorder(const Symtable_Node* root)
{
    if (root == NULL)
    {
        return;
    }

    avl_print_inorder(root->left);
    printf("%s ", root->data->identifier);
    avl_print_inorder(root->right);
}

void avl_print_postorder(const Symtable_Node* root)
{
    if (root == NULL)
    {
        return;
    }

    avl_print_postorder(root->right);
    printf("%s ", root->data->identifier);
    avl_print_postorder(root->left);
}

void avl_print_preorder(const Symtable_Node* root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%s ", root->data->identifier);
    avl_print_preorder(root->left);
    avl_print_preorder(root->right);
}

Symtable_Row* avl_create_row(char* name) {
    Symtable_Row* row = malloc(sizeof(Symtable_Row));
    if(row == NULL) return NULL; //suicide
    row->identifier = name;

    return row;
}

int avl_compare(Symtable_Row* r1, Symtable_Node* r2){
    if(r2 == NULL) return -1;

    int temp = strcmp(r1->identifier, r2->data->identifier);
    return temp;
}
int avl_compare_string(char* r1, Symtable_Node* r2){
    if(r2 == NULL) return -1;

    int temp = strcmp(r1, r2->data->identifier);
    return temp;
}