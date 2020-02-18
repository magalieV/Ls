/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** __DESCRIPTION__
*/

#include "ls_header.h"

char *fille_str_date(int k, char *new, linked_list_t *list)
{
    for (int j = 0; list->date[2][j]; j++)
        new[k++] = list->date[2][j];
    for (int e = 0; list->date[3][e]; e++)
        new[k++] = list->date[3][e];
    for (int l = 0; list->date[4][l]; l++)
        new[k++] = list->date[4][l];
    for (int a = 0; list->date[5][a]; a++)
        new[k++] = list->date[5][a];
    new[k] = '\0';
    return (new);
}
