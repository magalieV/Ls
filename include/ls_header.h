/*
** EPITECH PROJECT, 2019
** my_ls_new
** File description:
** __DESCRIPTION__
*/

#ifndef INCLUDE
#define INCLUDE

#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <time.h>
#include <stdio.h>
#include <grp.h>
#include <errno.h>

typedef struct linked_list {
    struct dirent *file_d;
    char *file;
    struct stat data;
    char **date;
    int d_opt;
    int month;
    char *user_name;
    char *user_group;
    char *access;
    char *directory;
    struct linked_list *next;
    struct linked_list *prev;
} linked_list_t;

#include "size_header.h"
#include "list_header.h"
#include "display_header.h"
#include "flag_header.h"
#include "ls_ls_header.h"
#include "secu_header.h"
#include "transfo_header.h"

#endif
