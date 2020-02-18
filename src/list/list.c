/*
** EPITECH PROJECT, 2019
** my_ls_new
** File description:
** __DESCRIPTION__
*/

#include "ls_header.h"

int verif_list(linked_list_t *list, int bol, int bol_b)
{
    if (bol == 0 && list->next == NULL) {
        bol_b == 1 ? my_putstr("\n") : 0;
        return (1);
        }
    if (bol == 1 && list->prev == NULL) {
        bol_b == 1 ? my_putstr("\n") : 0;
        return (1);
    }
    return (0);
}

linked_list_t *first_two(linked_list_t *begin, char *path)
{
    linked_list_t *new_st = malloc(sizeof(linked_list_t));
    struct stat data = {0};
    struct passwd *id;
    struct group *id_group;

    stat(path, &data);
    id_group = getgrgid(data.st_gid);
    id = getpwuid(data.st_uid);
    new_st->data = data;
    new_st->file_d = NULL;
    new_st->date = my_str_to_word_array(ctime(&data.st_mtime));
    new_st = fille_list(path, new_st, id, id_group);
    new_st->next = NULL;
    new_st->d_opt = 0;
    if (begin == NULL)
        new_st->prev = NULL;
    else {
        new_st->prev = begin;
        begin->next = new_st;
    }
    return (new_st);
}

linked_list_t *fille_first(linked_list_t *new_st, struct dirent *path,
    struct stat data)
{
    struct passwd *id;
    struct group *id_group;

    id_group = getgrgid(data.st_gid);
    id = getpwuid(data.st_uid);
    if (id == NULL || id_group == NULL)
        exit(0);
    new_st->data = data;
    new_st->file_d = path;
    new_st->date = my_str_to_word_array(ctime(&data.st_mtime));
    new_st->file = my_strcpy(path->d_name);
    new_st->month = accord_month(new_st->date[1]);
    new_st->user_name = my_strcpy(id->pw_name);
    new_st->user_group = my_strcpy(id_group->gr_name);
}

linked_list_t *first_t(linked_list_t *begin, struct dirent *path,
    char *directory)
{
    linked_list_t *new_st = malloc(sizeof(linked_list_t));
    struct stat data = {0};
    char *tmp = my_strcpy(path->d_name);
    char *access = concat_string_directory(directory, tmp);

    stat(access, &data);
    new_st = fille_first(new_st, path, data);
    new_st->directory = my_strcpy(directory);
    new_st->access = my_strcpy(access);
    new_st->d_opt = 0;
    new_st->next = NULL;
    if (begin == NULL)
        new_st->prev = NULL;
    else {
        new_st->prev = begin;
        begin->next = new_st;
    }
    free(tmp);
    return (new_st);
}

linked_list_t *my_params_to_list(char *path)
{
    linked_list_t *object = NULL;
    DIR *dir = NULL;
    struct dirent *file = NULL;

    dir = open_folder_path(path);
    if (can_read_file(dir, path, 0) == 1 && dir != NULL)
        file = readdir(dir);
    else if (can_read_file(dir, path, 1) == 0)
        object = first_two(object, path);
    while (file != NULL) {
        object = first_t(object, file, path);
        file = readdir(dir);
    }
    object = list_to_begin(object);
    if (object == NULL && dir == NULL)
        print_message(path);
    if (dir)
        closedir(dir);
    return (object);
}
