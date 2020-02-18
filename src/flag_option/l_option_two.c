/*
** EPITECH PROJECT, 2019
** my_ls_new
** File description:
** __Part two option l__
*/

#include "ls_header.h"

void attribute_function(linked_list_t *list)
{
    right(list);
    my_putchar('\t');
    my_put_nbr(list->data.st_nlink);
    my_putchar('\t');
    user(list);
    size_file(list);
    date_file(list);
    my_putstr(list->file);
    my_putchar('\n');
}

void right_group(linked_list_t *list)
{
    int bol = 0;

    (list->data.st_mode & S_IRGRP) == 0 ? my_putstr("-") : my_putstr("r");
    (list->data.st_mode & S_IWGRP) == 0 ? my_putstr("-") : my_putstr("w");
    (list->data.st_mode & S_ISGID) != 0 ? (my_putstr("s"), bol++) : 0;
    (list->data.st_mode & S_IXGRP) != 0 && bol == 0 ?
    (my_putstr("x"), bol++) : 0;
    if (bol == 0)
        my_putstr("-");
}

void user(linked_list_t *list)
{
    my_putstr(list->user_name);
    my_putchar('\t');
    my_putstr(list->user_group);
}

void size_file(linked_list_t *list)
{
    my_putchar('\t');
    my_put_nbr(list->data.st_size);
    my_putchar('\t');
}

void date_file(linked_list_t *list)
{
    my_putstr(list->date[1]);
    my_putchar('\t');
    my_putstr(list->date[2]);
    my_putchar('\t');
    my_putstr(list->date[3]);
    my_putchar(':');
    my_putstr(list->date[4]);
    my_putchar('\t');
}
