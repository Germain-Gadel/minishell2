/*
** EPITECH PROJECT, 2019
** delete spaces and tabs from a string
** File description:
** by Germain Gadel
*/

#include "my.h"

int next_word(char *str, int x)
{
    while ((str[x] == ' ' || str[x] == '\t') && str[x] != '\0')
        x++;
    return (x);
}

char *mall_clean(char *str)
{
    char *dest;
    int len = 0;

    for (int x = next_word(str, 0); str[x] != '\0'; x++) {
        if (str[x] == ' ' || str[x] == '\t') {
            x = next_word(str, x);
            len++;
        }
        len++;
        if (str[x] == '\0')
            x--;
    }
    dest = malloc(sizeof(char) * len + 1);
    if (!dest)
        return (NULL);
    return (dest);
}

char *my_clean_str(char *str)
{
    char *dest = mall_clean(str);
    int j = 0;

    for (int x = next_word(str, 0); str[x] != '\0'; x++) {
        if ((str[x] == ' ' || str[x] == '\t') &&
        str[next_word(str, x)] == '\0') {
            x = next_word(str, x) - 1;
        } else if (str[x] == ' ' || str[x] == '\t') {
            x = next_word(str, x) - 1;
            dest[j] = ' ';
            j++;
        } else {
            dest[j] = str[x];
            j++;
        }
    }
    dest[j] = '\0';
    return (dest);
}
