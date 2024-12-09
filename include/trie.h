#ifndef UNTITLED1_TRIE_H
#define UNTITLED1_TRIE_H

#include <corecrt.h>

typedef int tvalue;

typedef struct trie_item
{
    //unsigned char end_flag: 1;

    struct trie_item **subtrees;
} trie_item, *p_trie_item;

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
    char const *to_insert);

#endif //UNTITLED1_TRIE_H