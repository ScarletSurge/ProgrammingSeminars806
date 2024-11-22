#include "../include/binary_search_tree.h"
#include <stdio.h>
#include <malloc.h>

#define OK 0
#define UJASHO 1
#define PYK_SRENK 2
#define KEY_NOT_FOUND 3

int swap(
    void *first,
    void *second,
    size_t bytes_to_swap_count)
{
    int i;
    for (i = 0; i < bytes_to_swap_count; ++i)
    {
        *((unsigned char *)first + i) ^= *((unsigned char *)second + i);
        *((unsigned char *)second + i) ^= *((unsigned char *)first + i);
        *((unsigned char *)first + i) ^= *((unsigned char *)second + i);
    }

    return 0;
}

int initialize_bst(
    p_bst bst_ptr,
    comparer keys_comparer,
    binary_search_tree_disposal_strategy disposal_strategy)
{
    if (bst_ptr == NULL || keys_comparer == NULL)
    {
        return UJASHO;
    }

    bst_ptr->root = NULL;
    bst_ptr->keys_comparer = keys_comparer;
    bst_ptr->disposal_strategy = disposal_strategy;

    return 0;
}

int set_disposal_strategy(
    p_bst bst_ptr,
    binary_search_tree_disposal_strategy disposal_strategy)
{
    if (bst_ptr == NULL)
    {
        return UJASHO;
    }

    bst_ptr->disposal_strategy = disposal_strategy;

    return OK;
}

int deinitialize_bst(
    p_bst bst_ptr)
{
    if (bst_ptr == NULL)
        return UJASHO;

    bst_deinitialize_inner(bst_ptr->root);
    bst_ptr->root = NULL;
    return OK;
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
    binary_search_tree const *bst_ptr,
    TKey bst_key,
    TValue **bst_value_storage_ptr)
{
    p_bst_item current_node_ptr;
    int keys_comparison_result = 0;

    if (bst_ptr == NULL)
    {
        return UJASHO;
    }

    if (bst_value_storage_ptr == NULL)
    {
        return UJASHO;
    }

    current_node_ptr = bst_ptr->root;

    while (current_node_ptr != NULL)
    {
        keys_comparison_result = bst_ptr->keys_comparer(&bst_key, &current_node_ptr->key);

        if (keys_comparison_result == 0)
        {
            *bst_value_storage_ptr = &current_node_ptr->value;

            return OK;
        }

        current_node_ptr = keys_comparison_result > 0
            ? current_node_ptr->right_subtree
            : current_node_ptr->left_subtree;
    }

    return KEY_NOT_FOUND;
}

int dispose_from_bst(
    p_bst bst_ptr,
    TKey bst_key)
{
    pp_bst_item current_node_ptr, for_swap_node_ptr;
    p_bst_item temporary_node_ptr;
    int keys_comparison_result = 0;

    if (bst_ptr == NULL)
    {
        return UJASHO;
    }

    current_node_ptr = &bst_ptr->root;

    while (current_node_ptr != NULL)
    {
        keys_comparison_result = bst_ptr->keys_comparer(&bst_key, &(*current_node_ptr)->key);

        if (keys_comparison_result == 0)
        {
            if ((*current_node_ptr)->left_subtree != NULL &&
                (*current_node_ptr)->right_subtree != NULL)
            {
                for_swap_node_ptr = bst_ptr->disposal_strategy == swap_with_max_of_left_subtree
                                    ? &(*current_node_ptr)->left_subtree
                                    : &(*current_node_ptr)->right_subtree;
                while ((bst_ptr->disposal_strategy == swap_with_max_of_left_subtree
                        ? (*for_swap_node_ptr)->right_subtree
                        : (*for_swap_node_ptr)->left_subtree) != NULL)
                {
                    for_swap_node_ptr = bst_ptr->disposal_strategy == swap_with_max_of_left_subtree
                                        ? &(*for_swap_node_ptr)->right_subtree
                                        : &(*for_swap_node_ptr)->left_subtree;
                }

                swap((void *)&(*current_node_ptr)->key, (void *)&(*for_swap_node_ptr)->key, sizeof(TKey));
                swap((void *)&(*current_node_ptr)->value, (void *)&(*for_swap_node_ptr)->value, sizeof(TValue));

                current_node_ptr = for_swap_node_ptr;
            }

            if ((*current_node_ptr)->left_subtree == NULL &&
                (*current_node_ptr)->right_subtree == NULL)
            {
                free(*current_node_ptr);
                *current_node_ptr = NULL;
            }
            else
            {
                temporary_node_ptr = (*current_node_ptr)->left_subtree == NULL
                    ? (*current_node_ptr)->right_subtree
                    : (*current_node_ptr)->left_subtree;
                free(*current_node_ptr);
                *current_node_ptr = temporary_node_ptr;
            }

            return OK;
        }

        current_node_ptr = keys_comparison_result > 0
            ? &(*current_node_ptr)->right_subtree
            : &(*current_node_ptr)->left_subtree;
    }

    return KEY_NOT_FOUND;
}

void bst_prefix_traversion_inner(
    bst_item const* subtree,
    void (*callback)(TValue const *))
{
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
    void (*callback)(TValue const *))
{

}

int bst_postfix_traversion(
    bst const *bst_ptr,
    void (*callback)(TValue const *))
{

}

void bst_deinitialize_inner(p_bst_item subtree)
{
    if (subtree == NULL)
        return ;

    bst_deinitialize_inner(subtree->left_subtree);

    bst_deinitialize_inner(subtree->right_subtree);
    free(subtree);

}