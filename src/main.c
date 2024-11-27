#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#include "../include/recursion.h"
#include "../include/border_principle.h"

#define INPUT_ERROR (10)

#define __DEBUG1

// TODO: enum
// TODO: fork + exec

int allocation_demo(
    int argc,
    char *argv[],
    int **result);

int sum(int, int);

int demo1();

void demo2_foo(int *);
int demo2();

int demo3();

int demo4();

int demo5();

int demo6(
    int argc,
    char *argv[]);

int demo7(
    int argc,
    char *argv[]);

int demo8()
{
    int x = 1337;

    printf("%d %d", 20);

    return 0;
}

int files_demo(
    int argc,
    char *argv[])
{
    FILE *input_file, *output_file;
    char c;

    int x, y;

    y + x + 5;
    y = x = 5; // TODO: Fluent API

    if (!(input_file = fopen("input.txt", "r")))
    {
        // TODO: errno
        // TODO: handle file opening error!
    }

    if (!(output_file = fopen("output.txt", "w")))
    {
        // TODO: errno
        // TODO: handle file opening error!
        fclose(input_file);
        return 19;
    }

    // file reading loop with EOF handling
    while (!feof(input_file))
    {
        c = fgetc(input_file);

        // TODO: work with read symbol

        if (isdigit(c))
        {
            // TODO: logic o_O
        }
        else if (isalpha(c))
        {
            // TODO: logic o___O
        }
        if (c == EOF)
        {
            printf("%c", c);
        }

    }

    // file reading loop with EOF handling
    while ((c = fgetc(input_file)) != EOF)
    {

    }

    fclose(input_file);

    return 0;
}

int malloc_demo(
    int argc,
    char *argv[])
{


    return 0;
}

int gorner(
    char const *str,
    int base,
    int *result_placement);

int average(
    double *result_placement,
    int values_count,
    ...)
{
    double result = 0.0;
    va_list it;
    int i;

    va_start(it, values_count);

    for (i = 0; i < values_count; ++i)
    {
        result += va_arg(it, double);
    }

    va_end(it);

    *result_placement = result / values_count;

    return 0;
}

int compare_int_value(
    int const *value1,
    int const *value2)
{
    return *value1 - *value2;
}

#include "../include/array.h"

void printf_callback(
    T const *value_ptr)
{
    printf("%d ", *value_ptr);
}

int lexem_border_selector(
    char c)
{
    return isalpha(c);
}

int print_lexem_callback(
    char const *lexem)
{
    printf("Found lexem: \"%s\"\n", lexem);

    return 0;
}

int main(
    int argc,
    char *argv[])
{
    // printf("%d\n\n", sum('0', '0'));
    // return demo1();
    // return demo2();
    // return demo3();
    // return demo4();
    //return demo5();
    // return demo6(argc, argv);
    // return demo7(argc, argv);
    // return demo8();
    // double result;
    // switch (average(&result, 3, (double)1, (double)2, (double)3))
    // {
    //     case 0:
    //         printf("Average value == %lf", result);
    //         break;
    // }

    // return files_demo(argc, argv);

    // return malloc_demo(argc, argv);
    // return allocation_demo(argc, argv);

    char const *str = "abc1 75 %$a# , |";
    border_principle(str, isalnum, print_lexem_callback);

    return 0;

    int i, rand_generated;
    array instance;
    initialize_array(&instance);
    srand((unsigned)time(NULL));

    for (i = 0; i < 30; ++i)
    {
        rand_generated = rand() % 11 + 10;
        insert_into_array(&instance, &rand_generated, 0);
        forward_const_traversion_array(&instance, printf_callback);
        printf("\n");
    }

    int const value_to_dispose = 15;

    printf("After disposal of value %d operation:\n", value_to_dispose);
    dispose_from_array_by_value(&instance, &value_to_dispose, compare_int_value);
    forward_const_traversion_array(&instance, printf_callback);
    printf("\n");


    deinitialize_array(&instance);

    return 0;

    /*FILE *fout;
    int i, j;
    int **result_permutations = NULL;
    size_t result_permutations_count = 0;
    int const items_count = 13;

    srand((unsigned int)time(NULL));

    int *arr = (int *)malloc(items_count * sizeof(int));
    if (!arr)
    {
        printf("memory allocation error!11!1");

        return 1;
    }

    // [a...b] -> [0...b-a] + a -> rand() % (b - a + 1) + a

    for (i = 0; i < items_count; ++i)
    {
        // конгруэнтный линейный генератор псевдослучайных чисел
        arr[i] = rand() % 2001 - 1000;
    }

    if (!(fout = fopen("result.txt", "w")))
    {
        printf("Error opening file!!1!1");

        free(arr);

        return -1;
    }

    switch (permutations(arr, items_count, &result_permutations, &result_permutations_count, compare_int_value))
    {
        case LYUBLINO_OTRABOTALI:
            for (i = 0; i < result_permutations_count; ++i)
            {
                fprintf(fout, "Permutation #%d: [ ", i + 1);

                for (j = 0; j < items_count; ++j)
                {
                    fprintf(fout, "%d%s ", result_permutations[i][j], j == items_count - 1 ? "" : ",");
                }

                fprintf(fout, "]\n");

                free(result_permutations[i]);
            }

            // TODO: use vilka function =)

            free(result_permutations);

            break;
        case INVALID_PARAMETER_VALUE:
            printf("Invalid parameter value!");
            break;
        case EQUAL_VALUES_FOUND:
            printf("Found equal by passed comparer values!");
            break;
        case MEMORY_ALLOCATION_CANT_BE_PERFORMED:
            printf("Memory allocation error!");
            break;
    }

    fclose(fout);
    free(arr);

    return 0;*/
}

