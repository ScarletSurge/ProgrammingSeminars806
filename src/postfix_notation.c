#include "../include/postfix_notation.h"

#include <stdio.h>
#include <malloc.h>
#include <ctype.h>

int convert_to_postfix_notation(
    char const *infix_expression,
    int (*lexem_character_selector(char c),
    int (*priority_mapper)(char c),
    char **postfix_expression)
{
    // TODO: validate arguments...

    char *result, *r, *ie = infix_expression, prev = ' ';
    size_t result_size = 16;

    if (!(r = result = (char *)malloc(sizeof(char) * result_size)))
    {
        return UJASHO;
    }

    while (!*ie)
    {
        if (isdigit(*ie))
        {
            *r++ = *ie++;
        }
        else
        {
            if (lexem_character_selector(prev))
            {
                *r++ = ' ';
            }

            switch (*ie)
            {
                case '(':

                    break;
                case ')':

                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '%':
                case '^':
                case '~':

                    break;
            }
        }
    }

    *postfix_expression = result;
}