/*
** EPITECH PROJECT, 2018
** my_strcat.c
** File description:
** concanate two string together
*/

#include "./my.h"

char *my_strcat(char *dest, char *src)
{
    int j = 0;
    int length1 = my_strlen(dest);
    int length2 = my_strlen(src);
    int total = length1 + length2;
    int inc = 0;
    char *res = malloc(sizeof(char) * (total + 1));

    for (inc = 0; dest[inc]; inc++, j++)
        res[j] = dest[inc];
    for (inc = 0; src[inc]; inc++, j++)
        res[j] = src[inc];
    res[total] = '\0';
    return (res);
}

char *my_strcat_sep(char *dest, char *src, char sep)
{
    int inc = 0;
    int length1 = my_strlen(dest);
    int length2 = my_strlen(src);
    int total = length1 + length2 + 1;
    char *res = malloc(sizeof(char) * (total + 1));
    int j = 0;

    while (dest[inc] != '\0') {
        res[j] = dest[inc];
        inc++;
        j++;
    }
    res[j++] = sep;
    for (inc = 0; src[inc]; inc++, j++)
        res[j] = src[inc];
    res[total] = '\0';
    return (res);
}