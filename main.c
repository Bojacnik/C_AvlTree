#include <stdio.h>

#include "avltree.h"
#include "string.h"

int main(void) {


    Symtable_Node* root = avl_create_node(avl_create_row("negr"));
    avl_insert_avltree(root, avl_create_row("adolf"));
    avl_insert_avltree(root, avl_create_row("pica"));
    avl_insert_avltree(root, avl_create_row("zmrd"));
    avl_insert_avltree(root, avl_create_row("stalin"));
    avl_insert_avltree(root, avl_create_row("churchill"));
    avl_insert_avltree(root, avl_create_row("babis"));
    avl_insert_avltree(root, avl_create_row("joever"));

    avl_print_inorder(root);
    puts("");
    avl_print_postorder(root);
    puts("");
    avl_print_preorder(root);

     return 0;
}


