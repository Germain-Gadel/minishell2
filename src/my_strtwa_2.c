/*
** EPITECH PROJECT, 2019
** my str to word array
** File description:
** By Germain Gadel
*/

#include "my.h"

int my_little_len(char *str, int cnt, int *space, char sep)
{
    while (str[cnt] != sep && str[cnt] != '\0') {
        cnt++;
    }
    *(space) += 1;
    return (cnt);
}

int cntspace(char *str, char sep)
{
    int cnt = 0;
    int space = 0;

    while (str[cnt] != '\0') {
        if (str[cnt] == sep)
            space++;
        cnt++;
    }
    space++;
    return (space);
}