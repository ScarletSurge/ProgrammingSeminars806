#ifndef UNTITLED1_TRIE_H
#define UNTITLED1_TRIE_H

#include <corecrt.h>

typedef int tvalue;

typedef struct trie_item
{
    tvalue *value;
    struct trie_item **subtrees;
} trie_item, *p_trie_item;

// трие
typedef struct trie
{
    char *alphabet;
    size_t alphabet_size;
    p_trie_item root;
} trie, *p_trie;

int initialize_trie(
    p_trie to_initialize,
    char const *alphabet);

int deinitialize_trie(
    p_trie to_deinitialize);

int insert_into_trie(
    p_trie to_insert_into,
    char const *key,
    tvalue const *value);

int obtain_from_trie(
    trie const *to_obtain_from,
    char const *key,
    tvalue **value_ptr_placement);

int dispose_from_trie(
    p_trie to_dispose_from,
    char const *key,
    tvalue *value_placement);

#endif //UNTITLED1_TRIE_H