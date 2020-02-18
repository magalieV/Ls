/*
** EPITECH PROJECT, 2019
** my_ls_new
** File description:
** __DESCRIPTION__
*/

#include "ls_header.h"

linked_list_t *r_option(linked_list_t *list, char *flag, int bol, int bl)
{
    linked_list_t *tp = NULL;

    list = list_to_end(list);
    while (list) {
        list = if_end_list_no_print(list, 1, bl);
        if (list == NULL)
            return (list);
        if (S_ISDIR(list->data.st_mode)) {
            my_putchar('\n');
            my_putstr(concat_string_directory(list->directory, list->file));
            my_putstr(":\n");
            my_ls_two(concat_string_directory(list->directory, list->file),
            flag);
            delete_all_list(tp);
        }
        if (list->prev == NULL)
            break;
        list = list->prev;
    }
    return (list);
}
