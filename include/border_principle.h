#ifndef UNTITLED1_BORDER_PRINCIPLE_H
#define UNTITLED1_BORDER_PRINCIPLE_H

#include <stdio.h>

int border_principle(
    char const *buf,
    int (*lexem_character_selector)(char c),
    int (*lexem_action)(char const *lexem))
{
    char lexem_buf[BUFSIZ], *lb = lexem_buf, c, c_ = ' ';
    char const *b = buf;
    int selector_result;

    // TODO: validate input parameters ._.

    while (1)
    {
        c = *b;
        selector_result = lexem_character_selector(c);

        if (selector_result)
        {
            *lb = c;
            lb++;
        }
        else if (lexem_character_selector(c_))
        {
            *lb = '\0';
            lb = lexem_buf;
            switch (lexem_action(lexem_buf))
            {
                // TODO:
            }
        }

        if (!c)
        {
            break;
        }

        c_ = c;
        ++b;
    }

    return 0;
}

#endif //UNTITLED1_BORDER_PRINCIPLE_H