int sum(
    int left_summand,
    int right_summand)
{
    int result = left_summand + right_summand;

    return result;
}

int demo1()
{
    int sum_result = 0;
    int left_summand = 0, right_summand = 0;
    int x = printf("Hello, World!");
    printf(" x = %d\n", x);

    // == !=

    printf("Enter first summand (int value): ");
    if (scanf("%d", &left_summand) != 1)
    {
        printf("input error!");
        return INPUT_ERROR;
    }

    printf("Enter second summand (int value): ");
    if (scanf("%d", &right_summand) != 1)
    {
        printf("input error!");
        return INPUT_ERROR;
    }

    sum_result = sum(left_summand, right_summand);

    printf("%d\n", sum_result);
}

void demo2_foo(
    int *value_ptr)
{
    *value_ptr = 52;
}

int demo2()
{
    int value = 10;
    int *value_pointer;

    demo2_foo(value_pointer = &value);

    printf("value == %d\n", value);

    return 0;
}

int demo3()
{
    int const immutable_value = 10;
    int const immutable_value2 = 20;

    //int *value_ptr = &immutable_value;
    //value_ptr = &immutable_value2;

    //*value_ptr = 20;

    return 0;
}

int demo4()
{
    int const array_length = 15;
    int i = 0;
    int arr[array_length];

    for (i = 0; i < array_length; ++i)
    {
        // *(arr + i)
        // *(i + arr)
        printf("%d ", 2 + (i[arr] = i));
    }

    printf("\n");

    for (i = 0; i < array_length; ++i)
    {
        // *(arr + i)
        // *(i + arr)
        printf("%d ", arr[i]);
    }

    return 0;
}

int demo5()
{
    int i;
    char buf[BUFSIZ] = { 0 };

    printf("Input string value: ");
    scanf("%s", buf);

    printf("String length == %d\n\n", strlen(buf));

    for (i = 0; i < strlen(buf); ++i)
    {
        printf("%d ", (int const)buf[i]);
    }
    printf("\n%s", buf);

    return 0;
}

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

int demo6(
    int argc,
    char *argv[])
{
    char const *number_as_string = "102010";
    int const base = 2;
    int result;

    switch (gorner(number_as_string, base, &result))
    {
        case 0:
            printf("%s(%d) == %d(10)", number_as_string, base, result);
            break;
        case 1:
            printf("Invalid input string value!");
            break;
        case 2:
            printf("Invalid base value!");
            break;
        case 3:
            printf("Invalid result placement value!");
            break;
        default:
            printf("Undefined behavior o__O");
            break;
    }
}

int demo7(
    int argc,
    // char **argv
    char *argv[])
{
    int i;
    for (i = 0; i < argc; ++i)
    {
        printf("argv[%d] == \"%s\"\n", i, argv[i]);
    }

    if (argc < 8)
    {
        // TODO: add error handling
    }

    if (strlen(argv[7]) < 5)
    {
        // TODO: add error handling
    }

    printf("%c", argv[7][4]);

    return 0;
}

int allocation_demo(
    int argc,
    char *argv[],
    int **result)
{
    int *int_array = NULL;
    int *for_realloc;

    double memory_size = -0.6;
    printf("Memory size == %zu\n", memory_size);
    // TODO: memset, memcpy
    int_array = (int *)malloc(sizeof(int) * 20);
    // free(calloc(20, sizeof(int)));

    // for_realloc = (int *)realloc(int_array, 40 * sizeof(int));
    // if (for_realloc == NULL)
    // {
    //     free(int_array);
    // }

    char *p = "12345";
    char *dyn_str = (char *)malloc(sizeof(char) * (strlen(p) + 1));
    if (dyn_str == NULL)
    {
        // TODO: handle memory allocation error
    }
    dyn_str = p;
    strcpy(dyn_str, p);

    for_realloc = int_array;
    int_array = (int *)realloc(int_array, 40 * sizeof(int));
    if (int_array == NULL)
    {
        free(for_realloc);
    }

    printf("I'm still alive! ptr == %p\n", int_array);

    *result = int_array;

    printf("I'm still alive!\n");

    return 0;
}