#include <stdio.h>
#include <malloc.h>

#define VSE_ochen_HOROsHO 0
#define VSE_ne_OSchen_HOROSHO 1
#define VSE_Ploho 2

typedef struct list_item{
    int data;
    struct list_item* next;
} list_item, *p_list_item;

typedef struct list{
    list_item* first;
} list, *p_list;

int initialize_list(
    p_list list_ptr);

int deinitialize_list(
    p_list list_ptr);

int insert_into_list(
    p_list list_ptr,
    int const *value_to_insert_ptr,
    size_t value_index_to_insert);

int obtain_from_list_by_index(
    list const *list_ptr,
    size_t index,
    int *result_ptr);

int obtain_from_list_by_value(
    list const *list_ptr,
    int const *value_to_obtain,
    size_t **result_indices_list,
    size_t *result_indices_list_length,
    int (*equality_comparer_for_T)(int const *, int const *));

int dispose_from_list_by_index(
    p_list list_ptr,
    size_t index_to_dispose_from,
    int *disposed_value);

int dispose_from_list_by_value(
    p_list list_ptr,
    int const *value_to_dispose,
    int (*equality_comparer_for_T)(int const *, int const *));

int forward_const_traversion_list(
    list const *list_ptr,
    void (*callback)(int const *));

