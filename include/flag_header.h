/*
** EPITECH PROJECT, 2019
** my_ls_new
** File description:
** __HEADER FOR FLAG__
*/

#ifndef FLAG_HEADER
#define FLAG_HEADER

linked_list_t *fille_list(char const *, linked_list_t *,
    struct passwd *, struct group *);
linked_list_t *d_option(char const *);

linked_list_t *l_option(int bol, linked_list_t *list, int bl, int stati);
void user(linked_list_t *list);
void size_file(linked_list_t *list);
void date_file(linked_list_t *list);
void right_group(linked_list_t *list);
void attribute_function(linked_list_t *list);
void right(linked_list_t *list);

void t_option_sort(linked_list_t *);
linked_list_t *t_option(linked_list_t *);

linked_list_t *r_option(linked_list_t *list, char *flag, int bol, int bl);

#endif
