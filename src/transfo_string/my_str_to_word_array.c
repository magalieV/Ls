/*
** EPITECH PROJECT, 2019
** my_ls_new
** File description:
** __DESCRIPTION__
*/

#include "ls_header.h"

int my_strcmp(char const *sa, char const *sb)
{
    return (!*sa || (*sa != *sb) ? (*sa - *sb) : my_strcmp(sa + 1, sb + 1));
}

int accord_month(char *str)
{
    char *month[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug",
                    "Sep", "Oct", "Nov", "Dec", 0};
    for (int i = 0; month[i]; i++) {
        if (my_strcmp(month[i], str) == 0) {
            return (i + 1);
        }
    }
    return (0);
}

int if_alphnum(char const *str, int i)
{
    if (str[i] >= 'a' && str[i] <= 'z')
        return (1);
    else if (str[i] >= 'A' && str[i] <= 'Z')
        return (1);
    if (str[i] >= '0' && str[i] <= '9')
        return (1);
    return (0);
}

int alloc_memo(char const *str)
{
    int i = 0;
    int k = 0;

    while (str[i]) {
        if (if_alphnum(str, i) && !if_alphnum(str, i + 1))
            k++;
        i++;
    }
    return (k);
}

char **my_str_to_word_array(char const *str)
{
    char **dest;
    int i = 0;
    int g = 0;
    int n;

    dest = malloc(sizeof(char *) * (alloc_memo(str) + 1) + 1);
    while (str[g]) {
        if (!if_alphnum(str, g))
            g++;
        for (n = g; if_alphnum(str, n); n++);
        dest[i] = (char *)malloc((n - g) + 2);
        dest[i][0] = 0;
        for (n = 0; if_alphnum(str, g); n++)
            dest[i][n] = str[g++];
        dest[i][n] = '\0';
        if (dest[i][0])
            i++;
    }
    dest[i] = 0;
    return (dest);
}
