/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** compare two strings
*/
#include "my.h"

int my_strcmp(char const *str1, char const *str2)
{
    int i = 0;

    if (my_strlen(str1) != my_strlen(str2))
        return (1);
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i])
            return (1);
        i++;
    }
    return (0);
}