#ifndef UNTITLED1_ARRAY_H
#define UNTITLED1_ARRAY_H

#include <stdio.h>

typedef int T;

#define OBTAINING_BY_NONEXISTENT_INDEX 2

typedef struct array
{
    T *first_element;
    size_t capacity;
    size_t virtual_count;
} array, *p_array;

int initialize_array(
    p_array array_ptr);

int deinitialize_array(
    p_array array_ptr);

int insert_into_array(
    p_array array_ptr,
    T const *value_to_insert_ptr,
    size_t value_index_to_insert);

int obtain_from_array_by_index(
    array const *array_ptr,
    size_t index,
    T *result_ptr);

int obtain_from_array_by_value_first_implementation(
    array const *array_ptr,
    T const *value_to_obtain,
    size_t **result_indices_array,
    size_t *result_indices_array_length,
    int (*equality_comparer_for_T)(T const *, T const *));

int obtain_from_array_by_value_second_implementation(
    array const *array_ptr,
    T const *value_to_obtain,
    size_t **result_indices_array,
    size_t *result_indices_array_length,
    int (*equality_comparer_for_T)(T const *, T const *));

int dispose_from_array_by_index(
    p_array array_ptr,
    size_t index_to_dispose_from,
    T *disposed_value);

int dispose_from_array_by_value(
    p_array array_ptr,
    T const *value_to_dispose,
    int (*equality_comparer_for_T)(T const *, T const *));

int forward_const_traversion_array(
    array const *array_ptr,
    void (*callback)(T const *));

#endif //UNTITLED1_ARRAY_H