/*
** EPITECH PROJECT, 2019
** my_ls_new
** File description:
** __DESCRIPTION__
*/

#include "ls_header.h"

linked_list_t *change_place(linked_list_t *tmp_one, linked_list_t *tmp)
{
    linked_list_t *prev = tmp_one->prev;
    linked_list_t *next = tmp->next;

    if (tmp_one->prev)
        prev->next = tmp;
    if (tmp->next)
        next->prev = tmp_one;
    tmp_one->prev = tmp;
    tmp_one->next = next;
    tmp->prev = prev;
    tmp->next = tmp_one;
}

void delete_all_list(linked_list_t *list)
{
    list = list_to_begin(list);
    while (list) {
        if (list->next == NULL)
            break;
        list = list->next;
        free(list->prev->date);
        free(list->prev);
    }
    free(list);
}

linked_list_t *list_to_end(linked_list_t *list)
{
    if (list && list->next != NULL) {
        list = list->next;
        return (list_to_end(list));
    }
    return (list);
}

linked_list_t *list_to_begin(linked_list_t *list)
{
    if (list && list->prev != NULL) {
        list = list->prev;
        return (list_to_begin(list));
    }
    return (list);
}

linked_list_t *pass_list(linked_list_t *list, int bol)
{
    if (bol == 0)
        list = list->next;
    else
        list = list->prev;
    return (list);
}
