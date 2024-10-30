#include "../include/array.h"

#include <malloc.h>
#include <string.h>

#define OK 0
#define MEMORY_ALLOCATION_ERROR 1

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

int insert_into_array(
    p_array array_ptr,
    T *value_to_insert_ptr,
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