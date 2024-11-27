#include "../include/stack.h"

int initialize_stack(
    p_stack stack_ptr)
{
    if (stack_ptr == NULL)
    {
        return UJASHO;
    }

    return initialize_array(&stack_ptr->inner_array);
}

int deinitialize_stack(
    p_stack stack_ptr)
{
    if (stack_ptr == NULL)
    {
        return UJASHO;
    }

    return deinitialize_array(&stack_ptr->inner_array);
}

int push_into_stack(
    p_stack stack_ptr,
    T const *value_to_insert_ptr)
{
    if (stack_ptr == NULL || value_to_insert_ptr == NULL)
    {
        return UJASHO;
    }

    return insert_into_array(&stack_ptr->inner_array, value_to_insert_ptr, stack_ptr->inner_array.virtual_count);
}

int top_from_stack(
    stack const *stack_ptr,
    T *result_ptr)
{
    if (stack_ptr == NULL || result_ptr == NULL)
    {
        return UJASHO;
    }

    return obtain_from_array_by_index(&stack_ptr->inner_array, stack_ptr->inner_array.virtual_count - 1, result_ptr);
}

int pop_from_stack(
    p_stack stack_ptr,
    T *disposed_value)
{
    if (stack_ptr == NULL || disposed_value == NULL)
    {
        return UJASHO;
    }

    return dispose_from_array_by_index(&stack_ptr->inner_array, stack_ptr->inner_array.virtual_count - 1, disposed_value);
}