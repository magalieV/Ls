/*
** EPITECH PROJECT, 2019
** my_ls_new
** File description:
** __HEADER FOR LIST__
*/

#ifndef LIST_HEADER
#define LIST_HEADER

linked_list_t *change_place(linked_list_t *, linked_list_t *);
void delete_all_list(linked_list_t *);
linked_list_t *list_to_end(linked_list_t *);
linked_list_t *list_to_begin(linked_list_t *);
linked_list_t *pass_list(linked_list_t *, int);

int verif_list(linked_list_t *, int, int);
linked_list_t *first_two(linked_list_t *, char *);
linked_list_t *first_t(linked_list_t *, struct dirent *, char *);
linked_list_t *my_params_to_list(char *);

#endif
