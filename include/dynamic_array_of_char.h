#ifndef BORDER_PRINCIPLE_DYNAMIC_ARRAY_OF_CHAR_H
#define BORDER_PRINCIPLE_DYNAMIC_ARRAY_OF_CHAR_H

//
typedef struct dynamic_array_of_char
{
    // array pointer
    char *start;

    // pointer to memory cell to store next element to be add
    char *current;

    // current degree of 2, this is size of dynamic array
    int current_degree_of_2;
} dynamic_array_of_char, *p_dynamic_array_of_char;

int initialize_dynamic_array_of_char(p_dynamic_array_of_char);
int add_char_to_end_of_dynamic_array(p_dynamic_array_of_char, char);
int squeeze_dynamic_array_of_char(p_dynamic_array_of_char);
int deinitialize_dynamic_array_of_char(p_dynamic_array_of_char);

#endif //BORDER_PRINCIPLE_DYNAMIC_ARRAY_OF_CHAR_H