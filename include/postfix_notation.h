#ifndef UNTITLED1_POSTFIX_NOTATION_H
#define UNTITLED1_POSTFIX_NOTATION_H

int convert_to_postfix_notation(
    char const *infix_expression,
    int (*priority_mapper)(char c),
    char **postfix_expression);

#endif //UNTITLED1_POSTFIX_NOTATION_H