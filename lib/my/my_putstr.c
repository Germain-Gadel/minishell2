/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** By Germain Gadel
*/

#include "../../include/my.h"

int my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
    i++;
    }
    return (0);
}
