#ifndef PROGRAMMINGSEMINARS_STACK_H
#define PROGRAMMINGSEMINARS_STACK_H

#include "array.h"

#define OK 0
#define UJASHO 1

typedef struct stack
{
    array inner_array;
} stack, *p_stack;

int initialize_stack(
    p_stack stack_ptr);

int deinitialize_stack(
    p_stack stack_ptr);

int push_into_stack(
    p_stack stack_ptr,
    T const *value_to_insert_ptr);

int top_from_stack(
    stack const *stack_ptr,
    T *result_ptr);

int pop_from_stack(
    p_stack stack_ptr,
    T *disposed_value);

#endif