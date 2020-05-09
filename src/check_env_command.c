/*
** EPITECH PROJECT, 2018
** check env command
** File description:
** By Germain Gadel
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "my.h"

void print_env(char **envp)
{
    int i = 0;

    for (;envp[i] != NULL; i++) {
        if (my_strcmp(envp[i], "empty") == 0)
            continue;
        my_putstr(envp[i]);
        my_putchar('\n');
    }
}

char **check_commands_env(char *buffer, char **envp, int *state)
{
    char **envp_arg = my_strtwa(buffer, ' ');
    int len_array = len_double_array(envp_arg);

    if (my_strcmp(buffer, "env") == 0) {
        print_env(envp);
        *(state) += 1;
    } else if (my_strcmp(envp_arg[0], "setenv") == 0 && len_array >= 2) {
        envp = fill_envp(envp, envp_arg, len_array);
        *(state) += 1;
    } else
        envp = remove_from_envp(envp, envp_arg, len_array, state);
    envp_arg = free_double(envp_arg);
    return (envp);
}