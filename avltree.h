#pragma once

typedef struct AvlNode {
    int data;
    struct AvlNode* left;
    struct AvlNode* right;
    int height;
} AvlNode;

AvlNode* avl_create_node(int data);
AvlNode* avl_insert_avltree(AvlNode* root, int data);
AvlNode* avl_find_avltree(const AvlNode* root, int data);
void avl_print_inorder(const AvlNode* root);
void avl_print_preorder(const AvlNode* root);
void avl_print_postorder(const AvlNode* root);