#ifndef PROGRAMMINGSEMINARS_BINARY_SEARCH_TREE_H
#define PROGRAMMINGSEMINARS_BINARY_SEARCH_TREE_H

#include <corecrt.h>

typedef int TKey;
typedef int TValue;

typedef struct binary_search_tree_item
{
    TKey key;
    TValue value;
    struct binary_search_tree_item *left_subtree;
    struct binary_search_tree_item *right_subtree;
} binary_search_tree_item, *p_binary_search_tree_item;

typedef int (*keys_comparer)(TKey const *, TKey const *);

typedef struct binary_search_tree
{
    keys_comparer comparer;
    p_binary_search_tree_item root;
} binary_search_tree, *p_binary_search_tree;

int allocate_then_construct_bst_item(
    TKey key,
    TValue value,
    p_binary_search_tree_item *result);

int create_bst(
    p_binary_search_tree to_create,
    keys_comparer comparer);

int bst_insert_value_recursive_kernel(
    keys_comparer comparer,
    p_binary_search_tree_item *node_address,
    TKey key,
    TValue value);

int bst_insert_value_recursive(
    p_binary_search_tree to_insert_into,
    TKey key,
    TValue value);

int bst_insert_value_iterative(
    p_binary_search_tree to_insert_into,
    TKey key,
    TValue value);

#endif //PROGRAMMINGSEMINARS_BINARY_SEARCH_TREE_H