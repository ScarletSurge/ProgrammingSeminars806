#include "../include/binary_search_tree.h"
#include <stdio.h>
#include <malloc.h>
#define UJASHO 1
#define PYK_SRENK 2

int initialize_bst(
    p_bst bst_ptr,
    comparer keys_comparer)
{
    bst_ptr -> root = NULL;
    bst_ptr -> keys_comparer = keys_comparer;
    return 0;
}

int deinitialize_bst(
    p_bst bst_ptr);
{

}

int insert_into_bst(
    p_bst bst_ptr,
    TKey bst_key,
    TValue const *value_to_insert_ptr)
{
    int comparer_result;

    if (bst_ptr == NULL || value_to_insert_ptr == NULL)
    {
        return 3;
    }

    pp_bst_item iterator = &bst_ptr->root;

    while (*iterator != NULL)
    {
        comparer_result = bst_ptr -> keys_comparer(&(*iterator)->key, &bst_key);
        if (comparer_result == 0)
        {
            return PYK_SRENK;
        }

        iterator = comparer_result < 0
            ? &(*iterator)->left_subtree
            : &(*iterator)->right_subtree;
    }

    if ((*iterator = (p_bst_item)malloc(sizeof(bst_item))) == NULL)
    {
        return UJASHO;
    }

    (*iterator) -> left_subtree = NULL;
    (*iterator) -> right_subtree = NULL;
    (*iterator) -> key = bst_key;
    (*iterator) -> value = *value_to_insert_ptr;
    return  0;
}

int obtain_from_bst(
    p_bst const *bst_ptr,
    TKey bst_key,
    TValue ** bst_value);

int dispose_from_bst(
    p_bst const *bst_ptr,
    TKey bst_key);

void bst_prefix_traversion_inner(
    bst_item const* subtree,
    void (*callback)(TValue const *)) {

    if (subtree == NULL) {
        return;
    }
    callback(&subtree->value);
    bst_prefix_traversion_inner(subtree->left_subtree, callback);
    bst_prefix_traversion_inner(subtree->right_subtree, callback);
}

int bst_prefix_traversion(
    bst const *bst_ptr,
    void (*callback)(TValue const *)) {

    bst_prefix_traversion_inner(bst_ptr->root, callback);
    return 0;
}

int bst_infix_traversion(
    bst const *bst_ptr,
    void (*callback)(TValue const *));

int bst_postfix_traversion(
    bst const *bst_ptr,
    void (*callback)(TValue const *));