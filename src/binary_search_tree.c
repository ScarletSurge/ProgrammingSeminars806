#include "..\include\binary_search_tree.h"

#include <stdio.h>
#include <malloc.h>

int allocate_then_construct_bst_item(
    TKey key,
    TValue value,
    p_binary_search_tree_item *result)
{
    // TODO: validate input parameters

    if (!(*result = (p_binary_search_tree_item)malloc(sizeof(binary_search_tree_item))))
    {
        // TODO: handle memory allocation error
    }

    (*result)->key = key;
    (*result)->value = value;
    (*result)->left_subtree = (*result)->right_subtree = NULL;

    // TODO: You can obmazatj this with macro :)
    return 0;
}

int create_bst(
    p_binary_search_tree to_create,
    keys_comparer comparer)
{
    // TODO: validate input parameters

    to_create->root = NULL;
    to_create->comparer = comparer;
}

int bst_insert_value_recursive_kernel(
    keys_comparer comparer,
    p_binary_search_tree_item *node_address,
    TKey key,
    TValue value)
{
    int comparison_result = 0;

    // TODO: validate input parameters

    if (*node_address == NULL)
    {
        switch (allocate_then_construct_bst_item(key, value, node_address))
        {
            case 0:
                // handle states plz :/
                break;
        }

        // TODO: You can obmazatj this with macro :)
        return 0;
    }

    if ((comparison_result = comparer(&key, &(*node_address)->key)) == 0)
    {
        // TODO: upsert or raise error

        return 0;
    }

    return bst_insert_value_recursive_kernel(comparer, comparison_result < 0
        ? &(*node_address)->left_subtree
        : &(*node_address)->right_subtree, key, value);
}

int bst_insert_value_recursive(
    p_binary_search_tree to_insert_into,
    TKey key,
    TValue value)
{
    // TODO: validate input parameters

    return bst_insert_value_recursive_kernel(to_insert_into->comparer, &to_insert_into->root, key, value);
}

int bst_insert_value_iterative(
    p_binary_search_tree to_insert_into,
    TKey key,
    TValue value)
{
    int comparison_result = 0;

    // TODO: validate input parameters

    p_binary_search_tree_item *almost_iterator = &to_insert_into->root;

    while (*almost_iterator != NULL)
    {
        if ((comparison_result = to_insert_into->comparer(&key, &(*almost_iterator)->key)) == 0)
        {
            break;
        }

        almost_iterator = comparison_result < 0
            ? &(*almost_iterator)->left_subtree
            : &(*almost_iterator)->right_subtree;
    }

    if (*almost_iterator != NULL)
    {
        // TODO: upsert or raise error

        return 0;
    }

    switch (allocate_then_construct_bst_item(key, value, almost_iterator))
    {
        case 0:
            // handle states plz :/
            break;
    }

    // TODO: You can obmazatj this with macro :)
    return 0;
}