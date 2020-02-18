/*
** EPITECH PROJECT, 2019
** my_ls_new
** File description:
** __RECUP SIZE__
*/

#include "ls_header.h"

int my_strlen(char const *str)
{
    int size = 0;

    if (!str)
        return (0);
    for (size = 0; str[size]; size++);
    return (size);
}

int size_list(linked_list_t *list)
{
    int count = 0;

    list = list_to_begin(list);
    while (list && list->next != NULL) {
        count++;
        list = list->next;
    }
    return (count);
}
