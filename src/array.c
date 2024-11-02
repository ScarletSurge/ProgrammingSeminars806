#include "../include/array.h"

#include <malloc.h>
#include <string.h>

#define OK 0
#define MEMORY_ALLOCATION_ERROR 1
#define INVALID_PARAMETER_VALUE 2

int initialize_array(
    p_array array_ptr)
{
    if (array_ptr == NULL)
    {
        // TODO: handle error
    }

    array_ptr->capacity = 16;
    if (!(array_ptr->first_element = (T *)malloc(sizeof(T) * array_ptr->capacity)))
    {
        return MEMORY_ALLOCATION_ERROR;
    }

    array_ptr->virtual_count = 0;

    return OK;
}

int deinitialize_array(
    p_array array_ptr)
{
    if (array_ptr == NULL)
    {
        // TODO: handle error
    }

    free(array_ptr->first_element);
    array_ptr->first_element = NULL;
    array_ptr->capacity = 16;
    array_ptr->virtual_count = 0;

    return OK;
}

int insert_into_array(
    p_array array_ptr,
    T const *value_to_insert_ptr,
    size_t value_index_to_insert)
{
    T *for_realloc;

    if (array_ptr == NULL || value_to_insert_ptr)
    {
        // TODO: handle error
    }

    if (array_ptr->capacity == array_ptr->virtual_count)
    {
        if (!(for_realloc = (T *)realloc(array_ptr->first_element, sizeof(T) * (array_ptr->capacity << 1))))
        {
            return MEMORY_ALLOCATION_ERROR;
        }

        array_ptr->first_element = for_realloc;
        array_ptr->capacity <<= 1;
    }

    memcpy(array_ptr->first_element + value_index_to_insert + 1, array_ptr->first_element + value_index_to_insert,
           sizeof(T) * (array_ptr->virtual_count++ - value_index_to_insert));

    array_ptr->first_element[value_index_to_insert] = *value_to_insert_ptr;

    return OK;
}

int obtain_from_array_by_index(
    array const *array_ptr,
    size_t index,
    T *result_ptr)
{
    // TODO: validate parameters

    *result_ptr = array_ptr->first_element[index];

    return OK;
}

int obtain_from_array_by_value_first_implementation(
    array const *array_ptr,
    T const *value_to_obtain,
    size_t **result_indices_array,
    size_t *result_indices_array_length,
    int (*equality_comparer_for_T)(T const *, T const *))
{
    int i, entries_count = 0, entry_id = 0;

    // TODO: validate parameters

    for (i = 0; i < array_ptr->virtual_count; ++i)
    {
        if (!equality_comparer_for_T(value_to_obtain, array_ptr->first_element + i))
        {
            ++entries_count;
        }
    }

    if (!(*result_indices_array = (size_t *)malloc(sizeof(size_t) * entries_count)))
    {
        // TODO: You can do it!

        return MEMORY_ALLOCATION_ERROR;
    }

    for (i = 0; i < array_ptr->virtual_count; ++i)
    {
        if (equality_comparer_for_T(value_to_obtain, array_ptr->first_element + i))
        {
            continue;
        }

        (*result_indices_array)[entry_id++] = i;
    }

    *result_indices_array_length = entries_count;

    return OK;
}

int obtain_from_array_by_value_second_implementation(
    array const *array_ptr,
    T const *value_to_obtain,
    size_t **result_indices_array,
    size_t *result_indices_array_length,
    int (*equality_comparer_for_T)(T const *, T const *))
{
    int i, index;
    array indices;

    initialize_array(&indices);

    // TODO: validate parameters

    for (i = 0; i < array_ptr->virtual_count; ++i)
    {
        if (!equality_comparer_for_T(value_to_obtain, array_ptr->first_element + i))
        {
            insert_into_array(&indices, &i, indices.virtual_count);
        }
    }

    if (!(*result_indices_array = (size_t *)malloc(indices.virtual_count * sizeof(size_t))))
    {
        // TODO: handle

        return MEMORY_ALLOCATION_ERROR;
    }

    for (i = 0; i < indices.virtual_count; ++i)
    {
        obtain_from_array_by_index(&indices, i, &index);

        (*result_indices_array)[i] = index;
    }

    *result_indices_array_length = indices.virtual_count;

    deinitialize_array(&indices);

    return OK;
}

int dispose_from_array_by_index(
    p_array array_ptr,
    size_t index_to_dispose_from,
    T *disposed_value)
{
    if (array_ptr == NULL || index_to_dispose_from >= array_ptr->virtual_count || disposed_value == NULL)
    {
        return INVALID_PARAMETER_VALUE;
    }

    switch (obtain_from_array_by_index(array_ptr, index_to_dispose_from, disposed_value))
    {
        //TODO: switch result
    }

    memcpy(array_ptr->first_element+index_to_dispose_from,array_ptr->first_element+index_to_dispose_from + 1, (array_ptr->virtual_count - index_to_dispose_from - 1) * sizeof (T));

    --array_ptr->virtual_count;

    return OK;
}

int dispose_from_array_by_value(
    p_array array_ptr,
    T const *value_to_dispose,
    int (*equality_comparer_for_T)(T const *, T const *))
{
    size_t gm;
    size_t* gh;
    int count;
    int not_used;
    if (array_ptr == NULL || value_to_dispose == NULL || equality_comparer_for_T == NULL){
        return INVALID_PARAMETER_VALUE;
    }
    obtain_from_array_by_value_second_implementation(array_ptr, value_to_dispose, &gh, &gm, equality_comparer_for_T);
    for(count=gm-1; count>=0; --count){
        dispose_from_array_by_index(array_ptr, gh[count], &not_used);
    } return OK;


}

int forward_const_traversion_array(
    array const *array_ptr,
    void (*callback)(T const *))
{
    int i;

    // TODO: validations

    for (i = 0; i < array_ptr->virtual_count; ++i)
    {
        callback(array_ptr->first_element + i);
    }

    return OK;
}