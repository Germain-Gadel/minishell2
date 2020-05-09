/*
** EPITECH PROJECT, 2018
** char
** File description:
** moi
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
