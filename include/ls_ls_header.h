/*
** EPITECH PROJECT, 2019
** my_ls_new
** File description:
** __LS HEADER__
*/

#ifndef LS_HEADER
#define LS_HEADER

int is_here(char *, char);
int is_flag(char, char *);
char *flag_found(char *, char *, int *);
char *sort_flag(char **, int);
int found_flag_l(char *, char);

DIR *open_folder_path(char const *);
void my_ls_two(char const *, char *);
int my_ls(char **, int, char *, int);

#endif
