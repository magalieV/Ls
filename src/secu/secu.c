/*
** EPITECH PROJECT, 2019
** my_ls_new
** File description:
** __SECU__
*/

#include "ls_header.h"

void print_message(char const *path)
{
    int err = errno;

    if (err == EACCES) {
        my_putstr_r("my_ls: cannot open directory '");
        my_putstr_r(path);
        my_putstr_r("' : ");
        perror("");
    } else {
        my_putstr_r("my_ls: cannot access '");
        my_putstr_r(path);
        my_putstr_r("' : ");
        perror("");
    }
}

int if_one_el_and_file(linked_list_t *list)
{
    int count = 0;

    list = list_to_begin(list);
    while (list) {
        count++;
        if (list->next == NULL)
            break;
        list = list->next;
    }
    if (count == 1 &&
        (list->d_opt == 1 || S_ISDIR(list->data.st_mode)) != 1)
        return (0);
    return (1);
}

int not_a_directory(char const *path, int bol)
{
    struct stat data = {0};

    stat(path, &data);
    if (data.st_size == 0)
        return (2);
    if (S_ISDIR(data.st_mode))
        return (1);
    return (0);
}

void read_file_in_dir(struct dirent *file, DIR *dir)
{
    my_putstr(file->d_name);
    my_putchar('\n');
    file = readdir(dir);
    if (file == NULL)
        return;
    return (read_file_in_dir(file, dir));
}

int can_read_file(DIR *dir, char const *path, int bol)
{
    struct dirent *file = NULL;

    if (!dir) {
        if (not_a_directory(path, bol) == 0)
            return (0);
    } else
        return (1);
}
