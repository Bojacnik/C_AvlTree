#pragma once

typedef struct BinaryNode {
    int data;
    struct BinaryNode* left;
    struct BinaryNode* right;
} BinaryNode;

BinaryNode* create_node(int data);
void insert_binarytree(BinaryNode* root, int data);
void print_inorder(const BinaryNode* root);
void print_preorder(const BinaryNode* root);
void print_postorder(const BinaryNode* root);
