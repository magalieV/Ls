/*
** EPITECH PROJECT, 2019
** my_ls_new
** File description:
** __DESCRIPTION__
*/

#include "ls_header.h"

char *concat_string_directory(char const *str, char const *tab)
{
    int size = my_strlen(str);
    int size_tab = my_strlen(tab);
    int k = 0;
    char *new = malloc(sizeof(char) * (size + size_tab + 2));

    for (int i = 0; str[i]; i++)
        new[k++] = str[i];
    if (new[k - 1] != '/')
        new[k++] = 47;
    for (int j = 0; tab[j]; j++)
        new[k++] = tab[j];
    new[k] = '\0';
    return (new);
}

char *current_directory_in_string(char *str)
{
    str = malloc(sizeof(char) * 2);

    if (!str)
        exit(84);
    str[0] = '.';
    str[1] = '\0';
    return (str);
}

char *my_strcpy(char const *str)
{
    int size = my_strlen(str);
    char *new = malloc(sizeof(char) * (size + 1));
    int i = 0;

    for (i = 0; str[i]; i++)
        new[i] = str[i];
    new[i] = '\0';
    return (new);
}

char *my_strcat_list(linked_list_t *list)
{
    char *new = NULL;
    int k = 0;

    new = malloc(sizeof(char) * 15);
    for (int i = 0; list->date[6][i]; i++)
        new[k++] = list->date[6][i];
    if (list->month / 10 != 0) {
        new[k++] = list->month / 10 + 48;
        new[k++] = list->month % 10 + 48;
    } else {
        new[k++] = '0';
        new[k++] = list->month + 48;
    }
    if (!list->date[2][1])
        new[k++] = '0';
    new = fille_str_date(k, new, list);
    return (new);
}

void destroy_doub_tab(char **str)
{
    int i = 0;

    if (!str)
        return;
    for (i = 0; str[i]; i++)
        free(str[i]);
    free(str);
}
