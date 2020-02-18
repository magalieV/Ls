/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** __DESCRIPTION__
*/

#include "ls_header.h"

DIR *open_folder_path(char const *path)
{
    DIR *dir = NULL;

    dir = opendir(path);
    if (!dir)
        return (NULL);
    return (dir);
}

void my_ls_two(char const *path, char *flag)
{
    linked_list_t *list = NULL;
    int bol = 0;
    int bl = 0;

    if (found_flag_l(flag, 'd')) {
        list = d_option(path);
        bl = 1;
    } else {
        list = my_params_to_list((char *)path);
        list = list_to_begin(list);
    }
    if (found_flag_l(flag, 't'))
        list = t_option(list);
    if (found_flag_l(flag, 'r'))
        bol = 1;
    if (found_flag_l(flag, 'l'))
        l_option(bol, list, bl, 0);
    else
        display_list(list, bol, bl);
    if (found_flag_l(flag, 'R'))
        r_option(list, flag, bol, bl);
}

int is_av(char **av, int nb)
{
    int count = 0;

    if (!av)
        return (1);
    for (int i = 0; av[i]; i++) {
        if (av[i][0] == '-')
            count++;
    }
    if (av[1] && !av[2])
        return (10);
    if (count + 1 == nb)
        return (1);
    return (0);
}

void put_name_of_file(char **av, int tmp2, int nb, char *flag)
{
    if (is_av(av, tmp2) == 0) {
        my_putstr(av[nb]);
        my_putstr(":\n");
    }
    if (found_flag_l(flag, 'R') && is_av(av, tmp2) == 1)
        my_putstr(".:\n");
}

int my_ls(char **av, int nb, char *flag, int tmp2)
{
    char *path = NULL;
    linked_list_t *list = NULL;
    int tmp = 0;

    tmp = is_av(av, nb);
    nb--;
    nb = modif_nb_arg(av, nb, 0);
    if ((nb <= 0 && tmp == 0))
        return (1);
    if (!av || is_av(av, tmp2) == 1)
        path = current_directory_in_string(path);
    else if (nb != 0)
        path = av[nb];
    if (path == NULL)
        return (1);
    put_name_of_file(av, tmp2, nb, flag);
    my_ls_two(path, flag);
    !av ? free(path) : 0;
    if (av && av[nb] && modif_nb_arg(av, nb - 1, 1) >= 1)
        my_putchar('\n');
    return (av && av[nb] && nb > 1 ? my_ls(av, nb, flag, tmp2) : 1);
}
