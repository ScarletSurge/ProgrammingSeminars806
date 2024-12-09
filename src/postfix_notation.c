#include "../include/postfix_notation.h"

#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
#include <stdarg.h>

#include "../include/stack.h"
#include "../include/dynamic_array_of_char.h"

#define BINARY_SEARCH_FOUND 0
#define BINARY_SEARCH_NOT_FOUND 1

//
int gorner(
    char const *str,
    int base,
    int *result_placement)
{
    int result = 0;
    int is_negative = 0;

    if (str == NULL || !*str)
    {
        return 1;
    }

    if (*str == '-')
    {
#ifdef __DEBUG
        printf("пук среньк))0)0");
#endif
        ++str;
        is_negative = 1;

        if (!*str)
        {
            return 1;
        }
    }

    if (base < 2 || base > 36)
    {
        return 2;
    }

    if (result_placement == NULL)
    {
        return 3;
    }

    while (*str)
    {
        if (!isalnum(*str)) // TODO: remake this!!1!1
        {
            return 1;
        }

        result = result * base + (isdigit(*str)
                                  ? *str - '0'
                                  : tolower(*str) - 'a' + 10);

        ++str;
    }

    if (is_negative)
    {
        result = -result;
    }

    *result_placement = result;

    return 0;
}

int compare_operators(
    void const *first,
    void const *second)
{
    return (*((operator **)first))->representation - (*((operator **)second))->representation;
}

int binary_search_inner(
    void const *values,
    void const *value_to_find,
    size_t value_size,
    size_t left_bound_inclusive,
    size_t right_bound_exclusive,
    int (*comparer)(void const *, void const *),
    void **result_placement)
{
    size_t mediant_index;
    int comparison_result;

    if (left_bound_inclusive >= right_bound_exclusive)
    {
        return BINARY_SEARCH_NOT_FOUND;
    }

    mediant_index = (left_bound_inclusive + right_bound_exclusive) >> 1;
    comparison_result = comparer(value_to_find, (unsigned char *)values + (mediant_index * value_size));

    if (comparison_result == 0)
    {
        *result_placement = values + mediant_index;
        return BINARY_SEARCH_FOUND;
    }
    else if (comparison_result < 0)
    {
        right_bound_exclusive = mediant_index;
    }
    else
    {
        left_bound_inclusive = mediant_index + 1;
    }

    return binary_search_inner(values, value_to_find, value_size, left_bound_inclusive, right_bound_exclusive, comparer, result_placement);
}

int binary_search(
    void const *values,
    void const *value_to_find,
    size_t count,
    size_t value_size,
    int (*comparer)(void const *, void const *),
    void **result_placement)
{
    // TODO: validate args ._.

    return binary_search_inner(values, value_to_find, value_size, 0, count, comparer, result_placement);
}

int convert_to_postfix_notation(
    char const *infix_expression,
    int (*lexem_character_selector)(char c),
    int (*priority_mapper)(char c),
    char **postfix_expression)
{
    // TODO: validate arguments...

    char *ie = infix_expression, prev = ' ';
    size_t result_size = 16;
    stack operators;
    T for_stack_interaction = '(';
    dynamic_array_of_char result;
    char for_dynamic_array_interaction;

    initialize_dynamic_array_of_char(&result);
    initialize_stack(&operators);

    push_into_stack(&operators, &for_stack_interaction);

    while (1)
    {
        if (isdigit(*ie))
        {
            add_char_to_end_of_dynamic_array(&result, *ie);
        }
        else
        {
            if (lexem_character_selector(prev))
            {
                add_char_to_end_of_dynamic_array(&result, ' ');
            }

            switch (*ie)
            {
                case '(':
                    for_stack_interaction = *ie;
                    push_into_stack(&operators, &for_stack_interaction);
                    break;
                case ')':
                case '\0':
                    while (1)
                    {
                        switch (pop_from_stack(&operators, &for_stack_interaction))
                        {
                            // TODO: handle stack pop cases...
                        }

                        if ((char)for_stack_interaction == '(')
                        {
                            break;
                        }

                        add_char_to_end_of_dynamic_array(&result, (char)for_stack_interaction);
                        add_char_to_end_of_dynamic_array(&result, ' ');
                    }
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '%':
                case '^':
                case '~':
                    while (1)
                    {
                        top_from_stack(&operators, &for_stack_interaction);

                        if (priority_mapper((char)for_stack_interaction) < priority_mapper(*ie))
                        {
                            break;
                        }

                        pop_from_stack(&operators, &for_stack_interaction);

                        add_char_to_end_of_dynamic_array(&result, (char)for_stack_interaction);
                        add_char_to_end_of_dynamic_array(&result, ' ');
                    }
                    for_stack_interaction = (int)*ie;
                    push_into_stack(&operators, &for_stack_interaction);

                    // ~ - 3
                    // ^ - 2
                    // *, /, % - 1
                    // +, - - 0

                    break;
            }
        }

        if (!*ie)
        {
            break;
        }

        prev = *ie;
        ie++;
    }

    *(result.current - 1) = '\0';
    //add_char_to_end_of_dynamic_array(&result, '\0');
    squeeze_dynamic_array_of_char(&result);
    *postfix_expression = result.start;
    result.start = NULL;
    deinitialize_stack(&operators);
    deinitialize_dynamic_array_of_char(&result);

    return 0;
}

int calculate_postfix_expression(
    char const *postfix_expression,
    int *expression_result,
    size_t operators_count,
    ...)
{
    // TODO: validate arguments... o_O

    int i, left_operand, right_operand;
    operator **operators, current_operator, *current_operator_ptr = &current_operator, *found_operator_ptr = NULL;
    va_list arg;
    char const *pe = postfix_expression;
    char buf[BUFSIZ], *b = buf, prev = ' ';
    stack operands;

    if (!(operators = (operator **)malloc(sizeof(operator *) * operators_count)))
    {
        // TODO: handle me plz ._.
    }

    initialize_stack(&operands);

    va_start(arg, operators_count);

    for (i = 0; i < operators_count; ++i)
    {
        if (!(operators[i] = va_arg(arg, operator *)))
        {
            // TODO: handle
        }
    }

    va_end(arg);

    qsort((void *)operators, operators_count, sizeof(operator *), compare_operators);

    while (1)
    {
        if (isdigit(*pe))
        {
            *b++ = *pe;
        }
        else
        {
            if (isdigit(prev))
            {
                *b = 0;
                b = buf;
                switch (gorner(buf, 10, &right_operand))
                {
                    // TODO: handle statuses ._.
                }

                push_into_stack(&operands, &right_operand);
            }

            if (binary_search(operators, &current_operator_ptr, operators_count, sizeof(operator *), compare_operators, &found_operator_ptr) == BINARY_SEARCH_NOT_FOUND)
            {
                if (!*pe)
                {
                    top_from_stack(&operands, expression_result);

                    break;
                }

                // TODO: operator not found - handle me plz
            }

            switch (found_operator_ptr->type)
            {
                case unary:
                    pop_from_stack(&operands, &left_operand);
                    left_operand = found_operator_ptr->func(left_operand);
                    push_into_stack(&operands, &left_operand);
                    break;
                case binary:
                    pop_from_stack(&operands, &right_operand);
                    pop_from_stack(&operands, &left_operand);
                    left_operand = found_operator_ptr->func(left_operand, right_operand);
                    push_into_stack(&operands, &left_operand);
                    break;
            }
        }

        prev = *pe;
        pe++;
    }

    free(operators);
    deinitialize_stack(&operands);

    return 0;
}