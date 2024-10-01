#include <stdio.h>

#include "avltree.h"


int main(void) {
    AvlNode* root = avl_create_node(10);
    root = avl_insert_avltree(root, 40);
    root = avl_insert_avltree(root, 30);
    root = avl_insert_avltree(root, 20);
    root = avl_insert_avltree(root, 25);
    root = avl_insert_avltree(root, 45);
    root = avl_insert_avltree(root, 50);
    root = avl_insert_avltree(root, 35);

    root = avl_insert_avltree(root, 150);
    root = avl_insert_avltree(root, 156);
    root = avl_insert_avltree(root, 159);
    root = avl_insert_avltree(root, 157);
    root = avl_insert_avltree(root, 158);
    root = avl_insert_avltree(root, 151);

    const AvlNode* found = avl_find_avltree(root, 45);
    if (found != NULL)
    {
        printf("Found: %d\n", found->data);
    }
    else
    {
        puts("Not found");
    }


    avl_print_inorder(root);
    puts("");
    avl_print_postorder(root);
    puts("");
    avl_print_preorder(root);
    return 0;
}


