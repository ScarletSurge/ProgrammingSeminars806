#include "../include/recursion.h"

#include <stdio.h>
#include <malloc.h>
#include <string.h>

// paging
int permutations(
    int *items,
    size_t items_count,
    int ***result_permutations,
    size_t *result_permutations_count,
    int (*equality_comparer)(int const *, int const *) /* callback */)
{
    int i, j;
    int *current_permutation = NULL;
    int *not_inserted_items = NULL;
    int **target_permutations = NULL;
    size_t permutations_count = 1;

    if (items == NULL ||
        result_permutations == NULL ||
        result_permutations_count == NULL ||
        equality_comparer == NULL)
    {
        return INVALID_PARAMETER_VALUE;
    }

    for (i = 0; i < items_count - 1; ++i)
    {
        for (j = i + 1; j < items_count; ++j)
        {
            if (!equality_comparer(items + i, items + j))
            {
                return EQUAL_VALUES_FOUND;
            }
        }
    }

    if (!(current_permutation = (int *)malloc(sizeof(int) * items_count)))
    {
        return MEMORY_ALLOCATION_CANT_BE_PERFORMED;
    }

    if (!(not_inserted_items = (int *)malloc(sizeof(int) * items_count)))
    {
        free(current_permutation);

        return MEMORY_ALLOCATION_CANT_BE_PERFORMED;
    }

    for (i = 2; i <= items_count; ++i)
    {
        permutations_count *= i;
    }

    if (!(target_permutations = (int **)malloc(sizeof(int *) * permutations_count)))
    {
        free(current_permutation);
        free(not_inserted_items);

        return MEMORY_ALLOCATION_CANT_BE_PERFORMED;
    }

    for (i = 0; i < permutations_count; ++i)
    {
        if (!(target_permutations[i] = (int *)malloc(sizeof(int) * items_count)))
        {
            for (j = 0; j < i; ++j)
            {
                free(target_permutations[j]);
            }

            free(target_permutations);
            free(not_inserted_items);
            free(current_permutation);

            return MEMORY_ALLOCATION_CANT_BE_PERFORMED;
        }
    }

    size_t result_permutations_index_to_insert_permutation = 0;

    memcpy(not_inserted_items, items, items_count * sizeof(int));

    switch (permutations_inner(items_count, current_permutation, 0, not_inserted_items, items_count, target_permutations, &result_permutations_index_to_insert_permutation))
    {

    }

    free(current_permutation);
    free(not_inserted_items);

    *result_permutations = target_permutations;
    *result_permutations_count = permutations_count;

    return LYUBLINO_OTRABOTALI;
}

int permutations_inner(
    size_t items_count,
    int *current_permutation,
    size_t current_permutation_to_insert_index,
    int *not_inserted_items,
    size_t not_inserted_items_count,
    int * const *result_permutations,
    size_t *result_permutations_index_to_insert_permutation)
{
    // TODO: parameters validation - You can do it :)

    int not_inserted_item_index;

    // if (current_permutation_to_insert_index == items_count)
    if (not_inserted_items_count == 0)
    {
        // permutation is ready to be copied to result

        memcpy(result_permutations[*result_permutations_index_to_insert_permutation], current_permutation,
               sizeof(int) * items_count);
        ++*result_permutations_index_to_insert_permutation;

        return LYUBLINO_OTRABOTALI;
    }

    for (not_inserted_item_index = 0; not_inserted_item_index < not_inserted_items_count; ++not_inserted_item_index)
    {
        current_permutation[current_permutation_to_insert_index] = not_inserted_items[not_inserted_item_index];

        memcpy(not_inserted_items + not_inserted_item_index, not_inserted_items + not_inserted_item_index + 1, (not_inserted_items_count - not_inserted_item_index - 1) * sizeof(int));

        switch (permutations_inner(items_count, current_permutation, current_permutation_to_insert_index + 1, not_inserted_items, not_inserted_items_count - 1, result_permutations, result_permutations_index_to_insert_permutation))
        {
            case LYUBLINO_OTRABOTALI:
                // TODO: тут типа чёто есть =)
                break;
        }

        memcpy(not_inserted_items + not_inserted_item_index + 1, not_inserted_items + not_inserted_item_index, (not_inserted_items_count - not_inserted_item_index - 1) * sizeof(int));

        not_inserted_items[not_inserted_item_index] = current_permutation[current_permutation_to_insert_index];
    }

    return LYUBLINO_OTRABOTALI;
}