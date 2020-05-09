/*
** EPITECH PROJECT, 2018
** find in env
** File description:
** By Germain Gadel
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "my.h"

char *replace_var(char *envp_var, char **envp_arg, int len_envp_arg)
{
    if (len_envp_arg == 2)
        envp_var = my_strcat(envp_arg[1], "=");
    else
        envp_var = my_strcat(my_strcat(envp_arg[1], "="), envp_arg[2]);

    return (envp_var);
}

int find_envp_var_single(char **envp, char *single_var)
{
    char **var_exist_array = my_strtwa(envp[0], '=');
    int i = 0;

    while (var_exist_array[0] != NULL && (my_strcmp(var_exist_array[0],
    single_var))) {
        free_double(var_exist_array);
        i++;
        var_exist_array = my_strtwa(envp[i], '=');
        if (envp[i + 1] == NULL)
            return (-1);
    }
    var_exist_array = free_double(var_exist_array);
    return (i);
}

char **fill_envp(char **envp, char **envp_arg, int var_empty)
{
    int i = len_double_array(envp);
    int var_exist = find_envp_var_single(envp, envp_arg[1]);

    if (var_empty == 2 && var_exist == -1) {
        envp[i] = my_strcat(envp_arg[1], "=");
        envp[i + 1] = NULL;
    } else if (var_empty == 3 && var_exist == -1) {
        envp[i] = my_strcat(my_strcat(envp_arg[1], "="), envp_arg[2]);
        envp[i + 1] = NULL;
    } else
        envp[var_exist] = replace_var(envp[var_exist],
        envp_arg, len_double_array(envp_arg));
    return (envp);
}

char **remove_from_envp(char **envp, char **envp_arg, int len_array, int *state)
{
    int var_exist = -1;

    if (my_strcmp(envp_arg[0], "unsetenv") == 0 && len_array >= 2) {
        if ((var_exist = find_envp_var_single(envp, envp_arg[1])) != -1) {
            envp[var_exist] = "empty";
            *(state) += 1;
        }
    }
    return (envp);
}