/*
** EPITECH PROJECT, 2018
** change_prompt.c
** File description:
** By Germain Gadel
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "my.h"

char *get_user(char *user)
{
    char **user_name = my_strtwa(user, '=');

    if (user_name[1] != NULL)
        return (user_name[1]);
    user_name = free_double(user_name);
    return ("$ ");
}

char *get_user_var(char **envp)
{
    int var_exist_user = -1;

    var_exist_user = find_envp_var_single(envp, "USER");
    if (var_exist_user != -1) {
        return (my_strcat(get_user(envp[var_exist_user]), " $> "));
    }
    return ("$ ");
}