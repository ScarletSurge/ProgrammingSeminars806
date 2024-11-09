#include "../include/unidirectional_list.h"

int initialize_list(
    p_list list_ptr){
    if (list_ptr==NULL){
        return 1;
    }
    list_ptr->first = NULL;
    return 0;
}

int deinitialize_list(
    p_list list_ptr){

    list_item* run;
    list_item* nur;
    if(list_ptr == NULL){
        return 1;
    }

    run = list_ptr->first;
    nur = run;

    while(run == NULL){
        run = run->next;
        free(nur);
        nur = run;
    }
    list_ptr->first = NULL;
    return 0;
}

int insert_into_list(
    p_list list_ptr,
    int const *value_to_insert_ptr,
    size_t value_index_to_insert)
{
    if (list_ptr == NULL)
    {
        return 1;
    }

    if (value_to_insert_ptr == NULL)
    {
        return 2;
    }

    if (value_index_to_insert == 0)
    {
        list_item* new_item = (list_item*)malloc(sizeof(list_item));

        if (new_item == NULL)
        {
            return 3;
        }

        new_item->next = list_ptr->first;

        new_item->data = *value_to_insert_ptr;

        list_ptr->first = new_item;

        return 0;
    }
    else
    {
        int i;
        p_list_item current_item = list_ptr->first;

        for (i = 0; i < value_index_to_insert - 1; ++i)
        {
            current_item = current_item->next;

            if (current_item == NULL)
            {
                return 4;
            }
        }

        p_list_item new_item = (list_item*)malloc(sizeof(list_item));

        if (new_item == NULL)
        {
            return 3;
        }

        new_item->next = current_item->next;

        new_item->data = *value_to_insert_ptr;

        current_item->next = new_item;
    }

    return 0;
}

int obtain_from_list_by_index(
    list const *list_ptr,
    size_t index,
    int *result_ptr){
    int i;
    p_list_item current=list_ptr->first;
    if (list_ptr==NULL){
        return 1;
    }
    if (result_ptr==NULL){
        return 3;
    }
    for (i=0;i!=index;i++){
        if (current==NULL){
            return 2;
        }
        current=current->next;
    }
    if (current==NULL){
        return 2;
    }
    *result_ptr=current->data;
    return 0;
}

int obtain_from_list_by_value(
    list const *list_ptr,
    int const *value_to_obtain,
    size_t **result_indices_list,
    size_t *result_indices_list_length,
    int (*equality_comparer_for_T)(int const *, int const *))
{

}

int dispose_from_list_by_index(
    p_list list_ptr,
    size_t index_to_dispose_from,
    int *disposed_value)
{
    int i;
    p_list_item temp = NULL, item_to_delete = NULL;
    if (disposed_value == NULL || list_ptr == NULL) {
        return 1;
    }

    if (list_ptr->first == NULL)
    {
        return 2;
    }

    if (index_to_dispose_from == 0) {
        temp = list_ptr->first->next;
        free(list_ptr->first);
        list_ptr->first = temp;
        return 0;
    }
    temp = list_ptr->first;
    for (i = 0; i < index_to_dispose_from - 1; ++i)
    {
        if (temp == NULL)
        {
            return 2;
        }
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
    {
        return 3;
    }
    *disposed_value = (item_to_delete = temp->next)->data;
    temp->next = temp->next->next; // :)
    free(item_to_delete);
    return 0;
}

int dispose_from_list_by_value(
    p_list list_ptr,
    int const *value_to_dispose,
    int (*equality_comparer_for_T)(int const *, int const *))
{
    if (list_ptr == NULL || value_to_dispose == NULL || equality_comparer_for_T == NULL)
        return 1;

    p_list_item prev_elem = NULL;

    int i;
    while (1)
    {
        if (prev_elem == NULL)
        {
            if (list_ptr->first == NULL)
            {
                return 0;
            }
            if (!equality_comparer_for_T(value_to_dispose, &list_ptr->first->data))
            {
                // TODO: handle return value
                 dispose_from_list_by_index(list_ptr, 0, &i);
            }
            

        }
    }
}

int forward_const_traversion_list(
    list const *list_ptr,
    void (*callback)(int const *))
{
    list_item* run;
    if (list_ptr == NULL)
        return 1;
    if (callback == NULL)
        return 1;

    run=list_ptr->first;
    while (run != NULL)
    {
        callback(&run->data);
        run = run->next;
    }
    return 0;
}