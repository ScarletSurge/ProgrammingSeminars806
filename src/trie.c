#include "../include/trie.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UJASHO 666
#define OK 0

int initialize_trie_item(
    trie const *trie,
    p_trie_item to_initialize,
    tvalue const *value)
{
    int i;

    if (trie == NULL || to_initialize == NULL)
    {
        // TODO: handle error
    }

    if (!(to_initialize->subtrees = (p_trie_item *)malloc(sizeof(p_trie_item) * trie->alphabet_size)))
    {
        // TODO: handle error
    }

    if (value == NULL)
    {
        to_initialize->value = (tvalue *)NULL;
    }
    else
    {
        if (!(to_initialize->value = (tvalue *)malloc(sizeof(tvalue))))
        {
            // TODO: handle error
            free(to_initialize->subtrees);
            to_initialize->subtrees = NULL;
        }
    }

    for (i = 0; i < trie->alphabet_size; ++i)
    {
        to_initialize->subtrees[i] = (p_trie_item)NULL;
    }

    if (value != NULL)
    {
        memcpy(to_initialize->value, value, sizeof(tvalue));
    }

    return OK;
}

int create_trie_item(
    trie const *trie,
    tvalue const *value,
    p_trie_item *created_item_placement)
{
    if (created_item_placement == NULL)
    {
        // TODO: handle error
    }

    if (!(*created_item_placement = (p_trie_item)malloc(sizeof(trie_item))))
    {
        // TODO: handle error
        return UJASHO;
    }

    switch (initialize_trie_item(trie, *created_item_placement, value))
    {
        case UJASHO:
            free(*created_item_placement);
            *created_item_placement = NULL;
            return UJASHO;
    }

    return OK;
}

int char_comparer(
    void const *a,
    void const *b)
{
    return *((char const *)a) - *((char const *)b);
}

int initialize_trie(
    p_trie to_initialize,
    char const *alphabet)
{
    int i;
    char *alphabet_for_trie;

    // string.h - strcmp
    if (to_initialize == NULL || alphabet == NULL || !*alphabet)
    {
        // TODO: handle error
    }

    size_t alphabet_size = strlen(alphabet);
    if ((alphabet_for_trie = (char *)malloc(sizeof(char) * alphabet_size)) == NULL)
    {
        // TODO: handle memory allocation error
    }

    memcpy((void *)alphabet_for_trie, alphabet, sizeof(char) * alphabet_size);
    qsort((void *)alphabet_for_trie, alphabet_size, sizeof(char), char_comparer);

    for (i = 0; i < alphabet_size - 1; ++i)
    {
        if (alphabet[i] == alphabet[i + 1])
        {
            free(alphabet_for_trie);
            return UJASHO;
        }
    }

    to_initialize->alphabet=alphabet_for_trie;
    to_initialize->alphabet_size=alphabet_size;
    switch (create_trie_item(to_initialize, NULL, &to_initialize->root))
    {
        case UJASHO:
            // TODO:
            free(to_initialize->alphabet);
            to_initialize->alphabet = NULL;
            break;
    }

    return OK;
}

int deinitialize_trie_inner(
    trie const *trie,
    p_trie_item item_to_dispose)
{
    // if (trie == NULL)
    // {
    //     // TODO: handle error
    // }

    int i;

    if (item_to_dispose == NULL)
    {
        return OK;
    }

    for (i = 0; i < trie->alphabet_size; ++i)
    {
        deinitialize_trie_inner(trie, item_to_dispose->subtrees[i]);
    }

    free(item_to_dispose->subtrees);
    free(item_to_dispose->value);
    free(item_to_dispose);

    return OK;
}

int deinitialize_trie(
    p_trie to_deinitialize)
{
    if (to_deinitialize == NULL)
    {
        // TODO: handle error
    }

    free(to_deinitialize->alphabet);
    to_deinitialize->alphabet = NULL;

    return deinitialize_trie_inner(to_deinitialize, to_deinitialize->root);
}

int insert_into_trie(
    p_trie to_insert_into,
    char const *key,
    tvalue const *value)
{

}

int obtain_from_trie(
    trie const *to_obtain_from,
    char const *key,
    tvalue **value_ptr_placement)
{

}

int dispose_from_trie(
    p_trie to_dispose_from,
    char const *key,
    tvalue *value_placement)
{

}