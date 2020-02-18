/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** __DESCRIPTION__
*/

#include "ls_header.h"

linked_list_t *if_end_list(linked_list_t *list, int bol, int hiden)
{
    while (hiden == 0 && list->file[0] == '.') {
        if (verif_list(list, bol, 1) == 1)
            return (NULL);
        list = pass_list(list, bol);
    }
    return (list);
}

linked_list_t *if_end_list_no_print(linked_list_t *list, int bol, int hiden)
{
    while (hiden == 0 && list->file[0] == '.') {
        if (verif_list(list, bol, 0) == 1)
            return (NULL);
        list = pass_list(list, bol);
    }
    return (list);
}

void put_total(linked_list_t *list, int total)
{
    if (if_one_el_and_file(list) == 1) {
        my_putstr("total ");
        my_put_nbr(total / 2);
        my_putchar('\n');
    }
}

int modif_nb_arg(char **av, int nb, int bol)
{
    if (bol == 1 && !av[nb] || nb <= 0)
        return (nb);
    while (av && av[nb][0] == '-')
        nb--;
    return (nb);
}
