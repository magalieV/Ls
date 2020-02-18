/*
** EPITECH PROJECT, 2019
** my_ls_new
** File description:
** __SECU HEADER__
*/

#ifndef SECU_HEADER
#define SECU_HEADER

int if_one_el_and_file(linked_list_t *list);
int not_a_directory(char const *, int);
void read_file_in_dir(struct dirent *, DIR *);
int can_read_file(DIR *, char const *, int);
void print_message(char const *path);

linked_list_t *if_end_list(linked_list_t *list, int bol, int hiden);
void put_total(linked_list_t *list, int total);
linked_list_t *if_end_list_no_print(linked_list_t *list, int bol, int hiden);
int modif_nb_arg(char **av, int nb, int bol);
#endif
