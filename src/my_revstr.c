/*
** EPITECH PROJECT, 2018
** my_revstr.
** File description:
** By Germain Gadel
*/

#include "my.h"

char *my_revstr(char *str)
{
    int i = my_strlen(str) - 1;
    int j = 0;
    int k = my_strlen(str);
    char t;

    while (j < i) {
        t = str[j];
        str[j] = str[i];
        str[i] = t;
        j++;
        i--;
    }
    str[k] = '\0';
    return (str);
}