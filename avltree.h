#pragma once



typedef struct Symtable_Row_t{
    char* identifier;
} Symtable_Row;


typedef struct Symtable_Node_t {
    Symtable_Row* data;
    struct Symtable_Node_t* left;
    struct Symtable_Node_t* right;
    int height;
} Symtable_Node;



Symtable_Row* avl_create_row(char* name);
Symtable_Node* avl_create_node(Symtable_Row* data);
Symtable_Node* avl_insert_avltree(Symtable_Node* root, Symtable_Row* data);
Symtable_Node* avl_find_avltree(Symtable_Node* root, char* data);
void avl_print_inorder(const Symtable_Node* root);
void avl_print_preorder(const Symtable_Node* root);
void avl_print_postorder(const Symtable_Node* root);
int avl_compare(Symtable_Row* r1, Symtable_Node* r2);
int avl_compare_string(char* r1, Symtable_Node* r2);