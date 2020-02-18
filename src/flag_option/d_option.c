/*
** EPITECH PROJECT, 2019
** my_ls_new
** File description:
** __DESCRIPTION__
*/

#include "ls_header.h"

linked_list_t *fille_list(char const *path, linked_list_t *list,
    struct passwd *id, struct group *id_group)
{
    list->file = my_strcpy(path);
    list->month = accord_month(list->date[1]);
    list->user_name = my_strcpy(id->pw_name);
    list->user_group = my_strcpy(id_group->gr_name);
    list->access = my_strcpy(path);
    list->directory = my_strcpy(path);
    return (list);
}

linked_list_t *d_option_fille(struct stat data, linked_list_t *list)
{
    list->data = data;
    list->file_d = NULL;
    list->d_opt = 1;
    return (list);
}

linked_list_t *d_option(char const *path)
{
    char *directory = NULL;
    linked_list_t *list = malloc(sizeof(linked_list_t));
    struct stat data = {0};
    struct passwd *id;
    struct group *id_group;

    if (!path)
        directory = current_directory_in_string(directory);
    else
        directory = my_strcpy(path);
    stat(directory, &data);
    id_group = getgrgid(data.st_gid);
    id = getpwuid(data.st_uid);
    (id == NULL || id_group == NULL) ? exit(0) : 0;
    list = d_option_fille(data, list);
    list->date = my_str_to_word_array(ctime(&data.st_mtime));
    list = fille_list(directory, list, id, id_group);
    list->next = NULL;
    list->prev = NULL;
    path ? free(directory) : 0;
    return (list);
}
