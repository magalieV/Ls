/*
** EPITECH PROJECT, 2019
** my_ls_new
** File description:
** __DESCRIPTION__
*/

#include "ls_header.h"

void right_user(linked_list_t *list)
{
    int bol = 0;

    (list->data.st_mode & S_IRUSR) == 0 ? my_putstr("-") : my_putstr("r");
    (list->data.st_mode & S_IWUSR) == 0 ? my_putstr("-") : my_putstr("w");
    (list->data.st_mode & S_ISUID) != 0 ? (my_putstr("s"), bol++) : 0;
    (list->data.st_mode & S_IXUSR) != 0 && bol == 0 ?
    (my_putstr ("x"), bol++) : 0;
    if (bol == 0)
        my_putstr("-");
}

void type_of_file(linked_list_t *list)
{
    int bol = 0;

    S_ISDIR(list->data.st_mode) ? (my_putstr(" d"), bol++) : 0;
    S_ISLNK(list->data.st_mode) ? (my_putstr(" l"), bol++) : 0;
    S_ISCHR(list->data.st_mode) ? (my_putstr(" c"), bol++) : 0;
    S_ISBLK(list->data.st_mode) ? (my_putstr(" b"), bol++) : 0;
    S_ISREG(list->data.st_mode) ? (my_putstr(" -"), bol++) : 0;
    S_ISFIFO(list->data.st_mode) ? (my_putstr(" f"), bol++) : 0;
    S_ISSOCK(list->data.st_mode) ? (my_putstr(" s"), bol++) : 0;
    if (bol == 0)
        my_putstr(" O");
}

void right(linked_list_t *list)
{
    int bol = 0;

    type_of_file(list);
    right_user(list);
    right_group(list);
    (list->data.st_mode & S_IROTH) == 0 ? my_putstr("-") : my_putstr("r");
    (list->data.st_mode & S_IWOTH) == 0 ? my_putstr("-") : my_putstr("w");
    (list->data.st_mode & S_ISVTX) != 0 ? (my_putstr("t "), bol++) : 0;
    (list->data.st_mode & S_IXOTH) != 0 && bol == 0 ?
    (my_putstr ("x "), bol++) : 0;
    if (bol == 0)
        my_putstr("- ");
}

void total_list(linked_list_t *list, int bol, int bl, int total)
{
    while (bl == 0 && list->file[0] == '.') {
        if (verif_list(list, bol, 0) == 1) {
            put_total(list, total);
            return;
        }
        list = pass_list(list, bol);
    }
    total += list->data.st_blocks;
    if ((bol == 0 && list->next == NULL) || (bol == 1 && list->prev == NULL)) {
        put_total(list, total);
        return;
    }
    list = pass_list(list, bol);
    return (total_list(list, bol, bl, total));
}

linked_list_t *l_option(int bol, linked_list_t *list, int bl, int stati)
{
    if (stati == 0) {
        if (bol == 0)
            list = list_to_begin(list);
        else
            list = list_to_end(list);
        if (!list)
            return (list);
        total_list(list, bol, bl, 0);
    }
    stati++;
    while (bl == 0 && list && list->file[0] == '.') {
        if (verif_list(list, bol, 0) == 1)
            return (list);
        list = pass_list(list, bol);
    }
    attribute_function(list);
    if ((bol == 0 && list->next == NULL) || (bol == 1 && list->prev == NULL))
        return (list);
    list = pass_list(list, bol);
    return (l_option(bol, list, bl, stati));
}
