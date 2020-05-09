/*
** EPITECH PROJECT, 2018
** len array and get_pwd
** File description:
** By Germain Gadel
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "my.h"

int len_double_array(char **array)
{
    int count = 0;

    for (; array[count]; count++);
    return (count);
}

void get_pwd(void)
{
    char path[FILENAME_MAX];

    if (getcwd(path, sizeof(path)) != NULL) {
        my_putstr(path);
        my_putchar('\n');
    }
}