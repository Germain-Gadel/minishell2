/*
** EPITECH PROJECT, 2018
** exit and pwd
** File description:
** By Germain Gadel
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "my.h"

void check_commands(char *buffer, int *state)
{
    char **exit_arg = my_strtwa(buffer, ' ');
    int len_array = len_double_array(exit_arg);
    int exit_value;

    if (my_strcmp(exit_arg[0], "exit") == 0) {
        if (len_array >= 2) {
            free(buffer);
            exit_value = my_getnbr(exit_arg[1]);
            exit_arg = free_double(exit_arg);
            exit(exit_value);
        }
        free(buffer);
        exit_arg = free_double(exit_arg);
        exit (0);
    } else if (my_strcmp(buffer, "pwd") == 0) {
        get_pwd();
        *state += 1;
    }
}