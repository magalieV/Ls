/*
** EPITECH PROJECT, 2019
** my_ls_new
** File description:
** __DESCRIPTION__
*/

#include "ls_header.h"

void display_list(linked_list_t *list, int bol, int hiden)
{
    if (bol == 0)
        list = list_to_begin(list);
    else
        list = list_to_end(list);
    while (list) {
        list = if_end_list(list, bol, hiden);
        if (list == NULL)
            return;
        my_putstr(list->file);
        if (verif_list(list, bol, 0) == 1)
            break;
        my_putstr("\t");
        list = pass_list(list, bol);
    }
    if (list)
        my_putchar('\n');
}

void my_putstr_r(char const *str)
{
    if (!str)
        return;
    for (int i = 0; str[i]; i++)
        write(2, &str[i], 1);
}

void my_putstr(char const *str)
{
    if (!str)
        return;
    for (int i = 0; str[i]; i++)
        write(1, &str[i], 1);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nb)
{
    int number_mod = nb;
    int number_div;

    if (nb < 0) {
        nb *= -1;
        my_putchar('-');
    }
    if (nb >= 10) {
        number_mod = nb % 10;
        number_div = nb / 10;
        my_put_nbr(number_div);
        nb = number_mod;
    }
    my_putchar(nb + 48);
    return (0);
}
