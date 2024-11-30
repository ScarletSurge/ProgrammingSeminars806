#include "../include/dynamic_array_of_char.h"
#include <stdlib.h>

int initialize_dynamic_array_of_char(
    p_dynamic_array_of_char target)
{
    if (!target)
    {
        // TODO
        return -1;
    }

    target->current_degree_of_2 = 4;

    target->start = (char *)malloc(sizeof(char) * (1 << target->current_degree_of_2));
    if (!target->start)
    {
        // TODO: handle memory reallocation error
        return -2;
    }

    target->current = target->start;

    return 0;
}

// addition of new char with amortized complexity O(1)
int add_char_to_end_of_dynamic_array(
    p_dynamic_array_of_char target,
    char c)
{
    char *reallocated;

    if (!target)
    {
        // TODO
        return -1;
    }

    if ((target->current - target->start) == (1 << target->current_degree_of_2))
    {
        reallocated = (char*)realloc(target->start, sizeof(char) * (1 << (target->current_degree_of_2 + 1)));
        if (!reallocated)
        {
            // TODO: handle memory reallocation error
            return -2;
        }

        target->current = (target->start = reallocated) + sizeof(char) * (1 << target->current_degree_of_2++);
    }

    *(target->current)++ = c;

    return 0;
}

int squeeze_dynamic_array_of_char(
    p_dynamic_array_of_char target)
{
    char* reallocated = (char*)realloc(target->start, sizeof(char) * (target->current - target->start));
    if (!reallocated)
    {
        // TODO: handle memory reallocation error
        return -1;
    }

    target->start = reallocated;

    return 0;
}

int deinitialize_dynamic_array_of_char(
    p_dynamic_array_of_char target)
{
    free(target->start);

    return 0;
}