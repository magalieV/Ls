/*
** EPITECH PROJECT, 2019
** my_ls_new
** File description:
** __DESCRIPTION__
*/

#include "ls_header.h"

int is_here(char *flag, char c)
{
    for (int i = 0; flag[i]; i++)
        if (flag[i] == c)
            return (1);
    return (0);
}

int is_flag(char c, char *flag)
{
    if ((c == 'l' || c == 'R' || c == 'd') && is_here(flag, c) == 0)
        return (1);
    if ((c == 'r' || c == 't') && is_here(flag, c) == 0)
        return (1);
    return (0);
}

char *flag_found(char *str, char *flag, int *k)
{
    for (int i = 1; str[i]; i++) {
        if (is_flag(str[i], flag)) {
            flag[*k] = str[i];
            *k += 1;
            flag[*k] = '\0';
        }
    }
    return (flag);
}

char *sort_flag(char **av, int ac)
{
    char *flag = NULL;
    int k = 0;

    if (ac < 2)
        return (flag);
    flag = malloc(sizeof(char) * 6);
    flag[0] = '\0';
    for (int i = 1; av[i]; i++)
        if (av[i][0] == '-')
            flag = flag_found(av[i], flag, &k);
    return (flag);
}

int found_flag_l(char *flag, char c)
{
    if (!flag)
        return (0);
    for (int i = 0; flag[i]; i++) {
        if (flag[i] == c)
            return (1);
    }
    return (0);
}
