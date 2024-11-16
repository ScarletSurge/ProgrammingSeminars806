#ifndef PROGRAMMINGSEMINARS_BINARY_SEARCH_TREE_H
#define PROGRAMMINGSEMINARS_BINARY_SEARCH_TREE_H

typedef int TKey;
typedef int TValue;
typedef int (*comparer)(TKey const*, TKey const*);
typedef void (*value_handle_callback)(TValue const *);


typedef struct bst_item
{
    TKey key;
    TValue value;
    struct bst_item* left_subtree;
    struct bst_item* right_subtree;


} bst_item, *p_bst_item, **pp_bst_item;

typedef struct binary_search_tree {
    p_bst_item root;
    comparer keys_comparer;
} binary_search_tree, bst, *p_bst;

int initialize_bst(
    p_bst bst_ptr,
    comparer keys_comparer);

int deinitialize_bst(
    p_bst bst_ptr);

int insert_into_bst(
    p_bst bst_ptr,
    TKey bst_key,
    TValue const *value_to_insert_ptr);

int obtain_from_bst(
    p_bst const *bst_ptr,
    TKey bst_key,
    TValue ** bst_value);

int dispose_from_bst(
    p_bst *bst_ptr,
    TKey bst_key);

void bst_prefix_traversion_inner(
    bst_item const* subtree,
    value_handle_callback callback);

int bst_prefix_traversion(
    bst const *bst_ptr,
    value_handle_callback callback);

int bst_infix_traversion(
    bst const *bst_ptr,
    value_handle_callback callback);

int bst_postfix_traversion(
    bst const *bst_ptr,
    value_handle_callback callback);

#endif //PROGRAMMINGSEMINARS_BINARY_SEARCH_TREE_H