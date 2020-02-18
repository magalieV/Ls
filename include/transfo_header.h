/*
** EPITECH PROJECT, 2019
** my_ls_new
** File description:
** __HEADER FOR TRANSFO__
*/

#ifndef TRANSFO_HEADER
#define TRANSFO_HEADER

char *concat_string_directory(char const *, char const *);
char *current_directory_in_string(char *);
char *my_strcpy(char const *);
char *my_strcat_list(linked_list_t *);
void destroy_doub_tab(char **);

int my_strcmp(char const *, char const *);
int accord_month(char *);
int if_alphnum(char const *, int);
int alloc_memo(char const *);
char **my_str_to_word_array(char const *);

char *fille_str_date(int k, char *new, linked_list_t *list);

#endif
