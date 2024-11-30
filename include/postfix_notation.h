#ifndef UNTITLED1_POSTFIX_NOTATION_H
#define UNTITLED1_POSTFIX_NOTATION_H

#include <corecrt.h>

typedef enum operator_type
{
    unary,
    binary
} operator_type;

typedef struct operator
{
    char representation;
    operator_type type;
    int (*func)(int, ...);
    // int (*func)(int *, ...);
} operator;

int convert_to_postfix_notation(
    char const *infix_expression,
    int (*lexem_character_selector)(char c),
    int (*priority_mapper)(char c),
    char **postfix_expression);

int calculate_postfix_expression(
    char const *postfix_expression,
    int *expression_result,
    size_t operators_count,
    ...);

#endif //UNTITLED1_POSTFIX_NOTATION_H