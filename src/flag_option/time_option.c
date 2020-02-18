/*
** EPITECH PROJECT, 2019
** my_ls_new
** File description:
** __DESCRIPTION__
*/

#include "ls_header.h"

void t_option_sort(linked_list_t *list)
{
    char *tmp1 = NULL;
    char *tmp2 = NULL;

    if (list->file_d != NULL && list->next != NULL) {
        tmp1 = my_strcat_list(list);
        tmp2 = my_strcat_list(list->next);
        if (my_strcmp(tmp1, tmp2) < 0)
            change_place(list, list->next);
        free(tmp1);
        free(tmp2);
    }
    if (list->next == NULL)
        return;
    list = list->next;
    return (t_option_sort(list));
}

linked_list_t *t_option(linked_list_t *list)
{
    int count = size_list(list);

    for (int i = 0; i < count; i++) {
        t_option_sort(list);
        while (list && list->prev != NULL)
            list = list->prev;
        }
    return (list);
}
