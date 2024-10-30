#ifndef UNTITLED1_ARRAY_H
#define UNTITLED1_ARRAY_H

#include <stdio.h>

typedef int T;

typedef struct array
{
    T *first_element;
    size_t capacity;
    size_t virtual_count;
} array, *p_array;

int initialize_array(
    p_array array_ptr);

int insert_into_array(
    p_array array_ptr,
    T *value_to_insert_ptr,
    size_t value_index_to_insert);

int deinitialize_array(
    p_array array_ptr);

int forward_const_traversion_array(
    array const *array_ptr,
    void (*callback)(T const *));

#endif //UNTITLED1_ARRAY_H