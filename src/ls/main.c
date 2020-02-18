/*
** EPITECH PROJECT, 2019
** my_ls_new
** File description:
** __DESCRIPTION__
*/

#include "ls_header.h"

int main(int ac, char **av)
{
    DIR *dir = NULL;
    int nb = ac;
    char *flag = NULL;

    flag = sort_flag(av, ac);
    if (ac < 2)
        my_ls(NULL, 3, flag, 3);
    else
        my_ls(av, nb, flag, nb);
    return (0);
}
