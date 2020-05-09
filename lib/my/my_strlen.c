/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** By Germain Gadel
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}